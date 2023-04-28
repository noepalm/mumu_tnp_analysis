rm -r $MYEOS/TnP/nominalFit
echo "removed old plots"
cp -r results/muons/DoubleMu/plots/data/nominalFit/ $MYEOS/TnP
cp results/muons/DoubleMu/egammaEffi.txt_egammaPlots.pdf $MYEOS/TnP
cp results/muons/DoubleMu/egammaEffi.txt $MYEOS/TnP
echo "copied new plots + summary plot"
