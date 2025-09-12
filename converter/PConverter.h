/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Class to convert PHQMD output files:
 ** - create a root-file from all PHQMD output files
 ** and/or
 ** - convert PHQMD output into complete events with hadrons & clusters 
 **   (UniGen format or root-file including freeze-out momentum)
 **/

#ifndef PConverter_HH
#define PConverter_HH

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TString.h"
#include <iostream>
#include "EventFreeze.h"
#include "ParticleFreeze.h"
#include "URun.h"
#include "UEvent.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::map;

class PRun;
class PEventHadrons;
class PEventBaryons;

class PConverter
{
 public:

  PConverter() = default;
  virtual ~PConverter() = default;

  struct PBaryon_cluster {
    Int_t fPdgId;
    TVector3 fP;
    Float_t fMass;
    Float_t fEnergy;
    Float_t fEbin;
    TVector3 fX;
    TLorentzVector fXTFreeze;
    TLorentzVector fPEFreeze;
    Int_t fBaryonId;
    Int_t fProcessId;
    
  PBaryon_cluster(Int_t baryonId, Int_t PdgId,  Int_t processId, TVector3 P, Float_t mass, Float_t energy, TLorentzVector XTFreeze, TLorentzVector PEFreeze, Float_t Ebin) : fBaryonId(baryonId), fPdgId(PdgId), fProcessId(processId), fP(P), fMass(mass), fEnergy(energy), fXTFreeze(XTFreeze), fPEFreeze(PEFreeze), fEbin(Ebin) { fX = {0.0, 0.0, 0.0}; };
  PBaryon_cluster(Int_t baryonId, Int_t PdgId, TVector3 P, Float_t energy, TVector3 X) : fBaryonId(baryonId), fPdgId(PdgId), fProcessId(-1), fP(P), fEnergy(energy), fX(X) {fMass = TMath::Sqrt(energy*energy - P.Mag2()), fXTFreeze = {0.0, 0.0, 0.0, 0.0}; fPEFreeze = {0.0, 0.0, 0.0, 0.0}; };
  PBaryon_cluster(Int_t PdgId, Float_t Ebin) : fBaryonId(-1), fPdgId(0), fProcessId(-1), fMass(0.0), fEnergy(0.0), fEbin(Ebin) { fP = {0.0, 0.0, 0.0}; fXTFreeze = {0.0, 0.0, 0.0, 0.0}; fX = {0.0, 0.0, 0.0}; fPEFreeze = {0.0, 0.0, 0.0, 0.0}; };
  };

  struct ClusterEntry {
    Int_t fPdgId;
    Int_t fNProt;
    Int_t fNBary0;
    Int_t fNLamb;
    Int_t fNSigm;
    Double_t fBR;
  ClusterEntry() : fPdgId(-1), fNProt(-1), fNBary0(-1), fNLamb(-1), fNSigm(-1), fBR(-1) {};
  ClusterEntry(Int_t pdgId, Int_t nProt, Int_t nBary0, Int_t nLamb, Int_t nSigm, Double_t br) : fPdgId(pdgId), fNProt(nProt), fNBary0(nBary0), fNLamb(nLamb), fNSigm(nSigm), fBR(br) {};
  };

  void Init(TString indir = "", TString dataset = "", Bool_t CreatePHQMDout = kTRUE, Bool_t FreezeCoords = kFALSE, Bool_t CreateOutWithUnstable = kFALSE, Bool_t Convert = kFALSE, Bool_t ConvertMode = 0, Bool_t ConvertAnti = kTRUE, Bool_t WriteUnigen = kTRUE, Bool_t WriteEventFreeze = kFALSE,  Bool_t WriteEventFemto = kFALSE,  Int_t firstevent = 0);
  
  void OpenPHQMDoutCreate();
  void OpenPHQMDoutRead();
  
  void CreatePHeader();
  void CreatePEventsHadrons();
  void CreatePEventsBaryons(Bool_t CreateUnstable = kFALSE);

  void WritePHQMDout();
  void ClosePHQMDout();
  
  void MakeMaps();
  void ConvertPHQMD();
  void RemovePHQMDout();

  private:

  void InitCreatePHQMDout(Bool_t ConvertAnti = kTRUE, Int_t firstevent = 0);
  void InitCreatePHQMDoutUnstable(Bool_t ConvertAnti = kTRUE, Int_t firstevent = 0);
  void InitConvert(Bool_t WriteUnigen = kTRUE, Bool_t WriteEventFreeze = kTRUE, Bool_t WriteEventFemto = kTRUE, Bool_t ConvertAnti = kTRUE);

  void ClusterTablePrint();
  void GetClusterList();
  void GetPdgIdBaryon(Int_t charge, Int_t &pdgId, Bool_t IsAnti);
  Int_t ChangeProcessId3digits(Int_t processId);
  void GetClusterPdg(std::vector<PBaryon_cluster> baryons_cluster, Int_t clusterId, Int_t &pdgIdCl);
  void GetBaryonContent(std::vector<PBaryon_cluster> baryons_cluster, Int_t &nProt, Int_t &nBary0, Int_t &nLamb, Int_t &nSigm, Int_t &charge);
  Float_t CalculateClusterBindingEnergy(std::vector<PBaryon_cluster> baryons_cluster);
  void CalculateClusterKin(std::vector<PBaryon_cluster> baryons_cluster, Float_t &Px, Float_t &Py, Float_t &Pz, Float_t &energy);
  void GetClusterProcessId(std::vector<PBaryon_cluster> baryons_cluster, Int_t &processId);
  void CalculateClusterPos(std::vector<PBaryon_cluster> baryons_cluster, Float_t &X, Float_t &Y, Float_t &Z);
  void CalculateClusterProductionTime(Int_t clusterId, Int_t nbary, Float_t &TimeProductionCluster);
  void CalculateClusterFreezeOutTime(std::vector<PBaryon_cluster> baryons_cluster, Int_t nbary, Float_t TimeProductionCluster, Int_t &TsFreeze, Float_t &TimeFreezeCluster, Float_t &deltaT);
  void CalculateFreezeOutCoord(std::vector<PBaryon_cluster> baryons_cluster, Int_t nbary, Int_t TsFreeze,  Float_t TimeFreezeCluster, Float_t deltaT, TVector3 &posfo_cluster, TVector3 &pfo_cluster, Float_t &energyFreeze);

  TString fIndir = "";
  TString fDataset = "";

  TString finputFileInfo = "inputPHSD"	;	
  TString finputFileBulk = "phsd.dat";	
  TString finputFileBaryonFriga = "fort.891";
  TString finputFileBaryonFrigaAnti = "fort.881";
  TString finputFileBaryonFrigaUnstable = "fort.791";
  TString finputFileBaryonFrigaAntiUnstable = "fort.781";
  
  TString frootFileP =  "phqmd_out.root";
  TString frootFileDet;
  TString frootFileFreeze;
  TString fNameClustertable = "cluster_table.root";

  Bool_t fFreezeCoords;
  Bool_t fCreatePHQMDout;
  Bool_t fCreateOutWithUnstable;
  Bool_t fConvert;
  Int_t  fConvertMode;
  Bool_t fWriteUnigen;
  Bool_t fWriteEventFreeze;
  Bool_t fWriteEventFemto;
  Bool_t fConvertAnti;
  
  Float_t fEbin_max;
  Int_t fFirstEvent;
  map<int, vector<float>> feventId2time;

  TFile *foutputPHQMD;
  PRun *fpheader;
  PEventHadrons *feventH;
  PEventBaryons *feventB;
  TTree *ftreeH;
  TTree *ftreeB;

  map<int,int> feventId2EntryH;
  map<int,int[30]> feventId2EntryB;
  vector<map<int,int>> fbaryons2hadrons;
  vector<map<int,vector<int>>> fclusterId2baryonIds;

  std::vector<ClusterEntry> fclusterList;

};
#endif
