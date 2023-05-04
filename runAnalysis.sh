output_folder=$MYEOS/TnP

# Define flags and their default values
two_d_only=false
no_save=false
fit_only=false
nominal=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -2d_only)
            two_d_only=true
            shift ;;
        -no_save)
            no_save=true
            shift ;;
		-fit_only)
			fit_only=true
			shift ;;
		-nominal)
			nominal=true
			shift ;;
        *)
            echo "Unknown flag: $1"
            return 1 ;;
    esac
done

flagArray=('--createBins' '--createHists' '--doFit' '--doFit --altSig --mcSig' '--doFit --altSig' '--sumUp')

#iterate over 2D analysis, 1D pT projection and 1D eta projection by working folders
for folder in / /projPt /projEta; do

	prefix=$([ ${#folder} == 1 ] && echo "" || echo "_")
	settings_file=settings$prefix${folder:1}.py

	# choosing print output
	if [[ "$folder" == "/" ]]
	then
		echo "### 2D ANALYSIS"
	elif [[ "$folder" == "/projPt" ]]
	then
		echo "##### 1D ANALYSIS: X projection (pT only)"		
	elif [[ "$folder" == "/projEta" ]]
	then
		echo "##### 1D ANALYSIS: Y projection (eta only)"
	fi

	# Execute analysis
	for flag in "${flagArray[@]}"
	do
		# if -fit_only, then skip bin evaluation/hist filling
		# if -nominal, skip altSig fitting
		if [[( ($flag == "--createBins" || $flag == "--createHists") && "$fit_only" == false) || ($flag == "--doFit" || $flag == "--sumUp") || (($flag == "--doFit --altSig --mcSig" || $flag == "--doFit --altSig") && "$nominal" == false)]]; then
			python tnpEGM_fitter.py etc/config/$settings_file --flag DoubleMu $flag
		fi
	done

	
	# Copying results file to eos
	rm -r $output_folder$folder/nominalFit
		echo "removed old plots"
	cp -r results/muons$folder/DoubleMu/plots/data/nominalFit/ $output_folder$folder
	cp -r results/muons$folder/DoubleMu/plots/data/altSigFit/ $output_folder$folder
	cp results/muons$folder/DoubleMu/egammaEffi.txt_egammaPlots.pdf $output_folder$folder
	cp results/muons$folder/DoubleMu/egammaEffi.txt $output_folder$folder
		echo "copied new plots + summary plot"

	# Exit if -2d_only is provided
	if [ "$two_d_only" = true ]; then
		return 0
	fi

done


# draw and save efficiency plot
echo ".q" | root -b "draw2Deff.C(\"$output_folder\")"
