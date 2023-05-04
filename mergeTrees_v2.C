{
	// directory to search recursively (depth = 1 level)
	TString path = "/eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_v3";

	TList* lis = new TList();

	// Get folder list
	TSystemDirectory* mydir = new TSystemDirectory(path, path);
	TList* folderList = mydir->GetListOfFiles();

	for(auto folder_ : *folderList){
		TSystemFile* folder = dynamic_cast<TSystemFile*>(folder_); //couldn't cast directly in for loop

		// check for subfolders (excluding "..", ".")
		if(folder->IsDirectory() && folder->GetName() != string("..") && folder->GetName() != string(".")){
			std::cout << folder->GetName() << std::endl;

			// Get file list inside subfolder
			TString subfolder_dir = path + "/" + folder->GetName();
			TSystemDirectory* subfolder = new TSystemDirectory(subfolder_dir, subfolder_dir);
			TList* filelist = subfolder->GetListOfFiles();

			for(auto file_ : *filelist){
				TSystemFile* file = dynamic_cast<TSystemFile*>(file_);
				TString fname = file->GetName();
				std::cout << "	" << fname << std::endl;

				// if file is a root file, add to merge list
				if(fname.EndsWith(".root")){
				    TFile* tmpfile = TFile::Open(subfolder_dir + "/" + fname);
					lis->Add((TTree*)tmpfile->Get("nano_/tree"));
				}
			}

		}
	}

	// create output file
    TFile *ft = new TFile("DoubleMuTnp_v2.root","RECREATE");
    ft->mkdir("nano_");
    ft->cd("nano_");

	// merge, write and close
	TTree* mytree = TTree::MergeTrees(lis);
    mytree->SetName("tree");
    mytree->Write();

	ft->Close();
 
}


