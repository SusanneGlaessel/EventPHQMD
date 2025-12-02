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
  Int_t          fParentId;     // information about parents (parent PHSD-Id)
  Int_t          fBaryonId;     // baryon-Id (= -1 for mesons)
  Int_t          fMesonId;      // meson-Id (= -1 for baryons)
  TLorentzVector fXTFreeze;     // Position & time at freezeout (fm, fm, fm, fm/c)
  TLorentzVector fPEFreeze;     // 4-momentum at freezeout-time (pz, py, pz, energy) (GeV/c, GeV)
  Float_t        fDensityBfo;   // baryon density at freezeout-time
  Float_t        fDensityEfo;   // energy density at freezeout-time
  Float_t        fDensityBC;    // baryon density at chemical freezeout
  Float_t        fDensityEC;    // energy density at chemical freezeout
  
 public:
  
  PHadron();
  virtual ~PHadron();
  PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t parentId, Int_t baryonId, Int_t mesonId, Float_t xposfo, Float_t yposfo, Float_t zposfo , Float_t timefo, Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t energyfo, Float_t densityBfo, Float_t densityEfo, Float_t densityBC, Float_t densityEC);
  PHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t parentId, Int_t baryonId, Int_t mesonId);

  
  inline Int_t    GetPdg()                  const {return fPdgId;}
  inline Float_t  Px()                      const {return fP.X();}
  inline Float_t  Py()                      const {return fP.Y();}
  inline Float_t  Pz()                      const {return fP.Z();}
  inline TVector3 GetMomentum()             const {return fP;}
  inline TLorentzVector GetMomentum4()      const {return TLorentzVector(fP.X(),fP.Y(),fP.Z(),fEnergy);}
  inline Float_t  E()                       const {return fEnergy;}
  inline Float_t  Mass()                    const {return TMath::Sqrt(fEnergy*fEnergy - fP.X()*fP.X() - fP.Y()*fP.Y() - fP.Z()*fP.Z());}
  inline Int_t    GetProcessId()            const {return fProcessId;}
  inline Int_t    GetParentId()             const {return fParentId;}
  inline Int_t    GetBaryonId()             const {return fBaryonId;}
  inline Int_t    GetMesonId()              const {return fMesonId;}
  inline Float_t  XFreeze()                 const {return fXTFreeze.X();}
  inline Float_t  YFreeze()                 const {return fXTFreeze.Y();}
  inline Float_t  ZFreeze()                 const {return fXTFreeze.Z();}
  inline Float_t  TFreeze()                 const {return fXTFreeze.T();}
  inline TLorentzVector GetPositionFreeze() const {return TLorentzVector(fXTFreeze.X(),fXTFreeze.Y(),fXTFreeze.Z(),fXTFreeze.T());}  
  inline Float_t  PxFreeze()                const {return fPEFreeze.X();}
  inline Float_t  PyFreeze()                const {return fPEFreeze.Y();}
  inline Float_t  PzFreeze()                const {return fPEFreeze.Z();}
  inline Float_t  EnergyFreeze()            const {return fPEFreeze.T();}
  inline TLorentzVector GetMomentumFreeze() const {return TLorentzVector(fPEFreeze.X(),fPEFreeze.Y(),fPEFreeze.Z(),fPEFreeze.T());}
  inline Float_t  GetDensityBFreeze()       const {return fDensityBfo;}
  inline Float_t  GetDensityEFreeze()       const {return fDensityEfo;}
  inline Float_t  GetDensityBChem()         const {return fDensityBC;}
  inline Float_t  GetDensityEChem()         const {return fDensityEC;}
    
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
  inline void SetParentId(Int_t parentId)   {fParentId = parentId;}
  inline void SetBaryonId(Int_t baryonId)   {fBaryonId = baryonId;}
  inline void SetMesonId(Int_t mesonId)     {fMesonId = mesonId;}
  inline void SetXFreeze(Float_t xposfo)    {fXTFreeze.SetX(xposfo);}
  inline void SetYFreeze(Float_t yposfo)    {fXTFreeze.SetY(yposfo);}
  inline void SetZFreeze(Float_t zposfo)    {fXTFreeze.SetZ(zposfo);}
  inline void SetTFreeze(Float_t timefo)    {fXTFreeze.SetT(timefo);}
  inline void SetPositionFreeze(Float_t xposfo, Float_t yposfo, Float_t zposfo) {fXTFreeze.SetX(xposfo); fXTFreeze.SetY(yposfo); fXTFreeze.SetZ(zposfo);}
  inline void SetPositionFreeze(Float_t xposfo, Float_t yposfo, Float_t zposfo, Float_t timefo) {fXTFreeze.SetXYZT(xposfo, yposfo, zposfo, timefo);}
  inline void SetPositionFreeze(TLorentzVector XTFreeze) {fXTFreeze = XTFreeze;}  
  inline void SetPxFreeze(Float_t xpfo)     {fPEFreeze.SetX(xpfo);}
  inline void SetPyFreeze(Float_t ypfo)     {fPEFreeze.SetY(ypfo);}
  inline void SetPzFreeze(Float_t zpfo)     {fPEFreeze.SetZ(zpfo);}
  inline void SetMomentumFreeze(Float_t xpfo, Float_t ypfo, Float_t zpfo) {fPEFreeze.SetX(xpfo); fPEFreeze.SetY(ypfo); fPEFreeze.SetZ(zpfo);}
  inline void SetMomentumFreeze(Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t energyfo) {fPEFreeze.SetXYZT(xpfo, ypfo, zpfo, energyfo);}
  inline void SetMomentumgFreeze(TLorentzVector PEFreeze) {fPEFreeze = PEFreeze;} 
  inline void SetDensityBFreeze(Float_t densityBfo) {fDensityBfo = densityBfo;}
  inline void SetDensityEFreeze(Float_t densityEfo) {fDensityEfo = densityEfo;}
  inline void SetDensityBChem(Float_t densityBC)    {fDensityBC = densityBC;}
  inline void SetDensityEChem(Float_t densityEC)    {fDensityEC = densityEC;}  
 
  void Print() const;

 protected:
  TString GetYesNo(Int_t Iyes) const;

  ClassDef(PHadron, 1);
};
#endif
