{
	TList* lis = new TList();

	TTree* mytrees[8];
	TFile* files[8];

	for(int i = 0; i < 8; i++){
		files[i] = TFile::Open(TString::Format("/eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_2022D_v2/DoubleMuTnP_2022D_LowMass%i__v2.root", i));
		mytrees[i] = (TTree*)files[i]->Get("nano_/tree");
		lis->Add(mytrees[i]);
	}


	TFile *ft = new TFile("DoubleMuTnp.root","RECREATE");
	ft->mkdir("nano_");
	ft->cd("nano_");

	TTree* mytree = TTree::MergeTrees(lis);
	mytree->SetName("tree");
	mytree->Write();
	ft->Close();
	for(int i = 0; i < 8; i++) files[i]->Close();

}
