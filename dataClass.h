//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 18 13:59:54 2023 by ROOT version 6.24/08
// from TTree tree/tree
// found on file: /eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_2022D_LowMass0.root
//////////////////////////////////////////////////////////

#ifndef tree_h
#define tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   ULong64_t       event;
   UInt_t          luminosityBlock;
   UInt_t          nvtx;
  
   /*** Leading mu ***/
   // Offline
   Float_t         Jpsi_m1_pt;
   Float_t         Jpsi_m1_eta;
   Float_t         Jpsi_m1_phi;
   Float_t         Jpsi_m1_mass;
   Int_t           Jpsi_m1_q;
   Float_t         Jpsi_m1_vx;
   Float_t         Jpsi_m1_vy;
   Float_t         Jpsi_m1_vz;
   Float_t         Jpsi_m1_looseId;

   // [WIP] L1
   Float_t         Jpsi_m1_bestL1pt;
   Float_t         Jpsi_m1_bestL1eta;
   Float_t         Jpsi_m1_bestL1phi;
   Float_t         Jpsi_m1_bestL1Deta;
   Float_t         Jpsi_m1_bestL1Dphi;

   // Online mu for sig HLT [ask match]
   Int_t           Jpsi_m1_Dimu_match;
   Float_t         Jpsi_m1_Dimu_pt;
   Float_t         Jpsi_m1_Dimu_eta;
   Float_t         Jpsi_m1_Dimu_phi;


   /*** subleading mu ***/
   // Offline
   Float_t         Jpsi_m2_pt;
   Float_t         Jpsi_m2_eta;
   Float_t         Jpsi_m2_phi;
   Float_t         Jpsi_m2_mass;
   Int_t           Jpsi_m2_alsotag;
   Int_t           Jpsi_m2_q;
   Float_t         Jpsi_m2_vx;
   Float_t         Jpsi_m2_vy;
   Float_t         Jpsi_m2_vz;
   Float_t         Jpsi_m2_looseId;

   // L1
   Float_t         Jpsi_m2_bestL1pt;
   Float_t         Jpsi_m2_bestL1eta;
   Float_t         Jpsi_m2_bestL1phi;
   Float_t         Jpsi_m2_bestL1Deta;
   Float_t         Jpsi_m2_bestL1Dphi;
   
   // DoubleMu vars 
   Int_t           Jpsi_m2_Dimu_match;
   Float_t         Jpsi_m2_Dimu_pt;
   Float_t         Jpsi_m2_Dimu_eta;
   Float_t         Jpsi_m2_Dimu_phi;

   Int_t           DoubleMu_fired;

   // Online mu for ref HLT [ask match]
   Float_t         Jpsi_m1_trgobj_pt;
   Float_t         Jpsi_m1_trgobj_eta;
   Float_t         Jpsi_m1_trgobj_phi;
   Float_t         Jpsi_m1_trgobj_mass;
   Int_t           Jpsi_m1_trgobj_q;
   Float_t         Jpsi_m1_trgobj_vx;
   Float_t         Jpsi_m1_trgobj_vy;
   Float_t         Jpsi_m1_trgobj_vz;
   Float_t         Jpsi_m2_trgobj_pt;
   Float_t         Jpsi_m2_trgobj_eta;
   Float_t         Jpsi_m2_trgobj_phi;
   Float_t         Jpsi_m2_trgobj_mass;
   Int_t           Jpsi_m2_trgobj_q;
   Float_t         Jpsi_m2_trgobj_vx;
   Float_t         Jpsi_m2_trgobj_vy;
   Float_t         Jpsi_m2_trgobj_vz;


   /*** Jpsi vars ***/
   Float_t         Jpsi_fit_pt;
   Float_t         Jpsi_nonfit_pt;
   Float_t         Jpsi_fit_eta;
   Float_t         Jpsi_nonfit_eta;
   Float_t         Jpsi_fit_phi;
   Float_t         Jpsi_nonfit_phi;
   Float_t         Jpsi_fit_mass;
   Float_t         Jpsi_nonfit_mass;
   Float_t         Jpsi_fit_vprob;
   Float_t         Jpsi_muonsDr;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_Jpsi_m1_pt;   //!
   TBranch        *b_Jpsi_m1_eta;   //!
   TBranch        *b_Jpsi_m1_phi;   //!
   TBranch        *b_Jpsi_m1_mass;   //!
   TBranch        *b_Jpsi_m1_q;   //!
   TBranch        *b_Jpsi_m1_vx;   //!
   TBranch        *b_Jpsi_m1_vy;   //!
   TBranch        *b_Jpsi_m1_vz;   //!
   TBranch        *b_Jpsi_m1_looseId;   //!
   TBranch        *b_Jpsi_m1_bestL1pt;   //!
   TBranch        *b_Jpsi_m1_bestL1eta;   //!
   TBranch        *b_Jpsi_m1_bestL1phi;   //!
   TBranch        *b_Jpsi_m1_bestL1Deta;   //!
   TBranch        *b_Jpsi_m1_bestL1Dphi;   //!
   TBranch        *b_Jpsi_m1_Dimu_match;   //!
   TBranch        *b_Jpsi_m1_Dimu_pt;   //!
   TBranch        *b_Jpsi_m1_Dimu_eta;   //!
   TBranch        *b_Jpsi_m1_Dimu_phi;   //!
   TBranch        *b_Jpsi_m2_pt;   //!
   TBranch        *b_Jpsi_m2_eta;   //!
   TBranch        *b_Jpsi_m2_phi;   //!
   TBranch        *b_Jpsi_m2_mass;   //!
   TBranch        *b_Jpsi_m2_alsotag;   //!
   TBranch        *b_Jpsi_m2_q;   //!
   TBranch        *b_Jpsi_m2_vx;   //!
   TBranch        *b_Jpsi_m2_vy;   //!
   TBranch        *b_Jpsi_m2_vz;   //!
   TBranch        *b_Jpsi_m2_looseId;   //!
   TBranch        *b_Jpsi_m2_bestL1pt;   //!
   TBranch        *b_Jpsi_m2_bestL1eta;   //!
   TBranch        *b_Jpsi_m2_bestL1phi;   //!
   TBranch        *b_Jpsi_m2_bestL1Deta;   //!
   TBranch        *b_Jpsi_m2_bestL1Dphi;   //!
   TBranch        *b_Jpsi_m2_Dimu_match;   //!
   TBranch        *b_Jpsi_m2_Dimu_pt;   //!
   TBranch        *b_Jpsi_m2_Dimu_eta;   //!
   TBranch        *b_Jpsi_m2_Dimu_phi;   //!
   TBranch        *b_DoubleMu_fired;   //!
   TBranch        *b_Jpsi_m1_trgobj_pt;   //!
   TBranch        *b_Jpsi_m1_trgobj_eta;   //!
   TBranch        *b_Jpsi_m1_trgobj_phi;   //!
   TBranch        *b_Jpsi_m1_trgobj_mass;   //!
   TBranch        *b_Jpsi_m1_trgobj_q;   //!
   TBranch        *b_Jpsi_m1_trgobj_vx;   //!
   TBranch        *b_Jpsi_m1_trgobj_vy;   //!
   TBranch        *b_Jpsi_m1_trgobj_vz;   //!
   TBranch        *b_Jpsi_m2_trgobj_pt;   //!
   TBranch        *b_Jpsi_m2_trgobj_eta;   //!
   TBranch        *b_Jpsi_m2_trgobj_phi;   //!
   TBranch        *b_Jpsi_m2_trgobj_mass;   //!
   TBranch        *b_Jpsi_m2_trgobj_q;   //!
   TBranch        *b_Jpsi_m2_trgobj_vx;   //!
   TBranch        *b_Jpsi_m2_trgobj_vy;   //!
   TBranch        *b_Jpsi_m2_trgobj_vz;   //!
   TBranch        *b_Jpsi_fit_pt;   //!
   TBranch        *b_Jpsi_nonfit_pt;   //!
   TBranch        *b_Jpsi_fit_eta;   //!
   TBranch        *b_Jpsi_nonfit_eta;   //!
   TBranch        *b_Jpsi_fit_phi;   //!
   TBranch        *b_Jpsi_nonfit_phi;   //!
   TBranch        *b_Jpsi_fit_mass;   //!
   TBranch        *b_Jpsi_nonfit_mass;   //!
   TBranch        *b_Jpsi_fit_vprob;   //!
   TBranch        *b_Jpsi_muonsDr;   //!

   tree(TTree *tree=0);
   virtual ~tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tree_cxx
tree::tree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_2022D_LowMass0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_2022D_LowMass0.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_2022D_LowMass0.root:/nano_");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

tree::~tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("Jpsi_m1_pt", &Jpsi_m1_pt, &b_Jpsi_m1_pt);
   fChain->SetBranchAddress("Jpsi_m1_eta", &Jpsi_m1_eta, &b_Jpsi_m1_eta);
   fChain->SetBranchAddress("Jpsi_m1_phi", &Jpsi_m1_phi, &b_Jpsi_m1_phi);
   fChain->SetBranchAddress("Jpsi_m1_mass", &Jpsi_m1_mass, &b_Jpsi_m1_mass);
   fChain->SetBranchAddress("Jpsi_m1_q", &Jpsi_m1_q, &b_Jpsi_m1_q);
   fChain->SetBranchAddress("Jpsi_m1_vx", &Jpsi_m1_vx, &b_Jpsi_m1_vx);
   fChain->SetBranchAddress("Jpsi_m1_vy", &Jpsi_m1_vy, &b_Jpsi_m1_vy);
   fChain->SetBranchAddress("Jpsi_m1_vz", &Jpsi_m1_vz, &b_Jpsi_m1_vz);
   fChain->SetBranchAddress("Jpsi_m1_looseId", &Jpsi_m1_looseId, &b_Jpsi_m1_looseId);
   fChain->SetBranchAddress("Jpsi_m1_bestL1pt", &Jpsi_m1_bestL1pt, &b_Jpsi_m1_bestL1pt);
   fChain->SetBranchAddress("Jpsi_m1_bestL1eta", &Jpsi_m1_bestL1eta, &b_Jpsi_m1_bestL1eta);
   fChain->SetBranchAddress("Jpsi_m1_bestL1phi", &Jpsi_m1_bestL1phi, &b_Jpsi_m1_bestL1phi);
   fChain->SetBranchAddress("Jpsi_m1_bestL1Deta", &Jpsi_m1_bestL1Deta, &b_Jpsi_m1_bestL1Deta);
   fChain->SetBranchAddress("Jpsi_m1_bestL1Dphi", &Jpsi_m1_bestL1Dphi, &b_Jpsi_m1_bestL1Dphi);
   fChain->SetBranchAddress("Jpsi_m1_Dimu_match", &Jpsi_m1_Dimu_match, &b_Jpsi_m1_Dimu_match);
   fChain->SetBranchAddress("Jpsi_m1_Dimu_pt", &Jpsi_m1_Dimu_pt, &b_Jpsi_m1_Dimu_pt);
   fChain->SetBranchAddress("Jpsi_m1_Dimu_eta", &Jpsi_m1_Dimu_eta, &b_Jpsi_m1_Dimu_eta);
   fChain->SetBranchAddress("Jpsi_m1_Dimu_phi", &Jpsi_m1_Dimu_phi, &b_Jpsi_m1_Dimu_phi);
   fChain->SetBranchAddress("Jpsi_m2_pt", &Jpsi_m2_pt, &b_Jpsi_m2_pt);
   fChain->SetBranchAddress("Jpsi_m2_eta", &Jpsi_m2_eta, &b_Jpsi_m2_eta);
   fChain->SetBranchAddress("Jpsi_m2_phi", &Jpsi_m2_phi, &b_Jpsi_m2_phi);
   fChain->SetBranchAddress("Jpsi_m2_mass", &Jpsi_m2_mass, &b_Jpsi_m2_mass);
   fChain->SetBranchAddress("Jpsi_m2_alsotag", &Jpsi_m2_alsotag, &b_Jpsi_m2_alsotag);
   fChain->SetBranchAddress("Jpsi_m2_q", &Jpsi_m2_q, &b_Jpsi_m2_q);
   fChain->SetBranchAddress("Jpsi_m2_vx", &Jpsi_m2_vx, &b_Jpsi_m2_vx);
   fChain->SetBranchAddress("Jpsi_m2_vy", &Jpsi_m2_vy, &b_Jpsi_m2_vy);
   fChain->SetBranchAddress("Jpsi_m2_vz", &Jpsi_m2_vz, &b_Jpsi_m2_vz);
   fChain->SetBranchAddress("Jpsi_m2_looseId", &Jpsi_m2_looseId, &b_Jpsi_m2_looseId);
   fChain->SetBranchAddress("Jpsi_m2_bestL1pt", &Jpsi_m2_bestL1pt, &b_Jpsi_m2_bestL1pt);
   fChain->SetBranchAddress("Jpsi_m2_bestL1eta", &Jpsi_m2_bestL1eta, &b_Jpsi_m2_bestL1eta);
   fChain->SetBranchAddress("Jpsi_m2_bestL1phi", &Jpsi_m2_bestL1phi, &b_Jpsi_m2_bestL1phi);
   fChain->SetBranchAddress("Jpsi_m2_bestL1Deta", &Jpsi_m2_bestL1Deta, &b_Jpsi_m2_bestL1Deta);
   fChain->SetBranchAddress("Jpsi_m2_bestL1Dphi", &Jpsi_m2_bestL1Dphi, &b_Jpsi_m2_bestL1Dphi);
   fChain->SetBranchAddress("Jpsi_m2_Dimu_match", &Jpsi_m2_Dimu_match, &b_Jpsi_m2_Dimu_match);
   fChain->SetBranchAddress("Jpsi_m2_Dimu_pt", &Jpsi_m2_Dimu_pt, &b_Jpsi_m2_Dimu_pt);
   fChain->SetBranchAddress("Jpsi_m2_Dimu_eta", &Jpsi_m2_Dimu_eta, &b_Jpsi_m2_Dimu_eta);
   fChain->SetBranchAddress("Jpsi_m2_Dimu_phi", &Jpsi_m2_Dimu_phi, &b_Jpsi_m2_Dimu_phi);
   fChain->SetBranchAddress("DoubleMu_fired", &DoubleMu_fired, &b_DoubleMu_fired);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_pt", &Jpsi_m1_trgobj_pt, &b_Jpsi_m1_trgobj_pt);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_eta", &Jpsi_m1_trgobj_eta, &b_Jpsi_m1_trgobj_eta);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_phi", &Jpsi_m1_trgobj_phi, &b_Jpsi_m1_trgobj_phi);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_mass", &Jpsi_m1_trgobj_mass, &b_Jpsi_m1_trgobj_mass);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_q", &Jpsi_m1_trgobj_q, &b_Jpsi_m1_trgobj_q);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_vx", &Jpsi_m1_trgobj_vx, &b_Jpsi_m1_trgobj_vx);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_vy", &Jpsi_m1_trgobj_vy, &b_Jpsi_m1_trgobj_vy);
   fChain->SetBranchAddress("Jpsi_m1_trgobj_vz", &Jpsi_m1_trgobj_vz, &b_Jpsi_m1_trgobj_vz);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_pt", &Jpsi_m2_trgobj_pt, &b_Jpsi_m2_trgobj_pt);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_eta", &Jpsi_m2_trgobj_eta, &b_Jpsi_m2_trgobj_eta);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_phi", &Jpsi_m2_trgobj_phi, &b_Jpsi_m2_trgobj_phi);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_mass", &Jpsi_m2_trgobj_mass, &b_Jpsi_m2_trgobj_mass);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_q", &Jpsi_m2_trgobj_q, &b_Jpsi_m2_trgobj_q);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_vx", &Jpsi_m2_trgobj_vx, &b_Jpsi_m2_trgobj_vx);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_vy", &Jpsi_m2_trgobj_vy, &b_Jpsi_m2_trgobj_vy);
   fChain->SetBranchAddress("Jpsi_m2_trgobj_vz", &Jpsi_m2_trgobj_vz, &b_Jpsi_m2_trgobj_vz);
   fChain->SetBranchAddress("Jpsi_fit_pt", &Jpsi_fit_pt, &b_Jpsi_fit_pt);
   fChain->SetBranchAddress("Jpsi_nonfit_pt", &Jpsi_nonfit_pt, &b_Jpsi_nonfit_pt);
   fChain->SetBranchAddress("Jpsi_fit_eta", &Jpsi_fit_eta, &b_Jpsi_fit_eta);
   fChain->SetBranchAddress("Jpsi_nonfit_eta", &Jpsi_nonfit_eta, &b_Jpsi_nonfit_eta);
   fChain->SetBranchAddress("Jpsi_fit_phi", &Jpsi_fit_phi, &b_Jpsi_fit_phi);
   fChain->SetBranchAddress("Jpsi_nonfit_phi", &Jpsi_nonfit_phi, &b_Jpsi_nonfit_phi);
   fChain->SetBranchAddress("Jpsi_fit_mass", &Jpsi_fit_mass, &b_Jpsi_fit_mass);
   fChain->SetBranchAddress("Jpsi_nonfit_mass", &Jpsi_nonfit_mass, &b_Jpsi_nonfit_mass);
   fChain->SetBranchAddress("Jpsi_fit_vprob", &Jpsi_fit_vprob, &b_Jpsi_fit_vprob);
   fChain->SetBranchAddress("Jpsi_muonsDr", &Jpsi_muonsDr, &b_Jpsi_muonsDr);
   Notify();
}

Bool_t tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_cxx
