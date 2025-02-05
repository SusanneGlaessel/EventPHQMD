#include "ParticleFreeze.h"

#include "TString.h"
#include <iostream>
using namespace std;

ParticleFreeze::ParticleFreeze()
  : fPdgId(0),
    fEnergy(0.),
    fTimeFreeze(0.),
    fEnergyFreeze(0.),
    fOrigin(0)
{
  fP.SetXYZ(0.,0.,0.);
  fXFreeze.SetXYZ(0.,0.,0.);
  fPFreeze.SetXYZ(0.,0.,0.);
};

ParticleFreeze::ParticleFreeze(Int_t pdgId, TVector3 P, Float_t energy, TLorentzVector XTFreeze,  TLorentzVector PEFreeze, Int_t Origin)
  : fPdgId(pdgId),
    fP(P),
    fEnergy(energy),
    fOrigin(Origin)
{
  fTimeFreeze = XTFreeze.T();
  fXFreeze.SetXYZ(XTFreeze.X(), XTFreeze.Y(), XTFreeze.Z());
  fPFreeze.SetXYZ(PEFreeze.X(), PEFreeze.Y(), PEFreeze.Z());
  fEnergyFreeze = PEFreeze.T();
};

ParticleFreeze::ParticleFreeze(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Float_t timeFreeze, TVector3 XFreeze, TVector3 PFreeze, Float_t energyFreeze, Int_t Origin)
  : fPdgId(pdgId),
    fEnergy(energy),
    fTimeFreeze(timeFreeze),
    fXFreeze(XFreeze),
    fPFreeze(PFreeze),
    fOrigin(Origin),
    fEnergyFreeze(energyFreeze)
{
  fP.SetXYZ(Px, Py, Pz);
};

ParticleFreeze::ParticleFreeze(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, TLorentzVector XTFreeze,  TLorentzVector PEFreeze, Int_t Origin)
  : fPdgId(pdgId),
    fEnergy(energy),
    fOrigin(Origin)
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
       << "-I-                 Particle                 -I-" << endl
       << "PDG code                              : "  << fPdgId << endl
       << "Momentum (px, py, pz) (GeV)           : (" << fP.X() << ", " << fP.Y() << ", " << fP.Z() << ")" << endl
       << "Energy (GeV)                          : "  << fEnergy << endl
       << "Freezeout position (x, y, z) (fm)     : (" << fXFreeze.X() << ", " << fXFreeze.Y() << ", " << fXFreeze.Z() << ")" << endl
       << "Freezeout time (fm)                   : "  << fTimeFreeze << endl
       << "Freezeout momentum (px, py, pz) (GeV) : (" << fPFreeze.X() << ", " << fPFreeze.Y() << ", " << fPFreeze.Z() << ")" << endl
       << "Freezeout energy (GeV)                : "  << fEnergyFreeze << endl;
  if (TMath::Abs(fPdgId) == 1000010020) {
    cout<< "Deuteron is                           : ";
    if (fOrigin == 0) cout<<"kinetic "<<endl;
    if (fOrigin == 1) cout<<"potential " <<endl;		      
  } 
  cout<< "----------------------------------------------------------" << endl;
}

ClassImp(ParticleFreeze);
