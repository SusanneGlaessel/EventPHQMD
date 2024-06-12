/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Class to store PHQMD hadron events from phsd.dat
 **/

#ifndef PEventHadrons_HH
#define PEventHadrons_HH

#include "TROOT.h"

class PHadron;

class PEventHadrons : public TObject  {

 private:
  Int_t                 fEventId;            // Event Number
  Int_t                 fNHadrons;           // Number of hadrons
  Int_t                 fNParticipants;      // Number of participants
  Int_t                 fISub;               // Number of current subsequent events
  Int_t                 fINum;               // Number of current parallel events
  Float_t               fB;                  // Impact parameter (fm)
  std::array<Float_t,4> fPhi;                // Out-of-plane angle of the ith harmonic    
  std::array<Float_t,4> fPsi;                // Eccentricity of the ith harmonic
  std::vector<PHadron>  fHadrons;            // Array of hadrons
  
 public:  
  PEventHadrons();
  virtual ~PEventHadrons() = default;
  void Print(Option_t* option = "") const;
  
  inline Int_t                 GetEventId()             const {return fEventId;}
  inline Int_t                 GetNHadrons()            const {return fNHadrons;}
  inline Int_t                 GetNParticipants()       const {return fNParticipants;}
  inline Int_t                 GetISub()                const {return fISub;}
  inline Int_t                 GetINum()                const {return fINum;}
  inline Float_t               GetB()                   const {return fB;}
  inline std::array<Float_t,4> GetPhi()                 const {return fPhi;}
  inline std::array<Float_t,4> GetPsi()                 const {return fPsi;}
  inline std::vector<PHadron>  GetHadronList()          const {return fHadrons;}
  PHadron                      GetHadron(Int_t ihadron) const;
  
  void SetParameters    (Int_t eventId, Int_t nHadrons, Int_t nParticipants, Int_t iSub, Int_t iNum, Float_t b,  std::array<Float_t,4> phi, std::array<Float_t,4> psi);
  inline void SetEventId       (Int_t eventId)             {fEventId = eventId;}
  inline void SetNHadrons      (Int_t nHadrons)            {fNHadrons = nHadrons;}
  inline void SetNParticipants (Int_t nParticipants)       {fNParticipants = nParticipants;}
  inline void SetISub          (Int_t iSub)                {fISub = iSub;}
  inline void SetINum          (Int_t iNum)                {fINum = iNum;}
  inline void SetB             (Float_t b)                 {fB = b;}
  inline void SetPhi           (std::array<Float_t,4> phi) {fPhi = phi;}
  inline void SetPsi           (std::array<Float_t,4> psi) {fPhi = psi;}
  void AddHadron        (Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t baryonId, Int_t mesonId, Float_t xposfo, Float_t yposfo, Float_t zposfo, Float_t timefo, Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t densityB, Float_t densityE);
  void AddHadron        (Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t baryonId, Int_t mesonId);

  void Clear();
  
  ClassDef(PEventHadrons, 1);
};
#endif
