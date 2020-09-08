#############################################################
########## General settings
#############################################################
# flag to be Tested
bdtlppass0 = '(probeIsLowPt==1) && (probeMvaId > %f )' % 0.3,
seedbdtlppass3 = '(probeUnBiased > %f )' % 3.0

# flag to be Tested
flags = {
    'passingIdLP0'  : bdtlppass0,
    'passingRecoLP3'  : seedbdtlppass3,
    }
baseOutDir = 'results/test/'

#############################################################
########## samples definition  - preparing the samples
#############################################################
### samples are defined in etc/inputs/tnpSampleDef.py
### not: you can setup another sampleDef File in inputs
import etc.inputs.tnpSampleDef as tnpSamples
tnpTreeDir = 'tnpAna'

samplesDef = {
    'data'   : tnpSamples.Parking_Jan16['data_Run2018D'].clone(),
    'mcNom'  : tnpSamples.Parking_Jan16['BuToKJpsi'].clone(),
    'mcAlt'  : tnpSamples.Parking_Jan16['BuToKJpsi'].clone(),
    'tagSel' : tnpSamples.Parking_Jan16['BuToKJpsi'].clone(),
}

# rename samples - name must be different
if not samplesDef['mcAlt'] is None:
    samplesDef['mcAlt'].rename('BuToKJpsi_mcAlt')
if not samplesDef['tagSel'] is None:
    samplesDef['tagSel'].rename('BuToKJpsi_tagSel')

## can add data sample easily
#samplesDef['data'].add_sample( tnpSamples.ICHEP2016['data_2016_runC_ele'] )

# require mcTruth - chiara, per ora lo spengo
#if not samplesDef['mcNom' ] is None: samplesDef['mcNom' ].set_mcTruth()
#if not samplesDef['mcAlt' ] is None: samplesDef['mcAlt' ].set_mcTruth()
#if not samplesDef['tagSel'] is None: samplesDef['tagSel'].set_mcTruth()

# additional cuts for specific samples:
samplesDef['mcNom'].set_cut('probeMatchMC==1 && tagMatchMC==1')    # require mcTruth
samplesDef['mcAlt'].set_cut('probeMatchMC==1 && tagMatchMC==1')    # require mcTruth
samplesDef['tagSel'].set_cut('probeMatchMC==1 && tagMatchMC==1')   # require mcTruth

## set MC weight, simple way (use tree weight) 
weightName = 'weight'      
if not samplesDef['mcNom' ] is None: samplesDef['mcNom' ].set_weight(weightName)
if not samplesDef['mcAlt' ] is None: samplesDef['mcAlt' ].set_weight(weightName)
if not samplesDef['tagSel'] is None: samplesDef['tagSel'].set_weight(weightName)

#############################################################
########## bining definition  [can be nD bining]
#############################################################
biningDef = [
    #{ 'var' : 'probeAbsEta' , 'type': 'float', 'bins': [0, 1.4442, 2.5] },
    { 'var' : 'probeAbsEta' , 'type': 'float', 'bins': [0, 2.5] },
    { 'var' : 'probePt' , 'type': 'float', 'bins': [0.5,2.0,5.0,20.0] },
    #{ 'var' : 'probePt' , 'type': 'float', 'bins': [0.5,2.0,5.,50.] },
]

#############################################################
########## Cuts definition for all samples
#############################################################
### cut
## cutBase = 'hlt_12==1 && probePt>0.5 && probePt<20 && probeIsLowPt==1'
cutBase = 'probePt>0.5 && probePt<20 && probeIsLowPt==1'

# can add addtionnal cuts for some bins (first check bin5 number using tnpEGM --checkBins)
#additionalCuts = { 
#    0 : 'tag_Ele_trigMVA > 0.92 && sqrt( 2*event_met_pfmet*tag_Ele_pt*(1-cos(event_met_pfphi-tag_Ele_phi))) < 45',
#}

#### or remove any additional cut (default)
additionalCuts = None

#############################################################
########## fitting params to tune fit by hand if necessary
#############################################################
tnpParNomFit = [
    # 0.5-2 GeV
    "meanP[0.0,-0.5,0.5]","sigmaP[0.1,0.001,0.3]",
    "meanF[-0.0,-1.0,1.0]","sigmaF[0.1,0.01,1.5]",
    "acmsP[2.8,2.7,3.4]","betaP[0.05,0.01,0.1]","gammaP[0.01, 0, 1]","peakP[3.1]",
    "acmsF[4.,2.7,10.]","betaF[0.05,0.01,0.1]","gammaF[0.01, 0, 1]","peakF[3.1]",
    ]

tnpParNomFitJPsi = [
    "meanP[-0.0,-5.0,5.0]","sigmaP[0.1,0.01,3.0]",      
    "meanF[-0.0,-0.5,0.5]","sigmaF[0.1,0.01,1.0]",
    "alphaP[0.4,0.,1.]",
    "alphaF[0.,-5.,5.]",    
    ]

tnpParAltSigFitJPsi = [
    "meanP[3.10,3.06,3.12]","sigmaLP[0.07,0.03,0.1]","sigmaRP[0.05,0.02,0.08]","alphaLP[0.5,0.3,0.7]","alphaRP[0.5,0.3,0.7]",
    "meanF[3.05,3.04,3.10]","sigmaLF[0.02,0.01,0.1]","sigmaRF[0.02,0.01,0.10]","alphaLF[0.02,0.01,0.20]","alphaRF[0.010,0.008,0.014]",
    "expalphaP[0.4,0.,1.]",
    "expalphaF[0.,-5.,5.]",   
    ]
     
tnpParAltBkgFitJPsi = [
    "meanP[-0.0,-5.0,5.0]","sigmaP[0.1,0.01,3.0]",      
    "meanF[-0.0,-0.5,0.5]","sigmaF[0.1,0.01,1.0]",
    "cP[0.,-100.,100.]",
    "cF[0.,-100.,500.]",
    ]

