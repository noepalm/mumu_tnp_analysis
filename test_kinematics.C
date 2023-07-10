//Command:
//root /eos/cms/store/user/crovelli/HLT_DoubleMuv2/MuonDataset_2022Gv1__DoubleMuTriggerTnp.root/nano_
void test_kinematics(){
  TFile* f = TFile::Open("/eos/cms/store/user/crovelli/HLT_DoubleMuv2/MuonDataset_2022Gv1__DoubleMuTriggerTnp.root");
  TFile* fmc = TFile::Open("/eos/cms/store/user/crovelli/DoubleMuMCwithTag_v2/TnP__BsToJPsiPhi__Run3Summer22EE___withTagV2.root");

  TTree* tree = (TTree*)f->Get("nano_/tree");
  TTree* treemc = (TTree*)fmc->Get("nano_/tree");
  
  TString path = "/eos/home-n/npalmeri/www/";

  TCanvas* c1 = new TCanvas("c1", "c1", 1600, 800);
  c1->Divide(2,1);
  c1->cd(1);
  tree->Draw("Jpsi_m1_pt", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  tree->Draw("Jpsi_m1_pt", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  tree->Draw("Jpsi_m1_pt", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  tree->Draw("Jpsi_m1_pt", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();

  c1->cd(2);
  treemc->Draw("Jpsi_m1_pt", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  treemc->Draw("Jpsi_m1_pt", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  treemc->Draw("Jpsi_m1_pt", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  treemc->Draw("Jpsi_m1_pt", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();
  
  c1->Print(path + "verifyData.pdf(", "pdf");

  TCanvas* c5 = new TCanvas("c5", "c5", 1600, 800);
  c5->Divide(2,1);
  c5->cd(1);
  tree->Draw("Jpsi_m2_pt", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  tree->Draw("Jpsi_m2_pt", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  tree->Draw("Jpsi_m2_pt", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  tree->Draw("Jpsi_m2_pt", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();

  c5->cd(2);
  treemc->Draw("Jpsi_m2_pt", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  treemc->Draw("Jpsi_m2_pt", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  treemc->Draw("Jpsi_m2_pt", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  treemc->Draw("Jpsi_m2_pt", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();
  
  c5->Print(path + "verifyData.pdf", "pdf");


  TCanvas* c7 = new TCanvas("c7", "c7", 1600, 800);
  c7->Divide(2,1);
  c7->cd(1);
  tree->Draw("Jpsi_m1_eta", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  tree->Draw("Jpsi_m1_eta", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  tree->Draw("Jpsi_m1_eta", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  tree->Draw("Jpsi_m1_eta", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();

  c7->cd(2);
  treemc->Draw("Jpsi_m1_eta", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  treemc->Draw("Jpsi_m1_eta", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  treemc->Draw("Jpsi_m1_eta", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  treemc->Draw("Jpsi_m1_eta", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();
  
  c7->Print(path + "verifyData.pdf", "pdf");

  TCanvas* c8 = new TCanvas("c8", "c8", 1600, 800);
  c8->Divide(2,1);
  c8->cd(1);
  tree->Draw("Jpsi_m2_eta", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  tree->Draw("Jpsi_m2_eta", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  tree->Draw("Jpsi_m2_eta", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  tree->Draw("Jpsi_m2_eta", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();

  c8->cd(2);
  treemc->Draw("Jpsi_m2_eta", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  treemc->Draw("Jpsi_m2_eta", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  treemc->Draw("Jpsi_m2_eta", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  treemc->Draw("Jpsi_m2_eta", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();
  
  c8->Print(path + "verifyData.pdf", "pdf");


  TCanvas* c3 = new TCanvas("c3", "c3", 1600, 800);
  c3->Divide(2,1);

  c3->cd(1);
  tree->Draw("Jpsi_nonfit_mass:Jpsi_muonsDr", "", "colz");
  c3->cd(2);
  treemc->Draw("Jpsi_nonfit_mass:Jpsi_muonsDr", "", "colz");


  c3->Print(path + "verifyData.pdf", "pdf");



  TCanvas* c4 = new TCanvas("c4", "c4", 1600, 800);
  c4->Divide(2,1);
  
  c4->cd(1);
  tree->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  tree->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  tree->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  tree->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();

  c4->cd(2);
  treemc->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr > 0.4 && Jpsi_muonsDr < 0.6", "PLC");
  treemc->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr > 0.2 && Jpsi_muonsDr < 0.4", "PLC SAME");
  treemc->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr > 0.6 && Jpsi_muonsDr < 0.8", "PLC SAME");
  treemc->Draw("Jpsi_nonfit_mass", "Jpsi_muonsDr < 0.2", "PLC SAME");
  gPad->BuildLegend();

  c4->Print(path + "verifyData.pdf)", "pdf");

}