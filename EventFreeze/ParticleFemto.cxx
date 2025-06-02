#include "ParticleFemto.h"

#include "TString.h"
#include <iostream>
using namespace std;

ParticleFemto::ParticleFemto()
  : fIndex(-1),
    fEnergy(0.)
{
  fP.SetXYZ(0.,0.,0.);
  fX.SetXYZ(0.,0.,0.);
};

ParticleFemto::ParticleFemto(Int_t index, TLorentzVector P, TVector3 X)
  : fIndex(index)
{
  fX.SetXYZ(X.X(), X.Y(), X.Z());
  fP.SetXYZ(P.X(), P.Y(), P.Z());
  fEnergy = P.T();
};

void ParticleFemto::Print(Option_t* /*option*/) const
{
  // Print the data members to the standard output
  cout << "----------------------------------------------------------" << endl
       << "-I-                 Particle                 -I-" << endl
       << "Index                                 : " << fIndex << endl
       << "Momentum (px, py, pz) (GeV)           : (" << fP.X() << ", " << fP.Y() << ", " << fP.Z() << ")" << endl
       << "Energy (GeV)                          : "  << fEnergy << endl
       << "Position (x, y, z) (fm)               : (" << fX.X() << ", " << fX.Y() << ", " << fX.Z() << ")" << endl;
  cout<< "----------------------------------------------------------" << endl;
}

ClassImp(ParticleFemto);
