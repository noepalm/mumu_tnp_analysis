from settings import *

### Change output dir
baseOutDir = 'results/muons/projEta'

### Change binning
biningDef = [
    { 'var' : 'abs(Jpsi_m2_eta)', 'type' : 'float' , 'bins' : [0, 1.5, 2.6]},
    { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 40., 40., 40.]}, #NOTE: I have no idea why, but with < 4 entries --sumUp segfaults. wtf
]


### Change base cuts (tighter on pT, no cut on eta)
cutBase = ''
## turn-on cuts
cutBase += 'Jpsi_m1_pt > 3.1 && Jpsi_m2_pt > 3.1'
# cutBase += ' && abs(Jpsi_m1_eta) < 2.5 && abs(Jpsi_m2_eta) < 2.5'
# cutBase += ' && Jpsi_fit_pt > 4.9'
cutBase += ' && Jpsi_nonfit_pt > 4.9'
cutBase += ' && Jpsi_nonfit_mass > 2.6 && Jpsi_nonfit_mass < 3.5' 
## sanity cuts
# cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'

