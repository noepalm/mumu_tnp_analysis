from settings import *

### Change output dir

baseOutDir += 'projEta'

### Change binningse

# pt_bins_alt = [ { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 40., 40., 40.]} ] #NOTE: I have no idea why, but with < 4 entries --sumUp segfaults. wtf
pt_bins_alt = [ { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.5, 300., 300., 300.]} ] #NOTE: I have no idea why, but with < 4 entries --sumUp segfaults. wtf
deltaR_bins_alt = [ { 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [0, 1.]} ]

if is_vs_deltaR:
    biningDef = deltaR_bins + pt_bins_alt
elif is_vs_deltaR_eta:
    biningDef = eta_bins + deltaR_bins_alt
else:
    biningDef = eta_bins + pt_bins_alt    


### Change base cuts (tighter on x variable, i.e. pT or deltaR depending on flags)
if not is_vs_deltaR:
  cutBase += ' && Jpsi_m1_pt > 3.1 && Jpsi_m2_pt > 3.1'

# ### Change base cuts (tighter on pT, no cut on eta)
# cutBase = ''
# ## turn-on cuts
# cutBase += 'Jpsi_m1_pt > 3.1 && Jpsi_m2_pt > 3.1'
# # cutBase += ' && abs(Jpsi_m1_eta) < 2.5 && abs(Jpsi_m2_eta) < 2.5'
# # cutBase += ' && Jpsi_fit_pt > 4.9'
# cutBase += ' && Jpsi_nonfit_pt > 5.0' #4.9 nominal
# cutBase += ' && Jpsi_nonfit_mass > 2.6 && Jpsi_nonfit_mass < 3.5' 
# cutBase += ' && Jpsi_m1_pt > 7.8' #already imposed on data, but not on MC
# if is_vs_deltaR:
#     cutBase += ' && abs(Jpsi_m1_eta) < 2.4 && abs(Jpsi_m2_eta) < 2.4'

# if is_tagInEB:
#     cutBase += ' && Jpsi_m1_eta < 1.4'

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

