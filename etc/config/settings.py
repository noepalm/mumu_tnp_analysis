#############################################################
# General settings

# flag to be Tested
DoubleMu = 'DoubleMu_fired == 1'					# trigger fired
DoubleMu += ' && Jpsi_m1_Dimu_pt != Jpsi_m2_Dimu_pt'			# NOT (same HLT object matched to both offline muons)
DoubleMu += ' && Jpsi_m2_Dimu_dR < 0.1'					# probe HLT candidate matched to an offline muon


# flag to be Tested
flags = {
    'DoubleMu' : DoubleMu
    }
baseOutDir = 'results/muons/'

#############################################################
# Samples definition  - preparing the samples

### samples are defined in etc/inputs/tnpSampleDef.py
### not: you can setup another sampleDef File in inputs
import etc.inputs.tnpSampleDef as tnpSamples
tnpTreeDir = 'nano_'

samplesDef = {
    'data'   : tnpSamples.Parking_X['data'].clone(),
    'mcNom'  : tnpSamples.Parking_X['data'].clone(),
    'mcAlt'  : None,
    'tagSel' : None
    # 'mcNom'  : tnpSamples.Parking_X['MC'].clone(),
    # 'mcAlt'  : tnpSamples.Parking_X['MC'].clone(),
    # 'tagSel' : tnpSamples.Parking_X['MC'].clone(),
}

## if you need to use 2 times the same sample, then rename the second one
if not samplesDef['mcAlt'] is None:
    samplesDef['mcAlt'].rename('mcAlt')
if not samplesDef['tagSel'] is None:
    samplesDef['tagSel'].rename('tagSel')

## set MC weight
weightName = 'weight'    # 1 for data; pu_weight for MC   
if not samplesDef['mcNom' ] is None: samplesDef['mcNom' ].set_weight(weightName)
if not samplesDef['mcAlt' ] is None: samplesDef['mcAlt' ].set_weight(weightName)
if not samplesDef['tagSel'] is None: samplesDef['tagSel'].set_weight(weightName)

#############################################################
# Bining definition  [can be nD bining]
biningDef = [
    { 'var' : 'abs(Jpsi_m2_eta)', 'type' : 'float' , 'bins' : [0, 1.5, 2.6]},
    # { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3., 3.1, 3.2, 3.5, 4., 6., 7., 8., 9., 10., 12., 40]},
    { 'var' : 'Jpsi_m2_pt', 'type' : 'float' , 'bins' : [2.9, 3.1, 3.4, 5, 7., 9., 12., 40]},
]

#############################################################
# Cuts definition for all samples

cutBase = ''
## turn-on cuts
cutBase += 'Jpsi_m1_pt > 2.8 && Jpsi_m2_pt > 2.8'
cutBase += ' && abs(Jpsi_m1_eta) < 2.5 && abs(Jpsi_m2_eta) < 2.5'
cutBase += ' && Jpsi_fit_pt > 4.9'
## mass cuts
cutBase += ' && Jpsi_fit_mass > 2.6 && Jpsi_fit_mass < 3.5' 
## sanity cuts
cutBase += ' && Jpsi_m1_trgobj_pt != Jpsi_m2_trgobj_pt'


# can add addtionnal cuts for some bins (first check bin number using tnpEGM --checkBins)
#additionalCuts = { 
#    0 : 'tag_Ele_trigMVA > 0.92 && sqrt( 2*event_met_pfmet*tag_Ele_pt*(1-cos(event_met_pfphi-tag_Ele_phi))) < 45'
#}

# or remove any additional cut (default)
additionalCuts = None

#############################################################
# Fitting params to tune fit by hand if necessary
tnpParAltSigFitJPsi = [
    "meanP[3.0969, 3.07, 3.2]","sigmaP[0.03, 0.01, 0.2]",
    "meanF[3.0969, 3.07, 3.2]","sigmaF[0.03, 0.01, 0.2]",
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
    "expalphaP[0., -50., .1]", #-0.1 before
    "expalphaF[0., -50., .1]", #-0.2 before
    ]
     
tnpParAltBkgFitJPsi = [
    "meanP[-0.0,-5.0,5.0]","sigmaP[0.1,0.01,3.0]",      
    "meanF[-0.0,-0.5,0.5]","sigmaF[0.1,0.01,1.0]",
    "cP[0.,-100.,100.]",
    "cF[0.,-100.,500.]",
    ]

