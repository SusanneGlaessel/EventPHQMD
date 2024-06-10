# EventPHQMD

## General information
EventPHQMD converts PHQMD output files:
- creates root-file containing all unconverted information from the PHQMD output
- converts PHQMD output into complete events with hadrons & clusters (UniGen format
  or root-format including freeze-out momentum) 

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
 cd ../macro
 root -l rootlogon.C

## Run

Run macro:
 
 cd macro

 root convert_phqmd.C

 Input directory and options can be managed by the settings 
 (see explanation in macro):

 root convert_phqmd.C'(indir, dataset, firstevent, CreatePHQMDout, FreezeCoords, 
                      CreateWithUnstable, Convert, ConvertAnti, ConvertMode, 
                      WriteUnigen, WriteEventFreeze, SavePHQMDout)'
 
 For the conversion of clusters the cluster_table.root is required.
