//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb 20 18:07:35 2023 by ROOT version 6.24/08
// from TTree Events/Events
// found on file: /eos/cms/store/group/phys_bphys/crovelli/nanoaod_X/Xnani2022_2023Feb16/BPH_BToPsi2SKs_Psi2SToJPsiPiPi_JPsiToMuMu_McM_Run3/crab_BdToPsi2SKs2022/230216_122106/2023-02-20T103412Z_merged.root
//////////////////////////////////////////////////////////

#ifndef Events_h
#define Events_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Events {
public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

  // Fixed size dimensions of array or collections stored in the TTree if any.

  // Declaration of leaf types
  UInt_t          run;
  UInt_t          luminosityBlock;
  ULong64_t       event;
  UInt_t          bunchCrossing;

  // GENERAL EVENT DATA
  UInt_t          nB0; // reconstructed #B0 per event
  UInt_t          npipi;
  UInt_t          nK0s;
  UInt_t          nMuon;
  UInt_t          nJPsiToMuMu;

  // GENERATOR DATA
  UInt_t          nGenPart;
  Float_t         GenPart_eta[73];   //[nGenPart]
  Float_t         GenPart_mass[73];   //[nGenPart]
  Float_t         GenPart_phi[73];   //[nGenPart]
  Float_t         GenPart_pt[73];   //[nGenPart]
  Float_t         GenPart_vx[73];   //[nGenPart]
  Float_t         GenPart_vy[73];   //[nGenPart]
  Float_t         GenPart_vz[73];   //[nGenPart]
  Int_t           GenPart_genPartIdxMother[73];   //[nGenPart]
  Int_t           GenPart_pdgId[73];   //[nGenPart]
  Int_t           GenPart_status[73];   //[nGenPart]
  Int_t           GenPart_statusFlags[73];   //[nGenPart]

  // TRIGGER DATA
  Int_t           HLT_Dimuon25_Jpsi;
  Int_t           HLT_DoubleMu4_JpsiTrk_Bc;
  Int_t           HLT_DoubleMu4_JpsiTrkTrk_Displaced;
  Int_t           HLT_DoubleMu4_LowMass_Displaced;
  Int_t           HLT_DoubleMu4_MuMuTrk_Displaced;
  Int_t           HLT_DoubleMu4_3_LowMass;
  
  // RECO B0
  Float_t         B0_BSxRaw[14];   //[nB0]
  Float_t         B0_BSxWithZ[14];   //[nB0]
  Float_t         B0_BSyRaw[14];   //[nB0]
  Float_t         B0_BSyWithZ[14];   //[nB0]

  // which particles have been matched to each B0
  Int_t           B0_mu1_idx[14];   //[nB0]
  Int_t           B0_mu2_idx[14];   //[nB0]
  Int_t           B0_pi1_idx[14];   //[nB0]
  Int_t           B0_pi2_idx[14];   //[nB0]
  Int_t           B0_pv3D_idx[14];   //[nB0]
  Int_t           B0_k0short_idx[14];   //[nB0]

  Float_t         B0_K0_cosAlpha3D[14];   //[nB0]
  Float_t         B0_K0_lxySign_wrtBvtx[14];   //[nB0]

  // for the K0s, they also saved the kinematics of the pipi matched to it
  // - pi1
  Float_t         B0_K0s_matchTrack1_D0sign[14];   //[nB0]
  Float_t         B0_K0s_matchTrack1_dR[14];   //[nB0]
  Float_t         B0_K0s_matchTrack1_eta[14];   //[nB0]
  Float_t         B0_K0s_matchTrack1_maxD0Pv[14];   //[nB0]
  Float_t         B0_K0s_matchTrack1_minD0Pv[14];   //[nB0]
  Float_t         B0_K0s_matchTrack1_phi[14];   //[nB0]
  Float_t         B0_K0s_matchTrack1_pt[14];   //[nB0]
  // - pi2
  Float_t         B0_K0s_matchTrack2_D0sign[14];   //[nB0]
  Float_t         B0_K0s_matchTrack2_dR[14];   //[nB0]
  Float_t         B0_K0s_matchTrack2_eta[14];   //[nB0]
  Float_t         B0_K0s_matchTrack2_maxD0Pv[14];   //[nB0]
  Float_t         B0_K0s_matchTrack2_minD0Pv[14];   //[nB0]
  Float_t         B0_K0s_matchTrack2_phi[14];   //[nB0]
  Float_t         B0_K0s_matchTrack2_pt[14];   //[nB0]

  Float_t         B0_K0s_mcFitted_eta[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_mass[14];   //[nB0] <-- fixed by mc: constrained to pdg_K0s_mass
  Float_t         B0_K0s_mcFitted_phi[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_pt[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_svprob[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_vtxX[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_vtxXE[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_vtxY[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_vtxYE[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_vtxZ[14];   //[nB0]
  Float_t         B0_K0s_mcFitted_vtxZE[14];   //[nB0]

  Float_t         B0_K0s_nmcFitted_mass[14];   //[nB0]
  Float_t         B0_K0s_nmcFitted_pi1eta[14];   //[nB0]
  Float_t         B0_K0s_nmcFitted_pi1phi[14];   //[nB0]
  Float_t         B0_K0s_nmcFitted_pi1pt[14];   //[nB0]
  Float_t         B0_K0s_nmcFitted_pi2eta[14];   //[nB0]
  Float_t         B0_K0s_nmcFitted_pi2phi[14];   //[nB0]
  Float_t         B0_K0s_nmcFitted_pi2pt[14];   //[nB0]
  Float_t         B0_K0s_prefit_mass[14];   //[nB0]


  Float_t         B0_MuMu_DCA[14];   //[nB0]
  Float_t         B0_MuMu_LxySign[14];   //[nB0]
  Float_t         B0_MuMu_cosAlpha[14];   //[nB0]
  Float_t         B0_MuMu_fitted_eta[14];   //[nB0]
  Float_t         B0_MuMu_fitted_mass[14];   //[nB0]
  Float_t         B0_MuMu_fitted_phi[14];   //[nB0]
  Float_t         B0_MuMu_fitted_pt[14];   //[nB0]
  Float_t         B0_MuMu_fitted_vtxX[14];   //[nB0]
  Float_t         B0_MuMu_fitted_vtxXE[14];   //[nB0]
  Float_t         B0_MuMu_fitted_vtxY[14];   //[nB0]
  Float_t         B0_MuMu_fitted_vtxYE[14];   //[nB0]
  Float_t         B0_MuMu_fitted_vtxZ[14];   //[nB0]
  Float_t         B0_MuMu_fitted_vtxZE[14];   //[nB0]

  Float_t         B0_MuMu_mu1_dr[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dr_Dimuon25_Jpsi[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dr_DoubleMu4_3_LowMass[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dr_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dr_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dr_DoubleMu4_LowMass_Displaced[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dr_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dxysign[14];   //[nB0]
  Float_t         B0_MuMu_mu1_dzsign[14];   //[nB0]

  Float_t         B0_MuMu_mu2_dr[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dr_Dimuon25_Jpsi[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dr_DoubleMu4_3_LowMass[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dr_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dr_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dr_DoubleMu4_LowMass_Displaced[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dr_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dxysign[14];   //[nB0]
  Float_t         B0_MuMu_mu2_dzsign[14];   //[nB0]

  Float_t         B0_MuMu_prefit_mu1_eta[14];   //[nB0]
  Float_t         B0_MuMu_prefit_mu1_phi[14];   //[nB0]
  Float_t         B0_MuMu_prefit_mu1_pt[14];   //[nB0]
  Float_t         B0_MuMu_prefit_mu2_eta[14];   //[nB0]
  Float_t         B0_MuMu_prefit_mu2_phi[14];   //[nB0]
  Float_t         B0_MuMu_prefit_mu2_pt[14];   //[nB0]
  Float_t         B0_MuMu_sv_prob[14];   //[nB0] <-- output of kinematic vertex fit


  Float_t         B0_PiPi_p1_dr_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Float_t         B0_PiPi_p1_dr_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Float_t         B0_PiPi_p1_dr_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Float_t         B0_PiPi_p2_dr_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Float_t         B0_PiPi_p2_dr_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Float_t         B0_PiPi_p2_dr_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]

  Float_t         B0_PiPi_pi1_d0sig[14];   //[nB0]
  Float_t         B0_PiPi_pi1_dxysign[14];   //[nB0]
  Float_t         B0_PiPi_pi1_dzsign[14];   //[nB0]
  Float_t         B0_PiPi_pi1_maxd0PV[14];   //[nB0]
  Float_t         B0_PiPi_pi1_mind0PV[14];   //[nB0]

  Float_t         B0_PiPi_pi2_d0sig[14];   //[nB0]
  Float_t         B0_PiPi_pi2_dxysign[14];   //[nB0]
  Float_t         B0_PiPi_pi2_dzsign[14];   //[nB0]
  Float_t         B0_PiPi_pi2_maxd0PV[14];   //[nB0]
  Float_t         B0_PiPi_pi2_mind0PV[14];   //[nB0]

  Float_t         B0_PiPi_prefit_pi1_eta[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi1_phi[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi1_pt[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi1_vx[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi1_vy[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi1_vz[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi2_eta[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi2_phi[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi2_pt[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi2_vx[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi2_vy[14];   //[nB0]
  Float_t         B0_PiPi_prefit_pi2_vz[14];   //[nB0]
  Float_t         B0_PiPi_sv_prob[14];   //[nB0]

  Float_t         B0_PVEx[14];   //[nB0]
  Float_t         B0_PVEy[14];   //[nB0]
  Float_t         B0_PVEz[14];   //[nB0]
  Float_t         B0_PVx[14];   //[nB0]
  Float_t         B0_PVy[14];   //[nB0]
  Float_t         B0_PVz[14];   //[nB0]
  
  Float_t         B0_cosAlpha2D_BS[14];   //[nB0]
  Float_t         B0_cosAlpha2D_BSwithZ[14];   //[nB0]
  Float_t         B0_cosAlpha3D_PV[14];   //[nB0]
  Float_t         B0_decayVtxX[14];   //[nB0]
  Float_t         B0_decayVtxXE[14];   //[nB0]
  Float_t         B0_decayVtxY[14];   //[nB0]
  Float_t         B0_decayVtxYE[14];   //[nB0]
  Float_t         B0_decayVtxZ[14];   //[nB0]
  Float_t         B0_decayVtxZE[14];   //[nB0]

  Float_t         B0_finalFit_JPsi_mass[14];   //[nB0]
  Float_t         B0_finalFit_Rho_mass[14];   //[nB0]
  Float_t         B0_finalFit_X_mass[14];   //[nB0]
  Float_t         B0_finalFit_eta[14];   //[nB0]
  Float_t         B0_finalFit_k0s_eta[14];   //[nB0]
  Float_t         B0_finalFit_k0s_phi[14];   //[nB0]
  Float_t         B0_finalFit_k0s_pt[14];   //[nB0]
  Float_t         B0_finalFit_mass[14];   //[nB0]
  Float_t         B0_finalFit_mu1_eta[14];   //[nB0]
  Float_t         B0_finalFit_mu1_phi[14];   //[nB0]
  Float_t         B0_finalFit_mu1_pt[14];   //[nB0]
  Float_t         B0_finalFit_mu2_eta[14];   //[nB0]
  Float_t         B0_finalFit_mu2_phi[14];   //[nB0]
  Float_t         B0_finalFit_mu2_pt[14];   //[nB0]
  Float_t         B0_finalFit_phi[14];   //[nB0]
  Float_t         B0_finalFit_pi1_eta[14];   //[nB0]
  Float_t         B0_finalFit_pi1_phi[14];   //[nB0]
  Float_t         B0_finalFit_pi1_pt[14];   //[nB0]
  Float_t         B0_finalFit_pi2_eta[14];   //[nB0]
  Float_t         B0_finalFit_pi2_phi[14];   //[nB0]
  Float_t         B0_finalFit_pi2_pt[14];   //[nB0]
  Float_t         B0_finalFit_pt[14];   //[nB0]
  Float_t         B0_fitted_mass_womc[14];   //[nB0]

  Float_t         B0_lxySign_BS[14];   //[nB0]
  Float_t         B0_lxySign_BSwithZ[14];   //[nB0]
  Float_t         B0_lxySign_PV[14];   //[nB0]
  Float_t         B0_svchi2[14];   //[nB0]
  Float_t         B0_svprob[14];   //[nB0]

  Int_t           B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Int_t           B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Int_t           B0_K0s_matchTrack1_fired_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Int_t           B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Int_t           B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Int_t           B0_K0s_matchTrack2_fired_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu1_fired_Dimuon25_Jpsi[14];   //[nB0]
  Int_t           B0_MuMu_mu1_fired_DoubleMu4_3_LowMass[14];   //[nB0]
  Int_t           B0_MuMu_mu1_fired_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu1_fired_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Int_t           B0_MuMu_mu1_fired_DoubleMu4_LowMass_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu1_fired_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu1_trackQuality[14];   //[nB0]
  Int_t           B0_MuMu_mu2_fired_Dimuon25_Jpsi[14];   //[nB0]
  Int_t           B0_MuMu_mu2_fired_DoubleMu4_3_LowMass[14];   //[nB0]
  Int_t           B0_MuMu_mu2_fired_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu2_fired_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Int_t           B0_MuMu_mu2_fired_DoubleMu4_LowMass_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu2_fired_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Int_t           B0_MuMu_mu2_trackQuality[14];   //[nB0]
  Int_t           B0_PiPi_p1_fired_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Int_t           B0_PiPi_p1_fired_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Int_t           B0_PiPi_p1_fired_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]
  Int_t           B0_PiPi_p2_fired_DoubleMu4_JpsiTrkTrk_Displaced[14];   //[nB0]
  Int_t           B0_PiPi_p2_fired_DoubleMu4_JpsiTrk_Bc[14];   //[nB0]
  Int_t           B0_PiPi_p2_fired_DoubleMu4_MuMuTrk_Displaced[14];   //[nB0]

  Int_t           B0_dimuon_idx[14];   //[nB0]
  Int_t           B0_dipion_idx[14];   //[nB0]

  Float_t         BeamSpot_sigmaZ;
  Float_t         BeamSpot_sigmaZError;
  Float_t         BeamSpot_z;
  Float_t         BeamSpot_zError;
  Char_t          BeamSpot_type;
  
  Float_t         Generator_binvar;
  Float_t         Generator_scalePDF;
  Float_t         Generator_weight;
  Float_t         Generator_x1;
  Float_t         Generator_x2;
  Float_t         Generator_xpdf1;
  Float_t         Generator_xpdf2;
  Int_t           Generator_id1;
  Int_t           Generator_id2;
  Float_t         genWeight;
  UInt_t          nPSWeight;
  Float_t         PSWeight[1];   //[nPSWeight]

  Int_t           Muon_trackQuality[13];   //[nMuon]
  Bool_t          Muon_charge[13];   //[nMuon]
  Bool_t          Muon_isGlobal[13];   //[nMuon]
  Bool_t          Muon_looseId[13];   //[nMuon]
  Bool_t          Muon_softId[13];   //[nMuon]
  Float_t         Pileup_nTrueInt;
  Float_t         Pileup_pudensity;
  Float_t         Pileup_gpudensity;
  Int_t           Pileup_nPU;
  Int_t           Pileup_sumEOOT;
  Int_t           Pileup_sumLOOT;
  Float_t         Rho_fixedGridRhoAll;
  Float_t         Rho_fixedGridRhoFastjetAll;
  Float_t         Rho_fixedGridRhoFastjetCentral;
  Float_t         Rho_fixedGridRhoFastjetCentralCalo;
  Float_t         Rho_fixedGridRhoFastjetCentralChargedPileUp;
  Float_t         Rho_fixedGridRhoFastjetCentralNeutral;
  UInt_t          nProbeTracks;
  Int_t           ProbeTracks_nValidHits[1225];   //[nProbeTracks]
  Bool_t          ProbeTracks_isMatchedToLooseMuon[1225];   //[nProbeTracks]
  Bool_t          ProbeTracks_isMatchedToMuon[1225];   //[nProbeTracks]
  Bool_t          ProbeTracks_isMatchedToSoftMuon[1225];   //[nProbeTracks]
  UInt_t          nTrigObj;
  Float_t         TrigObj_pt[4];   //[nTrigObj]
  Float_t         TrigObj_eta[4];   //[nTrigObj]
  Float_t         TrigObj_phi[4];   //[nTrigObj]
  Int_t           TrigObj_id[4];   //[nTrigObj]
  UInt_t          nOtherPV;
  Float_t         OtherPV_z[3];   //[nOtherPV]
  Float_t         OtherPV_score[3];   //[nOtherPV]
  Float_t         PV_ndof;
  Float_t         PV_x;
  Float_t         PV_y;
  Float_t         PV_z;
  Float_t         PV_chi2;
  Float_t         PV_score;
  Int_t           PV_npvs;
  Int_t           PV_npvsGood;
  UInt_t          nSV;
  Float_t         SV_dlen[6];   //[nSV]
  Float_t         SV_dlenSig[6];   //[nSV]
  Float_t         SV_dxy[6];   //[nSV]
  Float_t         SV_dxySig[6];   //[nSV]
  Float_t         SV_pAngle[6];   //[nSV]
  Int_t           SV_charge[6];   //[nSV]
  Int_t           Muon_genPartIdx[13];   //[nMuon]
  Int_t           Muon_genPartFlav[13];   //[nMuon]
  Float_t         SV_chi2[6];   //[nSV]
  Float_t         SV_eta[6];   //[nSV]
  Float_t         SV_mass[6];   //[nSV]
  Float_t         SV_ndof[6];   //[nSV]
  Float_t         SV_phi[6];   //[nSV]
  Float_t         SV_pt[6];   //[nSV]
  Float_t         SV_x[6];   //[nSV]
  Float_t         SV_y[6];   //[nSV]
  Float_t         SV_z[6];   //[nSV]
  UChar_t         SV_ntracks[6];   //[nSV]
  Int_t           ProbeTracks_genPartIdx[1225];   //[nProbeTracks]
  Int_t           ProbeTracks_genPartFlav[1225];   //[nProbeTracks]

  // List of branches
  TBranch        *b_run;   //!
  TBranch        *b_luminosityBlock;   //!
  TBranch        *b_event;   //!
  TBranch        *b_bunchCrossing;   //!
  TBranch        *b_nB0;   //!
  TBranch        *b_B0_BSxRaw;   //!
  TBranch        *b_B0_BSxWithZ;   //!
  TBranch        *b_B0_BSyRaw;   //!
  TBranch        *b_B0_BSyWithZ;   //!
  TBranch        *b_B0_K0_cosAlpha3D;   //!
  TBranch        *b_B0_K0_lxySign_wrtBvtx;   //!
  TBranch        *b_B0_K0s_matchTrack1_D0sign;   //!
  TBranch        *b_B0_K0s_matchTrack1_dR;   //!
  TBranch        *b_B0_K0s_matchTrack1_eta;   //!
  TBranch        *b_B0_K0s_matchTrack1_maxD0Pv;   //!
  TBranch        *b_B0_K0s_matchTrack1_minD0Pv;   //!
  TBranch        *b_B0_K0s_matchTrack1_phi;   //!
  TBranch        *b_B0_K0s_matchTrack1_pt;   //!
  TBranch        *b_B0_K0s_matchTrack2_D0sign;   //!
  TBranch        *b_B0_K0s_matchTrack2_dR;   //!
  TBranch        *b_B0_K0s_matchTrack2_eta;   //!
  TBranch        *b_B0_K0s_matchTrack2_maxD0Pv;   //!
  TBranch        *b_B0_K0s_matchTrack2_minD0Pv;   //!
  TBranch        *b_B0_K0s_matchTrack2_phi;   //!
  TBranch        *b_B0_K0s_matchTrack2_pt;   //!
  TBranch        *b_B0_K0s_mcFitted_eta;   //!
  TBranch        *b_B0_K0s_mcFitted_mass;   //!
  TBranch        *b_B0_K0s_mcFitted_phi;   //!
  TBranch        *b_B0_K0s_mcFitted_pt;   //!
  TBranch        *b_B0_K0s_mcFitted_svprob;   //!
  TBranch        *b_B0_K0s_mcFitted_vtxX;   //!
  TBranch        *b_B0_K0s_mcFitted_vtxXE;   //!
  TBranch        *b_B0_K0s_mcFitted_vtxY;   //!
  TBranch        *b_B0_K0s_mcFitted_vtxYE;   //!
  TBranch        *b_B0_K0s_mcFitted_vtxZ;   //!
  TBranch        *b_B0_K0s_mcFitted_vtxZE;   //!
  TBranch        *b_B0_K0s_nmcFitted_mass;   //!
  TBranch        *b_B0_K0s_nmcFitted_pi1eta;   //!
  TBranch        *b_B0_K0s_nmcFitted_pi1phi;   //!
  TBranch        *b_B0_K0s_nmcFitted_pi1pt;   //!
  TBranch        *b_B0_K0s_nmcFitted_pi2eta;   //!
  TBranch        *b_B0_K0s_nmcFitted_pi2phi;   //!
  TBranch        *b_B0_K0s_nmcFitted_pi2pt;   //!
  TBranch        *b_B0_K0s_prefit_mass;   //!
  TBranch        *b_B0_MuMu_DCA;   //!
  TBranch        *b_B0_MuMu_LxySign;   //!
  TBranch        *b_B0_MuMu_cosAlpha;   //!
  TBranch        *b_B0_MuMu_fitted_eta;   //!
  TBranch        *b_B0_MuMu_fitted_mass;   //!
  TBranch        *b_B0_MuMu_fitted_phi;   //!
  TBranch        *b_B0_MuMu_fitted_pt;   //!
  TBranch        *b_B0_MuMu_fitted_vtxX;   //!
  TBranch        *b_B0_MuMu_fitted_vtxXE;   //!
  TBranch        *b_B0_MuMu_fitted_vtxY;   //!
  TBranch        *b_B0_MuMu_fitted_vtxYE;   //!
  TBranch        *b_B0_MuMu_fitted_vtxZ;   //!
  TBranch        *b_B0_MuMu_fitted_vtxZE;   //!
  TBranch        *b_B0_MuMu_mu1_dr;   //!
  TBranch        *b_B0_MuMu_mu1_dr_Dimuon25_Jpsi;   //!
  TBranch        *b_B0_MuMu_mu1_dr_DoubleMu4_3_LowMass;   //!
  TBranch        *b_B0_MuMu_mu1_dr_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_dr_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_MuMu_mu1_dr_DoubleMu4_LowMass_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_dr_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_dxysign;   //!
  TBranch        *b_B0_MuMu_mu1_dzsign;   //!
  TBranch        *b_B0_MuMu_mu2_dr;   //!
  TBranch        *b_B0_MuMu_mu2_dr_Dimuon25_Jpsi;   //!
  TBranch        *b_B0_MuMu_mu2_dr_DoubleMu4_3_LowMass;   //!
  TBranch        *b_B0_MuMu_mu2_dr_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu2_dr_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_MuMu_mu2_dr_DoubleMu4_LowMass_Displaced;   //!
  TBranch        *b_B0_MuMu_mu2_dr_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu2_dxysign;   //!
  TBranch        *b_B0_MuMu_mu2_dzsign;   //!
  TBranch        *b_B0_MuMu_prefit_mu1_eta;   //!
  TBranch        *b_B0_MuMu_prefit_mu1_phi;   //!
  TBranch        *b_B0_MuMu_prefit_mu1_pt;   //!
  TBranch        *b_B0_MuMu_prefit_mu2_eta;   //!
  TBranch        *b_B0_MuMu_prefit_mu2_phi;   //!
  TBranch        *b_B0_MuMu_prefit_mu2_pt;   //!
  TBranch        *b_B0_MuMu_sv_prob;   //!
  TBranch        *b_B0_PVEx;   //!
  TBranch        *b_B0_PVEy;   //!
  TBranch        *b_B0_PVEz;   //!
  TBranch        *b_B0_PVx;   //!
  TBranch        *b_B0_PVy;   //!
  TBranch        *b_B0_PVz;   //!
  TBranch        *b_B0_PiPi_p1_dr_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_p1_dr_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_PiPi_p1_dr_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_p2_dr_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_p2_dr_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_PiPi_p2_dr_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_pi1_d0sig;   //!
  TBranch        *b_B0_PiPi_pi1_dxysign;   //!
  TBranch        *b_B0_PiPi_pi1_dzsign;   //!
  TBranch        *b_B0_PiPi_pi1_maxd0PV;   //!
  TBranch        *b_B0_PiPi_pi1_mind0PV;   //!
  TBranch        *b_B0_PiPi_pi2_d0sig;   //!
  TBranch        *b_B0_PiPi_pi2_dxysign;   //!
  TBranch        *b_B0_PiPi_pi2_dzsign;   //!
  TBranch        *b_B0_PiPi_pi2_maxd0PV;   //!
  TBranch        *b_B0_PiPi_pi2_mind0PV;   //!
  TBranch        *b_B0_PiPi_prefit_pi1_eta;   //!
  TBranch        *b_B0_PiPi_prefit_pi1_phi;   //!
  TBranch        *b_B0_PiPi_prefit_pi1_pt;   //!
  TBranch        *b_B0_PiPi_prefit_pi1_vx;   //!
  TBranch        *b_B0_PiPi_prefit_pi1_vy;   //!
  TBranch        *b_B0_PiPi_prefit_pi1_vz;   //!
  TBranch        *b_B0_PiPi_prefit_pi2_eta;   //!
  TBranch        *b_B0_PiPi_prefit_pi2_phi;   //!
  TBranch        *b_B0_PiPi_prefit_pi2_pt;   //!
  TBranch        *b_B0_PiPi_prefit_pi2_vx;   //!
  TBranch        *b_B0_PiPi_prefit_pi2_vy;   //!
  TBranch        *b_B0_PiPi_prefit_pi2_vz;   //!
  TBranch        *b_B0_PiPi_sv_prob;   //!
  TBranch        *b_B0_cosAlpha2D_BS;   //!
  TBranch        *b_B0_cosAlpha2D_BSwithZ;   //!
  TBranch        *b_B0_cosAlpha3D_PV;   //!
  TBranch        *b_B0_decayVtxX;   //!
  TBranch        *b_B0_decayVtxXE;   //!
  TBranch        *b_B0_decayVtxY;   //!
  TBranch        *b_B0_decayVtxYE;   //!
  TBranch        *b_B0_decayVtxZ;   //!
  TBranch        *b_B0_decayVtxZE;   //!
  TBranch        *b_B0_finalFit_JPsi_mass;   //!
  TBranch        *b_B0_finalFit_Rho_mass;   //!
  TBranch        *b_B0_finalFit_X_mass;   //!
  TBranch        *b_B0_finalFit_eta;   //!
  TBranch        *b_B0_finalFit_k0s_eta;   //!
  TBranch        *b_B0_finalFit_k0s_phi;   //!
  TBranch        *b_B0_finalFit_k0s_pt;   //!
  TBranch        *b_B0_finalFit_mass;   //!
  TBranch        *b_B0_finalFit_mu1_eta;   //!
  TBranch        *b_B0_finalFit_mu1_phi;   //!
  TBranch        *b_B0_finalFit_mu1_pt;   //!
  TBranch        *b_B0_finalFit_mu2_eta;   //!
  TBranch        *b_B0_finalFit_mu2_phi;   //!
  TBranch        *b_B0_finalFit_mu2_pt;   //!
  TBranch        *b_B0_finalFit_phi;   //!
  TBranch        *b_B0_finalFit_pi1_eta;   //!
  TBranch        *b_B0_finalFit_pi1_phi;   //!
  TBranch        *b_B0_finalFit_pi1_pt;   //!
  TBranch        *b_B0_finalFit_pi2_eta;   //!
  TBranch        *b_B0_finalFit_pi2_phi;   //!
  TBranch        *b_B0_finalFit_pi2_pt;   //!
  TBranch        *b_B0_finalFit_pt;   //!
  TBranch        *b_B0_fitted_mass_womc;   //!
  TBranch        *b_B0_lxySign_BS;   //!
  TBranch        *b_B0_lxySign_BSwithZ;   //!
  TBranch        *b_B0_lxySign_PV;   //!
  TBranch        *b_B0_svchi2;   //!
  TBranch        *b_B0_svprob;   //!
  TBranch        *b_B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_K0s_matchTrack1_fired_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_K0s_matchTrack2_fired_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_fired_Dimuon25_Jpsi;   //!
  TBranch        *b_B0_MuMu_mu1_fired_DoubleMu4_3_LowMass;   //!
  TBranch        *b_B0_MuMu_mu1_fired_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_fired_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_MuMu_mu1_fired_DoubleMu4_LowMass_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_fired_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu1_trackQuality;   //!
  TBranch        *b_B0_MuMu_mu2_fired_Dimuon25_Jpsi;   //!
  TBranch        *b_B0_MuMu_mu2_fired_DoubleMu4_3_LowMass;   //!
  TBranch        *b_B0_MuMu_mu2_fired_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu2_fired_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_MuMu_mu2_fired_DoubleMu4_LowMass_Displaced;   //!
  TBranch        *b_B0_MuMu_mu2_fired_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_MuMu_mu2_trackQuality;   //!
  TBranch        *b_B0_PiPi_p1_fired_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_p1_fired_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_PiPi_p1_fired_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_p2_fired_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_B0_PiPi_p2_fired_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_B0_PiPi_p2_fired_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_B0_dimuon_idx;   //!
  TBranch        *b_B0_dipion_idx;   //!
  TBranch        *b_B0_k0short_idx;   //!
  TBranch        *b_B0_mu1_idx;   //!
  TBranch        *b_B0_mu2_idx;   //!
  TBranch        *b_B0_pi1_idx;   //!
  TBranch        *b_B0_pi2_idx;   //!
  TBranch        *b_B0_pv3D_idx;   //!
  TBranch        *b_nJPsiToMuMu;   //!
  TBranch        *b_nK0s;   //!
  TBranch        *b_BeamSpot_sigmaZ;   //!
  TBranch        *b_BeamSpot_sigmaZError;   //!
  TBranch        *b_BeamSpot_z;   //!
  TBranch        *b_BeamSpot_zError;   //!
  TBranch        *b_BeamSpot_type;   //!
  TBranch        *b_npipi;   //!
  TBranch        *b_nGenPart;   //!
  TBranch        *b_GenPart_eta;   //!
  TBranch        *b_GenPart_mass;   //!
  TBranch        *b_GenPart_phi;   //!
  TBranch        *b_GenPart_pt;   //!
  TBranch        *b_GenPart_vx;   //!
  TBranch        *b_GenPart_vy;   //!
  TBranch        *b_GenPart_vz;   //!
  TBranch        *b_GenPart_genPartIdxMother;   //!
  TBranch        *b_GenPart_pdgId;   //!
  TBranch        *b_GenPart_status;   //!
  TBranch        *b_GenPart_statusFlags;   //!
  TBranch        *b_Generator_binvar;   //!
  TBranch        *b_Generator_scalePDF;   //!
  TBranch        *b_Generator_weight;   //!
  TBranch        *b_Generator_x1;   //!
  TBranch        *b_Generator_x2;   //!
  TBranch        *b_Generator_xpdf1;   //!
  TBranch        *b_Generator_xpdf2;   //!
  TBranch        *b_Generator_id1;   //!
  TBranch        *b_Generator_id2;   //!
  TBranch        *b_genWeight;   //!
  TBranch        *b_nPSWeight;   //!
  TBranch        *b_PSWeight;   //!
  TBranch        *b_nMuon;   //!
  TBranch        *b_Muon_trackQuality;   //!
  TBranch        *b_Muon_charge;   //!
  TBranch        *b_Muon_isGlobal;   //!
  TBranch        *b_Muon_looseId;   //!
  TBranch        *b_Muon_softId;   //!
  TBranch        *b_Pileup_nTrueInt;   //!
  TBranch        *b_Pileup_pudensity;   //!
  TBranch        *b_Pileup_gpudensity;   //!
  TBranch        *b_Pileup_nPU;   //!
  TBranch        *b_Pileup_sumEOOT;   //!
  TBranch        *b_Pileup_sumLOOT;   //!
  TBranch        *b_Rho_fixedGridRhoAll;   //!
  TBranch        *b_Rho_fixedGridRhoFastjetAll;   //!
  TBranch        *b_Rho_fixedGridRhoFastjetCentral;   //!
  TBranch        *b_Rho_fixedGridRhoFastjetCentralCalo;   //!
  TBranch        *b_Rho_fixedGridRhoFastjetCentralChargedPileUp;   //!
  TBranch        *b_Rho_fixedGridRhoFastjetCentralNeutral;   //!
  TBranch        *b_nProbeTracks;   //!
  TBranch        *b_ProbeTracks_nValidHits;   //!
  TBranch        *b_ProbeTracks_isMatchedToLooseMuon;   //!
  TBranch        *b_ProbeTracks_isMatchedToMuon;   //!
  TBranch        *b_ProbeTracks_isMatchedToSoftMuon;   //!
  TBranch        *b_HLT_Dimuon25_Jpsi;   //!
  TBranch        *b_HLT_DoubleMu4_JpsiTrk_Bc;   //!
  TBranch        *b_HLT_DoubleMu4_JpsiTrkTrk_Displaced;   //!
  TBranch        *b_HLT_DoubleMu4_LowMass_Displaced;   //!
  TBranch        *b_HLT_DoubleMu4_MuMuTrk_Displaced;   //!
  TBranch        *b_HLT_DoubleMu4_3_LowMass;   //!
  TBranch        *b_nTrigObj;   //!
  TBranch        *b_TrigObj_pt;   //!
  TBranch        *b_TrigObj_eta;   //!
  TBranch        *b_TrigObj_phi;   //!
  TBranch        *b_TrigObj_id;   //!
  TBranch        *b_nOtherPV;   //!
  TBranch        *b_OtherPV_z;   //!
  TBranch        *b_OtherPV_score;   //!
  TBranch        *b_PV_ndof;   //!
  TBranch        *b_PV_x;   //!
  TBranch        *b_PV_y;   //!
  TBranch        *b_PV_z;   //!
  TBranch        *b_PV_chi2;   //!
  TBranch        *b_PV_score;   //!
  TBranch        *b_PV_npvs;   //!
  TBranch        *b_PV_npvsGood;   //!
  TBranch        *b_nSV;   //!
  TBranch        *b_SV_dlen;   //!
  TBranch        *b_SV_dlenSig;   //!
  TBranch        *b_SV_dxy;   //!
  TBranch        *b_SV_dxySig;   //!
  TBranch        *b_SV_pAngle;   //!
  TBranch        *b_SV_charge;   //!
  TBranch        *b_Muon_genPartIdx;   //!
  TBranch        *b_Muon_genPartFlav;   //!
  TBranch        *b_SV_chi2;   //!
  TBranch        *b_SV_eta;   //!
  TBranch        *b_SV_mass;   //!
  TBranch        *b_SV_ndof;   //!
  TBranch        *b_SV_phi;   //!
  TBranch        *b_SV_pt;   //!
  TBranch        *b_SV_x;   //!
  TBranch        *b_SV_y;   //!
  TBranch        *b_SV_z;   //!
  TBranch        *b_SV_ntracks;   //!
  TBranch        *b_ProbeTracks_genPartIdx;   //!
  TBranch        *b_ProbeTracks_genPartFlav;   //!

  Events(TTree *tree=0);
  virtual ~Events();
  virtual Int_t    Cut(Long64_t entry);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Events_cxx
Events::Events(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/phys_bphys/crovelli/nanoaod_X/Xnani2022_2023Feb16/BPH_BToPsi2SKs_Psi2SToJPsiPiPi_JPsiToMuMu_McM_Run3/crab_BdToPsi2SKs2022/230216_122106/2023-02-20T103412Z_merged.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/cms/store/group/phys_bphys/crovelli/nanoaod_X/Xnani2022_2023Feb16/BPH_BToPsi2SKs_Psi2SToJPsiPiPi_JPsiToMuMu_McM_Run3/crab_BdToPsi2SKs2022/230216_122106/2023-02-20T103412Z_merged.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

Events::~Events()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Events::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Events::LoadTree(Long64_t entry)
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

void Events::Init(TTree *tree)
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
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("bunchCrossing", &bunchCrossing, &b_bunchCrossing);
   fChain->SetBranchAddress("nB0", &nB0, &b_nB0);
   fChain->SetBranchAddress("B0_BSxRaw", B0_BSxRaw, &b_B0_BSxRaw);
   fChain->SetBranchAddress("B0_BSxWithZ", B0_BSxWithZ, &b_B0_BSxWithZ);
   fChain->SetBranchAddress("B0_BSyRaw", B0_BSyRaw, &b_B0_BSyRaw);
   fChain->SetBranchAddress("B0_BSyWithZ", B0_BSyWithZ, &b_B0_BSyWithZ);
   fChain->SetBranchAddress("B0_K0_cosAlpha3D", B0_K0_cosAlpha3D, &b_B0_K0_cosAlpha3D);
   fChain->SetBranchAddress("B0_K0_lxySign_wrtBvtx", B0_K0_lxySign_wrtBvtx, &b_B0_K0_lxySign_wrtBvtx);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_D0sign", B0_K0s_matchTrack1_D0sign, &b_B0_K0s_matchTrack1_D0sign);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_dR", B0_K0s_matchTrack1_dR, &b_B0_K0s_matchTrack1_dR);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_eta", B0_K0s_matchTrack1_eta, &b_B0_K0s_matchTrack1_eta);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_maxD0Pv", B0_K0s_matchTrack1_maxD0Pv, &b_B0_K0s_matchTrack1_maxD0Pv);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_minD0Pv", B0_K0s_matchTrack1_minD0Pv, &b_B0_K0s_matchTrack1_minD0Pv);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_phi", B0_K0s_matchTrack1_phi, &b_B0_K0s_matchTrack1_phi);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_pt", B0_K0s_matchTrack1_pt, &b_B0_K0s_matchTrack1_pt);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_D0sign", B0_K0s_matchTrack2_D0sign, &b_B0_K0s_matchTrack2_D0sign);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_dR", B0_K0s_matchTrack2_dR, &b_B0_K0s_matchTrack2_dR);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_eta", B0_K0s_matchTrack2_eta, &b_B0_K0s_matchTrack2_eta);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_maxD0Pv", B0_K0s_matchTrack2_maxD0Pv, &b_B0_K0s_matchTrack2_maxD0Pv);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_minD0Pv", B0_K0s_matchTrack2_minD0Pv, &b_B0_K0s_matchTrack2_minD0Pv);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_phi", B0_K0s_matchTrack2_phi, &b_B0_K0s_matchTrack2_phi);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_pt", B0_K0s_matchTrack2_pt, &b_B0_K0s_matchTrack2_pt);
   fChain->SetBranchAddress("B0_K0s_mcFitted_eta", B0_K0s_mcFitted_eta, &b_B0_K0s_mcFitted_eta);
   fChain->SetBranchAddress("B0_K0s_mcFitted_mass", B0_K0s_mcFitted_mass, &b_B0_K0s_mcFitted_mass);
   fChain->SetBranchAddress("B0_K0s_mcFitted_phi", B0_K0s_mcFitted_phi, &b_B0_K0s_mcFitted_phi);
   fChain->SetBranchAddress("B0_K0s_mcFitted_pt", B0_K0s_mcFitted_pt, &b_B0_K0s_mcFitted_pt);
   fChain->SetBranchAddress("B0_K0s_mcFitted_svprob", B0_K0s_mcFitted_svprob, &b_B0_K0s_mcFitted_svprob);
   fChain->SetBranchAddress("B0_K0s_mcFitted_vtxX", B0_K0s_mcFitted_vtxX, &b_B0_K0s_mcFitted_vtxX);
   fChain->SetBranchAddress("B0_K0s_mcFitted_vtxXE", B0_K0s_mcFitted_vtxXE, &b_B0_K0s_mcFitted_vtxXE);
   fChain->SetBranchAddress("B0_K0s_mcFitted_vtxY", B0_K0s_mcFitted_vtxY, &b_B0_K0s_mcFitted_vtxY);
   fChain->SetBranchAddress("B0_K0s_mcFitted_vtxYE", B0_K0s_mcFitted_vtxYE, &b_B0_K0s_mcFitted_vtxYE);
   fChain->SetBranchAddress("B0_K0s_mcFitted_vtxZ", B0_K0s_mcFitted_vtxZ, &b_B0_K0s_mcFitted_vtxZ);
   fChain->SetBranchAddress("B0_K0s_mcFitted_vtxZE", B0_K0s_mcFitted_vtxZE, &b_B0_K0s_mcFitted_vtxZE);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_mass", B0_K0s_nmcFitted_mass, &b_B0_K0s_nmcFitted_mass);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_pi1eta", B0_K0s_nmcFitted_pi1eta, &b_B0_K0s_nmcFitted_pi1eta);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_pi1phi", B0_K0s_nmcFitted_pi1phi, &b_B0_K0s_nmcFitted_pi1phi);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_pi1pt", B0_K0s_nmcFitted_pi1pt, &b_B0_K0s_nmcFitted_pi1pt);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_pi2eta", B0_K0s_nmcFitted_pi2eta, &b_B0_K0s_nmcFitted_pi2eta);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_pi2phi", B0_K0s_nmcFitted_pi2phi, &b_B0_K0s_nmcFitted_pi2phi);
   fChain->SetBranchAddress("B0_K0s_nmcFitted_pi2pt", B0_K0s_nmcFitted_pi2pt, &b_B0_K0s_nmcFitted_pi2pt);
   fChain->SetBranchAddress("B0_K0s_prefit_mass", B0_K0s_prefit_mass, &b_B0_K0s_prefit_mass);
   fChain->SetBranchAddress("B0_MuMu_DCA", B0_MuMu_DCA, &b_B0_MuMu_DCA);
   fChain->SetBranchAddress("B0_MuMu_LxySign", B0_MuMu_LxySign, &b_B0_MuMu_LxySign);
   fChain->SetBranchAddress("B0_MuMu_cosAlpha", B0_MuMu_cosAlpha, &b_B0_MuMu_cosAlpha);
   fChain->SetBranchAddress("B0_MuMu_fitted_eta", B0_MuMu_fitted_eta, &b_B0_MuMu_fitted_eta);
   fChain->SetBranchAddress("B0_MuMu_fitted_mass", B0_MuMu_fitted_mass, &b_B0_MuMu_fitted_mass);
   fChain->SetBranchAddress("B0_MuMu_fitted_phi", B0_MuMu_fitted_phi, &b_B0_MuMu_fitted_phi);
   fChain->SetBranchAddress("B0_MuMu_fitted_pt", B0_MuMu_fitted_pt, &b_B0_MuMu_fitted_pt);
   fChain->SetBranchAddress("B0_MuMu_fitted_vtxX", B0_MuMu_fitted_vtxX, &b_B0_MuMu_fitted_vtxX);
   fChain->SetBranchAddress("B0_MuMu_fitted_vtxXE", B0_MuMu_fitted_vtxXE, &b_B0_MuMu_fitted_vtxXE);
   fChain->SetBranchAddress("B0_MuMu_fitted_vtxY", B0_MuMu_fitted_vtxY, &b_B0_MuMu_fitted_vtxY);
   fChain->SetBranchAddress("B0_MuMu_fitted_vtxYE", B0_MuMu_fitted_vtxYE, &b_B0_MuMu_fitted_vtxYE);
   fChain->SetBranchAddress("B0_MuMu_fitted_vtxZ", B0_MuMu_fitted_vtxZ, &b_B0_MuMu_fitted_vtxZ);
   fChain->SetBranchAddress("B0_MuMu_fitted_vtxZE", B0_MuMu_fitted_vtxZE, &b_B0_MuMu_fitted_vtxZE);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr", B0_MuMu_mu1_dr, &b_B0_MuMu_mu1_dr);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr_Dimuon25_Jpsi", B0_MuMu_mu1_dr_Dimuon25_Jpsi, &b_B0_MuMu_mu1_dr_Dimuon25_Jpsi);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr_DoubleMu4_3_LowMass", B0_MuMu_mu1_dr_DoubleMu4_3_LowMass, &b_B0_MuMu_mu1_dr_DoubleMu4_3_LowMass);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr_DoubleMu4_JpsiTrkTrk_Displaced", B0_MuMu_mu1_dr_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_MuMu_mu1_dr_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr_DoubleMu4_JpsiTrk_Bc", B0_MuMu_mu1_dr_DoubleMu4_JpsiTrk_Bc, &b_B0_MuMu_mu1_dr_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr_DoubleMu4_LowMass_Displaced", B0_MuMu_mu1_dr_DoubleMu4_LowMass_Displaced, &b_B0_MuMu_mu1_dr_DoubleMu4_LowMass_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_dr_DoubleMu4_MuMuTrk_Displaced", B0_MuMu_mu1_dr_DoubleMu4_MuMuTrk_Displaced, &b_B0_MuMu_mu1_dr_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_dxysign", B0_MuMu_mu1_dxysign, &b_B0_MuMu_mu1_dxysign);
   fChain->SetBranchAddress("B0_MuMu_mu1_dzsign", B0_MuMu_mu1_dzsign, &b_B0_MuMu_mu1_dzsign);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr", B0_MuMu_mu2_dr, &b_B0_MuMu_mu2_dr);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr_Dimuon25_Jpsi", B0_MuMu_mu2_dr_Dimuon25_Jpsi, &b_B0_MuMu_mu2_dr_Dimuon25_Jpsi);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr_DoubleMu4_3_LowMass", B0_MuMu_mu2_dr_DoubleMu4_3_LowMass, &b_B0_MuMu_mu2_dr_DoubleMu4_3_LowMass);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr_DoubleMu4_JpsiTrkTrk_Displaced", B0_MuMu_mu2_dr_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_MuMu_mu2_dr_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr_DoubleMu4_JpsiTrk_Bc", B0_MuMu_mu2_dr_DoubleMu4_JpsiTrk_Bc, &b_B0_MuMu_mu2_dr_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr_DoubleMu4_LowMass_Displaced", B0_MuMu_mu2_dr_DoubleMu4_LowMass_Displaced, &b_B0_MuMu_mu2_dr_DoubleMu4_LowMass_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu2_dr_DoubleMu4_MuMuTrk_Displaced", B0_MuMu_mu2_dr_DoubleMu4_MuMuTrk_Displaced, &b_B0_MuMu_mu2_dr_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu2_dxysign", B0_MuMu_mu2_dxysign, &b_B0_MuMu_mu2_dxysign);
   fChain->SetBranchAddress("B0_MuMu_mu2_dzsign", B0_MuMu_mu2_dzsign, &b_B0_MuMu_mu2_dzsign);
   fChain->SetBranchAddress("B0_MuMu_prefit_mu1_eta", B0_MuMu_prefit_mu1_eta, &b_B0_MuMu_prefit_mu1_eta);
   fChain->SetBranchAddress("B0_MuMu_prefit_mu1_phi", B0_MuMu_prefit_mu1_phi, &b_B0_MuMu_prefit_mu1_phi);
   fChain->SetBranchAddress("B0_MuMu_prefit_mu1_pt", B0_MuMu_prefit_mu1_pt, &b_B0_MuMu_prefit_mu1_pt);
   fChain->SetBranchAddress("B0_MuMu_prefit_mu2_eta", B0_MuMu_prefit_mu2_eta, &b_B0_MuMu_prefit_mu2_eta);
   fChain->SetBranchAddress("B0_MuMu_prefit_mu2_phi", B0_MuMu_prefit_mu2_phi, &b_B0_MuMu_prefit_mu2_phi);
   fChain->SetBranchAddress("B0_MuMu_prefit_mu2_pt", B0_MuMu_prefit_mu2_pt, &b_B0_MuMu_prefit_mu2_pt);
   fChain->SetBranchAddress("B0_MuMu_sv_prob", B0_MuMu_sv_prob, &b_B0_MuMu_sv_prob);
   fChain->SetBranchAddress("B0_PVEx", B0_PVEx, &b_B0_PVEx);
   fChain->SetBranchAddress("B0_PVEy", B0_PVEy, &b_B0_PVEy);
   fChain->SetBranchAddress("B0_PVEz", B0_PVEz, &b_B0_PVEz);
   fChain->SetBranchAddress("B0_PVx", B0_PVx, &b_B0_PVx);
   fChain->SetBranchAddress("B0_PVy", B0_PVy, &b_B0_PVy);
   fChain->SetBranchAddress("B0_PVz", B0_PVz, &b_B0_PVz);
   fChain->SetBranchAddress("B0_PiPi_p1_dr_DoubleMu4_JpsiTrkTrk_Displaced", B0_PiPi_p1_dr_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_PiPi_p1_dr_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_p1_dr_DoubleMu4_JpsiTrk_Bc", B0_PiPi_p1_dr_DoubleMu4_JpsiTrk_Bc, &b_B0_PiPi_p1_dr_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_PiPi_p1_dr_DoubleMu4_MuMuTrk_Displaced", B0_PiPi_p1_dr_DoubleMu4_MuMuTrk_Displaced, &b_B0_PiPi_p1_dr_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_p2_dr_DoubleMu4_JpsiTrkTrk_Displaced", B0_PiPi_p2_dr_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_PiPi_p2_dr_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_p2_dr_DoubleMu4_JpsiTrk_Bc", B0_PiPi_p2_dr_DoubleMu4_JpsiTrk_Bc, &b_B0_PiPi_p2_dr_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_PiPi_p2_dr_DoubleMu4_MuMuTrk_Displaced", B0_PiPi_p2_dr_DoubleMu4_MuMuTrk_Displaced, &b_B0_PiPi_p2_dr_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_pi1_d0sig", B0_PiPi_pi1_d0sig, &b_B0_PiPi_pi1_d0sig);
   fChain->SetBranchAddress("B0_PiPi_pi1_dxysign", B0_PiPi_pi1_dxysign, &b_B0_PiPi_pi1_dxysign);
   fChain->SetBranchAddress("B0_PiPi_pi1_dzsign", B0_PiPi_pi1_dzsign, &b_B0_PiPi_pi1_dzsign);
   fChain->SetBranchAddress("B0_PiPi_pi1_maxd0PV", B0_PiPi_pi1_maxd0PV, &b_B0_PiPi_pi1_maxd0PV);
   fChain->SetBranchAddress("B0_PiPi_pi1_mind0PV", B0_PiPi_pi1_mind0PV, &b_B0_PiPi_pi1_mind0PV);
   fChain->SetBranchAddress("B0_PiPi_pi2_d0sig", B0_PiPi_pi2_d0sig, &b_B0_PiPi_pi2_d0sig);
   fChain->SetBranchAddress("B0_PiPi_pi2_dxysign", B0_PiPi_pi2_dxysign, &b_B0_PiPi_pi2_dxysign);
   fChain->SetBranchAddress("B0_PiPi_pi2_dzsign", B0_PiPi_pi2_dzsign, &b_B0_PiPi_pi2_dzsign);
   fChain->SetBranchAddress("B0_PiPi_pi2_maxd0PV", B0_PiPi_pi2_maxd0PV, &b_B0_PiPi_pi2_maxd0PV);
   fChain->SetBranchAddress("B0_PiPi_pi2_mind0PV", B0_PiPi_pi2_mind0PV, &b_B0_PiPi_pi2_mind0PV);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi1_eta", B0_PiPi_prefit_pi1_eta, &b_B0_PiPi_prefit_pi1_eta);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi1_phi", B0_PiPi_prefit_pi1_phi, &b_B0_PiPi_prefit_pi1_phi);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi1_pt", B0_PiPi_prefit_pi1_pt, &b_B0_PiPi_prefit_pi1_pt);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi1_vx", B0_PiPi_prefit_pi1_vx, &b_B0_PiPi_prefit_pi1_vx);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi1_vy", B0_PiPi_prefit_pi1_vy, &b_B0_PiPi_prefit_pi1_vy);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi1_vz", B0_PiPi_prefit_pi1_vz, &b_B0_PiPi_prefit_pi1_vz);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi2_eta", B0_PiPi_prefit_pi2_eta, &b_B0_PiPi_prefit_pi2_eta);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi2_phi", B0_PiPi_prefit_pi2_phi, &b_B0_PiPi_prefit_pi2_phi);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi2_pt", B0_PiPi_prefit_pi2_pt, &b_B0_PiPi_prefit_pi2_pt);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi2_vx", B0_PiPi_prefit_pi2_vx, &b_B0_PiPi_prefit_pi2_vx);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi2_vy", B0_PiPi_prefit_pi2_vy, &b_B0_PiPi_prefit_pi2_vy);
   fChain->SetBranchAddress("B0_PiPi_prefit_pi2_vz", B0_PiPi_prefit_pi2_vz, &b_B0_PiPi_prefit_pi2_vz);
   fChain->SetBranchAddress("B0_PiPi_sv_prob", B0_PiPi_sv_prob, &b_B0_PiPi_sv_prob);
   fChain->SetBranchAddress("B0_cosAlpha2D_BS", B0_cosAlpha2D_BS, &b_B0_cosAlpha2D_BS);
   fChain->SetBranchAddress("B0_cosAlpha2D_BSwithZ", B0_cosAlpha2D_BSwithZ, &b_B0_cosAlpha2D_BSwithZ);
   fChain->SetBranchAddress("B0_cosAlpha3D_PV", B0_cosAlpha3D_PV, &b_B0_cosAlpha3D_PV);
   fChain->SetBranchAddress("B0_decayVtxX", B0_decayVtxX, &b_B0_decayVtxX);
   fChain->SetBranchAddress("B0_decayVtxXE", B0_decayVtxXE, &b_B0_decayVtxXE);
   fChain->SetBranchAddress("B0_decayVtxY", B0_decayVtxY, &b_B0_decayVtxY);
   fChain->SetBranchAddress("B0_decayVtxYE", B0_decayVtxYE, &b_B0_decayVtxYE);
   fChain->SetBranchAddress("B0_decayVtxZ", B0_decayVtxZ, &b_B0_decayVtxZ);
   fChain->SetBranchAddress("B0_decayVtxZE", B0_decayVtxZE, &b_B0_decayVtxZE);
   fChain->SetBranchAddress("B0_finalFit_JPsi_mass", B0_finalFit_JPsi_mass, &b_B0_finalFit_JPsi_mass);
   fChain->SetBranchAddress("B0_finalFit_Rho_mass", B0_finalFit_Rho_mass, &b_B0_finalFit_Rho_mass);
   fChain->SetBranchAddress("B0_finalFit_X_mass", B0_finalFit_X_mass, &b_B0_finalFit_X_mass);
   fChain->SetBranchAddress("B0_finalFit_eta", B0_finalFit_eta, &b_B0_finalFit_eta);
   fChain->SetBranchAddress("B0_finalFit_k0s_eta", B0_finalFit_k0s_eta, &b_B0_finalFit_k0s_eta);
   fChain->SetBranchAddress("B0_finalFit_k0s_phi", B0_finalFit_k0s_phi, &b_B0_finalFit_k0s_phi);
   fChain->SetBranchAddress("B0_finalFit_k0s_pt", B0_finalFit_k0s_pt, &b_B0_finalFit_k0s_pt);
   fChain->SetBranchAddress("B0_finalFit_mass", B0_finalFit_mass, &b_B0_finalFit_mass);
   fChain->SetBranchAddress("B0_finalFit_mu1_eta", B0_finalFit_mu1_eta, &b_B0_finalFit_mu1_eta);
   fChain->SetBranchAddress("B0_finalFit_mu1_phi", B0_finalFit_mu1_phi, &b_B0_finalFit_mu1_phi);
   fChain->SetBranchAddress("B0_finalFit_mu1_pt", B0_finalFit_mu1_pt, &b_B0_finalFit_mu1_pt);
   fChain->SetBranchAddress("B0_finalFit_mu2_eta", B0_finalFit_mu2_eta, &b_B0_finalFit_mu2_eta);
   fChain->SetBranchAddress("B0_finalFit_mu2_phi", B0_finalFit_mu2_phi, &b_B0_finalFit_mu2_phi);
   fChain->SetBranchAddress("B0_finalFit_mu2_pt", B0_finalFit_mu2_pt, &b_B0_finalFit_mu2_pt);
   fChain->SetBranchAddress("B0_finalFit_phi", B0_finalFit_phi, &b_B0_finalFit_phi);
   fChain->SetBranchAddress("B0_finalFit_pi1_eta", B0_finalFit_pi1_eta, &b_B0_finalFit_pi1_eta);
   fChain->SetBranchAddress("B0_finalFit_pi1_phi", B0_finalFit_pi1_phi, &b_B0_finalFit_pi1_phi);
   fChain->SetBranchAddress("B0_finalFit_pi1_pt", B0_finalFit_pi1_pt, &b_B0_finalFit_pi1_pt);
   fChain->SetBranchAddress("B0_finalFit_pi2_eta", B0_finalFit_pi2_eta, &b_B0_finalFit_pi2_eta);
   fChain->SetBranchAddress("B0_finalFit_pi2_phi", B0_finalFit_pi2_phi, &b_B0_finalFit_pi2_phi);
   fChain->SetBranchAddress("B0_finalFit_pi2_pt", B0_finalFit_pi2_pt, &b_B0_finalFit_pi2_pt);
   fChain->SetBranchAddress("B0_finalFit_pt", B0_finalFit_pt, &b_B0_finalFit_pt);
   fChain->SetBranchAddress("B0_fitted_mass_womc", B0_fitted_mass_womc, &b_B0_fitted_mass_womc);
   fChain->SetBranchAddress("B0_lxySign_BS", B0_lxySign_BS, &b_B0_lxySign_BS);
   fChain->SetBranchAddress("B0_lxySign_BSwithZ", B0_lxySign_BSwithZ, &b_B0_lxySign_BSwithZ);
   fChain->SetBranchAddress("B0_lxySign_PV", B0_lxySign_PV, &b_B0_lxySign_PV);
   fChain->SetBranchAddress("B0_svchi2", B0_svchi2, &b_B0_svchi2);
   fChain->SetBranchAddress("B0_svprob", B0_svprob, &b_B0_svprob);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrkTrk_Displaced", B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrk_Bc", B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrk_Bc, &b_B0_K0s_matchTrack1_fired_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_K0s_matchTrack1_fired_DoubleMu4_MuMuTrk_Displaced", B0_K0s_matchTrack1_fired_DoubleMu4_MuMuTrk_Displaced, &b_B0_K0s_matchTrack1_fired_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrkTrk_Displaced", B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrk_Bc", B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrk_Bc, &b_B0_K0s_matchTrack2_fired_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_K0s_matchTrack2_fired_DoubleMu4_MuMuTrk_Displaced", B0_K0s_matchTrack2_fired_DoubleMu4_MuMuTrk_Displaced, &b_B0_K0s_matchTrack2_fired_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_fired_Dimuon25_Jpsi", B0_MuMu_mu1_fired_Dimuon25_Jpsi, &b_B0_MuMu_mu1_fired_Dimuon25_Jpsi);
   fChain->SetBranchAddress("B0_MuMu_mu1_fired_DoubleMu4_3_LowMass", B0_MuMu_mu1_fired_DoubleMu4_3_LowMass, &b_B0_MuMu_mu1_fired_DoubleMu4_3_LowMass);
   fChain->SetBranchAddress("B0_MuMu_mu1_fired_DoubleMu4_JpsiTrkTrk_Displaced", B0_MuMu_mu1_fired_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_MuMu_mu1_fired_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_fired_DoubleMu4_JpsiTrk_Bc", B0_MuMu_mu1_fired_DoubleMu4_JpsiTrk_Bc, &b_B0_MuMu_mu1_fired_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_MuMu_mu1_fired_DoubleMu4_LowMass_Displaced", B0_MuMu_mu1_fired_DoubleMu4_LowMass_Displaced, &b_B0_MuMu_mu1_fired_DoubleMu4_LowMass_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_fired_DoubleMu4_MuMuTrk_Displaced", B0_MuMu_mu1_fired_DoubleMu4_MuMuTrk_Displaced, &b_B0_MuMu_mu1_fired_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu1_trackQuality", B0_MuMu_mu1_trackQuality, &b_B0_MuMu_mu1_trackQuality);
   fChain->SetBranchAddress("B0_MuMu_mu2_fired_Dimuon25_Jpsi", B0_MuMu_mu2_fired_Dimuon25_Jpsi, &b_B0_MuMu_mu2_fired_Dimuon25_Jpsi);
   fChain->SetBranchAddress("B0_MuMu_mu2_fired_DoubleMu4_3_LowMass", B0_MuMu_mu2_fired_DoubleMu4_3_LowMass, &b_B0_MuMu_mu2_fired_DoubleMu4_3_LowMass);
   fChain->SetBranchAddress("B0_MuMu_mu2_fired_DoubleMu4_JpsiTrkTrk_Displaced", B0_MuMu_mu2_fired_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_MuMu_mu2_fired_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu2_fired_DoubleMu4_JpsiTrk_Bc", B0_MuMu_mu2_fired_DoubleMu4_JpsiTrk_Bc, &b_B0_MuMu_mu2_fired_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_MuMu_mu2_fired_DoubleMu4_LowMass_Displaced", B0_MuMu_mu2_fired_DoubleMu4_LowMass_Displaced, &b_B0_MuMu_mu2_fired_DoubleMu4_LowMass_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu2_fired_DoubleMu4_MuMuTrk_Displaced", B0_MuMu_mu2_fired_DoubleMu4_MuMuTrk_Displaced, &b_B0_MuMu_mu2_fired_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_MuMu_mu2_trackQuality", B0_MuMu_mu2_trackQuality, &b_B0_MuMu_mu2_trackQuality);
   fChain->SetBranchAddress("B0_PiPi_p1_fired_DoubleMu4_JpsiTrkTrk_Displaced", B0_PiPi_p1_fired_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_PiPi_p1_fired_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_p1_fired_DoubleMu4_JpsiTrk_Bc", B0_PiPi_p1_fired_DoubleMu4_JpsiTrk_Bc, &b_B0_PiPi_p1_fired_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_PiPi_p1_fired_DoubleMu4_MuMuTrk_Displaced", B0_PiPi_p1_fired_DoubleMu4_MuMuTrk_Displaced, &b_B0_PiPi_p1_fired_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_p2_fired_DoubleMu4_JpsiTrkTrk_Displaced", B0_PiPi_p2_fired_DoubleMu4_JpsiTrkTrk_Displaced, &b_B0_PiPi_p2_fired_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("B0_PiPi_p2_fired_DoubleMu4_JpsiTrk_Bc", B0_PiPi_p2_fired_DoubleMu4_JpsiTrk_Bc, &b_B0_PiPi_p2_fired_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("B0_PiPi_p2_fired_DoubleMu4_MuMuTrk_Displaced", B0_PiPi_p2_fired_DoubleMu4_MuMuTrk_Displaced, &b_B0_PiPi_p2_fired_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("B0_dimuon_idx", B0_dimuon_idx, &b_B0_dimuon_idx);
   fChain->SetBranchAddress("B0_dipion_idx", B0_dipion_idx, &b_B0_dipion_idx);
   fChain->SetBranchAddress("B0_k0short_idx", B0_k0short_idx, &b_B0_k0short_idx);
   fChain->SetBranchAddress("B0_mu1_idx", B0_mu1_idx, &b_B0_mu1_idx);
   fChain->SetBranchAddress("B0_mu2_idx", B0_mu2_idx, &b_B0_mu2_idx);
   fChain->SetBranchAddress("B0_pi1_idx", B0_pi1_idx, &b_B0_pi1_idx);
   fChain->SetBranchAddress("B0_pi2_idx", B0_pi2_idx, &b_B0_pi2_idx);
   fChain->SetBranchAddress("B0_pv3D_idx", B0_pv3D_idx, &b_B0_pv3D_idx);
   fChain->SetBranchAddress("nJPsiToMuMu", &nJPsiToMuMu, &b_nJPsiToMuMu);
   fChain->SetBranchAddress("nK0s", &nK0s, &b_nK0s);
   fChain->SetBranchAddress("BeamSpot_sigmaZ", &BeamSpot_sigmaZ, &b_BeamSpot_sigmaZ);
   fChain->SetBranchAddress("BeamSpot_sigmaZError", &BeamSpot_sigmaZError, &b_BeamSpot_sigmaZError);
   fChain->SetBranchAddress("BeamSpot_z", &BeamSpot_z, &b_BeamSpot_z);
   fChain->SetBranchAddress("BeamSpot_zError", &BeamSpot_zError, &b_BeamSpot_zError);
   fChain->SetBranchAddress("BeamSpot_type", &BeamSpot_type, &b_BeamSpot_type);
   fChain->SetBranchAddress("npipi", &npipi, &b_npipi);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_vx", GenPart_vx, &b_GenPart_vx);
   fChain->SetBranchAddress("GenPart_vy", GenPart_vy, &b_GenPart_vy);
   fChain->SetBranchAddress("GenPart_vz", GenPart_vz, &b_GenPart_vz);
   fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   fChain->SetBranchAddress("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
   fChain->SetBranchAddress("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
   fChain->SetBranchAddress("Generator_weight", &Generator_weight, &b_Generator_weight);
   fChain->SetBranchAddress("Generator_x1", &Generator_x1, &b_Generator_x1);
   fChain->SetBranchAddress("Generator_x2", &Generator_x2, &b_Generator_x2);
   fChain->SetBranchAddress("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
   fChain->SetBranchAddress("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
   fChain->SetBranchAddress("Generator_id1", &Generator_id1, &b_Generator_id1);
   fChain->SetBranchAddress("Generator_id2", &Generator_id2, &b_Generator_id2);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("nPSWeight", &nPSWeight, &b_nPSWeight);
   fChain->SetBranchAddress("PSWeight", PSWeight, &b_PSWeight);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_trackQuality", Muon_trackQuality, &b_Muon_trackQuality);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_looseId", Muon_looseId, &b_Muon_looseId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Pileup_nTrueInt", &Pileup_nTrueInt, &b_Pileup_nTrueInt);
   fChain->SetBranchAddress("Pileup_pudensity", &Pileup_pudensity, &b_Pileup_pudensity);
   fChain->SetBranchAddress("Pileup_gpudensity", &Pileup_gpudensity, &b_Pileup_gpudensity);
   fChain->SetBranchAddress("Pileup_nPU", &Pileup_nPU, &b_Pileup_nPU);
   fChain->SetBranchAddress("Pileup_sumEOOT", &Pileup_sumEOOT, &b_Pileup_sumEOOT);
   fChain->SetBranchAddress("Pileup_sumLOOT", &Pileup_sumLOOT, &b_Pileup_sumLOOT);
   fChain->SetBranchAddress("Rho_fixedGridRhoAll", &Rho_fixedGridRhoAll, &b_Rho_fixedGridRhoAll);
   fChain->SetBranchAddress("Rho_fixedGridRhoFastjetAll", &Rho_fixedGridRhoFastjetAll, &b_Rho_fixedGridRhoFastjetAll);
   fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentral", &Rho_fixedGridRhoFastjetCentral, &b_Rho_fixedGridRhoFastjetCentral);
   fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentralCalo", &Rho_fixedGridRhoFastjetCentralCalo, &b_Rho_fixedGridRhoFastjetCentralCalo);
   fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentralChargedPileUp", &Rho_fixedGridRhoFastjetCentralChargedPileUp, &b_Rho_fixedGridRhoFastjetCentralChargedPileUp);
   fChain->SetBranchAddress("Rho_fixedGridRhoFastjetCentralNeutral", &Rho_fixedGridRhoFastjetCentralNeutral, &b_Rho_fixedGridRhoFastjetCentralNeutral);
   fChain->SetBranchAddress("nProbeTracks", &nProbeTracks, &b_nProbeTracks);
   fChain->SetBranchAddress("ProbeTracks_nValidHits", ProbeTracks_nValidHits, &b_ProbeTracks_nValidHits);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToLooseMuon", ProbeTracks_isMatchedToLooseMuon, &b_ProbeTracks_isMatchedToLooseMuon);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToMuon", ProbeTracks_isMatchedToMuon, &b_ProbeTracks_isMatchedToMuon);
   fChain->SetBranchAddress("ProbeTracks_isMatchedToSoftMuon", ProbeTracks_isMatchedToSoftMuon, &b_ProbeTracks_isMatchedToSoftMuon);
   fChain->SetBranchAddress("HLT_Dimuon25_Jpsi", &HLT_Dimuon25_Jpsi, &b_HLT_Dimuon25_Jpsi);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTrk_Bc", &HLT_DoubleMu4_JpsiTrk_Bc, &b_HLT_DoubleMu4_JpsiTrk_Bc);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTrkTrk_Displaced", &HLT_DoubleMu4_JpsiTrkTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_LowMass_Displaced", &HLT_DoubleMu4_LowMass_Displaced, &b_HLT_DoubleMu4_LowMass_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_MuMuTrk_Displaced", &HLT_DoubleMu4_MuMuTrk_Displaced, &b_HLT_DoubleMu4_MuMuTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_3_LowMass", &HLT_DoubleMu4_3_LowMass, &b_HLT_DoubleMu4_3_LowMass);
   fChain->SetBranchAddress("nTrigObj", &nTrigObj, &b_nTrigObj);
   fChain->SetBranchAddress("TrigObj_pt", TrigObj_pt, &b_TrigObj_pt);
   fChain->SetBranchAddress("TrigObj_eta", TrigObj_eta, &b_TrigObj_eta);
   fChain->SetBranchAddress("TrigObj_phi", TrigObj_phi, &b_TrigObj_phi);
   fChain->SetBranchAddress("TrigObj_id", TrigObj_id, &b_TrigObj_id);
   fChain->SetBranchAddress("nOtherPV", &nOtherPV, &b_nOtherPV);
   fChain->SetBranchAddress("OtherPV_z", OtherPV_z, &b_OtherPV_z);
   fChain->SetBranchAddress("OtherPV_score", OtherPV_score, &b_OtherPV_score);
   fChain->SetBranchAddress("PV_ndof", &PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_chi2", &PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_score", &PV_score, &b_PV_score);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_dlen", SV_dlen, &b_SV_dlen);
   fChain->SetBranchAddress("SV_dlenSig", SV_dlenSig, &b_SV_dlenSig);
   fChain->SetBranchAddress("SV_dxy", SV_dxy, &b_SV_dxy);
   fChain->SetBranchAddress("SV_dxySig", SV_dxySig, &b_SV_dxySig);
   fChain->SetBranchAddress("SV_pAngle", SV_pAngle, &b_SV_pAngle);
   fChain->SetBranchAddress("SV_charge", SV_charge, &b_SV_charge);
   fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   fChain->SetBranchAddress("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
   fChain->SetBranchAddress("SV_ntracks", SV_ntracks, &b_SV_ntracks);
   fChain->SetBranchAddress("ProbeTracks_genPartIdx", ProbeTracks_genPartIdx, &b_ProbeTracks_genPartIdx);
   fChain->SetBranchAddress("ProbeTracks_genPartFlav", ProbeTracks_genPartFlav, &b_ProbeTracks_genPartFlav);
   Notify();
}

Bool_t Events::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Events::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Events::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Events_cxx
