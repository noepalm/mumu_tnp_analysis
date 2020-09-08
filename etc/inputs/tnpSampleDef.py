from libPython.tnpClassUtils import tnpSample

### qll stat
#eosTnp = '/eos/cms/store/user/crovelli/LowPtEle/TnpData/'
eosTnp = '/eos/cms/store/group/phys_bphys/crovelli/'

Parking_Jan16 = {
    ### NanoAOD TnP for IDs scale factors
    'BuToKJpsi'          : tnpSample('BuToKJpsi',
#                                     eosTnp + 'Formatted_BuToKJpsi_Toee_BParkNANO_mc_hadd.root',
                                     eosTnp + 'Formatted_BuToKJpsi_Toee_BParkNANO_mc_hadd__noHLTcut.root',
                                     isMC = True, nEvts =  -1 ),

    'data_Run2018D' : tnpSample('data_Run2018D' , eosTnp + 'Formatted_Parking.root' , lumi = 20.),         # circa, perche' non ho i json di tutti
    #'data_Run2018D' : tnpSample('data_Run2018D' , eosTnp + 'Formatted_ParkingBPH1_Run2018D_part1.root' , lumi = 4.003),        # hlt9
    #'data_Run2018D' : tnpSample('data_Run2018D' , eosTnp + 'Formatted_ParkingBPH1_Run2018D_part1.root' , lumi = 5.118),        # hlt12
    }

