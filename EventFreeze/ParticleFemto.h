/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Class to store particles including their freezeout-momentum
 **/

#ifndef ParticleFemto_HH
#define ParticleFemto_HH

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class ParticleFemto : public TObject {
  
 private:
  Int_t    fIndex;    // index of this particle
  TVector3 fP;        // 3-momentum at final time (pz, py, pz) (GeV/c)
  Float_t  fEnergy;   // Energy (GeV/c)
  TVector3 fX;        // Position at freezeout-time (fm)

 public:

  ParticleFemto();
  virtual ~ParticleFemto() = default;

  inline Int_t   GetIndex()     const {return fIndex;}
  inline Float_t Px()           const {return fP.X();}
  inline Float_t Py()           const {return fP.Y();}
  inline Float_t Pz()           const {return fP.Z();}
  inline Float_t E()            const {return fEnergy;}
  inline TVector3 GetMomentum() const {return TVector3(fP.X(),fP.Y(),fP.Z());}
  inline Float_t X()            const {return fX.X();}
  inline Float_t Y()            const {return fX.Y();}
  inline Float_t Z ()           const {return fX.Z();}    
  inline TVector3 GetPosition() const {return TVector3(fX.X(),fX.Y(),fX.Z());}

  ParticleFemto(Int_t Index, TLorentzVector P, TVector3 X);
  void Print(Option_t* = "") const;

  ClassDef(ParticleFemto, 1);
};
#endif
