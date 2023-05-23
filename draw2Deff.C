void draw2Deff(string outpath, string inpath){
	TFile* f2D = TFile::Open(TString::Format("results%s/DoubleMu/egammaEffi.txt_EGM2D.root", inpath.c_str()), "read");

	TH2F* h2 = (TH2F*)f2D->Get("EGamma_EffData2D");
	
	int nbins_y = (inpath == "/vs_pt_deltaR") ? 4 : 2;
	
	// 1D vs pT efficiency plot
	std::string line;
	ifstream fpt(("results" + inpath + "/projPt/DoubleMu/egammaEffi.txt").c_str(), ios::in);
	std::vector<Double_t> pt_bin_center;
	std::vector<Double_t> pt_bin_center_err;
	std::vector<Double_t> pt_bin_eff;
	std::vector<Double_t> pt_bin_eff_err;
	std::vector<Double_t> pt_bin_mceff;
	std::vector<Double_t> pt_bin_mceff_err;
	std::vector<Double_t> pt_bin_alteff;
	std::vector<Double_t> pt_bin_alteff_err;

	Int_t dim1 = 0;
	for(int i = 0; i < 2; i++) std::getline(fpt, line); //read header
	
	while(std::getline(fpt, line)){
		dim1++;
		Double_t pt_min, pt_max;
		Double_t eta_min, eta_max;
		Double_t eff, eff_err;
		Double_t mceff, mceff_err;
		Double_t alteff, alteff_err;
		Double_t tmp;
		(stringstream)line >> eta_min >> eta_max >> pt_min >> pt_max >> eff >> eff_err >> mceff >> mceff_err >> tmp >> tmp >> alteff >> alteff_err >> tmp >> tmp;

		pt_bin_center.push_back((pt_min + pt_max)/2.);
		pt_bin_center_err.push_back((pt_max - pt_min)/2.);
		pt_bin_eff.push_back(eff);
		pt_bin_eff_err.push_back(eff_err);
		pt_bin_mceff.push_back(mceff);
		pt_bin_mceff_err.push_back(mceff_err);
		pt_bin_alteff.push_back(alteff);
		pt_bin_alteff_err.push_back(alteff_err);
	}

	// 1D vs eta efficiency
	ifstream feta((string("results") + inpath + "/projEta/DoubleMu/egammaEffi.txt").c_str(), ios::in);
	std::vector<Double_t> eta_bin_center;
	std::vector<Double_t> eta_bin_center_err;
	std::vector<Double_t> eta_bin_eff;
	std::vector<Double_t> eta_bin_eff_err;
	std::vector<Double_t> eta_bin_mceff;
	std::vector<Double_t> eta_bin_mceff_err;
	std::vector<Double_t> eta_bin_alteff;
	std::vector<Double_t> eta_bin_alteff_err;

	Int_t dim2 = 0;
	for(int i = 0; i < 2; i++) std::getline(feta, line); //read header
	Int_t nlines = inpath == "/vs_pt_deltaR" ? 4 : 2; //need to force stop after nbins bc of weird segfault [see settings file]

	while(std::getline(feta, line) && eta_bin_center.size() < nlines){
		dim2++;
		Double_t pt_min, pt_max;
		Double_t eta_min, eta_max;
		Double_t eff, eff_err;
		Double_t mceff, mceff_err;
		Double_t alteff, alteff_err;
		Double_t tmp;
		(stringstream) line >> eta_min >> eta_max >> pt_min >> pt_max >> eff >> eff_err >> mceff >> mceff_err >> tmp >> tmp >> alteff >> alteff_err >> tmp >> tmp;

		eta_bin_center.push_back((eta_min + eta_max)/2.);
		eta_bin_center_err.push_back((eta_max - eta_min)/2);
		eta_bin_eff.push_back(eff);
		eta_bin_eff_err.push_back(eff_err);
		eta_bin_mceff.push_back(mceff);
		eta_bin_mceff_err.push_back(mceff_err);
		eta_bin_alteff.push_back(alteff);
		eta_bin_alteff_err.push_back(alteff_err);
	}


	// 2D vs pT, eta
	ifstream fpteta(("results" + inpath + "/DoubleMu/egammaEffi.txt").c_str(), ios::in);
	std::vector<std::array<Double_t, 5>> pt_eta_point;
	std::vector<std::array<Double_t, 5>> pt_eta_mc_point;
	// std::vector<Double_t> pt_lowEta_bin_center;
	// std::vector<Double_t> pt_lowEta_bin_center_err;
	// std::vector<Double_t> pt_lowEta_bin_eff;
	// std::vector<Double_t> pt_lowEta_bin_eff_err;
	// std::vector<Double_t> pt_lowEta_bin_mceff;
	// std::vector<Double_t> pt_lowEta_bin_mceff_err;
	// std::vector<Double_t> pt_lowEta_bin_alteff;
	// std::vector<Double_t> pt_lowEta_bin_alteff_err;
	// std::vector<Double_t> pt_highEta_bin_center;
	// std::vector<Double_t> pt_highEta_bin_center_err;
	// std::vector<Double_t> pt_highEta_bin_eff;
	// std::vector<Double_t> pt_highEta_bin_eff_err;
	// std::vector<Double_t> pt_highEta_bin_mceff;
	// std::vector<Double_t> pt_highEta_bin_mceff_err;
	// std::vector<Double_t> pt_highEta_bin_alteff;
	// std::vector<Double_t> pt_highEta_bin_alteff_err;


	std::vector<std::vector<Double_t>> pt_ybin_bin_center;
	std::vector<std::vector<Double_t>> pt_ybin_bin_center_err;
	std::vector<std::vector<Double_t>> pt_ybin_bin_eff;
	std::vector<std::vector<Double_t>> pt_ybin_bin_eff_err;
	std::vector<std::vector<Double_t>> pt_ybin_bin_mceff;
	std::vector<std::vector<Double_t>> pt_ybin_bin_mceff_err;
	std::vector<std::vector<Double_t>> pt_ybin_bin_alteff;
	std::vector<std::vector<Double_t>> pt_ybin_bin_alteff_err;

	for(int i = 0; i < 2; i++) std::getline(fpteta, line); //read header

	int counter = 0;

	for(int i = 0; i < nbins_y; i++){
		pt_ybin_bin_center.push_back(std::vector<Double_t>());
		pt_ybin_bin_center_err.push_back(std::vector<Double_t>());
		pt_ybin_bin_eff.push_back(std::vector<Double_t>());
		pt_ybin_bin_eff_err.push_back(std::vector<Double_t>());
		pt_ybin_bin_mceff.push_back(std::vector<Double_t>());
		pt_ybin_bin_mceff_err.push_back(std::vector<Double_t>());
		pt_ybin_bin_alteff.push_back(std::vector<Double_t>());
		pt_ybin_bin_alteff_err.push_back(std::vector<Double_t>());
	}

	while(std::getline(fpteta, line)){
		Double_t pt_min, pt_max;
		Double_t eta_min, eta_max;
		Double_t eff, eff_err;
		Double_t mceff, mceff_err;
		Double_t alteff, alteff_err;
		Double_t tmp;
		(stringstream)line >> eta_min >> eta_max >> pt_min >> pt_max >> eff >> eff_err >> mceff >> mceff_err >> tmp >> tmp >> alteff >> alteff_err >> tmp >> tmp;

		// if(counter % 2 == 0){
		// 	pt_lowEta_bin_center.push_back((pt_min + pt_max)/2.);
		// 	pt_lowEta_bin_center_err.push_back((pt_max - pt_min)/2.);
		// 	pt_lowEta_bin_eff.push_back(eff);
		// 	pt_lowEta_bin_eff_err.push_back(eff_err);
		// 	pt_lowEta_bin_mceff.push_back(mceff);
		// 	pt_lowEta_bin_mceff_err.push_back(mceff_err);
		// 	pt_lowEta_bin_alteff.push_back(alteff);
		// 	pt_lowEta_bin_alteff_err.push_back(alteff_err);
		// } else {
		// 	pt_highEta_bin_center.push_back((pt_min + pt_max)/2.);
		// 	pt_highEta_bin_center_err.push_back((pt_max - pt_min)/2.);
		// 	pt_highEta_bin_eff.push_back(eff);
		// 	pt_highEta_bin_eff_err.push_back(eff_err);
		// 	pt_highEta_bin_mceff.push_back(mceff);
		// 	pt_highEta_bin_mceff_err.push_back(mceff_err);
		// 	pt_highEta_bin_alteff.push_back(alteff);
		// 	pt_highEta_bin_alteff_err.push_back(alteff_err);
		// }

		pt_ybin_bin_center[counter % nbins_y].push_back((pt_min + pt_max)/2.);
		pt_ybin_bin_center_err[counter % nbins_y].push_back((pt_max - pt_min)/2.);
		pt_ybin_bin_eff[counter % nbins_y].push_back(eff);
		pt_ybin_bin_eff_err[counter % nbins_y].push_back(eff_err);
		pt_ybin_bin_mceff[counter % nbins_y].push_back(mceff);
		pt_ybin_bin_mceff_err[counter % nbins_y].push_back(mceff_err);
		pt_ybin_bin_alteff[counter % nbins_y].push_back(alteff);
		pt_ybin_bin_alteff_err[counter % nbins_y].push_back(alteff_err);

		counter++;

		pt_eta_point.push_back({(pt_min + pt_max)/2., (pt_max - pt_min)/2., (eta_max + eta_min)/2., (eta_max - eta_min)/2., alteff});
		pt_eta_mc_point.push_back({(pt_min + pt_max)/2., (pt_max - pt_min)/2., (eta_max + eta_min)/2., (eta_max - eta_min)/2., mceff});
	}

	
	// restrict to 1 eta bin only (for analysis cutting on eta)
	if(inpath == "/muons_L1cuts") dim2 = 1;

	/*** NOMINAL FIT ***/

	// Creating TGraphs for efficiency
	auto gpt = new TGraphErrors(dim1, &pt_bin_center[0], &pt_bin_eff[0], &pt_bin_center_err[0], &pt_bin_eff_err[0]);
	auto geta = new TGraphErrors(dim2, &eta_bin_center[0], &eta_bin_eff[0], &eta_bin_center_err[0], &eta_bin_eff_err[0]);

	// changing graph style
	TGraphErrors* graphlist[2] = {gpt, geta};
	for(TGraphErrors* graph : graphlist){
		graph->SetMarkerStyle(8);
	}

	gROOT->SetBatch(kTRUE);
	gStyle->SetOptStat(0);

	// PLOTTING
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
	geta->GetYaxis()->SetRangeUser(.5, 1);
	geta->Draw("AP");

	pad_top->cd();
	gpt->SetTitle("Efficiency vs p_{T};p_{T} [GeV];Efficiency");
	gpt->Draw("AP");
	gpt->GetYaxis()->SetRangeUser(.5, 1);
	gpt->GetXaxis()->SetRangeUser(2., 40);

	c1->SaveAs((outpath + "/data_2D_efficiency.pdf").c_str());


	/*** ALT SIG FIT ***/

	// define 1D graphs (MC, data)
	auto mc_gpt = new TGraphErrors(dim1, &pt_bin_center[0], &pt_bin_mceff[0], &pt_bin_center_err[0], &pt_bin_mceff_err[0]);
	auto mc_geta = new TGraphErrors(dim2, &eta_bin_center[0], &eta_bin_mceff[0], &eta_bin_center_err[0], &eta_bin_mceff_err[0]);

	auto alt_gpt = new TGraphErrors(dim1, &pt_bin_center[0], &pt_bin_alteff[0], &pt_bin_center_err[0], &pt_bin_alteff_err[0]);
	auto alt_geta = new TGraphErrors(dim2, &eta_bin_center[0], &eta_bin_alteff[0], &eta_bin_center_err[0], &eta_bin_alteff_err[0]);

	// define 1D graph for low/high eta 
	// auto alt_gpt_lowEta = new TGraphErrors(dim1, &pt_lowEta_bin_center[0], &pt_lowEta_bin_alteff[0], &pt_lowEta_bin_center_err[0], &pt_lowEta_bin_alteff_err[0]);
	// auto alt_gpt_highEta = new TGraphErrors(dim1, &pt_highEta_bin_center[0], &pt_highEta_bin_alteff[0], &pt_highEta_bin_center_err[0], &pt_highEta_bin_alteff_err[0]);

	// auto mc_gpt_lowEta = new TGraphErrors(dim1, &pt_lowEta_bin_center[0], &pt_lowEta_bin_mceff[0], &pt_lowEta_bin_center_err[0], &pt_lowEta_bin_mceff_err[0]);
	// auto mc_gpt_highEta = new TGraphErrors(dim1, &pt_highEta_bin_center[0], &pt_highEta_bin_mceff[0], &pt_highEta_bin_center_err[0], &pt_highEta_bin_mceff_err[0]);

	std::vector<TGraphErrors*> alt_gpt_ybin;
	std::vector<TGraphErrors*> mc_gpt_ybin;
	for(int i = 0; i < nbins_y; i++){
		alt_gpt_ybin.push_back(new TGraphErrors(dim1, &pt_ybin_bin_center[i][0], &pt_ybin_bin_alteff[i][0], &pt_ybin_bin_center_err[i][0], &pt_ybin_bin_alteff_err[i][0]));
		mc_gpt_ybin.push_back(new TGraphErrors(dim1, &pt_ybin_bin_center[i][0], &pt_ybin_bin_mceff[i][0], &pt_ybin_bin_center_err[i][0], &pt_ybin_bin_mceff_err[i][0]));
	}

	// auto alt_gpt_lowEta = new TGraphErrors(dim1, &pt_lowEta_bin_center[0], &pt_lowEta_bin_alteff[0], &pt_lowEta_bin_center_err[0], &pt_lowEta_bin_alteff_err[0]);
	// auto alt_gpt_highEta = new TGraphErrors(dim1, &pt_highEta_bin_center[0], &pt_highEta_bin_alteff[0], &pt_highEta_bin_center_err[0], &pt_highEta_bin_alteff_err[0]);

	// auto mc_gpt_lowEta = new TGraphErrors(dim1, &pt_lowEta_bin_center[0], &pt_lowEta_bin_mceff[0], &pt_lowEta_bin_center_err[0], &pt_lowEta_bin_mceff_err[0]);
	// auto mc_gpt_highEta = new TGraphErrors(dim1, &pt_highEta_bin_center[0], &pt_highEta_bin_mceff[0], &pt_highEta_bin_center_err[0], &pt_highEta_bin_mceff_err[0]);


	
	// define 2D histogram for MC, alt sig

	// Data
	std::vector<Double_t> pts;
	std::vector<Double_t> etas;
	std::vector<Double_t> effs;
	std::vector<Double_t> pt_low;
	std::vector<Double_t> eta_low;
	int idx = 0;
	for(auto arr : pt_eta_point){
		if(idx % nbins_y == 0) pt_low.push_back(arr[0] - arr[1]);
		if(idx < nbins_y) eta_low.push_back(arr[2] - arr[3]);

		pts.push_back(arr[0]);
		etas.push_back(arr[2]);
		effs.push_back(arr[4]);
		idx++;
	}

	pt_low.push_back(pt_eta_point.back()[0] + pt_eta_point.back()[1]); //add last bin upper bound
	eta_low.push_back(pt_eta_point.back()[2] + pt_eta_point.back()[3]); //same


	TH2D* alt_hpteta = new TH2D("alt_hpteta", "alt_hpteta", dim1, &pt_low[0], dim2, &eta_low[0]); //define binning
	alt_hpteta->FillN(effs.size(), &pts[0], &etas[0], &effs[0]); //actually fill histogram


	// MC
	std::vector<Double_t> pts_mc;
	std::vector<Double_t> etas_mc;
	std::vector<Double_t> effs_mc;
	idx = 0;
	for(auto arr : pt_eta_mc_point){
		pts_mc.push_back(arr[0]);
		etas_mc.push_back(arr[2]);
		effs_mc.push_back(arr[4]);
		idx++;
	}

	TH2D* mc_hpteta = new TH2D("mc_hpteta", "mc_hpteta", dim1, &pt_low[0], dim2, &eta_low[0]); //define binning
	mc_hpteta->FillN(effs_mc.size(), &pts_mc[0], &etas_mc[0], &effs_mc[0]); //actually fill histogram
	

	// PLOTTING
	string plotvar = (inpath == "/vs_pt_deltaR") ? "#DeltaR" : "#eta";

	// changing graph style
	TGraphErrors* alt_graphlist[2] = {alt_gpt, alt_geta};
	for(TGraphErrors* graph : alt_graphlist){
		graph->SetMarkerStyle(8);
	}

	TCanvas* c2 = new TCanvas("ceff2d_altsig", "ceff2d_altsig", 3000, 2000);
	c2->Divide(3,2);

	// data
	c2->cd(1);
	alt_hpteta->SetTitle(TString::Format("[DATA] Efficiency vs p_{T}, %s;p_{T};%s", plotvar.c_str(), plotvar.c_str()));
    gPad->SetLogx();
	alt_hpteta->Draw("colz text45");
	// alt_hpteta->GetXaxis()->SetRangeUser(0, 20);
	// alt_hpteta->GetYaxis()->SetRangeUser(0, 2.6);

	c2->cd(2);
	alt_geta->SetTitle(TString::Format("[DATA] Efficiency vs %s;%s;Efficiency", plotvar.c_str(), plotvar.c_str()));
	alt_geta->Draw("AP");
	alt_geta->GetYaxis()->SetRangeUser(0, 1.02);

	c2->cd(3);
 	alt_gpt->SetTitle("[DATA] Efficiency vs p_{T};p_{T} [GeV];Efficiency");
	alt_gpt->Draw("AP PMC PLC");
	alt_gpt->GetXaxis()->SetRangeUser(2., 40);
	alt_gpt->GetYaxis()->SetRangeUser(0, 1.02);

	auto leg1 = new TLegend();
	leg1->AddEntry(alt_gpt, TString::Format("%s-integrated", plotvar.c_str()), "pl");

	if(inpath != "/muons_L1cuts"){
		for(int i = 0; i < nbins_y; i++){
			alt_gpt_ybin[i]->Draw("SAMES PMC PLC");
			leg1->AddEntry(alt_gpt_ybin[i], TString::Format("%.1f < %s < %.1f", eta_low[i], plotvar.c_str(), eta_low[i+1]), "pl");
		}
		leg1->Draw();
	}


	// MC
	c2->cd(4);
	mc_hpteta->SetTitle(TString::Format("[MC] Efficiency vs p_{T}, %s;p_{T};%s", plotvar.c_str(), plotvar.c_str()));
    gPad->SetLogx();
	mc_hpteta->Draw("colz text45");

	c2->cd(5);
	mc_geta->SetTitle(TString::Format("[MC] Efficiency vs %s;%s;Efficiency", plotvar.c_str(), plotvar.c_str()));
	mc_geta->Draw("AP");
	mc_geta->GetYaxis()->SetRangeUser(0, 1.02);

	c2->cd(6);
 	mc_gpt->SetTitle("[MC] Efficiency vs p_{T};p_{T} [GeV];Efficiency");
	mc_gpt->Draw("AP PLC");
	mc_gpt->GetXaxis()->SetRangeUser(2., 40);
	mc_gpt->GetYaxis()->SetRangeUser(0, 1.02);


	auto leg2 = new TLegend();
	leg2->AddEntry(mc_gpt, TString::Format("%s-integrated", plotvar.c_str()), "pl");

	if(inpath != "/muons_L1cuts"){		
		for(int i = 0; i < nbins_y; i++){
			mc_gpt_ybin[i]->Draw("SAMES PMC PLC");
			leg2->AddEntry(mc_gpt_ybin[i], TString::Format("%.1f < %s < %.1f", eta_low[i], plotvar.c_str(), eta_low[i+1]), "pl");
		}
		leg2->Draw();
	}

	c2->SaveAs((outpath + "/altSig_data_2D_efficiency.pdf").c_str());
}
