#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include "TROOT.h"
#include "TSystem.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"


using namespace std;
class BinHistoFunc2 {
public:

  //  BinHistoFunc(){} // Constructor without arguments

  float histoFunc(std::string histtype, std::string filename, std::string histname){ //histogram function that takes two file arguments
        TFile *F = TFile::Open(filename.c_str());
	if (histtype=="1D"){
	  TH1F *hist = (TH1F *)F->Get(histname.c_str());
	  int binsx = hist->GetNbinsX();

          std::cout << "hi" << std::endl;
        //  std::cout << F << std::endl;
	  std::cout << binsx << std::endl;
	  float valx;
	  for(int b = 1; b < binsx; b++){
            float valx = hist->GetBinContent(b);
	    std::cout << "valx is " << valx << std::endl;
	    std::cout << "bin is " << b << std::endl;
	  };
	  return valx;
	}
	else if (histtype=="2D"){
	    TH2F *hist = (TH2F *)F->Get(histname.c_str());
	    int binsx = hist->GetNbinsX();
	    int binsy = hist->GetNbinsY();

        //  std::cout << "hi" << std::endl;
        //  std::cout << F << std::endl;
	  //	  std::cout << binsx << std::endl;
	    float val;
	    for(int bx = 1; bx < binsx; bx++){
	      for(int by = 1; by < binsy; by++){
		float val = hist->GetBinContent(bx, by);
		//	      std::cout << "valx is " << valx << std::endl;
	      //	      std::cout << "bin is " << b << std::endl;
	      };
	    };
	    return val;
	}
	
  }
};
  BinHistoFunc2 obj;

//float a = obj.histoFunc("1D", "/home/rek81/userArea/CMSSW_10_2_2/src/trigger_turn_on/Final_for_Analysis_Note/SingleMuon/HTcut900/outputs/triggerRatePlots_RunE.root", "HTTrigNum");
float a = obj.histoFunc("2D", "2Dhistomaker/Hists_2dtest.root", "avgMassvsEta1");
