#!/bin/sh

echo "RunPHQMD root"
export runscript="runinfo_root.sh"
export SCRIPTDIR=$(pwd)
export PATH=$PATH:$SCRIPTDIR
export batchfile="batch_runPHQMD_root.sh"

. $SCRIPTDIR/$runscript

echo "Output will be written to: ${OUTDIR}"
echo "Lab energy is set to: ${ELAB} AGeV"

mkdir -p $OUTDIR
export LOGDIR=$OUTDIR"/log"
mkdir -p $LOGDIR

export OUTROOT=$OUTDIR/root
cp $SCRIPTDIR/$runscript $OUTDIR
cp $SCRIPTDIR"/runPHQMD_root.sh" $OUTDIR
cp $SCRIPTDIR/$batchfile $OUTDIR

if [ "$RunPhqmdCode" == 1 ]; then
    jobname=phqmd    
    echo "Run PHQMD code"
    cp $PHQMDDIR/phqmd_info $OUTDIR
fi

cd $SCRIPTDIR

if [ "$RunStabilisation" == 1 ]; then
    jobname=stab
    echo "Run Stabilisation"
    cp $SCRIPTDIR/791to891.f $OUTDIR
    export script_stab=791to891.exe
    cp $SCRIPTDIR/$script_stab $OUTDIR
fi

if [ "$ConvertToRoot" == 1 ]; then
    jobname=conv
    echo "Convert PHQMD output into root"
    export script_convert="convert_phqmd.C"
    mkdir -p $OUTROOT
    if [ "$ConvertToRoot" == 1 ]; then
	CLUSTERDIR=allclusters
    else
	CLUSTERDIR=smallclusters
    fi
    if [ "$WriteUnigen" == 1 ]; then
	mkdir -p $OUTROOT/unigen/$CLUSTERDIR
    fi
    if [ "$WriteFreeze" == 1 ]; then
	mkdir -p $OUTROOT/freeze/$CLUSTERDIR
    fi	

    cd $CONVERTDIR/macro
    cp $script_convert $OUTROOT
    cp cluster_table.dat $OUTROOT
    cd ../converter
    cp PConverter.cxx $OUTROOT 
   
    cd $SCRIPTDIR
fi

cd $SCRIPTDIR
sbatch --job-name=${jobname} --partition=${partition} --time=${time} --array=${array} -D $LOGDIR -o %a_%A.out.log -e %a_%A.err.log --export=ALL -- $batchfile
