#include "ParticleFreeze.h"

#include "TString.h"
#include <iostream>
using namespace std;

ParticleFreeze::ParticleFreeze()
  : fPdgId(0),
    fEnergy(0.),
    fTimeFreeze(0.),
    fOrigin(0)
{
  fP.SetXYZ(0.,0.,0.);
  fXFreeze.SetXYZ(0.,0.,0.);
  fPFreeze.SetXYZ(0.,0.,0.);
};

ParticleFreeze::ParticleFreeze(Int_t pdgId, TVector3 P, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin)
  : fPdgId(pdgId),
    fP(P),
    fEnergy(energy),
    fPFreeze(PFreeze),
    fOrigin(Origin)
{
  fTimeFreeze = XFreeze.T();
  fXFreeze.SetXYZ(XFreeze.X(), XFreeze.Y(), XFreeze.Z());
};

ParticleFreeze::ParticleFreeze(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Float_t TimeFreeze, TVector3 XFreeze, TVector3 PFreeze, Int_t Origin)
  : fPdgId(pdgId),
    fEnergy(energy),
    fTimeFreeze(TimeFreeze),
    fXFreeze(XFreeze),
    fPFreeze(PFreeze),
    fOrigin(Origin)
{
  fP.SetXYZ(Px, Py, Pz);
};

ParticleFreeze::ParticleFreeze(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin)
  : fPdgId(pdgId),
    fEnergy(energy),
    fPFreeze(PFreeze),
    fOrigin(Origin)
{
  fP.SetXYZ(Px, Py, Pz);
  fTimeFreeze = XFreeze.T();
  fXFreeze.SetXYZ(XFreeze.X(), XFreeze.Y(), XFreeze.Z());
};

Float_t ParticleFreeze::EFreeze()
{
  Float_t Mass = TMath::Sqrt(fEnergy*fEnergy - fP.X()*fP.X() - fP.Y()*fP.Y() - fP.Z()*fP.Z());
  return TMath::Sqrt(Mass*Mass + fPFreeze.X()*fPFreeze.X() + fPFreeze.Y()*fPFreeze.Y() + fPFreeze.Z()*fPFreeze.Z());
}

TLorentzVector ParticleFreeze::GetMomentumFreeze()
{
  Float_t Mass = TMath::Sqrt(fEnergy*fEnergy - fP.X()*fP.X() - fP.Y()*fP.Y() - fP.Z()*fP.Z());
  Float_t EFreeze = TMath::Sqrt(Mass*Mass + fPFreeze.X()*fPFreeze.X() + fPFreeze.Y()*fPFreeze.Y() + fPFreeze.Z()*fPFreeze.Z());
  return TLorentzVector(fPFreeze.X(),fPFreeze.Y(),fPFreeze.Z(), EFreeze);
}

void ParticleFreeze::Print(Option_t* /*option*/) const
{
  // Print the data members to the standard output
  cout << "----------------------------------------------------------" << endl
       << "-I-                 Particle                 -I-" << endl
       << "PDG code                              : "  << fPdgId << endl
       << "Momentum (px, py, pz) (GeV)           : (" << fP.X() << ", " << fP.Y() << ", " << fP.Z() << ")" << endl
       << "Energy (GeV)                          : "  << fEnergy << endl
       << "Freezeout Position (x, y, z) (fm)     : (" << fXFreeze.X() << ", " << fXFreeze.Y() << ", " << fXFreeze.Z() << ")" << endl
       << "Freezeout time (fm)                   : "  << fTimeFreeze << endl
       << "Freezeout momentum (px, py, pz) (GeV) : (" << fPFreeze.X() << ", " << fPFreeze.Y() << ", " << fPFreeze.Z() << ")" << endl;
  if (TMath::Abs(fPdgId) == 1000010020) {
    cout<< "Deuteron is                           : ";
    if (fOrigin == 0) cout<<"kinetic "<<endl;
    if (fOrigin == 1) cout<<"potential " <<endl;		      
  } 
  cout<< "----------------------------------------------------------" << endl;
}

ClassImp(ParticleFreeze);
