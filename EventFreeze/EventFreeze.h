/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Class to store events including the freezeout-momentum of particles
 **/

#ifndef EventFreeze_HH
#define EventFreeze_HH

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class ParticleFreeze;

class EventFreeze : public TObject  {
 private:

  Int_t   fEventId;       // Event Number
  Float_t fB;             // Impact parameter (fm)
  Int_t   fNParticipants; // Number of participants
  Float_t fTime;          // Final time at which event is written out (fm/c)
  Float_t fPhi;           // Reaction plane angle
  Int_t   fNpa;           // Number of particles
  std::vector<ParticleFreeze> fParticles;  // Array of particles

 public:
  EventFreeze();
  virtual ~EventFreeze() = default;
  
  inline Int_t    GetEventId()       const {return fEventId;}
  inline Float_t  GetB()             const {return fB;}
  inline Int_t    GetNParticipants() const {return fNParticipants;}
  inline Int_t    GetTime()          const {return fTime;}
  inline Float_t  GetPhi()           const {return fPhi;}
  inline Int_t    GetNpa()           const {return fNpa;}
  inline std::vector<ParticleFreeze> GetParticleList() const {return fParticles;}
  ParticleFreeze GetParticle(Int_t index) const;

  void SetParameters(Int_t eventId, Float_t b, Int_t nparticipants, Float_t time, Float_t phi);
  inline void SetEventId(Int_t eventId)              {fEventId = eventId;}
  inline void SetB      (Float_t b)                  {fB = b;}
  inline void SetNParticipants (Int_t nparticipants) {fNParticipants = nparticipants;}
  inline void SetTime   (Float_t time)               {fTime = time;}
  inline void SetPhi    (Float_t phi)                {fPhi = phi;}

  void AddParticle (Int_t pdgId, TVector3 P, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin); 
  void AddParticle (Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Float_t TimeFreezeCluster, TVector3 posfo_cluster, TVector3 pfo_cluster, Int_t Origin); 
  void AddParticle (Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, TLorentzVector XFreeze, TVector3 PFreeze, Int_t Origin);
  void Print(Option_t* option = "") const;
  void Clear();
  
  ClassDef(EventFreeze, 1);
};
#endif
