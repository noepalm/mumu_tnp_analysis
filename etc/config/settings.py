#############################################################
# General settings

#if true, binning vs deltaR. Must also cadd -deltaR flag when launching runAnalysis.sh
is_vs_deltaR = True
is_vs_deltaR_eta = False
is_tagInEB = False
is_L1cuts = False
is_prescale = False
is_altref = True

# flag to be Tested

DoubleMu = 'DoubleMu_fired == 1'		       			            # trigger fired
DoubleMu += ' && Jpsi_m1_Dimu_pt != Jpsi_m2_Dimu_pt'			    # NOT (same HLT object matched to both offline muons)
DoubleMu += ' && Jpsi_m1_Dimu_dR < 0.1 && Jpsi_m2_Dimu_dR < 0.1'	# probe HLT candidates matched to offline muons

# flag to be Tested
flags = {
    'DoubleMu' : DoubleMu
    }

if is_vs_deltaR:
    baseOutDir = 'results/vs_pt_deltaR/'
elif is_vs_deltaR_eta:
    baseOutDir = 'results/vs_deltaR_eta/'
elif is_tagInEB:
    baseOutDir = 'results/muons_tagInEB/'
else:
    baseOutDir = 'results/muons/'

if is_L1cuts:
    baseOutDir = baseOutDir[:-1] + '_L1cuts/'
if is_prescale:
    baseOutDir = baseOutDir[:-1] + '_prescale/'

if is_altref:
    baseOutDir = 'results/altref/' + baseOutDir[8:]


#############################################################
# Samples definition  - preparing the samples

### samples are defined in etc/inputs/tnpSampleDef.py
### not: you can setup another sampleDef File in inputs
import etc.inputs.tnpSampleDef as tnpSamples
tnpTreeDir = 'nano_'

# samplesDef = {
#     'data'   : tnpSamples.Parking_X['data'].clone(),
#     'mcNom'  : tnpSamples.Parking_X['MC'].clone(),
#     'mcAlt'  : None,
#     'tagSel' : None
#     # 'mcNom'  : tnpSamples.Parking_X['MC'].clone(),
#     # 'mcAlt'  : tnpSamples.Parking_X['MC'].clone(),
#     # 'tagSel' : tnpSamples.Parking_X['MC'].clone(),
# }

# [HLT_Mu8] when using main reference trigger, use dataE, dataF, dataG samples
if not is_altref:
  samplesDef = {
    'data'   : tnpSamples.Parking_X['dataE'].clone(),
    'mcNom'  : tnpSamples.Parking_X['MC'].clone(),
    'mcAlt'  : None,
    'tagSel' : None
    # 'mcNom'  : tnpSamples.Parking_X['MC'].clone(),
    # 'mcAlt'  : tnpSamples.Parking_X['MC'].clone(),
    # 'tagSel' : tnpSamples.Parking_X['MC'].clone(),
  }

  samplesDef['data'].add_sample( tnpSamples.Parking_X['dataF'] )
  samplesDef['data'].add_sample( tnpSamples.Parking_X['dataG'] )

# [HLT_Mu4_L1DoubleMu] use dataE_0, ... _7, dataF_0, ... _7, etc datasets
else:
  samplesDef = {
    'data'   : tnpSamples.Parking_X['dataE_0'].clone(),
    'mcNom'  : tnpSamples.Parking_X['MC'].clone(),
    'mcAlt'  : None,
    'tagSel' : None
  }

  # add all files for relevant run
  for run in ["E", "F", "G"]:
    for idx in range(8):
      if not (run == "E" and idx == 0):
        samplesDef['data'].add_sample( tnpSamples.Parking_X['data{}_{}'.format(run, idx)] )

samplesDef['data'].rename('data')


## if you need to use 2 times the same sample, then rename the second one
if not samplesDef['mcAlt'] is None:
    samplesDef['mcAlt'].rename('mcAlt')
if not samplesDef['tagSel'] is None:
    samplesDef['tagSel'].rename('tagSel')

## set MC weight
weightName = 'weight'    # 1 for data; pu_weight for MC   
# if not samplesDef['mcNom' ] is None: samplesDef['mcNom' ].set_weight(weightName)
# if not samplesDef['mcAlt' ] is None: samplesDef['mcAlt' ].set_weight(weightName)
# if not samplesDef['tagSel'] is None: samplesDef['tagSel'].set_weight(weightName)

#############################################################
# Bining definition  [can be nD bining]


deltaR_bins = [ { 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [0.0, 0.16, 0.32, 0.48, 0.8] } ] #5 bins in [0, 0.8] range
# deltaR_bins = [ { 'var' : 'Jpsi_muonsDr', 'type' : 'float' , 'bins' : [0.8/5.*i for i in range(6)] } ] #5 bins in [0, 0.8] range
pt_bins     = [ { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3.1, 3.4, 5, 7., 9., 12., 40]} ]
#               { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3., 3.1, 3.2, 3.5, 4., 6., 7., 8., 9., 10., 12., 40]},
eta_bins    = [ { 'var' : 'Jpsi_m2_eta', 'type' : 'float' , 'bins' : [-2.6, -2.05, -1.5, -0.75, 0, 0.75, 1.5, 2.05, 2.6]} ]
#               { 'var' : 'abs(Jpsi_m2_eta)', 'type' : 'float' , 'bins' : [0, 1.4, 2.6]},

if is_vs_deltaR:
    biningDef = deltaR_bins + pt_bins
elif is_vs_deltaR_eta:
    biningDef = eta_bins + deltaR_bins
else:
    biningDef = eta_bins + pt_bins

#############################################################
# Cuts definition for all samples

cutBase = ''

## turn-on cuts
cutBase += 'Jpsi_m1_pt > 2.8 && Jpsi_m2_pt > 2.8'
if is_vs_deltaR:
    cutBase += ' && abs(Jpsi_m1_eta) < 2.4 && abs(Jpsi_m2_eta) < 2.4' #100% efficient vs eta
else:
    cutBase += ' && abs(Jpsi_m1_eta) < 2.6 && abs(Jpsi_m2_eta) < 2.6' #2.5 before
cutBase += ' && Jpsi_nonfit_pt > 5.0' #4.9 nominal

if not is_altref:
  cutBase += ' && Jpsi_m1_pt > 7.8' #already imposed on data, but not on MC

## mass cuts
cutBase += ' && Jpsi_nonfit_mass > 2.6 && Jpsi_nonfit_mass < 3.5' 

if is_tagInEB:
    cutBase += ' && Jpsi_m1_eta < 1.4'

# L1 cuts (100% efficient)
if is_L1cuts:
    cutBase += '&& Jpsi_muonsDr < 1.3' #1.4 nominal
    cutBase += '&& abs(Jpsi_m1_eta - Jpsi_m2_eta) < 1.5' #1.6 nominal
    cutBase += '&& Jpsi_m1_bestL1dR < 0.3 && Jpsi_m2_bestL1dR < 0.3'

#Prescale cuts (disable PS=0 seeds in MC)
if is_prescale:
    cutBase += '&& (L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p6 || L1_DoubleMu0er2p0_SQ_OS_dEta_Max1p5 || L1_DoubleMu0er1p4_SQ_OS_dR_Max1p4 || L1_DoubleMu0er1p5_SQ_OS_dR_Max1p4 || L1_DoubleMu4p5_SQ_OS_dR_Max1p2 || L1_DoubleMu4_SQ_OS_dR_Max1p2)'


## sanity cuts
# cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'

# can add addtionnal cuts for some bins (first check bin number using tnpEGM --checkBins)
additionalCuts = None

#############################################################
# Fitting params to tune fit by hand if necessary
tnpParAltSigFitJPsi = [
    "meanP[3.0969, 3.0, 3.4]","sigmaP[0.03, 0.01, 0.5]",
    "meanF[3.0969, 3.0, 3.4]","sigmaF[0.03, 0.01, 0.5]", #sigmaF initial = 0.03, max 0.5, min 0.01
    "alphaP[-1, -10, 10]",
    "alphaF[-1, -10, 10]",    
    ]

tnpParNomFitJPsi = [
    # "meanP[3.0969, 3.09, 3.11]","sigmaP[0.05, 0.03, 0.2]",  "alphaLP[0.6, 0.2, 0.95]","alphaRP[1.2, 0.5, 1.5]","nLP[3.6, 3.56, 3.64]","nRP[1.85, 1.80, 1.95]",
    # "meanF[3.0969, 3.09, 3.11]","sigmaF[0.01, 0.001, 0.03]","alphaLF[0.6, 0.2, 0.7]","alphaRF[1.2, 1.0, 1.5]","nLF[3.6, 3.56, 3.64]","nRF[1.85, 1.80, 1.95]",
    # "expalphaP[0., -0.1, 0.8]", #-0.1 before
    # "expalphaF[0., -0.2, 0.8]", #-0.2 before
    "meanP[3.0969, 3.07, 3.11]","sigmaP[0.03, 0.01, 0.2]", "alphaLP[0.6, 0.05, 5.]","alphaRP[1.2, 0.1, 2.]","nLP[3.6, .01, 100.]","nRP[1.85, .010, 200.]",
    "meanF[3.0969, 3.07, 3.11]","sigmaF[0.03, 0.01, 0.1]","alphaLF[0.6, 0.05, 5.]","alphaRF[1.2, 0.1, 2.]","nLF[3.6, .01, 100.]","nRF[1.85, .001, 200.]",
    "expalphaP[0., -50., .1]",
    "expalphaF[0., -50., .1]",
    ]
     
tnpParAltBkgFitJPsi = [
    "meanP[-0.0,-5.0,5.0]","sigmaP[0.1,0.01,3.0]",      
    "meanF[-0.0,-0.5,0.5]","sigmaF[0.1,0.01,1.0]",
    "cP[0.,-100.,100.]",
    "cF[0.,-100.,500.]",
    ]

