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
