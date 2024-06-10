/** author: Susanne Glaessel (IKF Frankfurt)
 ** Class to store PHQMD baryons & anti-baryons entering the cluster routine from fort.791/fort.891/fort.781/fort.881
 **/

#ifndef PBaryon_HH
#define PBaryon_HH

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class PBaryon : public TObject {

 private:
  Int_t          fPdgId;        // PDG code
  TVector3       fP;            // 3-momentum at timestep (pz, py, pz) (GeV/c)
  TVector3       fX;            // Position 3-momentum at timestep (fm, fm, fm)
  Float_t        fMass;         // Baryon mass (GeV/c)
  Int_t          fClusterId;    // Number of cluster to which this baryons belongs to
  Int_t          fnBary;        // Size of the cluster to which this baryon belongs to
  Int_t          fBaryonId;     // Position of the baryon in PHSD vector
  Int_t          fProdId;       // = -1: from projectile, = +1 from target (wo collision),
                                // = other - made collision
  Int_t          fProdChanel;   // proction chanel of baryon
  Float_t        fProdTime;     // production time (fm/c)
  Float_t        fEbin;         // binding energy of cluster per baryon (GeV)
  
 public:  

  PBaryon();
  PBaryon(Int_t PdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t X, Float_t Y, Float_t Z, Float_t Mass, Int_t clusterId, Int_t nBary, Int_t baryonId, Int_t prodId, Int_t prodchanel, Float_t prodtime, Float_t ebin);
  virtual ~PBaryon();

  inline Int_t    GetPdg()         const {return fPdgId;}
  inline Float_t  Px()             const {return fP.X();}
  inline Float_t  Py()             const {return fP.Y();}
  inline Float_t  Pz()             const {return fP.Z();}
  inline TVector3 GetMomentum()    const {return fP;}
  inline TLorentzVector GetMomentum4() const {return TLorentzVector(fP.X(),fP.Y(),fP.Z(),E());}
  inline Float_t  Mass()           const {return fMass;}
  inline Float_t  E()              const {return TMath::Sqrt(fMass*fMass + fP.X()*fP.X() + fP.Y()*fP.Y() + fP.Z()*fP.Z());}
  inline Float_t  X()              const {return fX.X();}
  inline Float_t  Y()              const {return fX.Y();}
  inline Float_t  Z()              const {return fX.Z();}     
  inline TVector3 GetPosition()    const {return TVector3(fX.X(),fX.Y(),fX.Z());}
  inline Int_t    GetClusterId()   const {return fClusterId;}
  inline Int_t    GetNBary()       const {return fnBary;}
  inline Int_t    GetBaryonId()    const {return fBaryonId;}
  inline Int_t    GetProdId()      const {return fProdId;}
  inline Int_t    GetProdChanel()  const {return fProdChanel;}
  inline Float_t  GetProdTime()   const  {return fProdTime;}
  inline Float_t  GetEbin()        const {return fEbin;} 

  inline void SetPdg(Int_t pdgId)             {fPdgId = pdgId;}
  inline void SetPx(Float_t Px)               {fP.SetX(Px);}
  inline void SetPy(Float_t Py)               {fP.SetY(Py);}
  inline void SetPz(Float_t Pz)               {fP.SetZ(Pz);}
  inline void SetMomentum(Float_t Px, Float_t Py, Float_t Pz) {fP.SetXYZ(Px, Py, Pz);}
  inline void SetMomentum(TVector3 P)         {fP = P;}
  inline void SetMass(Float_t mass)           {fMass = mass;}
  inline void SetX(Float_t x)                 {fX.SetX(x);}
  inline void SetY(Float_t y)                 {fX.SetY(y);}
  inline void SetZ(Float_t z)                 {fX.SetZ(z);}
  inline void SetPosition(Float_t x, Float_t y, Float_t z) {fX.SetXYZ(x, y, z);}
  inline void SetPosition(TVector3 Pos)       {fX = Pos;}
  inline void SetClusterId(Int_t clusterId)   {fClusterId = clusterId;}
  inline void SetNBary(Int_t nBary)           {fnBary = nBary;}
  inline void SetBaryonId(Int_t baryonId)     {fBaryonId = baryonId;}
  inline void SetProdId(Int_t prodId)         {fProdId = prodId;}
  inline void SetProdChanel(Int_t prodchanel) {fProdChanel = prodchanel;}
  inline void SetProdTime(Float_t prodtime)   {fProdTime = prodtime;}
  inline void SetEbin(Float_t ebin)           {fEbin = ebin;}
 
 
  void Print() const;

 private:
  TString GetProdIdName() const;

  ClassDef(PBaryon, 1);
};
#endif
