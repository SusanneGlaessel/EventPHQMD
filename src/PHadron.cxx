#include "PHadron.h"

#include "TString.h"
#include <iostream>
using namespace std;

PHadron::PHadron()
  : fPdgId(0),
    fEnergy(0.),
    fProcessId(0),
    fParentId(-1),
    fBaryonId(-1),
    fMesonId(-1),
    fDensityBfo(0.0),
    fDensityEfo(0.0),
    fDensityBC(0.0),
    fDensityEC(0.0)
{
  fP.SetXYZ(0.,0.,0.);
  fXTFreeze.SetXYZT(0.,0.,0.,0.);
  fPEFreeze.SetXYZT(0.,0.,0.,0.);
};

PHadron::PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t parentId, Int_t baryonId, Int_t mesonId, Float_t xposfo, Float_t yposfo, Float_t zposfo , Float_t timefo, Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t energyfo, Float_t densityBfo, Float_t densityEfo, Float_t densityBC, Float_t densityEC)
  : fPdgId(pdgId),
    fEnergy(energy),
    fProcessId(processId),
    fParentId(parentId),
    fBaryonId(baryonId),
    fMesonId(mesonId),
    fDensityBfo(densityBfo),
    fDensityEfo(densityEfo),
    fDensityBC(densityBC),
    fDensityEC(densityEC)
{
  fP.SetXYZ(Px,Py,Pz);
  fXTFreeze.SetXYZT(xposfo,yposfo,zposfo,timefo);
  fPEFreeze.SetXYZT(xpfo,ypfo,zpfo,energyfo);

};

PHadron::PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t parentId, Int_t baryonId, Int_t mesonId)
  : fPdgId(pdgId),
    fEnergy(energy),
    fProcessId(processId),
    fParentId(parentId),
    fBaryonId(baryonId),
    fMesonId(mesonId),
    fDensityBfo(0.0),
    fDensityEfo(0.0),
    fDensityBC(0.0),
    fDensityEC(0.0)
{
  fP.SetXYZ(Px,Py,Pz);
  fXTFreeze.SetXYZT(0.,0.,0.,0.);
  fPEFreeze.SetXYZT(0.,0.,0.,0.);
};

PHadron::~PHadron()
{
  // Destructor
}

TString PHadron::GetYesNo(Int_t Iyes) const
{
  return Iyes ? "yes" : "no";
}

void PHadron::Print() const
{
  // Print the data members to the standard output
  cout << "----------------------------------------------------------------------------------------------" << endl
       << "-I-                               Hadron                                                   -I-" << endl
       << "PDG code                                          : "  << fPdgId        << endl
       << "Momentum (px, py, pz) (GeV)                       : "  << fP.X() << ", " << fP.Y() << ", " << fP.Z() << endl
       << "Energy (GeV)                                      : "  << fEnergy       << endl
       << "ProcessId                                         : "  << fProcessId    << endl;
    if ( fBaryonId == -1) {
      cout << "MesonId                                           : " << fMesonId  <<endl; } 
    else {
      cout << "BaryonId                                          : " << fBaryonId  <<endl; }
  cout << "ParentId                                          : "  << fParentId     << endl 
       << "Freezeout position (x, y, z) (fm)                 : "  << fXTFreeze.X() << ", " << fXTFreeze.Y() << ", " << fXTFreeze.Z() << endl
       << "Freezeout time (fm)                               : "  << fXTFreeze.T() << endl
       << "Freezeout momentum (px, py, pz) (GeV)             : "  << fPEFreeze.X()  << ", " << fPEFreeze.Y()  << ", " << fPEFreeze.Z()  << endl
       << "Freezeout energy (GeV)                            : "  << fPEFreeze.T() << endl
       << "Baryon density at freezeout                       : "  << fDensityBfo   << endl
       << "Energy density at freezeout (GeV/fm^(3))          : "  << fDensityEfo   << endl
       << "Baryon density at chemical freezeout              : "  << fDensityBC    << endl
       << "Energy density at chemical freezeout (GeV/fm^(3)) : "  << fDensityEC    << endl
       << "----------------------------------------------------------------------------------------------" << endl;
}

ClassImp(PHadron);

