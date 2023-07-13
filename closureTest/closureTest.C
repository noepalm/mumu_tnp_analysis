#define Events_cxx
#include <TH2.h>
#include <TH1.h>
#include <TMath.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TPaveStats.h>
#include <TPaveText.h>
#include <TPad.h>
#include <TLegend.h>
#include <TRatioPlot.h>
#include <TRandom.h>
#include <TROOT.h>
#include <TLeaf.h>
#include <TLine.h>

#include <iostream>
#include <fstream>
#include <string>

#include "closureTest.h"

#define NPATHS 1

using namespace std;

void Events::Loop(){
  
  if (fChain == 0) return;

  // path for saving plots
  TString PATH = TString("/eos/home-n/npalmeri/www/TnP_closure_test/");

  // run in batch mode (only save .pdf files, not display them)
  gROOT->SetBatch(kTRUE);

  string triggerPaths[1] = {"HLT_DoubleMu4_3_LowMass"};

  Double_t bin_low[8] = {2.9, 3.1, 3.4, 5, 7., 9., 12., 40.};

  // ROW 1: separated tag/probe histograms
  TH1F* hMuonPt_weighted[2];
  TH1F* hMuonPt_triggered[2];

  TH1F* hMuonPt_weighted_detailed[2];
  TH1F* hMuonPt_triggered_detailed[2];

  TH1F* hMuonPt_weighted_lowbins[2];
  TH1F* hMuonPt_triggered_lowbins[2];

  for(int i = 0; i < 2; i++){
    hMuonPt_weighted[i] = new TH1F(TString::Format("hMuonPt_weighted_%d", i), TString::Format("hMuonPt_weighted_%d", i), 50, 2, 50);
    hMuonPt_triggered[i] = new TH1F(TString::Format("hMuonPt_triggered_%d", i), TString::Format("hMuonPt_triggered_%d", i), 50, 2, 50);

    hMuonPt_weighted_detailed[i] = new TH1F(TString::Format("hMuonPt_weighted_detailed_%d", i), TString::Format("hMuonPt_weighted_detailed_%d", i), 50, 2.5, 10);
    hMuonPt_triggered_detailed[i] = new TH1F(TString::Format("hMuonPt_triggered_detailed_%d", i), TString::Format("hMuonPt_triggered_detailed_%d", i), 50, 2.5, 10);

    hMuonPt_weighted_lowbins[i] = new TH1F(TString::Format("hMuonPt_weighted_lowbins_%d", i), TString::Format("hMuonPt_weighted_lowbins_%d", i), 7, bin_low);
    hMuonPt_triggered_lowbins[i] = new TH1F(TString::Format("hMuonPt_triggered_lowbins_%d", i), TString::Format("hMuonPt_triggered_lowbins_%d", i), 7, bin_low);

    hMuonPt_weighted[i]->Sumw2();
    hMuonPt_triggered[i]->Sumw2();
    hMuonPt_weighted_detailed[i]->Sumw2();
    hMuonPt_triggered_detailed[i]->Sumw2();
    hMuonPt_weighted_lowbins[i]->Sumw2();
    hMuonPt_triggered_lowbins[i]->Sumw2();
  }

  /*-----------------------------------------------------*/
  /*----------------  RETRIEVE WEIGHTS ------------------*/
  /*-----------------------------------------------------*/

  int dim1 = 7;
  int dim2 = 8;
	int nbins_y = 8;

	ifstream fpteta("../results/muons/DoubleMu/egammaEffi.txt", ios::in);
	//In order: x bin center, x bin width, y bin center, y bin width, efficiency, error
	std::vector<std::array<Double_t, 6>> pt_eta_point;     //to save 2D coords + value, err for 2D graph
	std::vector<std::array<Double_t, 6>> pt_eta_mc_point;  //same

	std::string line;
	for(int i = 0; i < 2; i++) std::getline(fpteta, line); //read header

	int counter = 0;
	while(std::getline(fpteta, line)){
		Double_t pt_min, pt_max;
		Double_t eta_min, eta_max;
		Double_t eff, eff_err;
		Double_t mceff, mceff_err;
		Double_t alteff, alteff_err;
		Double_t tmp;
		(stringstream)line >> eta_min >> eta_max >> pt_min >> pt_max >> eff >> eff_err >> mceff >> mceff_err >> tmp >> tmp >> alteff >> alteff_err >> tmp >> tmp;

		// save (x, y, efficiency) for 2D plot
		pt_eta_point.push_back({(pt_min + pt_max)/2., (pt_max - pt_min)/2., (eta_max + eta_min)/2., (eta_max - eta_min)/2., alteff, alteff_err});
		pt_eta_mc_point.push_back({(pt_min + pt_max)/2., (pt_max - pt_min)/2., (eta_max + eta_min)/2., (eta_max - eta_min)/2., mceff, mceff_err});
	}

	std::vector<Double_t> pts;
	std::vector<Double_t> etas;
	std::vector<Double_t> effs;
	std::vector<Double_t> eff_errs;
	std::vector<Double_t> pt_low;
	std::vector<Double_t> eta_low;
	
  int idx = 0;
	for(auto arr : pt_eta_point){
		if(idx % nbins_y == 0) pt_low.push_back(arr[0] - arr[1]);
		if(idx < nbins_y) eta_low.push_back(arr[2] - arr[3]);

		pts.push_back(arr[0]);
		etas.push_back(arr[2]);
		effs.push_back(arr[4]);
		eff_errs.push_back(arr[5]);
		idx++;
	}

	pt_low.push_back(pt_eta_point.back()[0] + pt_eta_point.back()[1]); //add last bin upper bound
	eta_low.push_back(pt_eta_point.back()[2] + pt_eta_point.back()[3]); //same
	
  
	// MC
	std::vector<Double_t> pts_mc;
	std::vector<Double_t> etas_mc;
	std::vector<Double_t> effs_mc;
	std::vector<Double_t> eff_errs_mc;
	idx = 0;
	for(auto arr : pt_eta_mc_point){
		pts_mc.push_back(arr[0]);
		etas_mc.push_back(arr[2]);
		effs_mc.push_back(arr[4]);
		eff_errs_mc.push_back(arr[5]);

		idx++;
	}

	TH2D* alt_hpteta = new TH2D("alt_hpteta", "alt_hpteta", dim1, &pt_low[0], dim2, &eta_low[0]);
	alt_hpteta->FillN(effs.size(), &pts[0], &etas[0], &effs[0]);

	TH2D* mc_hpteta = new TH2D("mc_hpteta", "mc_hpteta", dim1, &pt_low[0], dim2, &eta_low[0]);
	mc_hpteta->FillN(effs_mc.size(), &pts_mc[0], &etas_mc[0], &effs_mc[0]);

  /*-----------------------------------------------------*/
  /*--------------  RETRIEVE ALT WEIGHT -----------------*/
  /*-----------------------------------------------------*/
  
  /* 
  // Retrieve weights from direct MC calculation
  */

  TFile* altweights_file = TFile::Open("~/X_trigger_studies/turnon_curves.root");
  if(!altweights_file){
    std::cout << "ERROR: .root file containing MC turn-on curves could not be found." << std::endl;
    exit(-1);
  }

  TGraphErrors* turnon_tag = (TGraphErrors*)altweights_file->Get("turnon_tag");
  TGraphErrors* turnon_probe = (TGraphErrors*)altweights_file->Get("turnon_probe");
  
  // build histogram from graph for easier data retrieval
  TH1F* eff_tag = new TH1F("eff_tag", "eff_tag", 7, bin_low);
  TH1F* eff_probe = new TH1F("eff_probe", "eff_probe", 7, bin_low);

  for(int i = 0; i < 7; i++){
    eff_tag->SetBinContent(i+1, turnon_tag->GetPointY(i));
    eff_tag->SetBinError(i+1, turnon_tag->GetErrorY(i));
    
    eff_probe->SetBinContent(i+1, turnon_probe->GetPointY(i));
    eff_probe->SetBinError(i+1, turnon_probe->GetErrorY(i));
  }

  std::cout << "TAG" << std::endl;
  for(int i = 0; i < 7; i++){
    std::cout << "   pT = " << eff_tag->GetBinCenter(i+1) << ": " << "eff = " << turnon_tag->GetPointY(i) << " +- " << turnon_tag->GetErrorY(i) << std::endl;
  }
  std::cout << "PROBE" << std::endl;
  for(int i = 0; i < 7; i++){
    std::cout << "   pT = " << eff_probe->GetBinCenter(i+1) << ": " << "eff = " << turnon_probe->GetPointY(i) << " +- " << turnon_probe->GetErrorY(i) << std::endl;
  }


  
  /*-----------------------------------------------------*/
  /*------------------  MAIN ANALYSIS ------------------ */
  /*-----------------------------------------------------*/
 
  TRandom *rng = new TRandom();

  Double_t m_pi = 0.139571; //GeV
  Double_t m_mu = 0.10565837; //GeV
  Double_t m_k0 = 0.493677; //GeV

  Long64_t nentries = fChain->GetEntriesFast();

  int weirdEvents = 0;

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;      

    /*** Retrieve gen dimuon, dipion, k0 4vec ***/
    TLorentzVector genMuMu[2]; //[0] muon, [1] antimuon
    TLorentzVector genPiPi[2]; //[0] pi+, [1] pi-
    TLorentzVector genK0;
    
    Bool_t foundMuons = 0, foundPions = 0, foundK0 = 0;
    
    for(int i = 0; i < nGenPart; i++){
      // dimuon from Jpsi	
      if(TMath::Abs(GenPart_pdgId[i]) == 13 && GenPart_genPartIdxMother[i] != -1 && GenPart_pdgId[GenPart_genPartIdxMother[i]] == 443){
        TLorentzVector vtmp;
        vtmp.SetPtEtaPhiM(GenPart_pt[i], GenPart_eta[i], GenPart_phi[i], m_mu);
        if(GenPart_pdgId[i] > 0) genMuMu[0] = vtmp;
        else genMuMu[1] = vtmp;
        foundMuons = 1;
      }
      // pipi from Psi(2S)
      else if(TMath::Abs(GenPart_pdgId[i]) == 211 && GenPart_genPartIdxMother[i] != -1 && GenPart_pdgId[GenPart_genPartIdxMother[i]] == 100443){
        TLorentzVector vtmp;
        vtmp.SetPtEtaPhiM(GenPart_pt[i], GenPart_eta[i], GenPart_phi[i], m_pi);
        if(GenPart_pdgId[i] > 0) genPiPi[0] = vtmp;
        else genPiPi[1] = vtmp;
        foundPions = 1;
      }
      // K0s from B0
      else if(TMath::Abs(GenPart_pdgId[i]) == 310 && GenPart_genPartIdxMother[i] != -1 && TMath::Abs(GenPart_pdgId[GenPart_genPartIdxMother[i]]) == 511){
        TLorentzVector vtmp;
        vtmp.SetPtEtaPhiM(GenPart_pt[i], GenPart_eta[i], GenPart_phi[i], m_k0);
        genK0 = vtmp;
        foundK0 = 1;
      }  
    }

    // DEBUG:
    // skip event if gen particles not found
    if(!foundMuons || !foundPions || !foundK0){
      std::cout << "Error: generated muons, pions or K0 not found" << std::endl;
      std::cout << "foundMuons = " << foundMuons << ", foundPions = " << foundPions << ", foundK0 = " << foundK0 << std::endl;
      continue;
    }

    int savedB0s = 0; //to verify that we're actually only saving 1 reco B0 per event

    for(int i = 0; i < nB0; i++){

      /*** 1) Calculate invariant mass of final state particles (pipimumupipi) before and after kinematic fit ***/
      // prefit
      TLorentzVector v_pipi_pi1; v_pipi_pi1.SetPtEtaPhiM(B0_PiPi_prefit_pi1_pt[i], B0_PiPi_prefit_pi1_eta[i], B0_PiPi_prefit_pi1_phi[i], m_pi);
      TLorentzVector v_pipi_pi2; v_pipi_pi2.SetPtEtaPhiM(B0_PiPi_prefit_pi2_pt[i], B0_PiPi_prefit_pi2_eta[i], B0_PiPi_prefit_pi2_phi[i], m_pi);
      
      TLorentzVector v_mumu_mu1; v_mumu_mu1.SetPtEtaPhiM(B0_MuMu_prefit_mu1_pt[i], B0_MuMu_prefit_mu1_eta[i], B0_MuMu_prefit_mu1_phi[i], m_mu);
      TLorentzVector v_mumu_mu2; v_mumu_mu2.SetPtEtaPhiM(B0_MuMu_prefit_mu2_pt[i], B0_MuMu_prefit_mu2_eta[i], B0_MuMu_prefit_mu2_phi[i], m_mu);
      
      TLorentzVector v_k0_pi1; v_k0_pi1.SetPtEtaPhiM(B0_K0s_matchTrack1_pt[i], B0_K0s_matchTrack1_eta[i], B0_K0s_matchTrack1_phi[i], m_pi);
      TLorentzVector v_k0_pi2; v_k0_pi2.SetPtEtaPhiM(B0_K0s_matchTrack2_pt[i], B0_K0s_matchTrack2_eta[i], B0_K0s_matchTrack2_phi[i], m_pi);
      
      Double_t s_unfitted = (v_pipi_pi1 + v_pipi_pi2 + v_mumu_mu1 + v_mumu_mu2 + v_k0_pi1 + v_k0_pi2).Mag();
      
      // fitted
      TLorentzVector v_pipi_fitted_pi1; v_pipi_fitted_pi1.SetPtEtaPhiM(B0_finalFit_pi1_pt[i], B0_finalFit_pi1_eta[i], B0_finalFit_pi1_phi[i], m_pi);
      TLorentzVector v_pipi_fitted_pi2; v_pipi_fitted_pi2.SetPtEtaPhiM(B0_finalFit_pi2_pt[i], B0_finalFit_pi2_eta[i], B0_finalFit_pi2_phi[i], m_pi);
      TLorentzVector v_mumu_fitted_mu1; v_mumu_fitted_mu1.SetPtEtaPhiM(B0_finalFit_mu1_pt[i], B0_finalFit_mu1_eta[i], B0_finalFit_mu1_phi[i], m_mu);
      TLorentzVector v_mumu_fitted_mu2; v_mumu_fitted_mu2.SetPtEtaPhiM(B0_finalFit_mu2_pt[i], B0_finalFit_mu2_eta[i], B0_finalFit_mu2_phi[i], m_mu);
      TLorentzVector v_k0; v_k0.SetPtEtaPhiM(B0_finalFit_k0s_pt[i], B0_finalFit_k0s_eta[i], B0_finalFit_k0s_phi[i], m_k0);
            
      /*** 2, 3) Calculate reco muon deltaR and pT ratio wrt gen muons, pions and K0s ***/
      
      // mumu
      Double_t drmu1 = TMath::Min(v_mumu_fitted_mu1.DeltaR(genMuMu[0]), v_mumu_fitted_mu1.DeltaR(genMuMu[1]));
      Double_t drmu2 = TMath::Min(v_mumu_fitted_mu2.DeltaR(genMuMu[0]), v_mumu_fitted_mu2.DeltaR(genMuMu[1]));
      
      Double_t ptratio_mu1;
      Double_t ptratio_mu1_1 = TMath::Abs(v_mumu_fitted_mu1.Pt() - genMuMu[0].Pt())/genMuMu[0].Pt(); Double_t ptratio_mu1_2 = TMath::Abs(v_mumu_fitted_mu1.Pt() - genMuMu[1].Pt())/genMuMu[1].Pt();
      ptratio_mu1 = TMath::Min(ptratio_mu1_1, ptratio_mu1_2);
      // NB: we're not necessarily picking the same best matched muon as for deltaR (if coincidentally the pT of the other muon is closer, we'd make the reco artificially better i.e. smaller pT ratio)
      
      Double_t ptratio_mu2;
      Double_t ptratio_mu2_1 = TMath::Abs(v_mumu_fitted_mu2.Pt() - genMuMu[0].Pt())/genMuMu[0].Pt(); Double_t ptratio_mu2_2 = TMath::Abs(v_mumu_fitted_mu2.Pt() - genMuMu[1].Pt())/genMuMu[1].Pt();
      ptratio_mu2 = TMath::Min(ptratio_mu2_1, ptratio_mu2_2);
      
      // pipi
      Double_t drpi1 = TMath::Min(v_pipi_fitted_pi1.DeltaR(genPiPi[0]), v_pipi_fitted_pi1.DeltaR(genPiPi[1]));
      Double_t drpi2 = TMath::Min(v_pipi_fitted_pi2.DeltaR(genPiPi[0]), v_pipi_fitted_pi2.DeltaR(genPiPi[1]));
      
      Double_t ptratio_pi1;
      Double_t ptratio_pi1_1 = TMath::Abs(v_pipi_fitted_pi1.Pt() - genPiPi[0].Pt())/genPiPi[0].Pt(); Double_t ptratio_pi1_2 = TMath::Abs(v_pipi_fitted_pi1.Pt() - genPiPi[1].Pt())/genPiPi[1].Pt();
      ptratio_pi1 = TMath::Min(ptratio_pi1_1, ptratio_pi1_2);
      
      Double_t ptratio_pi2;
      Double_t ptratio_pi2_1 = TMath::Abs(v_pipi_fitted_pi2.Pt() - genPiPi[0].Pt())/genPiPi[0].Pt(); Double_t ptratio_pi2_2 = TMath::Abs(v_pipi_fitted_pi2.Pt() - genPiPi[1].Pt())/genPiPi[1].Pt();
      ptratio_pi2 = TMath::Min(ptratio_pi2_1, ptratio_pi2_2);
            
      // k0
      Double_t drk0 = v_k0.DeltaR(genK0);
      Double_t ptratio_k0 = TMath::Abs(v_k0.Pt() - genK0.Pt())/genK0.Pt();
            
      
      /*** 4) Compute invariant mass of correctly reconstructed particles (selected on deltaR, pT ratio cut) ***/
      Double_t drMax = 0.01;
      Double_t ptratioMax_minus1 = 0.1;
      
      //Jpsi 
      // NB!!! i'm plotting pre/post fit mass even though i'm cutting on the finalFit quantities (we're not cutting anything though)
      Bool_t isJPsiCorrect = drmu1 < drMax && drmu2 < drMax && ptratio_mu1 < ptratioMax_minus1 && ptratio_mu2 < ptratioMax_minus1;
      Bool_t isRhoCorrect = drpi1 < drMax && drpi2 < drMax && ptratio_pi1 < ptratioMax_minus1 && ptratio_pi2 < ptratioMax_minus1;
      Bool_t isK0sCorrect = drk0 < drMax && ptratio_k0 < ptratioMax_minus1;

      
      if(isJPsiCorrect && isRhoCorrect && isK0sCorrect){

        savedB0s++;

        Double_t weight1;
        if(v_mumu_fitted_mu1.Pt() < 4) weight1 = 0;
        else weight1 = mc_hpteta->GetBinContent(mc_hpteta->FindBin(v_mumu_fitted_mu1.Pt(), v_mumu_fitted_mu1.Eta()));
        Double_t weight2 = mc_hpteta->GetBinContent(mc_hpteta->FindBin(v_mumu_fitted_mu2.Pt(), v_mumu_fitted_mu2.Eta()));

        // Double_t weight1 = eff_tag->GetBinContent(eff_tag->FindBin(v_mumu_fitted_mu1.Pt()));
        // Double_t weight2 = eff_probe->GetBinContent(eff_probe->FindBin(v_mumu_fitted_mu2.Pt()));

        Double_t wtot = weight1*weight2;

        if(wtot > 0){ // just for optimization, can be skipped
          // Weighted distribution
          hMuonPt_weighted[0]->Fill(v_mumu_fitted_mu1.Pt(), weight1);
          hMuonPt_weighted_detailed[0]->Fill(v_mumu_fitted_mu1.Pt(), weight1);
          hMuonPt_weighted_lowbins[0]->Fill(v_mumu_fitted_mu1.Pt(), weight1);
          
          hMuonPt_weighted[1]->Fill(v_mumu_fitted_mu2.Pt(), weight2);
          hMuonPt_weighted_detailed[1]->Fill(v_mumu_fitted_mu2.Pt(), weight2);
          hMuonPt_weighted_lowbins[1]->Fill(v_mumu_fitted_mu2.Pt(), weight2);
        }
        

        if(fChain->GetLeaf(triggerPaths[0].c_str())->GetValue()){

          // Triggered distribution
          Bool_t mu1_fired = fChain->GetLeaf(TString("B0_MuMu_mu1_fired_" + triggerPaths[0].substr(4)))->GetValue();
          Bool_t mu2_fired = fChain->GetLeaf(TString("B0_MuMu_mu2_fired_" + triggerPaths[0].substr(4)))->GetValue();
          
          Bool_t is_mu1_match_HLT = B0_MuMu_mu1_dr_DoubleMu4_3_LowMass[i] < drMax;
          Bool_t is_mu2_match_HLT = B0_MuMu_mu2_dr_DoubleMu4_3_LowMass[i] < drMax;

          if(mu1_fired && mu2_fired  && is_mu1_match_HLT && is_mu2_match_HLT){
            hMuonPt_triggered[0]->Fill(v_mumu_fitted_mu1.Pt());
            hMuonPt_triggered[1]->Fill(v_mumu_fitted_mu2.Pt());
            hMuonPt_triggered_detailed[0]->Fill(v_mumu_fitted_mu1.Pt());
            hMuonPt_triggered_detailed[1]->Fill(v_mumu_fitted_mu2.Pt());
            hMuonPt_triggered_lowbins[0]->Fill(v_mumu_fitted_mu1.Pt());
            hMuonPt_triggered_lowbins[1]->Fill(v_mumu_fitted_mu2.Pt());
          }
        }
      }
	  }    
  } //event loop

  // ROW 2: overall histograms (tag and probe in same histogram)
  TH1F* hMuonPt_weighted_tot = (TH1F*)hMuonPt_weighted[0]->Clone("hMuonPt_weighted_tot");
  TH1F* hMuonPt_triggered_tot = (TH1F*)hMuonPt_triggered[0]->Clone("hMuonPt_triggered_tot");

  TH1F* hMuonPt_weighted_detailed_tot = (TH1F*)hMuonPt_weighted_detailed[0]->Clone("hMuonPt_weighted_detailed_tot");
  TH1F* hMuonPt_triggered_detailed_tot = (TH1F*)hMuonPt_triggered_detailed[0]->Clone("hMuonPt_triggered_detailed_tot");

  TH1F* hMuonPt_weighted_lowbins_tot = (TH1F*)hMuonPt_weighted_lowbins[0]->Clone("hMuonPt_weighted_lowbins_tot");
  TH1F* hMuonPt_triggered_lowbins_tot = (TH1F*)hMuonPt_triggered_lowbins[0]->Clone("hMuonPt_triggered_lowbins_tot");
  
  hMuonPt_weighted_tot->Add(hMuonPt_weighted[1]);
  hMuonPt_triggered_tot->Add(hMuonPt_triggered[1]);
  hMuonPt_weighted_detailed_tot->Add(hMuonPt_weighted_detailed[1]);
  hMuonPt_triggered_detailed_tot->Add(hMuonPt_triggered_detailed[1]);
  hMuonPt_weighted_lowbins_tot->Add(hMuonPt_weighted_lowbins[1]);
  hMuonPt_triggered_lowbins_tot->Add(hMuonPt_triggered_lowbins[1]);


  // RESCALING
  // hMuonPt_triggered_tot->Scale(1./hMuonPt_triggered_tot->Integral());
  // hMuonPt_weighted_tot->Scale(1./hMuonPt_weighted_tot->Integral());

  // hMuonPt_triggered_detailed_tot->Scale(1./hMuonPt_triggered_detailed_tot->Integral());
  // hMuonPt_weighted_detailed_tot->Scale(1./hMuonPt_weighted_detailed_tot->Integral());

  // hMuonPt_triggered_lowbins_tot->Scale(1./hMuonPt_triggered_lowbins_tot->Integral());
  // hMuonPt_weighted_lowbins_tot->Scale(1./hMuonPt_weighted_lowbins_tot->Integral());

  // for(int i = 0; i < 2; i++){
  //   hMuonPt_triggered[i]->Scale(1./hMuonPt_triggered[i]->Integral());
  //   hMuonPt_weighted[i]->Scale(1./hMuonPt_weighted[i]->Integral());
    
  //   hMuonPt_triggered_detailed[i]->Scale(1./hMuonPt_triggered_detailed[i]->Integral());
  //   hMuonPt_weighted_detailed[i]->Scale(1./hMuonPt_weighted_detailed[i]->Integral());

  //   hMuonPt_triggered_lowbins[i]->Scale(1./hMuonPt_triggered_lowbins[i]->Integral());
  //   hMuonPt_weighted_lowbins[i]->Scale(1./hMuonPt_weighted_lowbins[i]->Integral());
  // }

  /*---- PLOTTING ----*/

  gStyle->SetOptStat(0);

  TCanvas* c1 = new TCanvas("c1", "c1", 2400, 1600);
  c1->Divide(3,2);

  c1->cd(1);
  gPad->SetRightMargin(.05);
  gPad->SetLeftMargin(.15);

  hMuonPt_weighted_tot->SetMaximum(TMath::Max(hMuonPt_weighted_tot->GetMaximum(), hMuonPt_triggered_tot->GetMaximum())*1.1);
  
  hMuonPt_weighted_tot->SetTitle("Overall p_{T} distribution [full range]");
  hMuonPt_weighted_tot->GetXaxis()->SetTitle("p_{T} [GeV]");
  hMuonPt_weighted_tot->GetYaxis()->SetTitle("Counts");
  hMuonPt_weighted_tot->SetLineColor(62);
  hMuonPt_weighted_tot->Draw("HISTE");
  hMuonPt_triggered_tot->SetLineColor(95);
  hMuonPt_triggered_tot->Draw("HISTE SAMES");

  auto leg1 = new TLegend(.55, 0.7, .95, 0.9);
  leg1->AddEntry(hMuonPt_weighted_tot, TString::Format("Weighted: %d evs", int(hMuonPt_weighted_tot->Integral())), "l");
  leg1->AddEntry(hMuonPt_triggered_tot, TString::Format("Triggered: %d evs", int(hMuonPt_triggered_tot->Integral())), "l");
  leg1->Draw();

  c1->cd(2);
  gPad->SetRightMargin(.05);
  gPad->SetLeftMargin(.15);

  hMuonPt_weighted_detailed_tot->SetMaximum(TMath::Max(hMuonPt_weighted_detailed_tot->GetMaximum(), hMuonPt_triggered_detailed_tot->GetMaximum())*1.1);

  hMuonPt_weighted_detailed_tot->SetTitle("Overall p_{T} distribution [zoomed]");
  hMuonPt_weighted_detailed_tot->GetXaxis()->SetTitle("p_{T} [GeV]");
  hMuonPt_weighted_detailed_tot->GetYaxis()->SetTitle("Counts");
  hMuonPt_weighted_detailed_tot->SetLineColor(62);
  hMuonPt_weighted_detailed_tot->Draw("HISTE");
  hMuonPt_triggered_detailed_tot->SetLineColor(95);
  hMuonPt_triggered_detailed_tot->Draw("HISTE SAMES");

  auto leg2 = new TLegend(.55, 0.7, .95, 0.9);
  leg2->AddEntry(hMuonPt_weighted_detailed_tot, TString::Format("Weighted: %d evs", int(hMuonPt_weighted_detailed_tot->Integral())), "l");
  leg2->AddEntry(hMuonPt_triggered_detailed_tot, TString::Format("Triggered: %d evs", int(hMuonPt_triggered_detailed_tot->Integral())), "l");
  leg2->Draw();
  
  c1->cd(3);
  gPad->SetRightMargin(.05);
  gPad->SetLeftMargin(.15);
  gPad->SetLogx();

  hMuonPt_weighted_lowbins_tot->SetMaximum(TMath::Max(hMuonPt_weighted_lowbins_tot->GetMaximum(), hMuonPt_triggered_lowbins_tot->GetMaximum())*1.1);

  hMuonPt_weighted_lowbins_tot->GetXaxis()->SetMoreLogLabels();
  hMuonPt_weighted_lowbins_tot->GetXaxis()->SetTitleOffset(1.25);
  hMuonPt_weighted_lowbins_tot->SetTitle("Overall p_{T} distribution [accurate binning]");
  hMuonPt_weighted_lowbins_tot->GetXaxis()->SetTitle("p_{T} [GeV]");
  hMuonPt_weighted_lowbins_tot->GetYaxis()->SetTitle("Counts");
  hMuonPt_weighted_lowbins_tot->SetLineColor(62);
  hMuonPt_weighted_lowbins_tot->Draw("HISTE SAMES");
  hMuonPt_triggered_lowbins_tot->SetLineColor(95);
  hMuonPt_triggered_lowbins_tot->Draw("HISTE SAMES");

  auto leg3 = new TLegend(.55, 0.7, .95, 0.9);
  leg3->AddEntry(hMuonPt_weighted_lowbins_tot, TString::Format("Weighted: %d evs", int(hMuonPt_weighted_lowbins_tot->Integral())), "l");
  leg3->AddEntry(hMuonPt_triggered_lowbins_tot, TString::Format("Triggered: %d evs", int(hMuonPt_triggered_lowbins_tot->Integral())), "l");
  leg3->Draw();

  // ROW 2
  c1->cd(4);
  gPad->SetRightMargin(.05);
  gPad->SetLeftMargin(.15);

  Double_t maxes[4] = {hMuonPt_triggered[0]->GetMaximum(), hMuonPt_triggered[1]->GetMaximum(), hMuonPt_weighted[0]->GetMaximum(), hMuonPt_weighted[1]->GetMaximum()};
  hMuonPt_weighted[0]->SetMaximum(TMath::MaxElement(4, maxes)*1.1);
  hMuonPt_weighted[0]->SetMinimum(0);  

  hMuonPt_weighted[0]->SetTitle("Tag/probe p_{T} distribution [full range]");
  hMuonPt_weighted[0]->GetXaxis()->SetTitle("p_{T} [GeV]");
  hMuonPt_weighted[0]->GetYaxis()->SetTitle("Counts");

  for(int i = 0; i < 2; i++){
    int color = i ? 62 : 95;
    hMuonPt_weighted[i]->SetLineColor(color);
    hMuonPt_triggered[i]->SetLineColor(color + 1);
    if(!i) hMuonPt_weighted[i]->Draw("HISTE");
    else hMuonPt_weighted[i]->Draw("HISTE SAMES");
    hMuonPt_triggered[i]->DrawCopy("E SAMES");
    hMuonPt_triggered[i]->SetLineWidth(2);
    hMuonPt_triggered[i]->Draw("HIST SAMES");
  }

  auto leg4 = new TLegend(.5, 0.6, .95, 0.9);
  leg4->AddEntry(hMuonPt_weighted[0], TString::Format("Weighted, tag muon: %d evs", int(hMuonPt_weighted[0]->Integral())), "l");
  leg4->AddEntry(hMuonPt_triggered[0], TString::Format("Triggered, tag muon: %d evs", int(hMuonPt_triggered[0]->Integral())), "l");
  leg4->AddEntry(hMuonPt_weighted[1], TString::Format("Weighted, probe muon: %d evs", int(hMuonPt_weighted[1]->Integral())), "l");
  leg4->AddEntry(hMuonPt_triggered[1], TString::Format("Triggered, probe muon: %d evs", int(hMuonPt_triggered[1]->Integral())), "l");
  leg4->Draw();

  c1->cd(5);
  gPad->SetRightMargin(.05);
  gPad->SetLeftMargin(.15);

  Double_t maxes2[4] = {hMuonPt_triggered_detailed[0]->GetMaximum(), hMuonPt_triggered_detailed[1]->GetMaximum(), hMuonPt_weighted_detailed[0]->GetMaximum(), hMuonPt_weighted_detailed[1]->GetMaximum()};
  hMuonPt_weighted_detailed[0]->SetMaximum(TMath::MaxElement(4, maxes2)*1.1);
  hMuonPt_weighted_detailed[0]->SetMinimum(0);  


  hMuonPt_weighted_detailed[0]->SetTitle("Tag/probe p_{T} distribution [zoomed]");
  hMuonPt_weighted_detailed[0]->GetXaxis()->SetTitle("p_{T} [GeV]");
  hMuonPt_weighted_detailed[0]->GetYaxis()->SetTitle("Counts");

  for(int i = 0; i < 2; i++){
    int color = i ? 62 : 95;
    hMuonPt_weighted_detailed[i]->SetLineColor(color);
    hMuonPt_triggered_detailed[i]->SetLineColor(color + 1);
    if(!i) hMuonPt_weighted_detailed[i]->Draw("HISTE");
    else hMuonPt_weighted_detailed[i]->Draw("HISTE SAMES");
    hMuonPt_triggered_detailed[i]->DrawCopy("E SAMES");
    hMuonPt_triggered_detailed[i]->SetLineWidth(2);
    hMuonPt_triggered_detailed[i]->Draw("HIST SAMES");
  }

  auto leg5 = new TLegend(.5, 0.6, .95, 0.9);
  leg5->AddEntry(hMuonPt_weighted_detailed[0], TString::Format("Weighted, tag muon: %d evs", int(hMuonPt_weighted_detailed[0]->Integral())), "l");
  leg5->AddEntry(hMuonPt_triggered_detailed[0], TString::Format("Triggered, tag muon: %d evs", int(hMuonPt_triggered_detailed[0]->Integral())), "l");
  leg5->AddEntry(hMuonPt_weighted_detailed[1], TString::Format("Weighted, probe muon: %d evs", int(hMuonPt_weighted_detailed[1]->Integral())), "l");
  leg5->AddEntry(hMuonPt_triggered_detailed[1], TString::Format("Triggered, probe muon: %d evs", int(hMuonPt_triggered_detailed[1]->Integral())), "l");
  leg5->Draw();

  c1->cd(6);
  gPad->SetRightMargin(.05);
  gPad->SetLeftMargin(.15);
  gPad->SetLogx();
  // gPad->SetLogy();
  hMuonPt_weighted_lowbins[0]->GetXaxis()->SetMoreLogLabels();
  hMuonPt_weighted_lowbins[0]->GetXaxis()->SetTitleOffset(1.25);

  Double_t maxes3[4] = {hMuonPt_triggered_lowbins[0]->GetMaximum(), hMuonPt_triggered_lowbins[1]->GetMaximum(), hMuonPt_weighted_lowbins[0]->GetMaximum(), hMuonPt_weighted_lowbins[1]->GetMaximum()};
  hMuonPt_weighted_lowbins[0]->SetMaximum(TMath::MaxElement(4, maxes3)*1.1);
  hMuonPt_weighted_lowbins[0]->SetMinimum(0);  


  hMuonPt_weighted_lowbins[0]->SetTitle("Tag/probe p_{T} distribution [accurate binning]");
  hMuonPt_weighted_lowbins[0]->GetXaxis()->SetTitle("p_{T} [GeV]");
  hMuonPt_weighted_lowbins[0]->GetYaxis()->SetTitle("Counts");

  for(int i = 0; i < 2; i++){
    int color = i ? 62 : 95;
    hMuonPt_weighted_lowbins[i]->SetLineColor(color);
    hMuonPt_triggered_lowbins[i]->SetLineColor(color + 1);
    if(!i) hMuonPt_weighted_lowbins[i]->Draw("HISTE");
    else hMuonPt_weighted_lowbins[i]->Draw("HISTE SAMES");
    hMuonPt_triggered_lowbins[i]->DrawCopy("E SAMES");
    hMuonPt_triggered_lowbins[i]->SetLineWidth(2);
    hMuonPt_triggered_lowbins[i]->Draw("HIST SAMES");    
  }

  auto leg6 = new TLegend(.5, 0.6, .95, 0.9);
  leg6->AddEntry(hMuonPt_weighted_lowbins[0], TString::Format("Weighted, tag muon: %d evs", int(hMuonPt_weighted_lowbins[0]->Integral())), "l");
  leg6->AddEntry(hMuonPt_triggered_lowbins[0], TString::Format("Triggered, tag muon: %d evs", int(hMuonPt_triggered_lowbins[0]->Integral())), "l");
  leg6->AddEntry(hMuonPt_weighted_lowbins[1], TString::Format("Weighted, probe muon: %d evs", int(hMuonPt_weighted_lowbins[1]->Integral())), "l");
  leg6->AddEntry(hMuonPt_triggered_lowbins[1], TString::Format("Triggered, probe muon: %d evs", int(hMuonPt_triggered_lowbins[1]->Integral())), "l");
  leg6->Draw();


	gStyle->SetLineScalePS(1.75);
  c1->SaveAs(PATH + "closureTest.pdf");

}
