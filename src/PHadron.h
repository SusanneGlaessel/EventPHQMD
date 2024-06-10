/** author: Susanne Glaessel (Universität Frankfurt)
 ** Class to store PHQMD hadrons from phsd.dat
 **/

#ifndef PHadron_HH
#define PHadron_HH

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class PHadron : public TObject {

 private:
    
  Int_t          fPdgId;        // PDG code
  TVector3       fP;            // 3-momentum at final time (pz, py, pz) (GeV/c)
  Float_t        fEnergy;       // Energy (GeV)
  Int_t          fProcessId;    // type of process / reaction from which particle comes
  Int_t          fInfoId;       // for baryons: participation in MST-routine: =1: baryon is in MST-output; =-1: NOT in MST-output,
                                // for mesons: information about parents (parent PHSD-Id)
  Int_t          fPHSDId;       // PHSD-Id
  TLorentzVector fXTFreeze;     // Position & time at freezeout (fm, fm, fm, fm/c)
  TVector3       fPFreeze;      // 3-momentum at freezeout-time (pz, py, pz) (GeV/c)
  Float_t        fDensityB;     // baryon density
  Float_t        fDensityE;     // energy density
  
 public:
  
  PHadron();
  virtual ~PHadron();
  PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t PHSDId, Float_t xposfo, Float_t yposfo, Float_t zposfo , Float_t timefo, Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t densityB, Float_t densityE);
  PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t PHSDId);

  
  inline Int_t    GetPdg()                  const {return fPdgId;}
  inline Float_t  Px()                      const {return fP.X();}
  inline Float_t  Py()                      const {return fP.Y();}
  inline Float_t  Pz()                      const {return fP.Z();}
  inline TVector3 GetMomentum()             const {return fP;}
  inline TLorentzVector GetMomentum4()      const {return TLorentzVector(fP.X(),fP.Y(),fP.Z(),fEnergy);}
  inline Float_t  E()                       const {return fEnergy;}
  inline Float_t  Mass()                    const {return TMath::Sqrt(fEnergy*fEnergy - fP.X()*fP.X() - fP.Y()*fP.Y() - fP.Z()*fP.Z());}
  inline Int_t    GetProcessId()            const {return fProcessId;}
  inline Int_t    GetInfoId()               const {return fInfoId;}
  inline Int_t    GetPHSDId()               const {return fPHSDId;}
  inline Float_t  XFreeze()                 const {return fXTFreeze.X();}
  inline Float_t  YFreeze()                 const {return fXTFreeze.Y();}
  inline Float_t  ZFreeze()                 const {return fXTFreeze.Z();}
  inline Float_t  TFreeze()                 const {return fXTFreeze.T();}
  inline TLorentzVector GetPositionFreeze() const {return TLorentzVector(fXTFreeze.X(),fXTFreeze.Y(),fXTFreeze.Z(),fXTFreeze.T());}  
  inline Float_t  PxFreeze()                const {return fPFreeze.X();}
  inline Float_t  PyFreeze()                const {return fPFreeze.Y();}
  inline Float_t  PzFreeze()                const {return fPFreeze.Z();}
  inline TVector3 GetMomentumFreeze()       const {return fPFreeze;}
  TLorentzVector GetMomentumFreeze4();
  Float_t EFreeze();    
  inline Float_t  GetDensityB()             const {return fDensityB;}
  inline Float_t  GetDensityE()             const {return fDensityE;}
    
  inline void SetPdg(Int_t pdgId)           {fPdgId = pdgId;}
  inline void SetPx(Float_t Px)             {fP.SetX(Px);}
  inline void SetPy(Float_t Py)             {fP.SetY(Py);}
  inline void SetPz(Float_t Pz)             {fP.SetZ(Pz);}
  inline void SetMomentum(Float_t Px, Float_t Py, Float_t Pz) {fP.SetXYZ(Px, Py, Pz);}
  inline void SetMomentum(Float_t Px, Float_t Py, Float_t Pz, Float_t energy) {fP.SetXYZ(Px, Py, Pz); fEnergy = energy;}
  inline void SetMomentum(TVector3 P)       {fP = P;}
  inline void SetMomentum(TLorentzVector P) {fP.SetXYZ(P.X(), P.Y(), P.Z()); fEnergy = P.T();}
  inline void SetE(Float_t energy)          {fEnergy = energy;}
  inline void SetProcessId(Int_t processId) {fProcessId = processId;}
  inline void SetInfoId(Int_t infoId)       {fInfoId = infoId;}
  inline void SetPHSDId(Int_t PHSDId)       {fPHSDId = PHSDId;}
  inline void SetXFreeze(Float_t xposfo)    {fXTFreeze.SetX(xposfo);}
  inline void SetYFreeze(Float_t yposfo)    {fXTFreeze.SetY(yposfo);}
  inline void SetZFreeze(Float_t zposfo)    {fXTFreeze.SetZ(zposfo);}
  inline void SetTFreeze(Float_t timefo)    {fXTFreeze.SetT(timefo);}
  inline void SetPositionFreeze(Float_t xposfo, Float_t yposfo, Float_t zposfo) {fXTFreeze.SetX(xposfo); fXTFreeze.SetY(yposfo); fXTFreeze.SetZ(zposfo);}
  inline void SetPositionFreeze(Float_t xposfo, Float_t yposfo, Float_t zposfo, Float_t timefo) {fXTFreeze.SetXYZT(xposfo, yposfo, zposfo, timefo);}
  inline void SetPositionFreeze(TLorentzVector XTFreeze) {fXTFreeze = XTFreeze;}  
  inline void SetPxFreeze(Float_t xpfo)     {fPFreeze.SetX(xpfo);}
  inline void SetPyFreeze(Float_t ypfo)     {fPFreeze.SetY(ypfo);}
  inline void SetPzFreeze(Float_t zpfo)     {fPFreeze.SetZ(zpfo);}
  void SetMomentumFreeze(Float_t xpfo, Float_t ypfo, Float_t zpfo) {fPFreeze.SetXYZ(xpfo, ypfo, zpfo);}
  void SetMomentumgFreeze(TVector3 PFreeze) {fPFreeze = PFreeze;} 
  inline void SetDensityB(Float_t densityB) {fDensityB = densityB;}
  inline void SetDensityE(Float_t densityE) {fDensityE = densityE;}  
 
  void Print() const;

 protected:
  TString GetYesNo(Int_t Iyes) const;

  ClassDef(PHadron, 1);
};
#endif
