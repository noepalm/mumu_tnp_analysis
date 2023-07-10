from libPython.tnpClassUtils import tnpSample

### samples
eosTnp = '/eos/cms/store/user/crovelli/LowPtEle/TnpData/March21noRegression/'


# Parking_Jan16 = {
#     ### NanoAOD TnP for IDs scale factors
#     'BuToKJpsi'          : tnpSample('BuToKJpsi',
#                                      eosTnp + 'Formatted_BuToKJpsi_Toee_BParkNANO_mc_2020May16_ext_probeLowPt__tagIdCutsAt0__withNvtxWeights.root',
#                                      isMC = True, nEvts =  -1 ),

#     'data_Run2018ALL' : tnpSample('data_Run2018ALL' , eosTnp + 'Formatted_Parking_Run2018ALL_probeLowPt__tagIdCutsAt0.root' , lumi = 20.), 
#     }

Parking_Jan16 = {
    ### NanoAOD TnP for IDs scale factors
    'BuToKJpsi'          : tnpSample('BuToKJpsi',
                                     eosTnp + 'Formatted_March21_NoRegr_BuToKJpsi_Toee_v2_probePF__withPuWeights.root',
                                     isMC = True, nEvts =  -1 ),

    'data_Run2018ALL' : tnpSample('data_Run2018ALL' , eosTnp + '/Formatted_March21_NoRegr_Parking2018A_probePF.root' , lumi = 20.), 
    }

# data_base_folder = "/eos/cms/store/user/crovelli/HLT_DoubleMu/DoubleMuTnP_v4"
data_base_folder_alt = "/eos/cms/store/user/crovelli/HLT_DoubleMu_tagHLT_Mu4_L1DoubleMu"

Parking_X = {
    # 'data' : tnpSample('data', "DoubleMuTnP_v2.root"),
#    'MC' : tnpSample('MC', "/eos/cms/store/user/crovelli/DoubleMuMC/TnP__JPsito2Mu_JPsiFilter_2MuFilter__Run3Summer22EE.root", isMC = True, nEvts = -1),
#    'MC' : tnpSample('MC', "/eos/cms/store/user/crovelli/DoubleMuMCv2/TnP__JPsito2Mu_JPsiFilter_2MuFilter__Run3Summer22__v2.root", isMC = True, nEvts = -1),
    # 'MC' : tnpSample('MC', "/eos/cms/store/user/crovelli/DoubleMuMC/TnP__JPsito2Mu_JPsiFilter_2MuFilter__Run3Summer22___version2.root", isMC = True, nEvts = -1),
    # 'MC' : tnpSample('MC', "/eos/cms/store/user/crovelli/DoubleMuMC/TnP__JPsito2Mu_JPsiFilter_2MuFilter__Run3Summer22EE___version2.root", isMC = True, nEvts = -1),
    # 'MC' : tnpSample('MC', "/eos/cms/store/user/crovelli/DoubleMuMCwithTag/TnP__JPsito2Mu_JPsiFilter_2MuFilter__Run3Summer22EE___withTag___version2.root", isMC = True, nEvts = -1),
    'MC' : tnpSample('MC', "/eos/cms/store/user/crovelli/DoubleMuMCwithTag_v2/TnP__BsToJPsiPhi__Run3Summer22EE___withTagV2.root", isMC = True, nEvts = -1),

    'dataE' : tnpSample('dataE', "/eos/cms/store/user/crovelli/HLT_DoubleMuv2/MuonDataset_2022Ev1__DoubleMuTriggerTnp.root"),
    'dataF' : tnpSample('dataF', "/eos/cms/store/user/crovelli/HLT_DoubleMuv2/MuonDataset_2022Fv1__DoubleMuTriggerTnp___partial.root"),
    'dataG' : tnpSample('dataG', "/eos/cms/store/user/crovelli/HLT_DoubleMuv2/MuonDataset_2022Gv1__DoubleMuTriggerTnp.root"),

    'dataE_0' : tnpSample('dataE_0', data_base_folder_alt + "/ParkingDoubleMuonLowMass0_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_1' : tnpSample('dataE_1', data_base_folder_alt + "/ParkingDoubleMuonLowMass1_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_2' : tnpSample('dataE_2', data_base_folder_alt + "/ParkingDoubleMuonLowMass2_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_3' : tnpSample('dataE_3', data_base_folder_alt + "/ParkingDoubleMuonLowMass3_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_4' : tnpSample('dataE_4', data_base_folder_alt + "/ParkingDoubleMuonLowMass4_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_5' : tnpSample('dataE_5', data_base_folder_alt + "/ParkingDoubleMuonLowMass5_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_6' : tnpSample('dataE_6', data_base_folder_alt + "/ParkingDoubleMuonLowMass6_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataE_7' : tnpSample('dataE_7', data_base_folder_alt + "/ParkingDoubleMuonLowMass7_2022Ev1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),

    'dataF_0' : tnpSample('dataF_0', data_base_folder_alt + "/ParkingDoubleMuonLowMass0_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_1' : tnpSample('dataF_1', data_base_folder_alt + "/ParkingDoubleMuonLowMass1_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_2' : tnpSample('dataF_2', data_base_folder_alt + "/ParkingDoubleMuonLowMass2_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_3' : tnpSample('dataF_3', data_base_folder_alt + "/ParkingDoubleMuonLowMass3_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_4' : tnpSample('dataF_4', data_base_folder_alt + "/ParkingDoubleMuonLowMass4_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_5' : tnpSample('dataF_5', data_base_folder_alt + "/ParkingDoubleMuonLowMass5_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_6' : tnpSample('dataF_6', data_base_folder_alt + "/ParkingDoubleMuonLowMass6_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataF_7' : tnpSample('dataF_7', data_base_folder_alt + "/ParkingDoubleMuonLowMass7_2022Fv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),

    'dataG_0' : tnpSample('dataG_0', data_base_folder_alt + "/ParkingDoubleMuonLowMass0_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_1' : tnpSample('dataG_1', data_base_folder_alt + "/ParkingDoubleMuonLowMass1_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_2' : tnpSample('dataG_2', data_base_folder_alt + "/ParkingDoubleMuonLowMass2_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_3' : tnpSample('dataG_3', data_base_folder_alt + "/ParkingDoubleMuonLowMass3_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_4' : tnpSample('dataG_4', data_base_folder_alt + "/ParkingDoubleMuonLowMass4_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_5' : tnpSample('dataG_5', data_base_folder_alt + "/ParkingDoubleMuonLowMass5_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_6' : tnpSample('dataG_6', data_base_folder_alt + "/ParkingDoubleMuonLowMass6_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    'dataG_7' : tnpSample('dataG_7', data_base_folder_alt + "/ParkingDoubleMuonLowMass7_2022Gv1__DoubleMuTriggerTnp__refMu4L1DoubleMu.root"),
    
}
