#include "EventFemtoTs.h"
#include "ParticleFemto.h"

#include "TString.h"
#include <iostream>
#include <cstddef>
using namespace std;

EventFemtoTs::EventFemtoTs()
  : fEventId(0),
    fStepNr(0),
    fNpa(0)
{
  fParticles.clear();
  fIndex2Particle.clear();
};

void EventFemtoTs::SetParameters(Int_t eventId, Int_t stepnr, Float_t time)
{
  fEventId = eventId;
  fStepNr  = stepnr;
  fTime    = time;
};

ParticleFemto EventFemtoTs::GetParticle(Int_t iparticle) const
{
  if(iparticle < 0 || iparticle >= fNpa) throw runtime_error("\n Particle " + to_string(iparticle) + " not found in current event!");
  return ((ParticleFemto) fParticles.at(iparticle));
}

ParticleFemto EventFemtoTs::GetParticleIndex(Int_t index) const
{
  auto it_particle = fIndex2Particle.find(index);
  if (it_particle != fIndex2Particle.end()) 
    return ((ParticleFemto) fParticles.at(it_particle->second));
  else
    return ParticleFemto();
}

void EventFemtoTs::AddParticle(Int_t index, TLorentzVector P, TVector3 X)
{
  fParticles.push_back(ParticleFemto(index, P, X));
  fIndex2Particle [index] = fNpa;
  
  fNpa += 1;
}; 

void EventFemtoTs::Print(Option_t* option) const
{
  // Print data members to the standard output
  cout << "---------------------------------------------"    << endl
       << "-I-                 Event                 -I-"    << endl
       << "Event number                : " << fEventId       << endl
       << "Timestep                    : " << fStepNr        << endl
       << "Event time (fm/c)           : " << fTime          << endl;

    
  
  TString opt = option;
  if(opt.Contains("all")) {
    ParticleFemto particle;
    for(Int_t iPa = 0; iPa < fNpa; iPa++) {
      particle = (ParticleFemto) fParticles.at(iPa);
      particle.Print(option);
    }
  }
  cout << "---------------------------------------------" << endl;
}

void EventFemtoTs::Clear()
{ fParticles.clear();
  fIndex2Particle.clear();
  fNpa = 0;
};

ClassImp(EventFemtoTs);
