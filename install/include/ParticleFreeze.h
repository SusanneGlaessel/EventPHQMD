/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Class to store particles including their freezeout-momentum
 **/

#ifndef ParticleFreeze_HH
#define ParticleFreeze_HH

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class ParticleFreeze : public TObject {
  
 private:
  Int_t    fPdgId;        // PDG code
  TVector3 fP;            // 3-momentum at final time (pz, py, pz) (GeV/c)
  Float_t  fEnergy;       // Energy (GeV/c)
  Float_t  fTimeFreeze;   // Freezeout-time (fm/c)
  TVector3 fXFreeze;      // Position at freezeout-time (fm)
  TVector3 fPFreeze;      // 3-momentum at freezeout-time (pz, py, pz) (GeV/c)
  Int_t    fOrigin;       // Information about origin of deuterons: = 0: kinetic deuteron (from phsd.dat), = 1: potential/MST deuteron (from fort.891)

 public:

  ParticleFreeze();
  virtual ~ParticleFreeze() = default;

  inline Int_t   GetPdg()         const {return fPdgId;}
  inline Float_t Px()             const {return fP.X();}
  inline Float_t Py()             const {return fP.Y();}
  inline Float_t Pz()             const {return fP.Z();}
  inline Float_t E()              const {return fEnergy;}
  inline TLorentzVector GetMomentum() const {return TLorentzVector(fP.X(),fP.Y(),fP.Z(),fEnergy);}
  inline Float_t XFreeze()        const {return fXFreeze.X();}
  inline Float_t YFreeze()        const {return fXFreeze.Y();}
  inline Float_t ZFreeze()        const {return fXFreeze.Z();}
  inline Float_t TFreeze()        const {return fTimeFreeze;}
  Float_t EFreeze();       
  inline TLorentzVector GetPositionFreeze() const {return TLorentzVector(fXFreeze.X(),fXFreeze.Y(),fXFreeze.Z(),fTimeFreeze);}
  inline Float_t PxFreeze()       const {return fPFreeze.X();}
  inline Float_t PyFreeze()       const {return fPFreeze.Y();}
  inline Float_t PzFreeze()       const {return fPFreeze.Z();}   
  TLorentzVector GetMomentumFreeze();
  inline Int_t   GetOrigin()      const {return fOrigin;}

  ParticleFreeze(Int_t pdgId, TVector3 P, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin);
  ParticleFreeze(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Float_t TimeFreeze, TVector3 XFreeze, TVector3 PFreeze, Int_t Origin);
  ParticleFreeze(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin);
  void Print(Option_t* = "") const;

  ClassDef(ParticleFreeze, 1);
};
#endif
