#include "PHadron.h"

#include "TString.h"
#include <iostream>
using namespace std;

PHadron::PHadron()
  : fPdgId(0),
    fEnergy(0.),
    fProcessId(0),
    fInfoId(0),
    fBaryonId(-1),
    fMesonId(-1),
    fDensityB(0.0),
    fDensityE(0.0)
{
  fP.SetXYZ(0.,0.,0.);
  fXTFreeze.SetXYZT(0.,0.,0.,0.);
  fPFreeze.SetXYZ(0.,0.,0.);
};

PHadron::PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t baryonId, Int_t mesonId, Float_t xposfo, Float_t yposfo, Float_t zposfo , Float_t timefo, Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t densityB, Float_t densityE)
  : fPdgId(pdgId),
    fEnergy(energy),
    fProcessId(processId),
    fInfoId(infoId),
    fBaryonId(baryonId),
    fMesonId(mesonId),
    fDensityB(densityB),
    fDensityE(densityE)
{
  fP.SetXYZ(Px,Py,Pz);
  fXTFreeze.SetXYZT(xposfo,yposfo,zposfo,timefo);
  fPFreeze.SetXYZ(xpfo,ypfo,zpfo);

};

PHadron::PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t baryonId, Int_t mesonId)
  : fPdgId(pdgId),
    fEnergy(energy),
    fProcessId(processId),
    fInfoId(infoId),
    fBaryonId(baryonId),
    fMesonId(mesonId),
    fDensityB(0.0),
    fDensityE(0.0)
{
  fP.SetXYZ(Px,Py,Pz);
  fXTFreeze.SetXYZT(0.,0.,0.,0.);
  fPFreeze.SetXYZ(0.,0.,0.);
};

PHadron::~PHadron()
{
  // Destructor
}

TLorentzVector PHadron::GetMomentumFreeze4()
{
  Float_t Mass = TMath::Sqrt(fEnergy*fEnergy - fP.X()*fP.X() - fP.Y()*fP.Y() - fP.Z()*fP.Z());
  Float_t EFreeze = TMath::Sqrt(Mass*Mass + fPFreeze.X()*fPFreeze.X() + fPFreeze.Y()*fPFreeze.Y() + fPFreeze.Z()*fPFreeze.Z());
  return TLorentzVector(fPFreeze.X(),fPFreeze.Y(),fPFreeze.Z(), EFreeze);
}

Float_t PHadron::EFreeze()
{
  Float_t Mass = TMath::Sqrt(fEnergy*fEnergy - fP.X()*fP.X() - fP.Y()*fP.Y() - fP.Z()*fP.Z());
  return TMath::Sqrt(Mass*Mass + fPFreeze.X()*fPFreeze.X() + fPFreeze.Y()*fPFreeze.Y() + fPFreeze.Z()*fPFreeze.Z());
}

TString PHadron::GetYesNo(Int_t Iyes) const
{
  return Iyes ? "yes" : "no";
}

void PHadron::Print() const
{
  // Print the data members to the standard output
  cout << "-------------------------------------------------------------------------------------" << endl
       << "-I-                           Hadron                                              -I-" << endl
       << "PDG code                                 : "  << fPdgId        << endl
       << "Momentum (px, py, pz) (GeV)              : "  << fP.X() << ", " << fP.Y() << ", " << fP.Z() << endl
       << "Energy (GeV)                             : "  << fEnergy       << endl
       << "ProcessId                                : "  << fProcessId    << endl;
    if ( fBaryonId == -1) {
      cout << "MesonId                                  : " << fMesonId  <<endl;  
      cout << "ParentId                                 : " << fInfoId << endl; }
    else {
      cout << "BaryonId                                 : " << fBaryonId  <<endl; 
      cout << "Participation in MST-routine             : " << GetYesNo(fInfoId) << endl; }
  cout << "Freezeout position (x, y, z) (fm)        : "  << fXTFreeze.X() << ", " << fXTFreeze.Y() << ", " << fXTFreeze.Z() << endl
       << "Freezeout time (fm)                      : "  << fXTFreeze.T() << endl
       << "Freezeout momentum (px, py, pz) (GeV)    : "  << fPFreeze.X()  << ", " << fPFreeze.Y()  << ", " << fPFreeze.Z()  << endl
       << "Baryon density at freezeout              : "  << fDensityB     << endl
       << "Energy density at freezeout (GeV/fm^(3)) : "  << fDensityE     << endl
       << "-------------------------------------------------------------------------------------" << endl;
}

ClassImp(PHadron);

