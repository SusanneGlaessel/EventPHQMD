#include "EventFreeze.h"
#include "ParticleFreeze.h"

#include "TString.h"
#include <iostream>
#include <cstddef>
using namespace std;

EventFreeze::EventFreeze()
  : fEventId(0),
    fB(0.),
    fNParticipants(0),
    fTime(0.),
    fPhi(0.),
    fNpa(0)
{
  fParticles.clear();  
};

void EventFreeze::SetParameters(Int_t eventId, Float_t b, Int_t nparticipants, Float_t time, Float_t phi)
{
  fEventId = eventId;
  fB = b;
  fNParticipants = nparticipants;
  fTime = time;
  fPhi = phi;
};

ParticleFreeze EventFreeze::GetParticle(Int_t index) const
{
  if(index < 0 || index >= fNpa) throw runtime_error("\n Particle " + to_string(index) + " not found in current event!");
  return ((ParticleFreeze) fParticles.at(index));
}

void EventFreeze::AddParticle(Int_t pdgId, TVector3 P, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin)
{
  fParticles.push_back(ParticleFreeze(pdgId, P, energy, XFreeze,  PFreeze, Origin));
  
  fNpa += 1;
}; 

void EventFreeze::AddParticle(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Float_t TimeFreezeCluster, TVector3 posfo_cluster, TVector3 pfo_cluster, Int_t Origin)
{
  fParticles.push_back(ParticleFreeze(pdgId, Px, Py, Pz, energy, TimeFreezeCluster, posfo_cluster, pfo_cluster, Origin));
  fNpa += 1;
}; 

void EventFreeze::AddParticle(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin)
{  
    fParticles.push_back(ParticleFreeze(pdgId, Px, Py, Pz, energy, XFreeze, PFreeze, Origin));
    fNpa += 1;
};

void EventFreeze::Print(Option_t* option) const
{
  // Print data members to the standard output
  cout << "---------------------------------------------"    << endl
       << "-I-                 Event                 -I-"    << endl
       << "Event number                : " << fEventId       << endl
       << "Impact parameter (fm)       : " << fB             << endl
       << "Final event time (fm)       : " << fTime          << endl
       << "Reaction plane angle (rad)  : " << fPhi           << endl
       << "Number of particles         : " << fNpa           << endl
       << "Number of participants      : " << fNParticipants << endl;
  
  TString opt = option;
  if(opt.Contains("all")) {
    ParticleFreeze particle;
    for(Int_t iPa = 0; iPa < fNpa; iPa++) {
      particle = (ParticleFreeze) fParticles.at(iPa);
      particle.Print(option);
    }
  }
  cout << "---------------------------------------------" << endl;
}

void EventFreeze::Clear()
{ fParticles.clear();
  fNpa = 0;
};

ClassImp(EventFreeze);
