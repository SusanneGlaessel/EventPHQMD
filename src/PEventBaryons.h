/** author: Susanne Glaessel (Universtitaet Frankfurt)
 ** Class to store PHQMD events with cluster baryons from fort.791/fort.891/fort.781/fort.881
 **/

#ifndef PEventBaryons_HH
#define PEventBaryons_HH

#include "TROOT.h"

class PBaryon;

class PEventBaryons : public TObject  {

 private:
  Int_t                 fEventId;            // Event Number
  Int_t                 fNBaryons;           // Number of baryons
  Int_t                 fNAntiBaryons;       // Number of anti-baronys
  Int_t                 fISub;               // Number of current subsquent event
  Int_t                 fINum;               // Number of current parallel event
  Float_t               fB;                  // Impact parameter (fm)
  Float_t               fRCluster;           // Cluster radius (fm)
  Int_t                 fStepNr;             // Step number of current event
  Float_t               fTime;               // Time at which event is written out (fm/c)
  std::vector<PBaryon>  fBaryons;            // Array of baryons & antibaryons
  
 public:  
  PEventBaryons();
  virtual ~PEventBaryons() = default;
  void Print(Option_t* option = "") const;

  inline Int_t                 GetEventId()             const {return fEventId;}
  inline Int_t                 GetNBaryons()            const {return fNBaryons;}
  inline Int_t                 GetNAntiBaryons()        const {return fNAntiBaryons;}
  inline Int_t                 GetNAllBaryons()         const {return fNBaryons + fNAntiBaryons;}
  inline Int_t                 GetISub()                const {return fISub;}
  inline Int_t                 GetINum()                const {return fINum;}
  inline Float_t               GetB()                   const {return fB;}
  inline Float_t               GetRCluster()            const {return fRCluster;}
  inline Int_t                 GetStepNr()              const {return fStepNr;}
  inline Float_t               GetTime()                const {return fTime;}
  inline std::vector<PBaryon>  GetBaryonList()          const {return fBaryons;}
  PBaryon                      GetBaryon(Int_t ibaryon) const;

  void SetParameters    (Int_t eventId, Int_t nBaryons, Int_t nAntiBaryons, Int_t iSub, Int_t iNum, Float_t b, Float_t Rcluster, Int_t stepnr, Float_t time);
  inline void SetEventId       (Int_t eventId)             {fEventId = eventId;}
  inline void SetNBaryons      (Int_t nBaryons)            {fNBaryons = nBaryons;}
  inline void SetNAntiBaryons  (Int_t nAntiBaryons)        {fNAntiBaryons = nAntiBaryons;}
  inline void SetISub          (Int_t iSub)                {fISub = iSub;}
  inline void SetINum          (Int_t iNum)                {fINum = iNum;}
  inline void SetB             (Float_t b)                 {fB = b;}
  inline void SetRCluster      (Float_t Rcluster)          {fRCluster = Rcluster;}
  inline void SetTime          (Int_t time)                {fTime = time;}
  void AddBaryon(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t Xpos, Float_t Ypos, Float_t Zpos, Float_t Mass, Int_t clusterId, Int_t nBary, Int_t baryonId, Int_t prodId, Int_t prodchanel, Float_t TimeFreeze, Float_t Ebin);
  void Clear();

  ClassDef(PEventBaryons, 1);
};
#endif
