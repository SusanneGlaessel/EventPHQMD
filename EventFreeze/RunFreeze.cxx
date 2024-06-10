#include "RunFreeze.h"
#include "TString.h"
#include "TMath.h"
#include <iostream>
#include <cstddef>
#include <iomanip>  
using namespace std;

RunFreeze::RunFreeze()
  : TNamed("run","Run Header"),
    fGenerator(""),
    fComment(""),
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
    fNEvents(0)
{
};

RunFreeze::RunFreeze(const char* generator, const char* comment, Int_t aProj, Int_t zProj, Int_t aTarg, Int_t zTarg, Float_t eLab, Float_t bMin, Float_t bMax, Int_t IBweight, Int_t nEvents)
  : TNamed("run","Run Header"),
    fGenerator(generator),
    fComment(comment),
    fAProj(aProj),
    fZProj(zProj),
    fATarg(aTarg),
    fZTarg(zTarg),
    fELab(eLab),
    fBMin(bMin),
    fBMax(bMax),
    fIBweight(IBweight),
    fNEvents(nEvents)
{
  fpProj = GetpProj();
  fpTarg = GetpTarg();
};
  
RunFreeze::~RunFreeze()
{
  // Destructor
}

Float_t RunFreeze::GetpProj() const
{
  return TMath::Sqrt(fELab*fProtonMass/2);
}

Float_t RunFreeze::GetpTarg() const
{
  return -TMath::Sqrt(fELab*fProtonMass/2);
}

Float_t RunFreeze::GetEnergyCM() const
{
  return TMath::Sqrt((fELab + (2 * fProtonMass)) * (2 * fProtonMass));
}

Float_t RunFreeze::GetBeamMomentum() const
{
  return 2 * fpProj / TMath::Sqrt(1 - fpProj*fpProj / (fpProj*fpProj + fProtonMass*fProtonMass));
}

void RunFreeze::Print(Option_t* /*option*/) const
{
  // Print all data members to the standard output
  cout << "------------------------------------------------------------"    << endl
       << "-I-                 Run Header                           -I-"    << endl
       << "Generator                         : " << fGenerator << endl
       << "Comment                           : " << fComment   << endl
       << "Projectile mass number            : " << fAProj     << endl
       << "Projectile charge                 : " << fZProj     << endl    
       << "Target mass number                : " << fATarg     << endl
       << "Target charge                     : " << fZTarg     << endl
       << "Lab energy per nucleon            : " << fELab      << " AGeV"   << endl
       << "Projectile momentum               : " << GetpProj() << " AGeV/c" << endl
       << "Target momentum                   : " << GetpTarg() << " AGeV/c" << endl
       << "Minimal impact parameter          : " << fBMin      << " fm"     << endl
       << "Maximal impact parameter          : " << fBMax      << " fm"     << endl
       << "Impact parameter weighting        : " << fIBweight               << endl
       << "Requested number of events        : " << fNEvents   << endl
       << "------------------------------------------------------------"    << endl;
      
}
ClassImp(RunFreeze);
