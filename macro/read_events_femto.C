#include "TROOT.h"
#include "TFile.h"
//************************************************************************************************************************************************
/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Macro for calculating the freeze-out coordinates for particle 1 & particle 2 of all pairs of
 ** a selected particle species from PHQMD.
 ** 
 ** Freeze-out coordinates are calculated in two ways:
 ** - extrapolation of freeze-out coordinates to the pair freeze-out time
 ** - using coordinates from closest timestep to pair freeze-out time and extrapolate 
 **   from there to pair freeze-out time
 ** 
 ** Information are taken from EventFreeze & EventFemtoTs stored in phqmd_femto.root which is 
 ** produced with convert_phqmd.C by setting WriteEventFemto = kTRUE. 
 ** This macro can only be applied for protons, neutrons, Lambdas and clusters (for deuterons: 
 ** only kinetic deuterons).
 **
 **/

#include "TMath.h"
#include "TString.h"
#include <iostream>
using namespace ROOT::Math;

void read_events_femto() {

  Int_t PDG = 2212;
  TString particlename = "protons";

  TString indir = "";
  TString outdir = indir;
  TString prefix = "";
  Int_t first_event = 0;
  Int_t last_event =100;
  TString inFilename = Form("%s/%sphqmd_femto.root",indir.Data(),prefix.Data());
  TString outFilename = Form("%s/%s%s_femto_%d_%d.root",outdir.Data(),prefix.Data(), particlename.Data(), first_event, last_event);
  
  std::cout << "inFilename = " <<inFilename<< std::endl;
  std::cout << "outFilename = " <<outFilename<< std::endl;

  Float_t px_freeze_1, py_freeze_1, pz_freeze_1, px_freeze_2, py_freeze_2, pz_freeze_2;
  Float_t px_step_1, py_step_1, pz_step_1, px_step_2, py_step_2, pz_step_2;
  Float_t x_freeze_1, y_freeze_1, z_freeze_1, x_freeze_2, y_freeze_2, z_freeze_2;
  Float_t x_extra_1, y_extra_1, z_extra_1, x_extra_2, y_extra_2, z_extra_2;
  Float_t x_step_1, y_step_1, z_step_1, x_step_2, y_step_2, z_step_2;

  std::array<Float_t,2> timeFreeze;
  std::array<TVector3,2> pos_freeze, mom_freeze;
  std::array<TVector3,2> pos_extra;
  std::array<TVector3,2> pos_step, mom_step;

  Float_t timeFreezeLatest, time_freeze_1, time_freeze_2;
  TVector3 *mom_freeze_1; TVector3 *mom_freeze_2;
  TVector3 *mom_step_1; TVector3 *mom_step_2;
  TVector3 *pos_freeze_1; TVector3 *pos_freeze_2;
  TVector3 *pos_extra_1; TVector3 *pos_extra_2;
  TVector3 *pos_step_1; TVector3 *pos_step_2;
     
  TFile *outFile;
  outFile = new TFile(outFilename,"RECREATE");
  
  TTree* outtree_pairs = new TTree("pairs", "pairs");
  outtree_pairs -> Branch("time_freeze_1", &timeFreeze.at(0), "time_freeze_1/F");
  outtree_pairs -> Branch("time_freeze_2", &timeFreeze.at(1), "time_freeze_2/F"); 
  outtree_pairs -> Branch("mom_freeze_1", &mom_freeze.at(0));
  outtree_pairs -> Branch("mom_freeze_2", &mom_freeze.at(1));
  outtree_pairs -> Branch("mom_step_1",   &mom_step.at(0));
  outtree_pairs -> Branch("mom_step_2",   &mom_step.at(1));
  outtree_pairs -> Branch("pos_freeze_1", &pos_freeze.at(0));
  outtree_pairs -> Branch("pos_freeze_2", &pos_freeze.at(1));
  outtree_pairs -> Branch("pos_extra_1",  &pos_extra.at(0));
  outtree_pairs -> Branch("pos_extra_2",  &pos_extra.at(1));
  outtree_pairs -> Branch("pos_step_1",   &pos_step.at(0));
  outtree_pairs -> Branch("pos_step_2",   &pos_step.at(1));

  TDirectory *dir = outFile->mkdir(particlename);
  dir->cd();
  
  TH1D *hp[3]; TH1D *hx[3]; 
  TString histname;
  TString xyz [] = {"x", "y", "z"};
  for (int i = 0; i < 3; i++) {
    histname= xyz[i];
    hx[i] = new TH1D(histname,histname,4001,-200.05,200.05);
    hx[i] ->Sumw2();
  }
  for (int i = 0; i < 3; i++) {
    histname=Form("p%s", xyz[i].Data());
    hp[i] = new TH1D(histname,histname,1401,-7.005,7.005);
    hp[i] ->Sumw2();
  }
  
  Float_t binwidth_p = hp[0]->GetXaxis()->GetBinWidth(1);
  Float_t binwidth_x = hx[0]->GetXaxis()->GetBinWidth(1);
  
  TFile *inFile;
  inFile = new TFile(inFilename);

  RunFreeze *header = (RunFreeze *)inFile->Get("run");
  Int_t last_step = header->GetNTime();
	
  TTree *tree;
  tree = (TTree *)inFile->Get("events");
  EventFreeze *event = new EventFreeze();
  tree->SetBranchAddress("event", &event);
 
  TTree *tree_ts;
  tree_ts = (TTree *)inFile->Get("events_femto_ts");
  EventFemtoTs *event_ts = new EventFemtoTs();
  tree_ts->SetBranchAddress("event", &event_ts);
  
  cout<< tree->GetEntries() <<" events in input file."<<endl;
  cout<<"Event "<<first_event << " to " << last_event << " will be processed."<<endl;

  map<int, vector<int>> event_ts_2_event;
  event_ts_2_event.clear();
  map<int, vector<float>> event_2_time;
  event_2_time.clear();

  for (int ievent_ts = 0; ievent_ts < tree_ts->GetEntries(); ievent_ts++) {
	       
    tree_ts->GetEntry(ievent_ts);
	    
    auto it_event = event_ts_2_event.find(event_ts->GetEventId());
    if (it_event != event_ts_2_event.end())
      event_ts_2_event[event_ts->GetEventId()].push_back(ievent_ts);
    else 
      event_ts_2_event[event_ts->GetEventId()] = {ievent_ts};

    auto it_event_2_time = event_2_time.find(event_ts->GetEventId());
    if (it_event_2_time != event_2_time.end())
      event_2_time[event_ts->GetEventId()].push_back(event_ts->GetTime());
    else 
      event_2_time[event_ts->GetEventId()] = {event_ts->GetTime()};
  }
  
      
  for (int ievent = first_event; ievent < last_event; ievent++) {
  
    inFile->cd();
    tree->GetEntry(ievent);
   
    Int_t EventId = event->GetEventId();

    std::array<Float_t,2> energy_freeze;
    std::array<Int_t, 2> index;
    
    for (int iparticle1 = 0; iparticle1 < event->GetNpa(); iparticle1 ++) {
      
      auto particle1 = event->GetParticle(iparticle1);
 
      Int_t pdgId = particle1.GetPdg();
  
      if (pdgId != PDG) continue;

      index.at(0) = particle1.GetIndex();
      timeFreeze.at(0) = particle1.TFreeze();
      pos_freeze.at(0).SetXYZ(particle1.XFreeze(),particle1.YFreeze(),particle1.ZFreeze());
      mom_freeze.at(0).SetXYZ(particle1.PxFreeze(),particle1.PyFreeze(),particle1.PzFreeze());
      energy_freeze.at(0) = particle1.EnergyFreeze();

      outFile->cd(particlename);
      for (int i = 0; i < 3; i++) {
	hp[i]->Fill(mom_freeze.at(0)(i),1.0/binwidth_p);
	hx[i]->Fill(pos_freeze.at(0)(i),1.0/binwidth_x);
      }

      inFile->cd();
      for (int iparticle2 = iparticle1 + 1; iparticle2 < event->GetNpa(); iparticle2 ++) {
	inFile->cd();
	auto particle2 = event->GetParticle(iparticle2);
	
	Int_t pdgId2 = particle2.GetPdg();
	if (pdgId2 != PDG) continue;

	index.at(1) = particle2.GetIndex();

	timeFreeze.at(1) = particle2.TFreeze();
	pos_freeze.at(1).SetXYZ(particle2.XFreeze(),particle2.YFreeze(),particle2.ZFreeze());
	mom_freeze.at(1).SetXYZ(particle2.PxFreeze(),particle2.PyFreeze(),particle2.PzFreeze());
	energy_freeze.at(1) = particle2.EnergyFreeze();

	if (timeFreeze.at(0) == timeFreeze.at(1)) { // freeze-out time is the same for both particles
	  for (int iparticle = 0; iparticle < 2; iparticle ++) {
	    for (int i = 0; i < 3; i++) {
	      pos_extra.at(iparticle)(i) = pos_freeze.at(iparticle)(i);
	      mom_step.at(iparticle) = mom_freeze.at(iparticle);
	      pos_step.at(iparticle)(i) = pos_freeze.at(iparticle)(i);
	    }
	  }
	}
	else { // freeze-out time is different for both particles
	  timeFreezeLatest = *max_element(timeFreeze.begin(), timeFreeze.end());
	  std::array<Float_t,2> deltaT;
	  for (int iparticle = 0; iparticle < 2; iparticle ++) {
	    deltaT.at(iparticle) = timeFreezeLatest - timeFreeze.at(iparticle);
	  }

	  for (int iparticle = 0; iparticle < 2; iparticle ++) {
	    if (deltaT.at(iparticle) == 0) { // particle freeze-out time is pair freeze-out time
	      for (int i = 0; i < 3; i++){
		pos_extra.at(iparticle)(i) = pos_freeze.at(iparticle)(i);
		mom_step.at(iparticle) = mom_freeze.at(iparticle);
		pos_step.at(iparticle)(i) = pos_freeze.at(iparticle)(i);
	      }
	    }
	    else { // particle freeze-out time is earlier than pair freeze-out time
	      for (int i = 0; i < 3; i++) { // extrapolate position
		pos_extra.at(iparticle)(i) = pos_freeze.at(iparticle)(i) + deltaT.at(iparticle) * mom_freeze.at(iparticle)(i) / energy_freeze.at(iparticle);	
	      }
	      
	      //Go into closest timestep of latest freeze-out time
	      auto it_ts = event_2_time.find(EventId);
	      auto it_TsFreeze_up = std::lower_bound(it_ts->second.begin(), it_ts->second.end(), timeFreezeLatest);
	      Int_t TsFreeze = std::distance(it_ts->second.begin(), it_TsFreeze_up); // first timestep after freezeout-time	   
	      if ( ((*it_TsFreeze_up - timeFreezeLatest) > 2.5 && it_TsFreeze_up != it_ts->second.begin()) || it_TsFreeze_up == it_ts->second.end())  TsFreeze --; // timestep closest to freeze-out time

	      
	      Float_t deltaT_step = timeFreezeLatest - it_ts->second.at(TsFreeze);
	    
	      Bool_t UseTimestep = kTRUE;
	      Bool_t WriteParticle = kTRUE;
	      if (TMath::Abs(deltaT_step) > TMath::Abs(timeFreeze.at(iparticle) - timeFreezeLatest)) { // difference between latest fo time and closest timestep is bigger than difference between particle fo time and latest fo time
		UseTimestep = kFALSE;	
	      }
	      if (UseTimestep == kTRUE) {
		auto it_event = event_ts_2_event.find(event->GetEventId());
		Int_t ievent_freeze = it_event -> second[TsFreeze];
		tree_ts->GetEntry(ievent_freeze);

		ParticleFemto particle_ts = event_ts->GetParticleIndex(index.at(iparticle));
		
		if (particle_ts.GetIndex() < 0) { // particle does not exisit in closest timestep

		  if (TsFreeze == last_step) {
		    UseTimestep = kFALSE;
		    WriteParticle = kFALSE;
		    cout<<"-- Warning: Particle " << index.at(iparticle) << " does not exisit in closest timestep or next timestep after closest timestep and will not be written! If you want it to be written nevertheless, set WriteParticle = kTRUE. --"<<endl;
		  }
		  else {
		    TsFreeze++; // go to next timestep	
		    deltaT_step = timeFreezeLatest - it_ts->second.at(TsFreeze);

		    if ((TMath::Abs(deltaT_step) > TMath::Abs(timeFreeze.at(iparticle) - timeFreezeLatest))) { // difference between particle fo time and closest timestep is bigger than difference between particle fo time and latest fo time
		      UseTimestep = kFALSE;
		    }
		    else {
		      ievent_freeze = it_event -> second[TsFreeze];
		      tree_ts->GetEntry(ievent_freeze);
		      particle_ts = event_ts->GetParticleIndex(index.at(iparticle));
		      if (particle_ts.GetIndex() < 0)  {
			WriteParticle = kFALSE;
			cout<<"-- Warning: Particle " << index.at(iparticle) << " does not exisit in closest timestep or next timestep after closest timestep and will not be written! If you want it to be written nevertheless, set WriteParticle = kTRUE. --"<<endl;
		      }
		    }
		  }
		}
		if (UseTimestep == kTRUE) {
		  mom_step.at(iparticle) = particle_ts.GetMomentum();

		  for (int i = 0; i < 3; i++) {
		    pos_step.at(iparticle)(i) = particle_ts.GetPosition()(i) + deltaT_step * particle_ts.GetMomentum()(i) / particle_ts.E();
	       
		  }
		}
		
	      }
	      if (UseTimestep == kFALSE && WriteParticle == kTRUE) {
		for (int i = 0; i < 3; i++) {
		  pos_step.at(iparticle)(i) = pos_extra.at(iparticle)(i);
		  mom_step.at(iparticle) = mom_freeze.at(iparticle);
		}
	      }
	    }
	  }
	}
	outFile -> cd();
	outtree_pairs -> Fill();
	
      }  
    }
  }

  inFile->Close();
  outFile->Write();
  outFile->Save(); 
}
