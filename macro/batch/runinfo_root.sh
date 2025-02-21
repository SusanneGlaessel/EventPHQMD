#!/bin/bash

###############################################################
## Options for running PHQMD code, stabilisation & conversion #

## Steps:
export RunPhqmdCode=0           ## = 1: run PHQMD code - input: inputPHSD, output: phsd.dat (hadrons), fort.791 (cluster-baryons), fort.891 (anti-cluster-baryons)
export RunStabilisation=0       ## = 1: run stabilisation routine - input: fort.791 & fort.781, output: fort.891 & fort.881
export ConvertToRoot=1          ## = 1: run conversion of PHQMD output into root & detector input - input: fort.891 & fort.881, output: root & unigen format

## Options for steps:
export ConvertAntiClusters=1    ## = 0: convert/stablise only clusters, = 1: convert clusters and anti-clusters

## Options for step "ConvertToRoot" - input:
export CreateRoot=1             ## = 0: root file already exists, UniGen or format containing freeze-out momentum will be created from root file, = 1: root file containing all the information from the PHQMD output files will be created
export FreezeCoords=0           ## = 0: PHQMD output is containing freeze-out coordinates (!needs to be changed in PHQMD code!)

## Options for step "ConvertToRoot" - conversion:
export Convert=1                ## = 1: convert output into full event with clusters (from root file - needs to be created before)
export CountAllClusters=1       ## = 0: only physical clusters are counted (unphysical clusters are counted as single baronys), = 1: all clusters are counted
export CreateUnstab=1           ## = 1: create root file including unstable clusters before stabilisation (from fort.791 & fort.781)

## Options for step "ConvertToRoot" - output formats:
export WriteUnigen=1            ## = 1: save full event in UniGen-format
export WriteFreeze=0            ## = 0: save full event in format containing freeze-out momentum (only with FreezeCoords=1)
export SaveRoot=1               ## = 1: keep root file with all information from PHQMD output

###############################################################
## Parameters for sbatch ######################################

export firstJob=1
export lastJob=1
export array=$firstJob-$lastJob
export last_hadd=$(printf "%0.0f" "$(echo " $lastJob / 100  " | bc -l)")
export array_hadd=1-$last_hadd
export array_hadd=1
export last_hadd_simcbm=$(printf "%0.0f" "$(echo " $lastJob / 10  " | bc -l)")
export array_hadd_simcbm=$firstJob-$last_hadd_simcbm
export time="7:59:59"
export partition="main"

###############################################################
## Parameters for inputPHSD (more parameters availabe, but should usually not be changed)

export SYSTEM=auau              ## specification below for auau, pbpb, aupb, aupt - other systems need to be added below
export ENERGY=4.93              ## center of mass energy - !for sqrt(s) > 6 GeV setting for kinetic deuterons in PHQMD code should be changed! 
export ELAB=$(echo " $ENERGY * $ENERGY / (2 * 0.938) - (2 * 0.938)" | bc -l)  ##  Lab energy per nucleon (needed for PHQMD)
export NUM=100                  ## number of parallel events (NUM=100 for 3 GeV & 4.9 GeV required)
export ISUBS=1                  ## number of subsequent runs
export nEvents=$(echo " $NUM * $ISUBS " | bc -l)

export IMPACTPARAMETER_MIN=0.0  ## minimal impact parameter in fm
export IMPACTPARAMETER_MAX=15.0 ## maximum impact parameter in fm ! Max impact parameter must not be > 15.0 fm !

export IGLUE=1                  ## =1 with partonic QGP phase (PHSD mode); =0 - HSD mode ! Needs to be set to = 0 for 3 GeV
export EOS=0                    ## EoS; =0: hard EOS without M.D.I; =1 soft EoS; =2 soft EoS with mom. dependence 
export ICLUSTER=1               ## enable or disable CLUSTER output

##############################################################
#############  Directories and files #########################
    
export version_phqmd=phqmd52_winn
export LOCATION=/lustre
export DIR=$LOCATION/cbm/users/$USER
export PHQMDDIR=$DIR/$version_phqmd                                        ## path to PHQMD installation
export CONVERTDIR=/lustre/cbm/users/$USER/EventPHQMD                       ## path to local installation of EventPHQMD
export ROOT_SOURCE=/cvmfs/fairsoft.gsi.de/debian11/fairsoft/nov22p1/bin    ## path to root installation (UniGen classes are not required)    
export OUTDIR=$DIR/mc/$version_phqmd/$SYSTEM"_"$ENERGY"GeV_"$IMPACTPARAMETER_MAX"fm_Num"$NUM"xSub"$ISUBS"_EoS"$EOS

##############################################################
############### Specify collision system #####################

if [[ $SYSTEM == "auau" ]] ; then
    export MASSTA=197
    export MSTAPR=79
    export MASSPR=$MASSTA
    export MSPRPR=$MSTAPR
fi

if [[ $SYSTEM == "pbpb" ]] ; then
    export MASSTA=208
    export MSTAPR=82
    export MASSPR=$MASSTA
    export MSPRPR=$MSTAPR
fi

if [[ $SYSTEM == "aupb" ]] ; then
    export MASSTA=208
    export MSTAPR=82
    export MASSPR=197
    export MSPRPR=79
fi

if [[ $SYSTEM == "aupt" ]] ; then                                                                                                           
    export MASSTA=195                                                                                                                       
    export MSTAPR=78                                                                                                                        
    export MASSPR=197                                                                                                                       
    export MSPRPR=79                                                                                                                        
fi




