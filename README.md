# EventPHQMD

## General information
EventPHQMD converts PHQMD output files into:
- a root-file containing all unconverted information from the PHQMD output (no clusters)
- a root-file containing full events with hadrons & clusters (UniGen format or root-format
including freeze-out momentum)

branch **PHQMD52 _Winn** is compatible with PHQMD version PHQMD52-Winn_2023

## Requirements

### Root
https://root.cern/install/

Root with c++17 standard is strongly recommended.

UniGen classes are not required, they are part of the installation.

## Installation

Set rootsource

	source ROOTSOURCE/bin/thisroot.sh

Install

	mkdir build install
	cd build
	cmake -DCMAKE_INSTALL_PREFIX=../install ../
	make -j install

Load root libraries

Path in rootlogon.C needs to be set to current directory:

- for LINUX:

gSystem->Load("path\_to\_EventPHQMD/install/lib/libEventPHQMD.dylib");

- for MAC:

gSystem->Load("path\_to\_EventPHQMD/install/lib/libEventPHQMD.so");

	cd ../macro
	root -l rootlogon.C

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
 
 For the conversion of clusters the cluster_table.root is required.
 
 To make changes in the cluster\_table.root, update cluster\_table.dat and run

	cd macro
	root -l write_clustertree.C
