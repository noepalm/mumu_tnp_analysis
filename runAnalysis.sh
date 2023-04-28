echo "### 2D ANALYSIS"
python tnpEGM_fitter.py etc/config/settings.py --flag DoubleMu --createBins
python tnpEGM_fitter.py etc/config/settings.py --flag DoubleMu --createHists
python tnpEGM_fitter.py etc/config/settings.py --flag DoubleMu --doFit
python tnpEGM_fitter.py etc/config/settings.py --flag DoubleMu --sumUp
rm -r $MYEOS/test/nominalFit
echo "	removed old plots"
cp -r results/muons/DoubleMu/plots/data/nominalFit/ $MYEOS/TnP
cp results/muons/DoubleMu/egammaEffi.txt_egammaPlots.pdf $MYEOS/TnP
cp results/muons/DoubleMu/egammaEffi.txt $MYEOS/TnP
echo "	copied new plots + summary plot"

echo "##### 1D ANALYSIS: X projection (pT only)"
python tnpEGM_fitter.py etc/config/settings_projPt.py --flag DoubleMu --createBins
python tnpEGM_fitter.py etc/config/settings_projPt.py --flag DoubleMu --createHists
python tnpEGM_fitter.py etc/config/settings_projPt.py --flag DoubleMu --doFit
python tnpEGM_fitter.py etc/config/settings_projPt.py --flag DoubleMu --sumUp
rm -r $MYEOS/TnP/projPt/nominalFit
echo "	removed old plots"
cp -r results/muons/projPt/DoubleMu/plots/data/nominalFit/ $MYEOS/TnP/projPt
cp results/muons/projPt/DoubleMu/egammaEffi.txt_egammaPlots.pdf $MYEOS/TnP/projPt
cp results/muons/projPt/DoubleMu/egammaEffi.txt $MYEOS/TnP/projPt
echo "	copied new plots + summary plot"

echo "##### 1D ANALYSIS: Y projection (eta only) --finer binning--"
python tnpEGM_fitter.py etc/config/settings_projEta.py --flag DoubleMu --createBins
python tnpEGM_fitter.py etc/config/settings_projEta.py --flag DoubleMu --createHists
python tnpEGM_fitter.py etc/config/settings_projEta.py --flag DoubleMu --doFit
python tnpEGM_fitter.py etc/config/settings_projEta.py --flag DoubleMu --sumUp
rm -r $MYEOS/TnP/projEta/nominalFit
echo "	removed old plots"
cp -r results/muons/projEta/DoubleMu/plots/data/nominalFit/ $MYEOS/TnP/projEta
cp results/muons/projEta/DoubleMu/egammaEffi.txt_egammaPlots.pdf $MYEOS/TnP/projEta
cp results/muons/projEta/DoubleMu/egammaEffi.txt $MYEOS/TnP/projEta
echo "	copied new plots + summary plot"
