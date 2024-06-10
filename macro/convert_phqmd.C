//************************************************************************************************************************************************
/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Macro for creating a root-file from all PHQMD output files and/or a UniGen-file  
 ** with complete events (or root-file with with freeze-out coordinates)
 ** 
 ** This macro:
 **
 ** 1) copies the information from all PHQMD output-files after stabilization into a 
 **    single root-file containing all information from the PHQMD-files.
 **    Output: [dataset].phqmd_out.root
 **
 ** and/or
 **   
 ** 2) converts* the PHQMD output after stabilization into complete events with 
 **    hadrons and clusters and stores them in:
 **    a) UniGen format including the FREEZEOUT-TIME & -POSITION. The UniGen-output 
 **       can be selected with the flag: WriteUnigen = kTRUE.
 **       Output:
 **       - for clusters & anticlusters: [dataset].phqmd.root
 **       - for clusters only**: [dataset].phqmd_noanti.root
 **    b) root-file with complete events including the FREEZEOUT-TIME, -POSITION &  
 **       -MOMENTUM (EventFreeze). 
 **       Output: 
 **       - for clusters & anticlusters: [dataset].phqmd_freeze.root
 **       - for clusters only**: [dataset].phqmd_freeze_noanti.root
 **
 ** * In PHQMD clusters / anticlusters are recognised independently of their physical 
 ** existence. The cluster-baryons are listed separately in the outputfile. This 
 ** routine builds clusters from the single baryons based on their cluster-ID and 
 ** identifies physical clusters according to the cluster_table.root. Baryons from 
 ** unphysical clusters (eg. p-p) are counted as single baryons (see options below).
 **
 ** ** PHQMD writes baryons and anti-baryons into two separate files. The conversion 
 ** of anti-baryons is optional and can be switched off with option 
 ** ConvertAnti = kFALSE.
 **
 ** PHQMD outputfiles are: 
 ** inputPHSD           : input information for PHQMD simulation
 ** fort.891            : baryons that are entering the cluster routine  
 **                       (for every timestep)
 ** fort.881 (optional) : antibaryons that are entering the cluster routine 
 ** phsd.dat            : hadrons (at last timestep)
 ** cluster_table.root  : contains a list with nuclei & hypernuclei with up to 
 **                       9 baryons with their baryon content for the 
 **                       identification of physical clusters
 ** 
 ** The conversion can be done from the PHQMD output files or from the single 
 ** root-file [dataset].phqmd_out.root.
 **
 **
 ** Options:
 ** ----------------------------------------------------------------------------------
 ** FreezeCoords        : PHQMD input contains freezeout coordinates  
 ** AntiBaryons         : Include anti-baryons in output (from fort.881 / fort.781)    
 ** CreatePHQMDout      : Create single root-file from PHQMD output files
 ** CreateWithUnstable  : Include PHQMD output before stabilisation 
 **                       (from fort.791 & fort.781) into root-file
 ** Convert             : Convert PHQMD output into complete events with clusters
 ** ConvertMode         : = 0: Conversion of physical clusters according to cluster 
 **                            table
 **                       = 1: Same as "0" for A < 8, for A > 7 conversion of 
 **                            all clusters         
 ** WriteUnigen         : Converted output is written in UniGen format 
 ** WriteEventFreeze    : Converted output is written in root format including freeze- 
 **                       out momentum
 ** SavePHQMDout        : Root-file containg PHQMD output is kept.
 ** ----------------------------------------------------------------------------------
 ** 
 ** Deuterons are not only produced with the MST-algorithm, but also through kinetic
 ** interactions. The information of the origin can be taken from the UniGen-output:
 ** UParticle* particle -> GetStatus(): = 0 kinetic deuteron, = 1 MST deuteron.
 **
 ** Inputfiles need to be from PHQMD MST-mode.
 **/             

#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include "TString.h"
#include "TNamed.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TTree.h"

void convert_phqmd(TString indir             = "",
		   //TString dataset           = "00001",
		   TString dataset           = "",
		   Int_t  firstevent         = 0,
		   Bool_t CreatePHQMDout     = kTRUE,
		   Bool_t FreezeCoords       = kTRUE,
		   Bool_t CreateWithUnstable = kFALSE,
		   Bool_t Convert            = kTRUE,
		   Int_t  ConvertMode        = 1,
		   Bool_t ConvertAnti        = kTRUE,
		   Bool_t WriteUnigen        = kTRUE,
		   Bool_t WriteEventFreeze   = kTRUE,
		   Bool_t SavePHQMDout       = kTRUE)
{
  PConverter* pconverter = new PConverter();
  pconverter->Init(indir, dataset, CreatePHQMDout, FreezeCoords, CreateWithUnstable, Convert, ConvertMode, ConvertAnti, WriteUnigen, WriteEventFreeze, firstevent);

  if (CreatePHQMDout == kTRUE) {  
    pconverter->OpenPHQMDoutCreate();
    pconverter->CreatePHeader();
    pconverter->CreatePEventsHadrons();
    pconverter->CreatePEventsBaryons();
    if (CreateWithUnstable == kTRUE)
      pconverter->CreatePEventsBaryons(CreateWithUnstable);
    pconverter->WritePHQMDout();
    pconverter->ClosePHQMDout();
  }

  if (Convert == kTRUE) {
    pconverter->OpenPHQMDoutRead();
    pconverter->MakeMaps();
    pconverter->ConvertPHQMD();
    pconverter->ClosePHQMDout();
  }

  if (SavePHQMDout == kFALSE) pconverter->RemovePHQMDout();   //Remove root file with unconverted PHQMD output
}
  
  
