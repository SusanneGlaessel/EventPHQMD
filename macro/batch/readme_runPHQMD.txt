RUNNING & CONVERTING PHQMD

3 steps are required:

1) run the PHQMD code
2) stabilize the cluster output
3) write the PHQMD-output into root-format and/or convert into full event - detector-input 
(UniGen format) and/or format including freeze-out momentum

All 3 steps are performed with the batch-script. Single steps can be switched on or off. 

The following files are needed (besides the PHQMD code & EventPHQMD):

- runinfo_root.sh
- runPHQMD_root.sh
- batch_runPHQMD_root.sh
- 791to891.exe*

Only runinfo_root.sh needs to be modified:

- selection of steps
- options for conversion to root & UniGen**
- select input information for PHQMD, e.g system, energy, number of parallel events,
impactparamter etc. 
- location information

* Stabilisation: 791to891.exe converts fort.791 (fort.781) into fort.891 (fort.881) which
considers a clusters as stable when the cluster-baryons are freezed out (and if it has a 
negative binding energy).

** Conversion: EventPHQMD writes the raw information from the PHQMD outputfiles into a root
format for storage and creates a full event as the detector input (UniGen) and/or a writes 
the full event into a format containing the freeze-out momentum .

In PHQMD clusters / anticlusters are recognised independently of their physical
existence. The cluster-baryons are listed separately in the outputfile. This routine
builds clusters from the single baryons based on their cluster-ID and identifies physical
clusters according to the cluster_table.root. Baryons from unphysical clusters (eg. p-p)
are counted as single baryons. With option "CountAllClusters" all clusters with size A > 7 
are counted as clusters independent of their physical existence.

The cluster_table.dat contains the information about physical clusters and their
baryon content. It is required to perform the conversion and can be easily 
modified/extended. Each line contains the following information of the respective cluster:
>> name / pdgcode / number of protons / number of neutral baryons / number of Lambdas 
>> / number of Simga0

PHQMD writes baryons and anti-baryons into two separate files. The conversion
of anti-baryons is optional and can be switched off.

For questions, please contact glaessel@ikf.uni-frankfurt.de

