#include "PEventBaryons.h"
#include "PBaryon.h"

#include "TString.h"
#include <iostream>
#include <cstddef>
using namespace std;

PEventBaryons::PEventBaryons()
  : fEventId(0),
    fNBaryons(0),
    fNAntiBaryons(0),
    fISub(0),
    fINum(0),
    fB(0.),
    fRCluster(0.0),
    fStepNr(0),
    fTime(0.)
{
  fBaryons.clear();
};

void PEventBaryons::AddBaryon(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t Xpos, Float_t Ypos, Float_t Zpos, Float_t Mass, Int_t clusterId, Int_t nBary, Int_t baryonId, Int_t prodId, Int_t prodchanel, Float_t TimeFreeze, Float_t Ebin)
{
  fBaryons.push_back(PBaryon(pdgId, Px, Py, Pz, Xpos, Ypos, Zpos, Mass, clusterId, nBary, baryonId, prodId, prodchanel, TimeFreeze, Ebin));
};

PBaryon PEventBaryons::GetBaryon(Int_t ibaryon) const
{
  if(ibaryon < 0 || ibaryon >= fNBaryons + fNAntiBaryons) throw runtime_error("\n Baryon " + to_string(ibaryon) + " not found in current event!");
  return ((PBaryon) fBaryons.at(ibaryon));
}

void PEventBaryons::SetParameters(Int_t eventId, Int_t nBaryons, Int_t nAntiBaryons, Int_t iSub, Int_t iNum, Float_t b, Float_t Rcluster, Int_t stepnr, Float_t time)
{
  fEventId      = eventId;
  fNBaryons     = nBaryons;
  fNAntiBaryons = nAntiBaryons;
  fISub         = iSub;
  fINum         = iNum;
  fB            = b;
  fRCluster     = Rcluster;
  fStepNr       = stepnr;
  fTime         = time;
};

void PEventBaryons::Print(Option_t* option) const
{
  // Print data members to the standard output
  cout << "-------------------------------------------------------"<< endl
       << "-I-                  Event                          -I-"<< endl
       << "EventId                          : " << fEventId      << endl
       << "Number of baryons                : " << fNBaryons     << endl
       << "Number of anti-baryons           : " << fNAntiBaryons << endl
       << "Current subsequent event         : " << fISub         << endl
       << "Current parallel event           : " << fINum         << endl
       << "Impact parameter (fm)            : " << fB            << endl
       << "Max. cluster radius for MST (fm) : " << fRCluster     << endl
       << "Timestep                         : " << fStepNr       << endl
       << "Event time (fm/c)                : " << fTime         << endl;
      
  TString opt = option;
  if(opt.Contains("all")) {
    PBaryon baryon;
    for(Int_t iB = 0; iB < fNBaryons + fNAntiBaryons; iB++) {
      baryon = (PBaryon) fBaryons.at(iB);
      baryon.Print();
    }
  }
  cout << "-------------------------------------------------------" << endl;
}

void PEventBaryons::Clear()
{ fBaryons.clear();
};

ClassImp(PEventBaryons);
