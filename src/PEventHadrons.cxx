#include "PEventHadrons.h"
#include "PHadron.h"

#include "TString.h"
#include <iostream>
#include <cstddef>
using namespace std;

PEventHadrons::PEventHadrons()
  : fEventId(0),
    fNHadrons(0),
    fNParticipants(0),
    fISub(0),
    fINum(0),
    fB(0.),
    fPhi({0.0,0.0,0.0,0.0}),                   
    fPsi({0.0,0.0,0.0,0.0}),
    fRatQgp(0.)
{
  fHadrons.clear();
};

void PEventHadrons::AddHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t baryonId, Int_t mesonId, Float_t xposfo, Float_t yposfo, Float_t zposfo, Float_t timefo, Float_t xpfo, Float_t ypfo, Float_t zpfo, Float_t densityB, Float_t densityE)
{
  fHadrons.push_back(PHadron(pdgId, Px, Py, Pz, energy, processId, infoId, baryonId, mesonId, xposfo, yposfo, zposfo ,timefo, xpfo,ypfo,zpfo, densityB, densityE));
};

void PEventHadrons::AddHadron(Int_t pdgId, Float_t Px, Float_t Py, Float_t Pz, Float_t energy, Int_t processId, Int_t infoId, Int_t baryonId, Int_t mesonId)
{
  fHadrons.push_back(PHadron(pdgId, Px, Py, Pz, energy, processId, infoId, baryonId, mesonId));
};

PHadron PEventHadrons::GetHadron(Int_t ihadron) const
{
  if(ihadron < 0 || ihadron >= fNHadrons) throw runtime_error("\n Hadron " + to_string(ihadron) + " not found in current event!");
  return ((PHadron) fHadrons.at(ihadron));
}

void PEventHadrons::SetParameters(Int_t eventId, Int_t nHadrons, Int_t nParticipants, Int_t iSub, Int_t iNum, Float_t b,  std::array<Float_t,4> phi, std::array<Float_t,4> psi, Float_t ratqgp)
{
  fEventId = eventId;
  fNHadrons = nHadrons;
  fNParticipants = nParticipants;
  fISub = iSub;
  fINum = iNum;
  fB = b;
  fPhi = phi;
  fPsi = psi;
  fRatQgp = ratqgp;
};

void PEventHadrons::Print(Option_t* option) const
{
  // Print data members to the standard output
  cout << "-------------------------------------------------------------------------------------" << endl
       << "-I-                         Event                                                 -I-" << endl
       << "EventId                                : " << fEventId       << endl
       << "Number of hadrons                      : " << fNHadrons      << endl
       << "Number of participants                 : " << fNParticipants << endl
       << "Current subsequent event               : " << fISub          << endl
       << "Current parallel event                 : " << fINum          << endl
       << "Impact parameter (fm)                  : " << fB             << endl
       << "Out-of-plane angle of the ith harmonic : " << fPhi.at(0) << ", " << fPhi.at(1) << ", " << fPhi.at(2) << ", " << fPhi.at(3) << endl
       << "Eccentricity of the ith harmonic       : " << fPsi.at(0) << ", " << fPsi.at(1) << ", " << fPsi.at(2) << ", " << fPsi.at(3) << endl
       << "Ratio of QGP                           : " << fRatQgp        << endl;

  TString opt = option;
  if(opt.Contains("all")) {
    PHadron hadron;
    for(Int_t iH = 0; iH < fNHadrons; iH++) {
      hadron = (PHadron) fHadrons.at(iH);
      hadron.Print();
    }
  }
  cout << "-------------------------------------------------------------------------------------" << endl;
}

void PEventHadrons::Clear()
{
  fHadrons.clear();
};

ClassImp(PEventHadrons);
