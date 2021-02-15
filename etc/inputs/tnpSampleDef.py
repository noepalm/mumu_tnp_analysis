from libPython.tnpClassUtils import tnpSample

### samples
eosTnp = '/eos/cms/store/user/crovelli/LowPtEle/TnpData/Sept/Jan16/'

Parking_Jan16 = {
    ### NanoAOD TnP for IDs scale factors
    'BuToKJpsi'          : tnpSample('BuToKJpsi',
                                     eosTnp + 'Formatted_BuToKJpsi_Toee_BParkNANO_mc_2020May16_ext_probeLowPt__tagIdCutsAt0__withNvtxWeights.root',
                                     isMC = True, nEvts =  -1 ),

    'data_Run2018ALL' : tnpSample('data_Run2018ALL' , eosTnp + 'Formatted_Parking_Run2018ALL_probeLowPt__tagIdCutsAt0.root' , lumi = 20.), 
    }

