from settings import *

### Change output dir
baseOutDir = 'results/muons/projPt'

### Change binning
biningDef = [
    { 'var' : 'abs(Jpsi_m2_eta)', 'type' : 'float' , 'bins' : [0, 2.6]},
    { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3.1, 3.4, 5, 7., 9., 12., 40]},
]

### Change base cuts (tighter on pT, tighter on eta)

cutBase = ''
## turn-on cuts
cutBase += 'Jpsi_m1_pt > 2.8 && Jpsi_m2_pt > 2.8'
cutBase += ' && abs(Jpsi_m1_eta) < 2.4 && abs(Jpsi_m2_eta) < 2.4'
# cutBase += ' && Jpsi_fit_pt > 4.9'
cutBase += ' && Jpsi_nonfit_pt > 4.9'
cutBase += ' && Jpsi_nonfit_mass > 2.6 && Jpsi_nonfit_mass < 3.5' 
## sanity cuts
# cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'
