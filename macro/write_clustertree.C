// --------------------------------------------------------------------------
/** author: Susanne Glaessel (Universitaet Frankfurt)
 ** Macro for writing a TTree from cluster_table.dat which is needed as input for the 
 ** conversion of the PHQMD output.
 ** Entries in cluster_table.dat:
 ** name | pdg-code | nof protons | nof baryons with charge = 0 | nof lambdas | nof sigma0
*/
// --------------------------------------------------------------------------

void write_clustertree(TString indir="", TString outdir="")
{
 
  Int_t pdgId;
  Int_t nProt;
  Int_t nNeut;
  Int_t nLamb;
  Int_t nSigm;  
  char clustername [80];
    
  TString infile =  Form("%s/cluster_table.dat",indir.Data());
  TString outfile = Form("%s/cluster_table.root",outdir.Data());
  
  FILE *fClusterTable;
  fClusterTable = fopen(infile, "r");
  
  TFile *hClusterTable= new TFile(outfile,"RECREATE");
  TTree *tClusterTable = new TTree("ClusterTable","ClusterTable");

  tClusterTable->Branch("clustername",&clustername,"clustername/C");
  tClusterTable->Branch("pdgId",&pdgId,"pdgId/I");

  tClusterTable->Branch("nProt",&nProt,"nProt/I");
  tClusterTable->Branch("nNeut",&nNeut,"nNeut/I");
  tClusterTable->Branch("nLamb",&nLamb,"nLamb/I");
  tClusterTable->Branch("nSigm",&nSigm,"nSigm/I");

  Int_t num=1;
  while(1) {
    if (fscanf(fClusterTable, "%s %i %i %i %i %i\n", clustername, &pdgId, &nProt, &nNeut, &nLamb, &nSigm)==EOF) break;
    tClusterTable->Fill();
    printf ("%-12.11s pdgId = %12d\n", clustername, pdgId);
    num++;
  }

  tClusterTable->Write();
  hClusterTable->Close();
  fclose(fClusterTable);
  return 0;
}
