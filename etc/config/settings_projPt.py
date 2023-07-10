from settings import *

### Change output dir

baseOutDir += 'projPt'

### Change binning

deltaR_bins_alt = [ { 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [0, 1.]} ]
eta_bins_alt = [ { 'var' : 'Jpsi_m2_eta', 'type' : 'float' , 'bins' : [-2.6, 2.6]} ]

if is_vs_deltaR:
    biningDef = deltaR_bins_alt + pt_bins
elif is_vs_deltaR_eta:
    biningDef = eta_bins_alt + deltaR_bins
else:
    biningDef = eta_bins_alt + pt_bins


### Change base cuts (tighter on pT, tighter on eta)
cutBase += ' && abs(Jpsi_m1_eta) < 2.4 && abs(Jpsi_m2_eta) < 2.4'

# cutBase = ''
# ## turn-on cuts
# cutBase += 'Jpsi_m1_pt > 2.8 && Jpsi_m2_pt > 2.8'
# cutBase += ' && abs(Jpsi_m1_eta) < 2.4 && abs(Jpsi_m2_eta) < 2.4'
# # cutBase += ' && Jpsi_fit_pt > 4.9'
# cutBase += ' && Jpsi_nonfit_pt > 5.0' #4.9 nominal
# cutBase += ' && Jpsi_nonfit_mass > 2.6 && Jpsi_nonfit_mass < 3.5'
# if is_tagInEB:
#     cutBase += ' && Jpsi_m1_eta < 1.4'
# cutBase += ' && Jpsi_m1_pt > 7.8' #already imposed on data, but not on MC

# # L1 cuts (100% efficient)
# if is_L1cuts:
#     # cutBase += '&& Jpsi_muonsDr < 1.1' #1.2 nominal
#     # cutBase += '&& abs(Jpsi_m1_eta - Jpsi_m2_eta) < 1.4' #1.5 nominal
#     # cutBase += '&& abs(Jpsi_m1_eta) < 1.3 && abs(Jpsi_m2_eta) < 1.3' #1.4 nominal
#     cutBase += '&& Jpsi_muonsDr < 1.3' #1.4 nominal
#     cutBase += '&& abs(Jpsi_m1_eta - Jpsi_m2_eta) < 1.5' #1.6 nominal
#     cutBase += '&& Jpsi_m1_bestL1dR < 0.3 && Jpsi_m2_bestL1dR < 0.3'

# ## sanity cuts
# # cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'
