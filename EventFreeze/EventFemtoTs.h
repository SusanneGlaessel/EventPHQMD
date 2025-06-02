/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Class to store events for all timesteps (after freezeout of baryon / cluster) with baryon momentum & position
 **/

#ifndef EventFemtoTS_HH
#define EventFemtoTS_HH

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"

class ParticleFemto;

class EventFemtoTs : public TObject  {
 private:

  Int_t   fEventId;       // Event Number
  Int_t   fStepNr;        // Step number of current event
  Float_t fTime;          // Time at which event is written out (fm/c)
  Int_t   fNpa;           // Number of particles
  std::vector<ParticleFemto> fParticles;  // Array of particles
  std::map<int, int> fIndex2Particle; // Map to find particle with specific index

 public:
  EventFemtoTs();
  virtual ~EventFemtoTs() = default;
  
  inline Int_t    GetEventId()       const {return fEventId;}
  inline Int_t    GetStepNr()        const {return fStepNr;}
  inline Float_t  GetTime()          const {return fTime;}
  inline Int_t    GetNpa()           const {return fNpa;}
  inline std::vector<ParticleFemto> GetParticleList() const {return fParticles;}
  ParticleFemto GetParticle(Int_t i) const;
  ParticleFemto GetParticleIndex(Int_t index) const;  // Returns particle with index

  void SetParameters(Int_t eventId, Int_t stepnr, Float_t time);
  inline void SetEventId(Int_t eventId)  {fEventId = eventId;}
  inline void SetStepNr(Float_t stepnr)  {fStepNr = stepnr;}
  inline void SetTime(Int_t time)        {fTime = time;}

  void AddParticle (Int_t index, TLorentzVector P, TVector3 X);

  void Print(Option_t* option = "") const;
  void Clear();
  
  ClassDef(EventFemtoTs, 1);
};
#endif
