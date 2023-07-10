from settings import *

### Output directory
baseOutDir = 'results/muons/deltaR'

### Binning
biningDef = [
    #{ 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [0, 0.2, 0.4, 0.6, 1.]},
    { 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [1/7.*i for i in range(8)] },
    { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3.1, 3.4, 5, 7., 9., 12., 40] },
]

### Base cuts (both num/dem)
cutBase = ''
# turn-on cuts
cutBase += 'Jpsi_m1_pt > 2.8 && Jpsi_m2_pt > 2.8'
cutBase += ' && abs(Jpsi_m1_eta) < 2.4 && abs(Jpsi_m2_eta) < 2.4' #slightly tighter (vs 2.5 nominal)
cutBase += ' && Jpsi_fit_pt > 4.9'
# mass cuts
cutBase += ' && Jpsi_fit_mass > 2.6 && Jpsi_fit_mass < 3.5' 
# sanity cuts
cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'
