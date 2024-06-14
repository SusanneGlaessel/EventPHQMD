#include "PConverter.h"
#include "TMath.h"
#include "TNamed.h"
#include "TSystem.h"
#include "PRun.h"
#include "PEventHadrons.h"
#include "PEventBaryons.h"
#include "PHadron.h"
#include "PBaryon.h"
#include "RunFreeze.h"
#include "EventFreeze.h"
#include "ParticleFreeze.h"
#include "URun.h"
#include "UEvent.h"
#include <string>
#include <fstream>

using std::to_string;
using std::runtime_error;
using namespace std;

// ------------------------- Initialisation -----------------------------------------------

void PConverter::Init(TString indir, TString dataset, Bool_t CreatePHQMDout, Bool_t FreezeCoords, Bool_t CreateOutWithUnstable, Bool_t Convert, Bool_t ConvertMode, Bool_t ConvertAnti, Bool_t WriteUnigen, Bool_t WriteEventFreeze, Int_t firstevent)
{
  fFreezeCoords = FreezeCoords;
  fCreatePHQMDout = CreatePHQMDout;
  fCreateOutWithUnstable = CreateOutWithUnstable;
  fConvert = Convert;
  fConvertMode = ConvertMode;
  fDataset = dataset;
  fIndir = indir;

  if (FreezeCoords == kFALSE && WriteEventFreeze == kTRUE)
    throw runtime_error("EventFreeze can only be written if Freeze-out coordinates are available.");
  
  if (CreatePHQMDout == kFALSE && Convert == kFALSE)
    throw runtime_error("Either CreatePHQMDout or Convert must be set to true");

  if (CreatePHQMDout == kFALSE && CreateOutWithUnstable == kTRUE)
   throw runtime_error("If CreateOutWithUnstable is set true, CreatePHQMDout must be set true too.");

  cout << "********************************************************************" <<endl;
  string dataset_str(fDataset.Data());
  for (int i = 0; i < dataset_str.size(); i++)
    if (isdigit(dataset_str[i]) == kFALSE) { dataset_str.erase(i, 1); i--; }
  if (dataset_str.length() == 0) cout << "Start run " << endl;
  else cout << "Start run " << stoi(dataset_str) << endl;
  cout << "********************************************************************" <<endl;
  if (CreatePHQMDout == kTRUE) {
    InitCreatePHQMDout(ConvertAnti, firstevent);
    if (CreateOutWithUnstable == kTRUE)
      InitCreatePHQMDoutUnstable(ConvertAnti, firstevent);
  }
  if (Convert == kTRUE)
    InitConvert(WriteUnigen, WriteEventFreeze, ConvertAnti);
}

void PConverter::InitCreatePHQMDout(Bool_t ConvertAnti, Int_t firstevent)
{
  /** Initializes root-file for PHQMD output. **/
  
  fFirstEvent = firstevent;
  fConvertAnti = ConvertAnti;
  if (fDataset.Length() == 0) {
    finputFileInfo            = "inputPHSD";
    finputFileBulk            = "phsd.dat";
    finputFileBaryonFriga     = "fort.891";
    finputFileBaryonFrigaAnti = "fort.881";
  }
  else {
    finputFileInfo            = Form("%s/inputPHSD",fIndir.Data());
    finputFileBulk            = Form("%s/%s/phsd.dat",fIndir.Data(),fDataset.Data());
    finputFileBaryonFriga     = Form("%s/%s/fort.891",fIndir.Data(),fDataset.Data());
    finputFileBaryonFrigaAnti = Form("%s/%s/fort.881",fIndir.Data(),fDataset.Data());
  }

  if (fDataset.Length() == 0)
     frootFileP =  "phqmd_out.root";
  else
    frootFileP =  Form("%s/root/%s.phqmd_out.root",fIndir.Data(),fDataset.Data());
}

void PConverter::InitCreatePHQMDoutUnstable(Bool_t ConvertAnti, Int_t firstevent)
{
  /** Initializes root-file for PHQMD output with unstabilized clusters. **/
  
  if (fDataset.Length() == 0) {
    finputFileBaryonFrigaUnstable = "fort.791";
    finputFileBaryonFrigaAntiUnstable = "fort.781";
  }
  else {
    finputFileBaryonFrigaUnstable     = Form("%s/%s/fort.791",fIndir.Data(),fDataset.Data());
    finputFileBaryonFrigaAntiUnstable = Form("%s/%s/fort.781",fIndir.Data(),fDataset.Data());
  }
}

void PConverter::InitConvert(Bool_t WriteUnigen, Bool_t WriteEventFreeze, Bool_t ConvertAnti)
{
  /** Initializes output for conversion. **/
  
  fEbin_max = 0.0;
  fWriteUnigen = WriteUnigen;
  fWriteEventFreeze = WriteEventFreeze;
  fConvertAnti = ConvertAnti;

  if (fDataset.Length() == 0) {
    frootFileP =  "phqmd_out.root";
    if (fWriteUnigen == kTRUE) {
      if (fConvertAnti == kTRUE) frootFileDet = "phqmd.root";
      if (fConvertAnti == kFALSE) frootFileDet = "phqmd_noanti.root";
    } 
    if (fWriteEventFreeze == kTRUE) {
      if (fConvertAnti == kTRUE) frootFileFreeze = "phqmd_freeze.root";
      if (fConvertAnti == kFALSE) frootFileFreeze = "phqmd_freeze_noanti.root";
    }
    fNameClustertable = "cluster_table.root";
  }

  else {
    frootFileP =  Form("%s/root/%s.phqmd_out.root",fIndir.Data(),fDataset.Data());
    if (fWriteUnigen == kTRUE) {
      if (fConvertAnti == kTRUE)  frootFileDet    = Form("%s/root/unigen/%s.phqmd.root",fIndir.Data(),fDataset.Data());
      if (fConvertAnti == kFALSE) frootFileDet    = Form("%s/root/unigen/%s.phqmd_noanti.root",fIndir.Data(),fDataset.Data());
    } 
    if (fWriteEventFreeze == kTRUE) {
      if (fConvertAnti == kTRUE)  frootFileFreeze = Form("%s/root/freeze/%s.phqmd_freeze.root",fIndir.Data(),fDataset.Data());
      if (fConvertAnti == kFALSE) frootFileFreeze = Form("%s/root/freeze/%s.phqmd_freeze_noanti.root",fIndir.Data(),fDataset.Data());
    }
    fNameClustertable = Form("%s/root/cluster_table.root",fIndir.Data()); 
  }
}

// ----------------------------------------------------------------------------------------

void PConverter::OpenPHQMDoutCreate()
{
  cout << endl;
  cout << "Input files: " << endl;
  cout << finputFileInfo << endl;
  cout << finputFileBulk << endl;
  cout << finputFileBaryonFriga << endl;
  if (fConvertAnti == kTRUE)  cout << finputFileBaryonFrigaAnti << endl;

  if (fCreateOutWithUnstable == kTRUE) {
    cout << finputFileBaryonFrigaUnstable << endl;
    if (fConvertAnti == kTRUE)
      cout << finputFileBaryonFrigaAntiUnstable << endl;
  }
  
  foutputPHQMD = new TFile (frootFileP, "recreate");
}

void PConverter::OpenPHQMDoutRead()
{
  if (fCreatePHQMDout == kFALSE)
    cout << endl << "Input file: " << frootFileP << endl << endl;

  foutputPHQMD = new TFile (frootFileP);

  fpheader = (PRun *)foutputPHQMD->Get("run");

  ftreeH = (TTree *)foutputPHQMD->Get("events_hadrons");
  feventH = new PEventHadrons();
  ftreeH->SetBranchAddress("event", &feventH);
   
  foutputPHQMD->cd();
  ftreeB = (TTree *)foutputPHQMD->Get("events_baryons");
  feventB = new PEventBaryons();
  ftreeB->SetBranchAddress("event", &feventB);
}

void PConverter::WritePHQMDout()
{
  foutputPHQMD->Save();
  cout << endl;
  if (fConvert == kTRUE)  cout << "PHQMD output files written into root file: ";
  if (fConvert == kFALSE) cout << "Macro finished successfully." << endl << "Output file: ";
  cout << frootFileP << endl;
  if (fConvert == kFALSE) cout << "********************************************************************" <<endl;
  cout << endl;
}

void PConverter::ClosePHQMDout()
{
  foutputPHQMD->Close();
}


void PConverter::RemovePHQMDout()
{
  gSystem->Unlink(frootFileP);
  cout << frootFileP << "is removed."<< endl; 
}

// ----------------------------------------------------------------------------------------

void PConverter::GetPdgIdBaryon(Int_t charge, Int_t &pdgId, Bool_t IsAnti)
{
  /** Gets PDG for baryons from fort-files. **/
  
  if(TMath::Abs(charge) == 1) pdgId = 2212;
  if(charge == 0) pdgId = 2112;
  if(TMath::Abs(charge) == 17) pdgId = 3122;
  if (TMath::Abs(charge) == 18) pdgId = 3212;

  if (IsAnti == kTRUE) pdgId *= -1;
}

void PConverter::ClusterTablePrint()
{
  /** Prints the cluster table used for the conversion of clusters. **/
  
  char clustername [80];
  Int_t pdgId, nProt, nNeut, nLamb, nSigm;

  TFile *clusterTable = new TFile(fNameClustertable,"READ");
  TTree *tClusterTable = (TTree*) clusterTable -> Get("ClusterTable");

  tClusterTable->SetBranchAddress("clustername",&clustername);
  tClusterTable->SetBranchAddress("pdgId",&pdgId);
  tClusterTable->SetBranchAddress("nProt",&nProt);
  tClusterTable->SetBranchAddress("nNeut",&nNeut);
  tClusterTable->SetBranchAddress("nLamb",&nLamb);
  tClusterTable->SetBranchAddress("nSigm",&nSigm);

  printf("-------------------------\n");
  for (int i=0; i < tClusterTable->GetEntries(); i++) {
    tClusterTable->GetEntry(i);
    printf("%-12s %-10i\n", clustername, pdgId);
  }
  printf("-------------------------\n");

  clusterTable->Close();
}

void PConverter::GetClusterPdg(TTree * tClusterTable, std::vector<PBaryon_cluster> baryons_cluster, Int_t clusterId, Int_t &pdgIdCl)
{
  /** Gets PDG for clusters according to cluster table. **/
  
  Int_t nProtCl = 0; Int_t nBary0Cl = 0; Int_t nLambCl = 0; Int_t nSigmCl = 0;
  Int_t nbary = baryons_cluster.size();
  for (int ibary = 0; ibary < nbary; ibary++) {
    Int_t pdgId = baryons_cluster.at(ibary).fPdgId;
    if (TMath::Abs(pdgId) == 2212) nProtCl ++;
    if (TMath::Abs(pdgId) == 2112 || TMath::Abs(pdgId) == 3122 || TMath::Abs(pdgId) == 3212) nBary0Cl ++;
    if (TMath::Abs(pdgId) == 3122) nLambCl ++;
    if (TMath::Abs(pdgId) == 3212) nSigmCl ++;
  }
  
  Int_t pdgId, nProt, nNeut, nLamb, nSigm;
  tClusterTable->SetBranchAddress("pdgId",&pdgId);
  tClusterTable->SetBranchAddress("nProt",&nProt);
  tClusterTable->SetBranchAddress("nNeut",&nNeut);
  tClusterTable->SetBranchAddress("nLamb",&nLamb);
  tClusterTable->SetBranchAddress("nSigm",&nSigm);
 
  for (int i = 0; i < tClusterTable->GetEntries(); i++){
    tClusterTable->GetEntry(i);   
    if (nProtCl == nProt && nBary0Cl == nNeut && nLambCl == nLamb && nSigmCl == nSigm) {
      pdgIdCl = TMath::Sign(pdgId, clusterId);
      break;
    }
    else {
      pdgIdCl=99999;
    }
  }
  if (fConvertMode == 1 && pdgIdCl == 99999 && nbary > 7) {
    pdgIdCl = 1000000000 + nbary * 10 + nProtCl * 10000 + (nLambCl+nSigmCl) * 10000000;
    pdgIdCl = TMath::Sign(pdgIdCl, clusterId);                                                                        
  }
}

Float_t PConverter::CalculateClusterBindingEnergy(std::vector<PBaryon_cluster> baryons_cluster)
{
  /** Calculates cluster bindind energy. **/
  
  Float_t Ebin = 0.;
  for (int ibary = 0; ibary < baryons_cluster.size(); ibary++) {
    Ebin += baryons_cluster.at(ibary).fEbin;
  }
  return Ebin; 
}

void PConverter::CalculateClusterKin(std::vector<PBaryon_cluster> baryons_cluster, Float_t &Px, Float_t &Py, Float_t &Pz, Float_t &energy)
{
  /** Calculates momentum and energy of cluster. **/
  
  Px = 0.; Py = 0.; Pz = 0.; energy = 0;
  Float_t Mass = 0.;
  for (int ibary = 0; ibary < baryons_cluster.size(); ibary++) {
    Int_t pdgId = baryons_cluster.at(ibary).fPdgId;
    Px += baryons_cluster.at(ibary).fP.X();
    Py += baryons_cluster.at(ibary).fP.Y();
    Pz += baryons_cluster.at(ibary).fP.Z();
    if (TMath::Abs(pdgId) == 2212 || TMath::Abs(pdgId) == 2112) Mass += 0.938;
    if (TMath::Abs(pdgId) == 3122) Mass += 1.116;
    if (TMath::Abs(pdgId) == 3212) Mass += 1.193;
  }
  energy = TMath::Sqrt(Mass*Mass+Px*Px+Py*Py+Pz*Pz);
}

void PConverter::CalculateClusterFreezeOutTime(std::vector<PBaryon_cluster> baryons_cluster, Int_t nbary, Int_t &TsFreeze, Float_t &TimeFreezeCluster, Float_t &deltaT)
{
  /** Calculates freezeout time of a cluster. **/
  
  std::vector<float> timefo_bary;
  for (int ibary = 0; ibary < nbary; ibary ++)
    timefo_bary.push_back(baryons_cluster.at(ibary).fXTFreeze.T());

  TimeFreezeCluster = *max_element(timefo_bary.begin(), timefo_bary.end());
  auto it_TsFreeze_up = std::lower_bound(fts_time.begin(), fts_time.end(), TimeFreezeCluster);
  TsFreeze = std::distance(fts_time.begin(), it_TsFreeze_up); // first timestep after freezeout-time
  if (it_TsFreeze_up == fts_time.end()) TsFreeze --;
  deltaT = TimeFreezeCluster - fts_time.at(TsFreeze);
}

void PConverter::CalculateFreezOutCoord(std::vector<PBaryon_cluster> baryons_cluster, Int_t nbary, Int_t TsFreeze, Float_t TimeFreezeCluster, Float_t deltaT, TVector3 &posfo_cluster, TVector3 &pfo_cluster)
{
  /** Calculates freezeout coordinates (position and momentum) of a cluster. **/
  
  auto it_ieventfr = feventId2EntryB.find(feventB->GetEventId());
  Int_t ieventFreeze = it_ieventfr -> second[TsFreeze];
  ftreeB->GetEntry(ieventFreeze);
	    
  for (int ibary = 0; ibary < nbary; ibary++) {	      
    auto it_bary = fbaryonId2pos[ieventFreeze].find(baryons_cluster.at(ibary).fBaryonId);
    PBaryon baryon_fo = feventB->GetBaryon(it_bary->second);
    for (int i = 0; i < 3; i++) {
      if (baryons_cluster.at(ibary).fXTFreeze.T() < TimeFreezeCluster)
	posfo_cluster(i) += baryon_fo.GetPosition()(i) + deltaT * baryon_fo.GetMomentum()(i) / baryon_fo.E();
      else
	posfo_cluster(i) +=  baryons_cluster.at(ibary).fXTFreeze(i);
      pfo_cluster(i) +=  baryon_fo.GetMomentum()(i);
    }
  }
  for (int i = 0; i < 3; i++)
    posfo_cluster(i) /= nbary;
}

// ------------------------------------------------------------------------

void PConverter::CreatePHeader()
{
  /** Reads PHQMD run information from inputPHSD and write into root-header. **/
    
  Int_t NUM, ISUBS, NTIME;
  Int_t aProj, zProj, aTarg, zTarg, IBweight;  
  Double_t eLab, bMin, bMax, DBimp, Tstart, Tfinal, dT;
  Int_t Ieos, Iglue, Iphqmd, Inuclei, Ires, Idilept, Icq, Ihard;
  Int_t Eyuk, Easy, Epair, Ecoul, IfragWig;
  Double_t Evasy, Etapair;
    
  FILE *inputInfo = fopen(finputFileInfo, "r");
  
  fscanf(inputInfo, "%i %*[^\n]%*c", &aTarg);
  fscanf(inputInfo, "%i %*[^\n]%*c", &zTarg);
  fscanf(inputInfo, "%i %*[^\n]%*c", &aProj);
  fscanf(inputInfo, "%i %*[^\n]%*c", &zProj);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &eLab);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &bMin);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &bMax);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &DBimp); 
  fscanf(inputInfo, "%i %*[^\n]%*c", &NUM);
  fscanf(inputInfo, "%i %*[^\n]%*c", &ISUBS);
  fscanf(inputInfo, "%*[^\n]%*c");
  fscanf(inputInfo, "%i %*[^\n]%*c", &Iglue);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &Tfinal); 
  fscanf(inputInfo, "%*[^\n]%*c");
  fscanf(inputInfo, "%i %*[^\n]%*c", &Idilept);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Icq);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Ihard);
  fscanf(inputInfo, "%i %*[^\n]%*c", &IBweight);
  fscanf(inputInfo, "%*[^\n]%*c");
  fscanf(inputInfo, "%i %*[^\n]%*c", &Inuclei);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Iphqmd);
  fscanf(inputInfo, "%*[^\n]%*c");
  fscanf(inputInfo, "%lf %*[^\n]%*c", &Tstart);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &dT);
  fscanf(inputInfo, "%i %*[^\n]%*c", &NTIME);
  fscanf(inputInfo, "%*[^\n]%*c");
  fscanf(inputInfo, "%i %*[^\n]%*c", &Eyuk);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Easy);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Epair);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Ecoul);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &Evasy);
  fscanf(inputInfo, "%lf %*[^\n]%*c", &Etapair);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Ieos);
  fscanf(inputInfo, "%i %*[^\n]%*c", &Ires);  
  if (fscanf(inputInfo, "%i %*[^\n]%*c", &IfragWig) == EOF)
    throw runtime_error("Unexpected end of file " + finputFileInfo + ".\n ");

  Int_t nEvents = NUM*ISUBS;
  cout << endl;
  cout << "Conversion of " << nEvents << " events with " << NTIME << " timesteps" <<endl;
  cout << endl;  
 
  fpheader = new PRun ("phqmd", aProj, zProj, aTarg, zTarg, eLab, bMin, bMax, IBweight, DBimp, NUM, ISUBS, Tstart, Tfinal, dT, NTIME, Ieos, Iglue, Iphqmd, Inuclei, Ires, Idilept, Icq, Ihard, Eyuk, Easy, Epair, Ecoul, Evasy, Etapair, IfragWig);

  foutputPHQMD->cd();
  fpheader->Write();

  int check_eof;
  if(fscanf(inputInfo, "%i %*[^\n]%*c", &check_eof) != EOF) 
    throw runtime_error("\n  Error when reading "+ finputFileInfo + ": File not read until the end. Check input format.\n ");
    
  fclose(inputInfo);
}

void PConverter::CreatePEventsHadrons()
{
  /** Reads information about hadrons from phsd.dat and write into root-event. **/
  
  TString treename = "events_hadrons";
  FILE *BulkFile = fopen(finputFileBulk, "r");
    
  feventH = new PEventHadrons();
  ftreeH = new TTree (treename, treename);
  ftreeH->Branch ("event", "PEventHadrons", &feventH, 12800000);
      
  for (int isub = 0; isub < fpheader->GetSub(); isub++) {  // loop over all subsequent runs
    for (int inum = 0; inum < fpheader->GetNum(); inum ++) {  // loop over all parallel runs

      Int_t nHadrons, eventId, ISub, INum, nParticipants;
      Float_t impactpar;
      std::array<Float_t,4> phi, psi;
      Int_t pdgId, charge, PHSDId, baryonId, mesonId, processId, infoId;
      Float_t Px, Py, Pz, energy, xposfo, yposfo, zposfo, timefo, xpfo, ypfo, zpfo, densityB, densityE;
      
      //Get Hadrons from phsd.dat
      
      foutputPHQMD->cd();
      feventH->Clear();
      eventId = fFirstEvent + isub*fpheader->GetNum() + inum;
      
      if(fscanf(BulkFile, "%i %i %i %f %*i\n", &nHadrons, &ISub, &INum, &impactpar)==EOF)
	throw runtime_error("Unexpected end of file phsd.dat at run " + to_string(inum));	
      if(fscanf(BulkFile, "%i %f %f %f %f %f %f %f %f\n", &nParticipants, &phi.at(0), &psi.at(0), &phi.at(1), &psi.at(1), &phi.at(2), &psi.at(2), &phi.at(3), &psi.at(3))==EOF)  
	throw runtime_error("Unexpected end of file phsd.dat at run " + to_string(inum));
      
      feventH->SetParameters(eventId, nHadrons, nParticipants, ISub, INum, impactpar, phi, psi);
 
      for (int i = 0; i < nHadrons; i++) {
	if (fFreezeCoords == kTRUE) {
	  if(fscanf(BulkFile, "%i %i %f %f %f %f %i %i %i %f %f %f %f %f %f %f %f %f\n", &pdgId, &charge, &Px, &Py, &Pz, &energy, &processId, &infoId, &PHSDId, &xposfo, &yposfo, &zposfo, &timefo, &xpfo, &ypfo, &zpfo, &densityB, &densityE)==EOF) {	
	    throw runtime_error("Unexpected end of file phsd.dat at run " + to_string(inum) + " particle " + to_string(i));
	  }
	}
	else {
	  if(fscanf(BulkFile, "%i %i %f %f %f %f %i %i %i\n", &pdgId, &charge, &Px, &Py, &Pz, &energy, &processId, &infoId, &PHSDId)==EOF) {	
	    throw runtime_error("Unexpected end of file phsd.dat at run " + to_string(inum) + " particle " + to_string(i));
	  }
	}
	      
	if (TMath::Abs(pdgId) == 100121) pdgId = 1000010020*charge; // correct pdg-code for kinetic deuterons    

	if (TMath::Abs(pdgId) < 1000) { mesonId = PHSDId; baryonId = -1; }
	else { baryonId = PHSDId; mesonId = -1;	}	

	foutputPHQMD->cd();
	if (fFreezeCoords == kTRUE)
	  feventH->AddHadron(pdgId, Px, Py, Pz, energy, processId, infoId, baryonId, mesonId, xposfo, yposfo, zposfo ,timefo, xpfo,ypfo,zpfo, densityB, densityE);
	else
	  feventH->AddHadron(pdgId, Px, Py, Pz, energy, processId, infoId, baryonId, mesonId);
      }
      foutputPHQMD->cd();
      ftreeH->Fill();
    } 
  }
  foutputPHQMD->cd();
  ftreeH->Write();
  
  if(fscanf(BulkFile, "%*[^\n]%*c")!=EOF) 	
    throw runtime_error("\n  Error when reading phsd.dat: File not read until the end. Check input format.\n ");	
  fclose(BulkFile);
}

void PConverter::CreatePEventsBaryons(Bool_t CreateUnstable) 
{
  /** Reads information about baryons from fort.891/fort.881/fort.791/fort.781 and write into root-event. **/
  
  TString treename; TString inputFileBaryonFriga; TString inputFileBaryonFrigaAnti;
  
  if (CreateUnstable == kFALSE) treename = "events_baryons";
  if (CreateUnstable == kTRUE) treename = "events_baryons_unstable";

    
  FILE *BaryonFrigaFile = fopen(finputFileBaryonFriga, "r");
  FILE *BaryonFrigaFileAnti;
  if (fConvertAnti == kTRUE) BaryonFrigaFileAnti = fopen(finputFileBaryonFrigaAnti, "r");
  
  feventB = new PEventBaryons();
  ftreeB = new TTree (treename, treename);
  ftreeB->Branch ("event", "PEventBaryons", &feventB, 12800000);

  for (int isub = 0; isub < fpheader->GetSub(); isub++) {  // loop over all subsequent runs
    for (int it = 0; it < fpheader->GetNTime() + 1; it++) { // loop over all timesteps
      for (int inum = 0; inum < fpheader->GetNum(); inum ++) {  // loop over all parallel runs

	Int_t eventId = fFirstEvent + isub*fpheader->GetNum() + inum;
		
	Int_t INum, ISub, nBaryons, nAntiBaryons;
	Float_t time, impactpar, rcluster;
	Int_t pdgId, charge, nBary, baryonId, clusterId, prodId, prodchanel;
	Float_t Px, Py, Pz, Xpos, Ypos, Zpos, Mass, Ebin, prodtime;

	Bool_t IsAnti = kFALSE;

	foutputPHQMD->cd();
	feventB->Clear();

	if(fscanf(BaryonFrigaFile, "%i %i %f %f %*i %*i %*i %*i %*i %*f %*i\n", &INum, &ISub, &impactpar, &time)==EOF)
	  throw runtime_error("Unexpected end of file fort.891 at run " + to_string(inum));
 	if(fscanf(BaryonFrigaFile, "%*[^\n]%*c")==EOF)	  
 	  throw runtime_error("Unexpected end of file fort.891 at run " + to_string(inum));
 	if(fscanf(BaryonFrigaFile, "%i %*i %*i %f\n", &nBaryons, &rcluster)==EOF)
	  throw runtime_error("Unexpected end of file fort.891 at run " + to_string(inum));

	foutputPHQMD->cd();
	feventB->SetParameters(eventId, nBaryons, 0, ISub, INum, impactpar, rcluster, it, time); 

	for (int i = 0; i < nBaryons; i++) {
	  if(fscanf(BaryonFrigaFile, "%*i %i %f %f %f %f %f %f %f %i %i %i %*i %*i %i %i %f %f\n", &charge, &Px, &Py, &Pz, &Xpos, &Ypos, &Zpos, &Mass, &clusterId, &nBary, &baryonId, &prodId, &prodchanel, &prodtime, &Ebin)==EOF) {
	    throw runtime_error("Unexpected end of file fort.891 at run " + to_string(inum) + "timestep" + to_string(it) + " particle " + to_string(i));
	  }

	  GetPdgIdBaryon(charge, pdgId, IsAnti);
	  foutputPHQMD->cd();
	  feventB->AddBaryon(pdgId, Px, Py, Pz, Xpos, Ypos, Zpos, Mass, clusterId, nBary, baryonId, prodId, prodchanel, prodtime, Ebin);
	} 

	// Get Anti-Baryons Friga from fort.881
	
	if (fConvertAnti == kTRUE) {

	  IsAnti = kTRUE;

	  if(fscanf(BaryonFrigaFileAnti, "%*[^\n]%*c")==EOF)
	    throw runtime_error("Unexpected end of file fort.881 at run " + to_string(inum));
	  if(fscanf(BaryonFrigaFileAnti, "%*[^\n]%*c")==EOF)
	    throw runtime_error("Unexpected end of file fort.881 at run " + to_string(inum));
	  if(fscanf(BaryonFrigaFileAnti, "%i %*[^\n]%*c", &nAntiBaryons)==EOF)
	    throw runtime_error("Unexpected end of file fort.881 at run " + to_string(inum));

	  feventB->SetNAntiBaryons(nAntiBaryons);
	  
	  for (int i = 0; i < nAntiBaryons; i++) {
	    if(fscanf(BaryonFrigaFileAnti, "%*i %i %f %f %f %f %f %f %f %i %i %i %*i %*i %i %i %f %f\n", &charge, &Px, &Py, &Pz, &Xpos, &Ypos, &Zpos, &Mass, &clusterId, &nBary, &baryonId, &prodId, &prodchanel, &prodtime, &Ebin)==EOF) {
	      throw runtime_error("Unexpected end of file fort.881 at run " + to_string(inum) + "timestep" + to_string(it) + " particle " + to_string(i));
	    }

	    GetPdgIdBaryon(charge, pdgId, IsAnti);
	    foutputPHQMD->cd();
	    feventB->AddBaryon(pdgId, Px, Py, Pz, Xpos, Ypos, Zpos, Mass, -clusterId, nBary, baryonId, prodId, prodchanel, prodtime, Ebin);
	  } 
	}
	foutputPHQMD->cd();
	ftreeB->Fill();
	
      }  // end loop parallel runs
    }  // end loop timesteps
  }  // end loop subsequent runs
  foutputPHQMD->cd();
  ftreeB->Write();
  
  if(fscanf(BaryonFrigaFile, "%*[^\n]%*c")!=EOF) 	
    throw runtime_error("\n  Error when reading " + inputFileBaryonFriga + ": File not read until the end. Check input format.\n ");
  fclose(BaryonFrigaFile);
  if (fConvertAnti == kTRUE) {
    if(fscanf(BaryonFrigaFileAnti, "%*[^\n]%*c")!=EOF) 	
      throw runtime_error("\n  Error when reading " + inputFileBaryonFrigaAnti + ": File not read until the end. Check input format.\n ");
    fclose(BaryonFrigaFileAnti);
  }
}
// ------------------------------------------------------------------------

void PConverter::MakeMaps()
{
  /** Creates Maps to:
   ** - find baryons across timesteps 
   ** - find baryons in phsd.dat 
   ** - to assign baryons to clusters. **/

  fbaryons2hadrons.resize(ftreeH->GetEntries());
  fbaryonId2pos.resize(ftreeB->GetEntries());
  fclusterId2baryonIds.resize(ftreeB->GetEntries());
  if (fpheader->GetNTime() > 29) throw runtime_error("Size of eventmap for baryons is too small for " + to_string(fpheader->GetNTime()) + " timesteps in fort.891");

  fts_time.resize(fpheader->GetNTime() + 1);
  foutputPHQMD->cd();
  for (int ievent = 0;ievent < ftreeH->GetEntries(); ievent++) {
    ftreeH->GetEntry(ievent);
    feventId2EntryH[feventH->GetEventId()] = ievent;
  }

  for (int ievent = 0; ievent < ftreeB->GetEntries(); ievent++) {
    ftreeB->GetEntry(ievent);
    if (feventB->GetINum() == 1) fts_time.at(feventB->GetStepNr()) = feventB->GetTime();   
    feventId2EntryB[feventB->GetEventId()][feventB->GetStepNr()] = ievent;

    for (int ibaryon = 0 ; ibaryon < feventB->GetNAllBaryons() ; ibaryon++) {
      PBaryon baryon = feventB->GetBaryon(ibaryon);
      fbaryonId2pos[ievent][baryon.GetBaryonId()] = ibaryon;
      Int_t clusterId = baryon.GetClusterId();
      Int_t baryonId = baryon.GetBaryonId();
      auto it = fclusterId2baryonIds[ievent].find(clusterId);
      if (it != fclusterId2baryonIds[ievent].end()) 
	it->second.emplace_back(baryonId);
      else 
	fclusterId2baryonIds[ievent][clusterId] = {static_cast<int>(baryonId)};

      if(feventB->GetStepNr() != fpheader->GetNTime()) continue;
      auto it_ieventH = feventId2EntryH.find(feventB->GetEventId());
      Int_t ieventH = it_ieventH->second;
      ftreeH->GetEntry(ieventH);
      for (int ihadron = 0 ; ihadron < feventH->GetNHadrons() ; ihadron++) {
	PHadron hadron = feventH->GetHadron(ihadron);
	if (hadron.GetBaryonId() == baryon.GetBaryonId()) {
	  fbaryons2hadrons[ieventH][baryon.GetBaryonId()] = ihadron;
	  break;
	}
      }
    }
  }
}

void PConverter::ConvertPHQMD()
{
  /** Converts PHQMD output after stabilization into complete events with hadrons and clusters according to cluster table.
   ** Output:
   ** a) UniGen format including the FREEZEOUT-TIME & -POSITION. The UniGen-output can be selected with the flag: WriteUnigen = kTRUE.
   **    - for clusters & anticlusters: [dataset].phqmd.root
   **    - for clusters only**: [dataset].phqmd_noanti.root
   ** b) root-file with complete events including the FREEZEOUT-TIME, -POSITION & -MOMENTUM (EventFreeze). 
   **    - for clusters & anticlusters: [dataset].phqmd_freeze.root
   **    - for clusters only**: [dataset].phqmd_freeze_noanti.root. **/

  TString run_comment;
  if (fConvertMode == 0) run_comment = "physical clusters A < 10";
  if (fConvertMode == 1) run_comment = "physical clusters A < 8, all clusters A > 7";
    
  TFile *output; URun *header; TTree *tree;
  UEvent *uevent = new UEvent;
  if (fWriteUnigen == kTRUE) {
    header = new URun ("phqmd", run_comment, fpheader->GetAProj(), fpheader->GetZProj(), fpheader->GetpProj(), fpheader->GetATarg(), fpheader->GetZTarg(), fpheader->GetpTarg(), fpheader->GetBMin(), fpheader->GetBMax(), 0, 0, 0, 0, fpheader->GetNEvents());
    uevent = new UEvent;
    output = new TFile (frootFileDet, "recreate");
    tree = new TTree ("events", "signal");
    header->Write();
    tree->Branch ("event", "UEvent", uevent);
  }
  
  TFile *outputFreeze; TTree *treeFreeze; RunFreeze *headerFreeze; EventFreeze *eventFreeze;  
  if (fWriteEventFreeze == kTRUE) {
    headerFreeze = new RunFreeze ("phqmd", run_comment, fpheader->GetAProj(), fpheader->GetZProj(), fpheader->GetATarg(), fpheader->GetZTarg(), fpheader->GetELab(), fpheader->GetBMin(), fpheader->GetBMax(), fpheader->GetIBweight(), fpheader->GetNEvents());
    outputFreeze = new TFile (frootFileFreeze, "recreate");
    treeFreeze = new TTree ("events", "events");
    headerFreeze->Write();
    eventFreeze = new EventFreeze();
    treeFreeze->Branch ("event", "EventFreeze", &eventFreeze, 12800000);
  }

  TFile *clusterTable= new TFile(fNameClustertable,"READ");
  TTree *tClusterTable = (TTree*) clusterTable -> Get("ClusterTable");
  
  cout << "Clustertable used: " << fNameClustertable << endl;
  ClusterTablePrint();
  cout << "Conversion mode " << fConvertMode;
  
  if (fConvertMode == 0)
    cout << " : Conversion of physical clusters according to cluster table.\nBaryons from all other clusters are counted as single baryons. " << endl;
  if (fConvertMode == 1)
    cout << " : Conversion of physical clusters according to cluster table.\nConversion of clusters A > 7 independent of their physical existence." << endl;
  
  foutputPHQMD->cd();
  for (int ieventB = 0; ieventB < ftreeB->GetEntries(); ieventB++) {
    foutputPHQMD->cd();
    ftreeB->GetEntry(ieventB);
   
    if(feventB->GetStepNr() == fpheader->GetNTime()) {
      auto it_ieventH = feventId2EntryH.find(feventB->GetEventId());
      Int_t ieventH = it_ieventH->second;
      ftreeH->GetEntry(ieventH);
      Int_t index=0;
      Int_t child[2] = {0,0};
      if (fWriteUnigen == kTRUE) {
	output->cd();
	uevent->Clear();
	uevent->SetParameters(feventB->GetEventId(), feventH->GetB(), feventH->GetPhi().at(0), feventH->GetNParticipants(), 1, feventB->GetTime(), 0);
	}
      if (fWriteEventFreeze == kTRUE) {
	outputFreeze->cd();
	eventFreeze->Clear();
	eventFreeze->SetParameters(feventB->GetEventId(), feventH->GetB(), feventH->GetNParticipants(), feventB->GetTime(), feventH->GetPhi().at(0)) ;
      }
 
      foutputPHQMD->cd(); // Loop over hadrons
      for (auto hadron : feventH->GetHadronList()) {
	auto it_bar2had = fbaryons2hadrons[ieventH].find(hadron.GetBaryonId());	
	if (it_bar2had != fbaryons2hadrons[ieventH].end()) continue; // baryon is participating in MST
	if (fWriteUnigen == kTRUE) {
	  output->cd();
	  uevent->AddParticle (index, hadron.GetPdg(), 0, -1, -1, -1, -1, child, hadron.Px(), hadron.Py(),hadron.Pz(), hadron.E(), hadron.XFreeze(), hadron.YFreeze(), hadron.ZFreeze(), hadron.TFreeze(), 1);
	}	
	if (fWriteEventFreeze == kTRUE) {
	  outputFreeze->cd();
	  eventFreeze->AddParticle(hadron.GetPdg(), hadron.GetMomentum(), hadron.E(), hadron.GetPositionFreeze(), hadron.GetMomentumFreeze(), 0);
	}
	index++;    		  
      } // end loop hadrons
      
      foutputPHQMD->cd(); // Loop over cluster baryons & check if clusters are physical
      for (auto it_clId : fclusterId2baryonIds[ieventB]) {

	Int_t clusterId = it_clId.first;
	Int_t nbary = it_clId.second.size();

	std::vector<PBaryon_cluster> baryons_cluster;
	baryons_cluster.clear();
	
	for (Int_t baryonId : it_clId.second) {
	  auto it_bary = fbaryonId2pos[ieventB].find(baryonId);
	  PBaryon baryon = feventB->GetBaryon(it_bary->second);

	  auto it_had = fbaryons2hadrons[ieventH].find(baryon.GetBaryonId());
	  Int_t hadronId = it_had->second;
	  PHadron hadron = feventH->GetHadron(hadronId);
	  baryons_cluster.push_back(PBaryon_cluster(baryonId, baryon.GetPdg(), baryon.GetMomentum(), baryon.E(), hadron.GetPositionFreeze(), hadron.GetMomentumFreeze(), baryon.GetEbin()));
	}
	if (nbary == 1) {
	  Int_t ibary  = 0;
	  if (fWriteUnigen == kTRUE) {
	    output->cd();
	    uevent->AddParticle (index, baryons_cluster.at(ibary).fPdgId, 1, -1, -1, -1, -1, child, baryons_cluster.at(ibary).fP.X(), baryons_cluster.at(ibary).fP.Y(), baryons_cluster.at(ibary).fP.Z(), baryons_cluster.at(ibary).fEnergy, baryons_cluster.at(ibary).fXTFreeze.X(), baryons_cluster.at(ibary).fXTFreeze.Y(), baryons_cluster.at(ibary).fXTFreeze.Z(), baryons_cluster.at(ibary).fXTFreeze.T(), 1);
	  }	  
	  if (fWriteEventFreeze == kTRUE) {
	    outputFreeze->cd();
	    eventFreeze->AddParticle(baryons_cluster.at(ibary).fPdgId, baryons_cluster.at(ibary).fP, baryons_cluster.at(ibary).fEnergy, baryons_cluster.at(ibary).fXTFreeze, baryons_cluster.at(ibary).fPFreeze, 1);
	  }	  
	  index++;
	}
	if (nbary > 1) {
	  Int_t pdgId = 99999;
	  GetClusterPdg(tClusterTable, baryons_cluster, clusterId, pdgId);
	  Float_t Ebin = CalculateClusterBindingEnergy(baryons_cluster);

	  if (pdgId != 99999 && Ebin/nbary < fEbin_max) {
	    Float_t Px = 0; Float_t Py = 0; Float_t Pz = 0; Float_t energy = 0;
	    CalculateClusterKin(baryons_cluster, Px, Py, Pz, energy);
		
	    //Calculate Cluster Freeze-out coordinates
	    Float_t TimeFreezeCluster = 0.0;
	    Float_t deltaT; Int_t TsFreeze;
	    TVector3 posfo_cluster = {0.0, 0.0, 0.0}; TVector3 pfo_cluster = {0.0, 0.0, 0.0};
	    if (fFreezeCoords == kTRUE) {
	      CalculateClusterFreezeOutTime(baryons_cluster, nbary, TsFreeze, TimeFreezeCluster, deltaT);
	      CalculateFreezOutCoord(baryons_cluster, nbary, TsFreeze, TimeFreezeCluster, deltaT, posfo_cluster, pfo_cluster);
	      ftreeB->GetEntry(ieventB);
	    }	 
	    if (fWriteUnigen == kTRUE) {
	      output->cd();
	      uevent->AddParticle (index, pdgId, 1, -1, -1, -1, -1, child, Px, Py, Pz, energy, posfo_cluster.X(), posfo_cluster.Y(), posfo_cluster.Z(), TimeFreezeCluster, 1);
	    }	    
	    if (fWriteEventFreeze == kTRUE) {
	      outputFreeze->cd();
	      eventFreeze->AddParticle(pdgId, Px, Py, Pz, energy, TimeFreezeCluster, posfo_cluster, pfo_cluster, 1);
	    }	    
	    index++;
	  }
	  else {
	    for (int ibary=0;ibary<nbary;ibary++) {
	      if (fWriteUnigen == kTRUE) {
		output->cd();
		uevent->AddParticle (index, baryons_cluster.at(ibary).fPdgId, 1, -1, -1, -1, -1, child, baryons_cluster.at(ibary).fP.X(), baryons_cluster.at(ibary).fP.Y(), baryons_cluster.at(ibary).fP.Z(), baryons_cluster.at(ibary).fEnergy, baryons_cluster.at(ibary).fXTFreeze.X(), baryons_cluster.at(ibary).fXTFreeze.Y(), baryons_cluster.at(ibary).fXTFreeze.Z(), baryons_cluster.at(ibary).fXTFreeze.T(), 1);
		}	     
	      if (fWriteEventFreeze == kTRUE) {
		outputFreeze->cd();
		eventFreeze->AddParticle(baryons_cluster.at(ibary).fPdgId, baryons_cluster.at(ibary).fP, baryons_cluster.at(ibary).fEnergy, baryons_cluster.at(ibary).fXTFreeze, baryons_cluster.at(ibary).fPFreeze, 1);
	      }	       
	      index++;
	    }
	  }
	}
      }
      if (fWriteUnigen == kTRUE) {
	output->cd();
	tree->Fill();
      }	      
      if (fWriteEventFreeze == kTRUE) {
	outputFreeze->cd();
	treeFreeze->Fill();
      }	
    } 
  }

  clusterTable->Close(); 
  foutputPHQMD->Close();
  
  if (fWriteUnigen == kTRUE) {
    output->cd();
    tree->Write();
    output->Close();
  }
  
  if (fWriteEventFreeze == kTRUE) {
    outputFreeze->cd();
    treeFreeze->Write();
    outputFreeze->Close();
  }

  cout << endl;
  cout << "Macro finished successfully." << endl;
  if (fWriteUnigen == kTRUE)
    cout << "Output file in UniGen format: " <<frootFileDet<< endl;
  if (fWriteEventFreeze == kTRUE)
    cout << "Output file including freezeout momentum: " <<frootFileFreeze<< endl;
  cout << endl;
}

// ------------------------------------------------------------------------


  
  
