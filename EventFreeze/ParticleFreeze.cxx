#include "ParticleFreeze.h"

#include "TString.h"
#include <iostream>
using namespace std;

ParticleFreeze::ParticleFreeze()
  : fIndex(-1),
    fPdgId(0),
    fParent(-1),
    fDecay(-1),
    fEnergy(0.),
    fTimeFreeze(0.),
    fEnergyFreeze(0.),
    fOrigin(0),
    fWeight(0)
{
  fP.SetXYZ(0.,0.,0.);
  fXFreeze.SetXYZ(0.,0.,0.);
  fPFreeze.SetXYZ(0.,0.,0.);
};

ParticleFreeze::ParticleFreeze(Int_t index, Int_t pdgId, Int_t parent, Int_t decay, TVector3 P, Float_t energy, TLorentzVector XTFreeze,  TLorentzVector PEFreeze, Int_t origin, Int_t weight)
  : fIndex(index),
    fPdgId(pdgId),
    fParent(parent),
    fDecay(decay),
    fP(P),
    fEnergy(energy),
    fOrigin(origin),
    fWeight(weight)
{
  fTimeFreeze = XTFreeze.T();
  fXFreeze.SetXYZ(XTFreeze.X(), XTFreeze.Y(), XTFreeze.Z());
  fPFreeze.SetXYZ(PEFreeze.X(), PEFreeze.Y(), PEFreeze.Z());
  fEnergyFreeze = PEFreeze.T();
};

ParticleFreeze::ParticleFreeze(Int_t index, Int_t pdgId, Int_t parent, Int_t decay, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Float_t timeFreeze, TVector3 XFreeze, TVector3 PFreeze, Float_t energyFreeze, Int_t origin, Int_t weight)
  : fIndex(index),
    fPdgId(pdgId),
    fParent(parent),
    fDecay(decay),
    fEnergy(energy),
    fTimeFreeze(timeFreeze),
    fXFreeze(XFreeze),
    fPFreeze(PFreeze),
    fEnergyFreeze(energyFreeze),
    fOrigin(origin),
    fWeight(weight)
{
  fP.SetXYZ(Px, Py, Pz);
};

ParticleFreeze::ParticleFreeze(Int_t index, Int_t pdgId, Int_t parent, Int_t decay, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, TLorentzVector XTFreeze,  TLorentzVector PEFreeze, Int_t origin, Int_t weight)
  : fIndex(index),
    fPdgId(pdgId),
    fParent(parent),
    fDecay(decay),
    fEnergy(energy),
    fOrigin(origin),
    fWeight(weight)
{
  fP.SetXYZ(Px, Py, Pz);
  fTimeFreeze = XTFreeze.T();
  fXFreeze.SetXYZ(XTFreeze.X(), XTFreeze.Y(), XTFreeze.Z());
  fPFreeze.SetXYZ(PEFreeze.X(), PEFreeze.Y(), PEFreeze.Z());
  fEnergyFreeze = PEFreeze.T();
};

void ParticleFreeze::Print(Option_t* /*option*/) const
{
  // Print the data members to the standard output
  cout << "----------------------------------------------------------" << endl
       << "-I-                 Particle                 -I-"           << endl
       << "Index                                 : "  << fIndex        << endl
       << "PDG code                              : "  << fPdgId        << endl
       << "Parent index                          : "  << fParent       << endl
       << "Decay index                           : "  << fDecay        << endl
       << "Momentum (px, py, pz) (GeV)           : (" << fP.X() << ", " << fP.Y() << ", " << fP.Z() << ")" << endl
       << "Energy (GeV)                          : "  << fEnergy       << endl
       << "Freezeout position (x, y, z) (fm)     : (" << fXFreeze.X() << ", " << fXFreeze.Y() << ", " << fXFreeze.Z() << ")" << endl
       << "Freezeout time (fm)                   : "  << fTimeFreeze   << endl
       << "Freezeout momentum (px, py, pz) (GeV) : (" << fPFreeze.X() << ", " << fPFreeze.Y() << ", " << fPFreeze.Z() << ")" << endl
       << "Freezeout energy (GeV)                : "  << fEnergyFreeze << endl;
  if (TMath::Abs(fPdgId) == 1000010020) {
    cout<< "Deuteron is                           : ";
    if (fOrigin == 0) cout<<"kinetic "<<endl;
    if (fOrigin == 1) cout<<"potential " <<endl;
  }
  cout << "Weight                                : "  << fWeight       << endl;
  cout<< "-----------------------------------------------------------" << endl;
}

ClassImp(ParticleFreeze);
