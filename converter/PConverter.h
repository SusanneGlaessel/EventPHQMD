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
  Float_t fEnergy;
  Float_t fEbin;
  TLorentzVector fXTFreeze;
  TVector3 fPFreeze;
  Int_t fBaryonId;
  Int_t fClusterId;
  PBaryon_cluster(Int_t baryonId, Int_t PdgId, TVector3 P, Float_t energy, TLorentzVector XTFreeze, TVector3 PFreeze, Float_t Ebin) : fBaryonId(baryonId), fPdgId(PdgId), fP(P), fEnergy(energy), fXTFreeze(XTFreeze), fPFreeze(PFreeze), fEbin(Ebin) {};
};

  void Init(TString indir = "", TString dataset = "", Bool_t CreatePHQMDout = kTRUE, Bool_t FreezeCoords = kFALSE, Bool_t CreateOutWithUnstable = kFALSE, Bool_t Convert = kFALSE, Bool_t WriteUnigen = kTRUE, Bool_t ConvertMode = 0, Bool_t ConvertAnti = kTRUE, Bool_t WriteEventFreeze = kFALSE,  Int_t firstevent = 0);
  
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
  void InitConvert(Bool_t WriteUnigen = kTRUE, Bool_t WriteEventFreeze = kTRUE, Bool_t ConvertAnti = kTRUE);

  void ClusterTablePrint();
  void GetPdgIdBaryon(Int_t charge, Int_t &pdgId, Bool_t IsAnti);
  void GetClusterPdg(TTree * tClusterTable, std::vector<PBaryon_cluster> baryons_cluster, Int_t clusterId, Int_t &pdgIdCl);
  void GetBaryonContent(std::vector<PBaryon_cluster> baryons_cluster, Int_t &nProt, Int_t &nBary0, Int_t &nLamb, Int_t &nSigm, Int_t &charge);
  Float_t CalculateClusterBindingEnergy(std::vector<PBaryon_cluster> baryons_cluster);
  void CalculateClusterKin(std::vector<PBaryon_cluster> baryons_cluster, Float_t &Px, Float_t &Py, Float_t &Pz, Float_t &energy);
  void CalculateClusterFreezeOutTime(std::vector<PBaryon_cluster> baryons_cluster, Int_t nbary, Int_t &TsFreeze, Float_t &TimeFreezeCluster, Float_t &deltaT);
  void CalculateFreezOutCoord(std::vector<PBaryon_cluster> baryons_cluster, Int_t nbary, Int_t TsFreeze,  Float_t TimeFreezeCluster, Float_t deltaT, TVector3 &posfo_cluster, TVector3 &pfo_cluster);

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
  Bool_t fConvertAnti;
  
  Float_t fEbin_max;
  Int_t fFirstEvent;
  std::vector<float> fts_time;
  //Int_t fNTIME;

  TFile *foutputPHQMD;
  PRun *fpheader;
  PEventHadrons *feventH;
  PEventBaryons *feventB;
  TTree *ftreeH;
  TTree *ftreeB;

  std::map<int,int> feventId2EntryH;
  std::map<int,int[30]> feventId2EntryB;
  std::vector<std::map<int,int>> fbaryonId2pos;
  std::vector<std::map<int,int>> fbaryons2hadrons;
  std::vector<std::map<int,vector<int>>> fclusterId2baryonIds;

};
#endif
