output_folder=$MYEOS/TnP
input_folder=/muons

# Define flags and their default values
two_d_only=false
fit_only=false
nominal=false
copy_only=false
draw_only=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -2d_only)
            two_d_only=true
            shift ;;
		-fit_only)
			fit_only=true
			shift ;;
		-nominal)
			nominal=true
			shift ;;
		-copy_only)
			copy_only=true
			shift ;;
		-draw_only)
			draw_only=true
			shift ;;
		-deltaR)
			input_folder=/vs_pt_deltaR
			output_folder=$MYEOS/TnP_vs_pt_deltaR
			shift ;;
		-tagInEB)
			input_folder=/muons_tagInEB
			output_folder=$MYEOS/TnP_tagInEB
			shift ;;
		-L1cuts)
			input_folder=/muons_L1cuts
			output_folder=$MYEOS/TnP_L1cuts
			shift ;;
        *)
            echo "Unknown flag: $1"
            return 1 ;;
    esac
done

flagArray=('--createBins' '--createHists' '--doFit' '--doFit --altSig --mcSig' '--doFit --altSig' '--doFit --altSig --iBin' '--sumUp')

# bins to be refit (list bins by number)
bins_2d=(2 3)
bins_pt=(0)

#iterate over 2D analysis, 1D pT projection and 1D eta projection by working folders
# for folder in / /projPt /projEta /deltaR; do
for folder in / /projPt /projEta; do

	if [[ ($copy_only == false) && ($draw_only == false) ]]; then
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
		# elif [[ "$folder" == "/deltaR" ]]
		# then
		# 	echo "##### 2D ANALYSIS: pT vs deltaR"
		fi 

		# Execute analysis
		for flag in "${flagArray[@]}"
		do
			# if -fit_only, then skip bin evaluation/hist filling
			# if -nominal, skip altSig fitting

			# main command
			if [[ ( ($flag == "--createBins" || $flag == "--createHists") && "$fit_only" == false) || ($flag == "--doFit" || $flag == "--sumUp") || (($flag == "--doFit --altSig --mcSig" || $flag == "--doFit --altSig") && "$nominal" == false)]]; then
				python tnpEGM_fitter.py etc/config/$settings_file --flag DoubleMu $flag

			# per-bin refit (fine tuning, different initial params)
			elif [[ ($flag == "--doFit --altSig --iBin"*) && ($folder == "/" || $folder == "/projPt") ]]; then
				bin_array=()
				if [[ $folder == "/" ]]; then
					bin_array=(${bins_2d[@]})
				elif [[ $folder == "/projPt" ]]; then
					bin_array=(${bins_pt[@]})
				fi

				for bin in "${bin_array[@]}"; do
					flag_mod="${flag} ${bin}" #add bin to flag
					settings_file_mod="${settings_file::-3}_bin${bin}.py" #change settings file to use
					
					python tnpEGM_fitter.py etc/config/$settings_file_mod --flag DoubleMu $flag_mod
				done										
			fi

		done
		
	fi

	if [[ $draw_only == false ]]; then
		# Copying results file to eos
		rm -r $output_folder$folder/nominalFit
		echo "removed old plots in $output_folder$folder/nominalFit"
		cp -r results$input_folder$folder/DoubleMu/plots/data/nominalFit $output_folder$folder
		echo "copied fit plots folder results$input_folder$folder/DoubleMu/plots/data/nominalFit/ to $output_folder$folder/nominalFit"

		rm -r ${output_folder}/MC${folder}/altSigFit
		echo "removed old plots in $output_folder/MC$folder/altSigFit"
		cp -r results$input_folder$folder/DoubleMu/plots/MC/altSigFit ${output_folder}/MC${folder}
		echo "copied fit plots folder results$input_folder$folder/DoubleMu/plots/MC/altSigFit/ to $output_folder/MC$folder/altSigFit"

		if [[ $nominal == false ]]; then
			rm -r $output_folder$folder/altSigFit
			echo "removed old plots in $output_folder$folder/altSigFit"
			cp -r results$input_folder$folder/DoubleMu/plots/data/altSigFit/ $output_folder$folder
			echo "copied fit plots folder results$input_folder$folder/DoubleMu/plots/data/altSigFit to $output_folder$folder"
		fi
		cp results$input_folder$folder/DoubleMu/egammaEffi.txt_egammaPlots.pdf $output_folder$folder
		cp results$input_folder$folder/DoubleMu/egammaEffi.txt $output_folder$folder
		echo "copied summary plots + txt from results$input_folder$folder/DoubleMu to $output_folder$folder"

		# Exit if -2d_only is provided
		if [ "$two_d_only" = true ]; then
			return 0
		fi

	fi

done


if [[ $copy_only == false ]]; then
	# draw and save efficiency plot
	echo ".q" | root -b "draw2Deff.C(\"$output_folder\", \"$input_folder\")"
fi
