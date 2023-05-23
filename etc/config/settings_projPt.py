from settings import *

### Change output dir

if is_vs_deltaR:
    baseOutDir = 'results/vs_pt_deltaR/projPt'
elif is_tagInEB:
    baseOutDir = 'results/muons_tagInEB/projPt'
elif is_L1cuts:
    baseOutDir = 'results/muons_L1cuts/projPt'
else:
    baseOutDir = 'results/muons/projPt'


### Change binning

if is_vs_deltaR:
    biningDef = [
        { 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [0, 1.]},
        { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3.1, 3.4, 5, 7., 9., 12., 40]},
    ]
else:
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
cutBase += ' && Jpsi_nonfit_pt > 5.0' #4.9 nominal
cutBase += ' && Jpsi_nonfit_mass > 2.6 && Jpsi_nonfit_mass < 3.5'
if is_tagInEB:
    cutBase += ' && Jpsi_m1_eta < 1.4'
cutBase += ' && Jpsi_m1_pt > 7.8' #already imposed on data, but not on MC

# L1 cuts (100% efficient)
if is_L1cuts:
    cutBase += '&& Jpsi_muonsDr < 1.1' #1.2
    cutBase += '&& abs(Jpsi_m1_eta - Jpsi_m2_eta) < 1.4' #1.5
    cutBase += '&& abs(Jpsi_m1_eta) < 1.3 && abs(Jpsi_m2_eta) < 1.3' #1.4

## sanity cuts
# cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'
