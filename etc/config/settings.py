#############################################################
# General settings

# flag to be Tested
idbdtlppassEB = '(probeIsLowPt==1) && probeAbsEta<1.5 && (probeMvaId > %f )' % 1.5
idbdtlppassEE = '(probeIsLowPt==1) && probeAbsEta>1.5 && (probeMvaId > %f )' % 1.5

# flag to be Tested
flags = {
    'passingIdLPEB'  : idbdtlppassEB,
    'passingIdLPEE'  : idbdtlppassEE,
    }
baseOutDir = 'results/test/'

#############################################################
# Samples definition  - preparing the samples

### samples are defined in etc/inputs/tnpSampleDef.py
### not: you can setup another sampleDef File in inputs
import etc.inputs.tnpSampleDef as tnpSamples
tnpTreeDir = 'tnpAna'

samplesDef = {
    'data'   : tnpSamples.Parking_Jan16['data_Run2018ALL'].clone(),
    'mcNom'  : tnpSamples.Parking_Jan16['BuToKJpsi'].clone(),
    'mcAlt'  : tnpSamples.Parking_Jan16['BuToKJpsi'].clone(),
    'tagSel' : tnpSamples.Parking_Jan16['BuToKJpsi'].clone(),
}

## if you need to use 2 times the same sample, then rename the second one
if not samplesDef['mcAlt'] is None:
    samplesDef['mcAlt'].rename('BuToKJpsi_mcAlt')
if not samplesDef['tagSel'] is None:
    samplesDef['tagSel'].rename('BuToKJpsi_tagSel')

## set MC weight
weightName = 'weight'    # 1 for data; pu_weight for MC   
if not samplesDef['mcNom' ] is None: samplesDef['mcNom' ].set_weight(weightName)
if not samplesDef['mcAlt' ] is None: samplesDef['mcAlt' ].set_weight(weightName)
if not samplesDef['tagSel'] is None: samplesDef['tagSel'].set_weight(weightName)

#############################################################
# Bining definition  [can be nD bining]
biningDef = [
    # EB
    #{ 'var' : 'probeAbsEta' , 'type': 'float', 'bins': [0, 1.5] },
    #{ 'var' : 'probePt' , 'type': 'float', 'bins': [0.5,1.5,2.0,5.0,20.0] },
    # EE
    { 'var' : 'probeAbsEta' , 'type': 'float', 'bins': [1.5, 2.5] },
    { 'var' : 'probePt' , 'type': 'float', 'bins': [0.5,2.0,5.0,20.0] },
]

#############################################################
# Cuts definition for all samples
# EB
#cutBase = 'probePt>0.5 && probePt<20 && probeIsLowPt==1 && hlt_9 && probeAbsEta<1.5'
# EE
cutBase = 'probePt>0.5 && probePt<20 && probeIsLowPt==1 && hlt_9 && probeAbsEta>1.5'

# can add addtionnal cuts for some bins (first check bin number using tnpEGM --checkBins)
#additionalCuts = { 
#    0 : 'tag_Ele_trigMVA > 0.92 && sqrt( 2*event_met_pfmet*tag_Ele_pt*(1-cos(event_met_pfphi-tag_Ele_phi))) < 45'
#}

# or remove any additional cut (default)
additionalCuts = None

#############################################################
# Fitting params to tune fit by hand if necessary
tnpParAltSigFitJPsi = [
    "meanP[-0.0,-5.0,5.0]","sigmaP[0.1,0.01,3.0]",      
    "meanF[-0.0,-0.5,0.5]","sigmaF[0.1,0.01,1.0]",
    "alphaP[0.5, 0.2, 0.8]",
    "alphaF[0.5, 0.2, 0.8]",    
    ]

tnpParNomFitJPsi = [

    # EB with pT 0.5-1.5 
    # with fix sigmaF, meanF, alphaLF, alphaRF, nLF, nRF to those for passing
    # 26 bin, 2.3-3.6
    #"meanP[3.0969, 3.095, 3.098]","sigmaP[0.05, 0.03, 0.1]","alphaLP[0.6, 0.2, 0.7]","alphaRP[1.2, 1.0, 1.5]","nLP[3.6, 3.56, 3.64]","nRP[1.85, 1.80, 1.95]",
    #"meanF[3.0969, 3.09, 3.10]","sigmaF[0.05, 0.03, 0.1]","alphaLF[0.6, 0.2, 0.7]","alphaRF[1.2, 0.8, 1.5]","nLF[3.6, 3.56, 3.64]","nRF[1.85, 1.80, 1.95]",
    #"expalphaP[0.5, 0.2, 0.8]",
    #"expalphaF[0.5, 0.2, 0.8]",   

    # EB with pT 1.5-2 
    # with fix sigmaF=sigmaP  
    # 26 bin, 2.3-3.6  
    #"meanP[3.0969, 3.08, 3.10]","sigmaP[0.05, 0.03, 0.1]","alphaLP[0.6, 0.2, 0.7]","alphaRP[1.2, 1.0, 1.5]","nLP[3.6, 3.56, 3.64]","nRP[1.85, 1.80, 1.95]",
    #"meanF[3.0969, 3.09, 3.10]","sigmaF[0.05, 0.03, 0.1]","alphaLF[0.6, 0.2, 0.7]","alphaRF[1.2, 1.0, 1.5]","nLF[3.6, 3.56, 3.64]","nRF[1.85, 1.80, 1.95]",
    #"expalphaP[0.5, -0.2, 0.8]",
    #"expalphaF[0.5, 0.2, 0.8]",   

    # EB with pT 2-5 and pT>5
    # with fix sigmaF, alphaLF, alphaRF, nLF, nRF to those for passing. NB: meanF free
    # 18 bin, 2.6-3.5   
    #"meanP[3.09, 3.085, 3.095]","sigmaP[0.05, 0.03, 0.1]",  "alphaLP[0.6, 0.2, 0.7]","alphaRP[1.2, 1.0, 1.5]","nLP[3.6, 3.56, 3.64]","nRP[1.80, 1.70, 1.95]",
    #"meanF[3.082, 3.070, 3.085]","sigmaF[0.01, 0.001, 0.03]","alphaLF[0.6, 0.2, 0.7]","alphaRF[1.2, 1.0, 1.5]","nLF[3.6, 3.56, 3.64]","nRF[1.85, 1.80, 1.95]",
    #"expalphaP[-0.75, -1., -0.5]",
    #"expalphaF[0., -0.5, 0.2]",       

    # EE with pT<5
    # with fix sigmaF, meanF, alphaLF, alphaRF, nLF, nRF to those for passing
    # 26 bin, 2.3-3.6
    #"meanP[3.0969, 3.095, 3.1]","sigmaP[0.05, 0.03, 0.12]","alphaLP[0.6, 0.2, 0.7]","alphaRP[0.75, 0.4, 1.]","nLP[3.4, 3.3, 3.60]","nRP[1.85, 1.80, 1.95]",
    #"meanF[3.0969, 3.095, 3.098]","sigmaF[0.05, 0.03, 0.1]","alphaLF[0.6, 0.2, 0.7]","alphaRF[1.2, 1.0, 1.5]","nLF[3.6, 3.56, 3.64]","nRF[1.85, 1.80, 1.95]",
    #"expalphaP[0.6, 0.5, 1.]",
    #"expalphaF[0., -0.2, 0.8]",   
    
    # EE with pT>5 
    # with fix sigmaF, meanF, alphaLF, alphaRF, nLF, nRF to those for passing
    # 26 bin, 2.3-3.6
    "meanP[3.0969, 3.09, 3.11]","sigmaP[0.05, 0.03, 0.2]",  "alphaLP[0.6, 0.2, 0.95]","alphaRP[1.2, 0.5, 1.5]","nLP[3.6, 3.56, 3.64]","nRP[1.85, 1.80, 1.95]",
    "meanF[3.0969, 3.09, 3.11]","sigmaF[0.01, 0.001, 0.03]","alphaLF[0.6, 0.2, 0.7]","alphaRF[1.2, 1.0, 1.5]","nLF[3.6, 3.56, 3.64]","nRF[1.85, 1.80, 1.95]",
    "expalphaP[0., -0.1, 0.8]",
    "expalphaF[0., -0.2, 0.8]",   
    ]
     
tnpParAltBkgFitJPsi = [
    "meanP[-0.0,-5.0,5.0]","sigmaP[0.1,0.01,3.0]",      
    "meanF[-0.0,-0.5,0.5]","sigmaF[0.1,0.01,1.0]",
    "cP[0.,-100.,100.]",
    "cF[0.,-100.,500.]",
    ]

