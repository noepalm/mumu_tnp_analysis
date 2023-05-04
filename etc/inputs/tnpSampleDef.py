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


Parking_X = {
    'data' : tnpSample('data', "DoubleMuTnP_v2.root"),
    'MC' : tnpSample('MC', "DoubleMuTnP_v2.root", isMC = True, nEvts = -1)
}
