/** author: Susanne Glaessel, Universitaet Frankfurt
 ** Class to store PHQMD run information from inputPHSD
 **/

#ifndef PRun_HH
#define PRun_HH

#include "TNamed.h"
#include "TString.h"

class PRun : public TNamed {

 private:
  TString fGenerator;      // Generator description
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
  Float_t fDBimp;          // Impact parameter step (fm) (used only if IBweight=0)
  Int_t   fNUM;            // Number of parallel events
  Int_t   fISUBS;          // Number of subsequent events
  Float_t fTStart;         // Starting time for MST/SACA (fm/c)
  Float_t fTFinal;         // Final time of calculation (fm/c)
  Float_t fdT;             // Time step for MST/SACA calculations
  Int_t   fNTIME;          // Number of MST/SACA timesteps
  Int_t   fIEos;           // EoS (for QMD option): =0: hard EOS without M.D.I; =1: soft EoS
  Int_t   fIGlue;          // =1: With partonic QGP phase (PHSD mode); =0: HSD mode 
  Int_t   fIPhqmd;         // =1: Propagation with QMD dynamics; =0: with HSD/PHSD dynamics
  Int_t   fINuclei;        // =1: Kinetic deuterons; =0: without
  Int_t   fIRes;           // =1: All resonances with their decay in MST/SACA;
                           // =2: Only nucleons;
                           // =3: Nucleons and hyperons
  Int_t   fIDilept;        // =0: No dileptons; =1: electron pair; =2:  muon pair
  Int_t   fICq;            // Vector meson spectral function:
                           // =0: Free rho's, =1: dropping mass, =2: broadening, =3: drop.+broad.
  Int_t   fIHard;          // =1: With charm and bottom; =0: without 
  Int_t   fEyuk;           // =1: Yukawa potential in SACA; =0: without
  Int_t   fEasy;           // =1: Asymmetry energy in SACA; =0: without
  Int_t   fEcoul;          // =1: Coulomb energy for fragment selection; =0 without
  Int_t   fEpair;          // =1: Structure effects (pairing,...) in SACA; =0: without
  Float_t fEvasy;          // Asymmetry potential energy at normal density (MeV)
  Float_t fEtapair;        // Pairing potential exponant (0.->only forbids unbound isotopes, 1., 0.65, 0.35 or 0.25) in SACA 
  Int_t   fIFragWig;       // =1: Light clusters formation according to the Wigner density, =0: no
  
 public:

  PRun();
  virtual ~PRun();
  PRun(const char* generator, Int_t aProj, Int_t zProj, Int_t aTarg, Int_t zTarg, Float_t eLab, Float_t bMin, Float_t bMax, Int_t IBweight, Float_t DBimp, Int_t NUM, Int_t ISUBS, Float_t Tstart, Float_t Tfinal, Float_t dT, Int_t NTIME, Int_t Ieos, Int_t Iglue, Int_t Iphqmd, Int_t Inuclei, Int_t Ires, Int_t Idilept, Int_t Icq, Int_t Ihard, Int_t Eyuk, Int_t Easy, Int_t Epair, Int_t Ecoul, Float_t Evasy, Int_t Etapair, Int_t IfragWig);
  void Print(Option_t* = "") const;

  inline TString GetGenerartor() const {return fGenerator;}      
  inline Int_t   GetAProj()      const {return fAProj;}            
  inline Int_t   GetZProj()      const {return fZProj;}            
  inline Int_t   GetATarg()      const {return fATarg;}            
  inline Int_t   GetZTarg()      const {return fZTarg;}            
  inline Float_t GetELab()       const {return fELab;}
  inline Float_t GetBMin()       const {return fBMin;}     
  inline Float_t GetBMax()       const {return fBMax;}    
  inline Int_t   GetIBweight()   const {return fIBweight;}        
  inline Float_t GetDBimp()      const {return fDBimp;}          
  inline Int_t   GetNum()        const {return fNUM;}
  inline Int_t   GetSub()        const {return fISUBS;}
  inline Int_t   GetNEvents()    const {return fNUM * fISUBS;}
  inline Float_t GetTStart()     const {return fTStart;}      
  inline Float_t GetTFinal()     const {return fTFinal;}        
  inline Float_t GetdT()         const {return fdT;}             
  inline Int_t   GetNTime()      const {return fNTIME;}
  inline Int_t   GetIEos()       const {return fIEos;}             
  inline Int_t   GetIGlue()      const {return fIGlue;}           
  inline Int_t   GetIPhqmd()     const {return fIPhqmd;}        
  inline Int_t   GetINuclei()    const {return fINuclei;}         
  inline Int_t   GetIRes()       const {return fIRes;}           
  inline Int_t   GetIDilept()    const {return fIDilept;}          
  inline Int_t   GetICq()        const {return fICq;}              
  inline Int_t   GetIHard()      const {return fIHard;}           
  inline Int_t   GetEyuk()       const {return fEyuk;}            
  inline Int_t   GetEasy()       const {return fEasy;}           
  inline Int_t   GetEcoul()      const {return fEcoul;}   
  inline Int_t   GetEpair()      const {return fEpair;}      
  inline Float_t GetEvasy()      const {return fEvasy;}      
  inline Float_t GetEtapair()    const {return fEtapair;}      
  inline Int_t   GetIFragWig()   const {return fIFragWig;}

  Float_t GetpProj() const;   
  Float_t GetpTarg() const;
  Float_t GetEnergyCM() const;  
  Float_t GetBeamMomentum() const;
  
 private:
  Float_t GetFinalTMst() const;
  TString GetEosName() const;
  TString GetPropDyn() const;
  TString GetResName() const;
  TString GetPhaseName() const;
  TString GetDilepName() const;
  TString GetMesSpecName() const;
  TString GetYesNo(Int_t Iyes) const;
  bool    Int2Bool(Int_t var)  const;

  const Float_t fProtonMass = 0.938272321;

  ClassDef(PRun, 1);
};
#endif
