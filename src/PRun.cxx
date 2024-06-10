#include "PRun.h"
#include "TString.h"
#include "TMath.h"
#include <iostream>
#include <cstddef>
#include <iomanip>  
using namespace std;

PRun::PRun()
  : TNamed("run","Run Header"),
    fGenerator(""),
    fAProj(0),
    fZProj(0),
    fATarg(0),
    fZTarg(0),
    fELab(0.0),
    fpProj(0.0),
    fpTarg(0.0),
    fBMin(0.0),
    fBMax(0.0),
    fIBweight(-1),
    fDBimp(0.0),
    fNUM(0),
    fISUBS(0),
    fTStart(0.0),
    fTFinal(0.0),
    fdT(0.0),
    fNTIME(0),
    fIEos(-1),
    fIGlue(-1),
    fIPhqmd(-1),
    fINuclei(-1),
    fIRes(-1),
    fIDilept(-1),
    fICq(-1),
    fIHard(-1),
    fEyuk(-1),
    fEasy(-1),
    fEpair(-1),
    fEcoul(-1),
    fEvasy(-1),
    fEtapair(-1),
    fIFragWig(-1)
{
};

PRun::PRun(const char* generator, Int_t aProj, Int_t zProj, Int_t aTarg, Int_t zTarg, Float_t eLab, Float_t bMin, Float_t bMax, Int_t IBweight, Float_t DBimp, Int_t NUM, Int_t ISUBS, Float_t Tstart, Float_t Tfinal, Float_t dT, Int_t NTIME, Int_t Ieos, Int_t Iglue, Int_t Iphqmd, Int_t Inuclei, Int_t Ires, Int_t Idilept, Int_t Icq, Int_t Ihard, Int_t Eyuk, Int_t Easy, Int_t Epair, Int_t Ecoul, Float_t Evasy, Int_t Etapair, Int_t IfragWig)
  : TNamed("run","Run Header"),
    fGenerator(generator),
    fAProj(aProj),
    fZProj(zProj),
    fATarg(aTarg),
    fZTarg(zTarg),
    fELab(eLab),
    fBMin(bMin),
    fBMax(bMax),
    fIBweight(IBweight),
    fDBimp(DBimp),
    fNUM(NUM),
    fISUBS(ISUBS),
    fTStart(Tstart),
    fTFinal(Tfinal),
    fdT(dT),
    fNTIME(NTIME),
    fIEos(Ieos),
    fIGlue(Iglue),
    fIPhqmd(Iphqmd),
    fINuclei(Inuclei),
    fIRes(Ires),
    fIDilept(Idilept),
    fICq(Icq),
    fIHard(Ihard),
    fEyuk(Eyuk),
    fEasy(Easy),
    fEpair(Epair),
    fEcoul(Ecoul),
    fEvasy(Evasy),
    fEtapair(Etapair),
    fIFragWig(IfragWig)
{

  fpProj = TMath::Sqrt(eLab*fProtonMass/2);
  fpTarg = -fpProj;
  cout << "Centre of mass energy (GeV) : " << setprecision(3) << GetEnergyCM()     << endl;
  cout << "Laboratory energy (AGeV)    : " << setprecision(3) << eLab              << endl;
  cout << "Beam momentum (GeV/c)       : " << setprecision(3) << GetBeamMomentum() << endl;
  cout << "Projectile momentum (AGeV/c): " << setprecision(3) << fpProj            << endl;
  cout << "Target momentum (AGeV/c)    : " << setprecision(3) << fpTarg            << endl;
};
  
PRun::~PRun()
{
  // Destructor
}

Float_t PRun::GetpProj() const
{
  return TMath::Sqrt(fELab*fProtonMass/2);
}

Float_t PRun::GetpTarg() const
{
  return -TMath::Sqrt(fELab*fProtonMass/2);
}

Float_t PRun::GetEnergyCM() const
{
  return TMath::Sqrt((fELab + (2 * fProtonMass)) * (2 * fProtonMass));
}

Float_t PRun::GetBeamMomentum() const
{
  return 2 * fpProj / TMath::Sqrt(1 - fpProj*fpProj / (fpProj*fpProj + fProtonMass*fProtonMass));
}

Float_t PRun::GetFinalTMst() const
{
  return fTStart + fNTIME * fdT;  
}

TString PRun::GetEosName() const
{
  TString EosName;
  if(fIEos == 0) EosName = "hard";
  if(fIEos == 1) EosName = "soft";
  return EosName;
}

TString PRun::GetPropDyn() const
{
  TString PropDyn;
  if(fIPhqmd == 0) PropDyn = "HSD/PHSD";
  if(fIPhqmd == 1) PropDyn = "QMD";
  return PropDyn;
}

TString PRun::GetResName() const
{
  TString ResName;
  if(fIRes == 1) ResName = "all resonances with their decays";
  if(fIRes == 2) ResName = "only nucleons";
  if(fIRes == 3) ResName = "only nucleons & hyperons";
  return ResName;
}

TString PRun::GetPhaseName() const
{
  TString PhaseName;
  if(fIGlue == 0) PhaseName = "with partonic QGP phase (PHSD mode)";
  if(fIGlue == 1) PhaseName = "no QGP (HSD mode)";
  return PhaseName;
}

TString PRun::GetDilepName() const
{
  TString DilepName;
  if (fIDilept == 0) DilepName = "without";
  if (fIDilept == 1) DilepName = "electron pair";
  if (fIDilept == 2) DilepName = "muon pair";
  return DilepName;
}     

TString PRun::GetMesSpecName() const
{
  TString MesSpecName;
  if (fICq == 0) MesSpecName = "Free rho's";
  if (fICq == 1) MesSpecName = "dropping mass";
  if (fICq == 2) MesSpecName = "broadening";
  if (fICq == 3) MesSpecName = "drop. + broad.";
  return MesSpecName;
} 

TString PRun::GetYesNo(Int_t Iyes) const
{
  return Iyes ? "yes" : "no";
}

bool PRun::Int2Bool(Int_t var) const
{
  return var ? true : false;
}


void PRun::Print(Option_t* /*option*/) const
{
  // Print all data members to the standard output
  cout << "------------------------------------------------------------"    << endl
       << "-I-                 Run Header                           -I-"    << endl
       << "Generator                         : " << fGenerator << endl
       << "Projectile mass number            : " << fAProj     << endl
       << "Projectile charge                 : " << fZProj     << endl    
       << "Target mass number                : " << fATarg     << endl
       << "Target charge                     : " << fZTarg     << endl
       << "Lab energy per nucleon            : " << fELab      << " AGeV"   << endl
       << "Projectile momentum               : " << fpProj     << " AGeV/c" << endl
       << "Target momentum                   : " << fpTarg     << " AGeV/c" << endl
       << "Minimal impact parameter          : " << fBMin      << " fm"     << endl
       << "Maximal impact parameter          : " << fBMax      << " fm"     << endl
       << "Impact parameter weighting        : " << fIBweight               << endl
       << "Impact parameter step             : " << fDBimp     << " fm"     << endl
       << "Number of parallel events         : " << fNUM                    << endl
       << "Number of subsequent events       : " << fISUBS                  << endl
       << "Final time                        : " << fTFinal    << " fm/c"   << endl
       << "Starting time for MST/SACA        : " << fTStart    << " fm/c"   << endl
       << "Time step dT                      : " << fdT        << " fm/c"   << endl
       << "Number of timesteps               : " << fNTIME                  << endl
       << "Final time for MST/SACA           : " << GetFinalTMst() <<" fm/c"<< endl
       << "EoS                               : " << GetEosName()            << endl
       << "Phase transition                  : " << GetPhaseName()          << endl
       << "Propagation dynamics              : " << GetPropDyn()            << endl
       << "Kinetic deuterons                 : " << GetYesNo(fINuclei)      << endl
       << "Resoncances in MST/SACA           : " << GetResName()            << endl
       << "Dileptons                         : " << GetDilepName()          << endl
       << "Vector meson spectral function    : " << GetMesSpecName()        << endl
       << "With charm and bottom             : " << GetYesNo(fIHard)        << endl
       << "Yukawa potential in SACA          : " << GetYesNo(fEyuk)         << endl
       << "Asymmetry energy in SACA          : " << GetYesNo(fEasy)         << endl
       << "Coul. energy for fragm. select.   : " << GetYesNo(fEcoul)        << endl
       << "Struct. eff. in SACA              : " << GetYesNo(fEpair)        << endl
       << "Asymm. pot. energy at norm. dens. : " << fEvasy      << " MeV"   << endl
       << "Pairing pot. exponant in SACA     : " << GetYesNo(fEtapair)      << endl
       << "Light clusters acc. to Wig. dens. : " << GetYesNo(fIFragWig)     << endl
       << "------------------------------------------------------------"    << endl;
      
}
ClassImp(PRun);
