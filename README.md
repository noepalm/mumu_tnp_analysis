# Introduction
This is a fork of egm_tnp_analysis, which uses the tag and probe analysis to analyze the efficiency of a dimuon trigger path. It has been modified to accomodate the needs of this specific analysis.

# Setup instructions
* **For running**: Same steps as main repo (setup files have been slightly modified).
Additionally, a global environment variable `$MY_EOS` must be defined containing the path to the output folder (I used by EOS path). All subfolders are handled by the program.
* **For editing**: must setup CPython to edit `.pyc` files (which are converted to `.C` and must be then compiled with `make`).

# Fork differences

* A wrapper to run the code to obtain 1D projections has been added;
* Since this code uses the alternative model as the main one (i.e. gaussian for signal + exponential for backgoound), all drawing was handled by the new macro `draw2Deff.C` (which, despite its name, also draws the 1D projections for each variable). This is to be used through the wrapper;
* $y$ variable is not automatically extended to negative values, so the same code can be used for positive definite quantities (e.g. $\Delta R$);
* [Other stuff I surely forgot]

# Usage
The program is set up can calculate 1D and 2D efficiencies vs. probe's $p_T$, $\eta$ and $\Delta R$ between the tag and probe (in all possible combinations). This is done by running the original code in various settings.

Use the wrapper by using:
```source runAnalysis.sh <-flags>```

To select each setting, you must:
* Activate the corresponding flag in `etc/config/settings.py`;
* Launch `runAnalysis.sh` with the corresponding flag.

Always remember to **change both** when switching configuration.

## Flags

**Changing variables**:
* **No flags** [`runAnalysis.sh`: no flags, `settings.py`: all flags are `False`]:

  [Default] Runs analysis vs. $p_T$, $\eta$. Outputs to `$MY_EOS/TnP`.
* **$\Delta R$ flags** [`runAnalysis.sh`: -deltaR, `settings.py`: is_vs_deltaR = True]:

  Runs analysis vs. $p_T$, $\Delta R$. Outputs to `$MY_EOS/TnP_vs_pt_deltaR`.
* **$\Delta R, \eta$ flags** [`runAnalysis.sh`: -deltaR_eta, `settings.py`: is_vs_deltaR_eta = True]:
  
  Runs analysis vs. $\Delta R$, $\eta$. Outputs to `$MY_EOS/TnP_vs_deltaR_eta`.

**Changings cuts**:
* **No flags**:
 
  [Default] HLT+L1 efficiency is calculated.
* **L1 flags** [`runAnalysis.sh`: -L1cuts, `settings.py`: is_L1cuts = True]:

  Calculates HLT efficiency only (i.e. places base cuts that place us in the 100% efficient region of the L1 trigger). Outputs to `$MY_EOS/<path_depending_on_variables>_L1_cuts`.

The two kinds of flags can be combined (e.g. to study HLT-only efficiency vs. $p_T$, $\Delta R$, run `runAnalysis.sh -deltaR -L1cuts` and, in `settings.py`, set both `is_deltaR = True` and `is_L1cuts = True`).

There are also some wrapper-only flags that can be used to perform specific actions:

* `-fit_only`: does not rebin data, but only reperforms the fits. This can save a lot of time when only changing fit parameters or fine-tuning the fits, but not binning, especially for large files.
* `-copy_only`: only transfers output files to output folders.
* `-draw_only`: does not rebin nor refit, but only redraws the efficiency plots.
* `-2d_only`: does not rerun analysis on 1D projections, but just on 2D plot.

## Changing selection and binning
WIP...

## Fine-tuning
[**Warning**: Refitting is currently only implemented for 2D distribution and 1D $y$ projection, but it should be easy to extend to 1d $x$ projection by simply copying the same structure.]
[**Tip**: at this stage, run the program with the `-fit_only` flag.]

If you notice the fit failing in some specific bin, you can specify the initial parameters to help it converge. To do so, you'll have to:
* List the bins to be refit in the `bins_2d`, `bins_pt` lists inside `runAnalysis.sh`;
  ** To avoid modifying the array every time you change configuration, use the `if` cases below it
* Create a file for each bin named as `settings_bin<number>` for 2D projection and `settings_projPt_bin<number>` for 1D $y$ projection containing the model's initial parameter. Clone the existing example files in `etc/config` and modify the initial parameters (**NOTE**: the initial `import` MUST be left untouched).

Please remember to empty the array in `runAnalysis.sh` when running multiple configurations.

## Output
The program's output includes the following structure:
```
.
├── altSig_data_2D_efficiency.pdf
├── altSigFit
├── projPt
|   └── altSigFit
├── projEta
|   └── altSigFit
|
├── MC
|   ├── altSigFit
|   ├── projPt
|   |   └── altSigFit
|   └── projEta
|       └── altSigFit
|   
└── ...
```

where:

* `altSig_data_2D_efficiency.pdf` is the main output, containing the 2D plot and 1D projections of the efficiency vs. the two selected variables for both data and MC. It also includes scale factor plots.
* the `altSigFit` subfolder contains the individual fit plots for each bin and category (passing/failing probes);

[**Note**: the `projPt` folder always contains the $x$ variable (as plotted in 2D efficiency graphs. In the bin names in the output png, that is the second variable --sorry for the confusion!--), while `projEta` always contains the $y$ variable (first variable in bin names, but actually plotted on the $y$ axis in 2D efficiency).]