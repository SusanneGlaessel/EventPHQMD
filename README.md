# EventPHQMD

## General information
EventPHQMD converts PHQMD output files into:
- a root-file containing all unconverted information from the PHQMD output (no clusters)
- a root-file containing full events with hadrons & clusters (UniGen format or root-format
including freeze-out momentum)

branch **main** is compatible with PHQMD version PHQMD41_2023 & PHQMD41_2023_Reduced

## Requirements

### Root
https://root.cern/install/

Root with c++17 standard is recommended.

UniGen classes are not required, they are part of the installation.

## Installation

Clone

	git clone --branch PHQMD52_Winn git@github.com:SusanneGlaessel/EventPHQMD

Set rootsource

	source path_to_root/bin/thisroot.sh

Install

	cd EventPHQMD
	mkdir build install
	cd build
	cmake -DCMAKE_INSTALL_PREFIX=../install ../
	make -j install

Load root libraries

	cd ../macro
	root -l rootlogon.C

The *path\_to\_installation* in macro/rootlogon.C needs to be replaced by the acutal
location of EventPHQMD:

	LINUX: gSystem->Load("path_to_installation/install/lib/libEventPHQMD.so");
	MAC:   gSystem->Load("path_to_installation/install/lib/libEventPHQMD.dylib");

## Run

Run macro:
 
	cd macro
	root -l convert_phqmd.C

 Input directory and options can be managed by the settings 
 (see explanation in macro):
    
	root -l convert_phqmd.C(TString indir, TString dataset,	Int_t firstevent,
			Bool_t CreatePHQMDout, Bool_t FreezeCoords, Bool_t CreateWithUnstable,
			Bool_t Convert, Bool_t ConvertAnti, Int_t ConvertMode, Bool_t WriteUnigen,
			Bool_t WriteEventFreeze, Bool_t SavePHQMDout)
 
 For the conversion of clusters the cluster_table.dat is required. It
 can be easily modified/extended. Each line contains the following
 information of the respective cluster:
 
	name / pdgcode / number of protons / number of neutral baryons /
	number of Lambdas / number of Simga0

