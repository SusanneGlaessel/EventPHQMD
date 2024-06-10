#include "PBaryon.h"
#include "TString.h"
#include <iostream>
using namespace std;

PBaryon::PBaryon()
  : fPdgId(0),
    fMass(0.0),
    fClusterId(0),
    fnBary(0),
    fBaryonId(0),
    fProdId(0),
    fProdChanel(0),
    fEbin(0),
    fProdTime(0.)
{
  fP.SetXYZ(0.,0.,0.);
  fX.SetXYZ(0.,0.,0.);
};

PBaryon::PBaryon(Int_t PdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t X, Float_t Y, Float_t Z, Float_t Mass, Int_t clusterId, Int_t nBary, Int_t baryonId, Int_t prodId, Int_t prodchanel, Float_t prodtime, Float_t ebin)
  : fPdgId(PdgId),
    fMass(Mass),
    fClusterId(clusterId),
    fnBary(nBary),
    fBaryonId(baryonId),
    fProdId(prodId),
    fProdChanel(prodchanel),
    fProdTime(prodtime),
    fEbin(ebin)
{
  fP.SetXYZ(Px,Py,Pz);
  fX.SetXYZ(X,Y,Z);
};

PBaryon::~PBaryon()
{
  // Destructor
}

TString PBaryon::GetProdIdName() const
{
  TString ProdIdName;
  if(fProdId == -1) ProdIdName = "from projectile";
  else if(fProdId == 1) ProdIdName = "from target";
  else ProdIdName = "made in collision";
  return ProdIdName;
}

void PBaryon::Print() const
{
  // Print the data members to the standard output
  cout << "-------------------------------------------------------" << endl
       << "-I-                 Baryon                          -I-" << endl
       << "PDG code                     : "  << fPdgId                << endl
       << "Momentum (px, py, pz) (GeV)  : "  << fP.X() << ", " << fP.Y() << ", " << fP.Z() << endl
       << "Position (x, y, z) (fm)      : "  << fX.X() << ", " << fX.Y() << ", " << fX.Z() << endl
       << "Mass (GeV)                   : "  << fMass                 << endl
       << "ClusterId                    : "  << fClusterId            << endl
       << "Number of baryons in cluster : "  << fnBary                << endl 
       << "BaryonId                     : "  << fBaryonId             << endl
       << "Production                   : "  << GetProdIdName()       << endl
       << "Production chanel            : "  << fProdChanel           << endl 
       << "Production time (fm)         : "  << fProdTime             << endl
       << "Binding energy               : "  << fEbin                 << endl 
       << "-------------------------------------------------------" << endl;
}

ClassImp(PBaryon);
