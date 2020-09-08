#include "TString.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TColor.h"
#include "TVirtualFitter.h"
#include <iostream>

//const TString lumiString = "CMS Preliminary, #sqrt{s}=13 TeV, #intLdt=4.0 fb^{-1}";
const TString lumiString = "";

const int nEtaBins = 1;
const int nPtBins = 3;   

const double ptBinLimits[nPtBins+1]  = { 0.5,  2.,   5., 20.};
const double ptBinCenters[nPtBins]   = { 1.25, 3.5, 12.5 };
const double ptBinHalfWidth[nPtBins] = { 0.75, 1.5,  7.5 };
const TString etaLimitsStringArray[nEtaBins] = { "0. < |#eta| < 2.5" };

// ----------------------------------------
// Data efficiencies and statistical errors
double data[nEtaBins][nPtBins] = {
  { 0.1711, 0.8731, 0.9670 }
};

// statistical only errors 
double dataErrStat[nEtaBins][nPtBins] = {
  { 0.0232, 0.0213, 0.0100 }
};

// ----------------------------------------
// MC efficiencies and errors - C&C
double mc[nEtaBins][nPtBins] = {
  //  { 0.206, 0.856, 0.967 }            // HLT12, no MC match
  //  { 0.228, 0.863, 0.967 }            // no HLT12, no MC match  
  { 0.2407, 0.8919, 0.9896 }         // HLT12, with MC match
};

// statistical only errors
double mcErr[nEtaBins][nPtBins] = {
  { 0.0095, 0.0045, 0.0012 }           // HLT12, with MC match  
};


void drawResults(){
  
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "================================" << std::endl;  
  std::cout << "scale factors: " << std::endl;
  // Scale factors and errors
  double sf[nEtaBins][nPtBins];
  double sfErrTot[nEtaBins][nPtBins];
  for (int iEta=0; iEta<nEtaBins; iEta++){ 
    for (int iPt=0; iPt<nPtBins; iPt++){ 
      sf[iEta][iPt] = data[iEta][iPt]/mc[iEta][iPt];
      float sigmaDoD   = dataErrStat[iEta][iPt]/data[iEta][iPt];
      float sigmaMCoMC = mcErr[iEta][iPt]/mc[iEta][iPt];
      sfErrTot[iEta][iPt] = sf[iEta][iPt]*sqrt( (sigmaDoD*sigmaDoD) + (sigmaMCoMC*sigmaMCoMC) );
      std::cout << sf[iEta][iPt] << " +/- " << sfErrTot[iEta][iPt] << std::endl;
    }
  }

  // Draw all canvases
  for(int ieta = 0; ieta<nEtaBins; ieta++){

    TString cname = "sfEff";
    TCanvas *c1 = new TCanvas(cname, cname, 10,10,700,700);
    c1->SetFillColor(kWhite);
    c1->Draw();
    TPad *pad1 = new TPad("main","",0, 0.3, 1.0, 1.0);
    pad1->SetTopMargin(0.20);
    pad1->SetBottomMargin(0.02);
    pad1->SetGrid();
    TPad *pad2 = new TPad("ratio", "", 0, 0, 1.0, 0.3);
    pad2->SetTopMargin(0.05);
    pad2->SetBottomMargin(0.30);
    pad2->SetGrid();

    pad1->Draw();
    pad2->Draw();

    // Create and fill arrays for graphs for this eta bin
    double *dataSlice    = new double[nPtBins];
    double *dataSliceErr = new double[nPtBins];
    double *mcSlice      = new double[nPtBins];
    double *mcSliceErr   = new double[nPtBins];
    double *sfSlice      = new double[nPtBins];
    double *sfSliceErr   = new double[nPtBins];
    for(int ipt = 0; ipt<nPtBins; ipt++){
      dataSlice   [ipt] = data     [ieta][ipt];
      dataSliceErr[ipt] = dataErrStat  [ieta][ipt];
      mcSlice     [ipt] = mc       [ieta][ipt];
      mcSliceErr  [ipt] = mcErr    [ieta][ipt];
      sfSlice     [ipt] = sf       [ieta][ipt];
      sfSliceErr  [ipt] = sfErrTot [ieta][ipt];
    }

    // Create an d configure the graphs   
    TGraphErrors *grData = new TGraphErrors(nPtBins, ptBinCenters, dataSlice, ptBinHalfWidth, dataSliceErr);
    TGraphErrors *grMc   = new TGraphErrors(nPtBins, ptBinCenters, mcSlice, ptBinHalfWidth, mcSliceErr);
    TGraphErrors *grSf   = new TGraphErrors(nPtBins, ptBinCenters, sfSlice, ptBinHalfWidth, sfSliceErr);
    
    grData->SetLineColor(kBlack);
    grData->SetMarkerColor(kBlack);
    grData->SetMarkerStyle(20);
    grData->SetMarkerSize(1.);

    int ci = TColor::GetColor("#99ccff");
    grMc->SetFillColor(kGreen-8);
    ci = TColor::GetColor("#3399ff");
    grMc->SetLineColor(kGreen+4);
    grMc->SetMarkerStyle(22);
    grMc->SetMarkerColor(kGreen+4);
    grMc->SetMarkerSize(1.);

    ci = TColor::GetColor("#99ccff");
    grSf->SetFillColor(kGreen-8);
    ci = TColor::GetColor("#3399ff");
    grSf->SetLineColor(kGreen+4);
    grSf->SetMarkerStyle(20);
    grSf->SetMarkerColor(kGreen+4);
    grSf->SetMarkerSize(1.);
    grSf->Fit("pol0","","",20,350);

    // Create and configure the dummy histograms on which to draw the graphs
    TH2F *h1 = new TH2F("dummy1","", 100, 0, 20.5, 100, 0., 1.1);
    h1->GetYaxis()->SetTitle("Efficiency");
    h1->SetStats(0);
    h1->GetXaxis()->SetLabelSize(0);
    h1->GetXaxis()->SetNdivisions(505);
    h1->GetXaxis()->SetDecimals();
    h1->GetYaxis()->SetTitleOffset(0.8);
    h1->GetYaxis()->SetTitleSize(0.05);
    TH2F *h2 = new TH2F("dummy2","", 100, 0, 20.5, 100, 0.7, 1.7);
    h2->GetXaxis()->SetTitle("p_{T} [GeV]");
    h2->GetYaxis()->SetTitle("Scale Factor");
    h2->GetXaxis()->SetTitleOffset(1.0);
    h2->GetXaxis()->SetTitleSize(0.1);
    h2->GetYaxis()->SetTitleOffset(0.4);
    h2->GetYaxis()->SetTitleSize(0.1);
    h2->GetXaxis()->SetLabelSize(0.08);
    h2->GetYaxis()->SetLabelSize(0.08);
    h2->GetYaxis()->SetNdivisions(505);
    h2->GetYaxis()->SetDecimals();
    h2->SetStats(0);

    TLegend *leg = new TLegend(0.65,0.1,0.9,0.25);
    leg->SetFillColor(kWhite);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->AddEntry(grData, "Data", "pl");
    leg->AddEntry(grMc, "Simulation", "pFlE");

    TLatex *latLumi = new TLatex(0, 1.15, lumiString);

    TLatex *latEta = new TLatex(60.0, 0.5, etaLimitsStringArray[ieta]);


    // --------------------------------------
    // Draw the efficiencies
    pad1->cd();
    h1->Draw();
    grMc  ->Draw("2same");
    grMc  ->Draw("pZ,same");
    grData->Draw("PEZ,same");
    leg->Draw("same");
    latEta->Draw("same");
    latLumi->Draw("same");
    // Draw the scale factors
    pad2->cd();
    h2->Draw();
    grSf  ->Draw("2same");
    grSf  ->Draw("pEZ,same");
    // Save into a file
    TString fname = cname;
    fname += ".png";
    c1->Print(fname);
  }

}



