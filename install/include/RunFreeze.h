/** author: Susanne Glaessel, Universitaet Frankfurt
 ** Class to store run information for events including the freezeout-momentum of particles
 **/

#ifndef RunFreeze_HH
#define RunFreeze_HH

#include "TNamed.h"
#include "TString.h"

class RunFreeze : public TNamed {

 private:
  
  TString fGenerator;      // Generator description
  TString fComment;        // Run comment
  Int_t   fAProj;          // Projectile mass number
  Int_t   fZProj;          // Projectile charge
  Int_t   fATarg;          // Target mass number
  Int_t   fZTarg;          // Target charge
  Float_t fELab;           // Lab energy per nucleon (AGeV)
  Float_t fpProj;          // Projectile momentum per nucleon (GeV)
  Float_t fpTarg;          // Target momentum per nucleon (GeV)            
  Float_t fBMin;           // Minimum impact parameter (fm)
  Float_t fBMax;           // Maximum impact parameter (fm)
  Int_t   fIBweight;       // Impact paramter weighting
                           // =0: constant step in B = DBimp (flat distribution)
                           // =1: choose B by Monte-Carlo in [Bmin,Bmax] (geometrical weights)
  Int_t   fNEvents;        // Requested number of events
  
 public:

  RunFreeze();
  virtual ~RunFreeze();
  RunFreeze(const char* generator, const char* comment, Int_t aProj, Int_t zProj, Int_t aTarg, Int_t zTarg, Float_t eLab, Float_t bMin, Float_t bMax, Int_t IBweight, Int_t nEvents);
  void Print(Option_t* = "") const;
  
  inline TString GetGenerartor() const {return fGenerator;}
  inline TString GetComment()    const {return fComment;}
  inline Int_t   GetAProj()      const {return fAProj;}            
  inline Int_t   GetZProj()      const {return fZProj;}            
  inline Int_t   GetATarg()      const {return fATarg;}            
  inline Int_t   GetZTarg()      const {return fZTarg;}            
  inline Float_t GetElab()       const {return fELab;}
  inline Float_t GetBMin()       const {return fBMin;}     
  inline Float_t GetBMax()       const {return fBMax;}    
  inline Int_t   GetIBweight()   const {return fIBweight;}        
  inline Int_t   GetNEvents()    const {return fNEvents;}

  Float_t GetpProj() const;   
  Float_t GetpTarg() const;
  Float_t GetEnergyCM() const;  
  Float_t GetBeamMomentum() const;
  
 private:
  const Float_t fProtonMass = 0.938272321;

  ClassDef(RunFreeze, 1);
};
#endif
