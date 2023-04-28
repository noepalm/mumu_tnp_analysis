void draw2Deff(const char* outpath){
	TFile* f2D = TFile::Open("results/muons/DoubleMu/egammaEffi.txt_EGM2D.root", "read");
	TH2F* h2 = (TH2F*)f2D->Get("EGamma_EffData2D");
	
	
	// retrieve 1D efficiency plot from .tx
	std::string line;
	ifstream fpt("results/muons/projPt/DoubleMu/egammaEffi.txt", ios::in);
	std::vector<Double_t> pt_bin_center;
	std::vector<Double_t> pt_bin_center_err;
	std::vector<Double_t> pt_bin_eff;
	std::vector<Double_t> pt_bin_eff_err;

	Int_t dim1 = 0;
	for(int i = 0; i < 2; i++) std::getline(fpt, line); //read header
	
	while(std::getline(fpt, line)){
		dim1++;
		Double_t pt_min, pt_max;
		Double_t eta_min, eta_max;
		Double_t eff, eff_err;
		Double_t tmp;
		(stringstream)line >> eta_min >> eta_max >> pt_min >> pt_max >> eff >> eff_err >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp;

		pt_bin_center.push_back((pt_min + pt_max)/2.);
		pt_bin_center_err.push_back(0);
		pt_bin_eff.push_back(eff);
		pt_bin_eff_err.push_back(eff_err);
	}


	ifstream feta("results/muons/projEta/DoubleMu/egammaEffi.txt", ios::in);
	std::vector<Double_t> eta_bin_center;
	std::vector<Double_t> eta_bin_center_err;
	std::vector<Double_t> eta_bin_eff;
	std::vector<Double_t> eta_bin_eff_err;

	Int_t dim2 = 0;
	for(int i = 0; i < 2; i++) std::getline(feta, line); //read header
	
	while(std::getline(feta, line)){
		dim2++;
		Double_t pt_min, pt_max;
		Double_t eta_min, eta_max;
		Double_t eff, eff_err;
		Double_t tmp;
		(stringstream) line >> eta_min >> eta_max >> pt_min >> pt_max >> eff >> eff_err >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp;

		eta_bin_center.push_back((eta_min + eta_max)/2.);
		eta_bin_center_err.push_back(0);
		eta_bin_eff.push_back(eff);
		eta_bin_eff_err.push_back(eff_err);
	}


	// Creating TGraphs for efficiency

	auto gpt = new TGraphErrors(dim1, &pt_bin_center[0], &pt_bin_eff[0], &pt_bin_center_err[0], &pt_bin_eff_err[0]);
	auto geta = new TGraphErrors(dim2, &eta_bin_center[0], &eta_bin_eff[0], &eta_bin_center_err[0], &eta_bin_eff_err[0]);


	
	// PLOTTING

	// changing graph style
	TGraphErrors* graphlist[2] = {gpt, geta};
	for(TGraphErrors* graph : graphlist){
		graph->SetMarkerStyle(8);
	}

	
	TCanvas* c1 = new TCanvas("ceff2d", "ceff2d", 1500, 1000);

	TPad* pad_center = new TPad("pad_center", "pad_center", 0, .3, .7, 1);
	TPad* pad_bottom = new TPad("pad_bottom", "pad_bottom", 0, 0, .7, .3);
	TPad* pad_top = new TPad("pad_top", "pad_top", .7, .3, 1, 1);
	
	pad_center->Draw();
	pad_bottom->Draw();
	pad_top->Draw();

	pad_center->cd();
	h2->Draw("colz TEXT");
	pad_center->SetLogy();

	pad_bottom->cd();
	geta->SetTitle("Efficiency vs #eta;#eta;Efficiency");
	geta->Draw("AP");

	pad_top->cd();
	gpt->SetTitle("Efficiency vs p_{T};p_{T} [GeV];Efficiency");
	gpt->Draw("AP");
	gpt->GetYaxis()->SetRangeUser(.8, 1.1);
	gpt->GetXaxis()->SetRangeUser(2., 12);

	c1->SaveAs(outpath + "/" + TString("data_2D_efficiency.pdf"));

}
