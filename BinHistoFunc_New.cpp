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

class BinHistoFunc_New {
public:
  TFile *F;
  TH1F *hist1;
  TH2F *hist2;
  TH3F *hist3;
  BinHistoFunc_New(std::string filename, std::string histname){
    std::cout << "in constructor" << std::endl;
    F = TFile::Open(filename.c_str());
    std::cout << "file in constructor is " << F << std::endl;

    hist1 = dynamic_cast<TH1F*> (F->Get(histname.c_str()));
    hist2 = dynamic_cast<TH2F*> (F->Get(histname.c_str()));
    hist3 = dynamic_cast<TH3F*> (F->Get(histname.c_str()));

    std::cout << "histo1 in constructor is " << hist1 << std::endl;
    std::cout << "histo2 in constructor is " << hist2 << std::endl;
    std::cout << "histo3 in constructor is " << hist3 << std::endl;
  };

  float GetBinContent(void){ 
    std::cout << "hist1 is " << hist1 << std::endl;
    std::cout << "hist2 is " << hist2 << std::endl;
    std::cout << "hist3 is " << hist3 << std::endl;
    
    float val;
    if (hist1 != 0) {
      std::cout << "in if of func" << std::endl;
      int binsx = hist1->GetNbinsX();
      std::cout << binsx << std::endl;
      for(int b = 1; b < binsx; b++){
	val = hist1->GetBinContent(b);
	std::cout << "val is " << val << std::endl;
	std::cout << "bin is " << b << std::endl;
      }
    }
  
    else if (hist2 != 0){
      int binsx = hist2->GetNbinsX();
      int binsy = hist2->GetNbinsY();
      for(int bx = 1; bx < binsx; bx++){
	for(int by = 1; by < binsy; by++){
	  float val = hist2->GetBinContent(bx, by);
	  std::cout << "val is " << val << std::endl;
	}
      }
    }
  
    else {}
    return val; 
  }
  float GetBinContentByAxis(float xmin = 0 , float xmax = 0 , float ymin = 0, float ymax = 0) {
    float val;
    if (hist1){ 
      float Xmin = xmin;
      float Xmax = xmax;
      TAxis *xaxis = hist1->GetXaxis();
      int bxmin = xaxis->FindBin(Xmin);
      int bxmax = xaxis->FindBin(Xmax);
      for(int bx = bxmin; bx < bxmax; bx++){
	val = hist1->GetBinContent(bx);
	std::cout << "val is " << val << std::endl;
      }
    }
    else if (hist2){
      std::cout << "I am in 2D if statment" << std::endl;
      float Xmin = xmin;
      float Xmax = xmax;
      float Ymin = ymin;
      float Ymax = ymax;
      TAxis *xaxis = hist2->GetXaxis();
      TAxis *yaxis = hist2->GetYaxis();
      int bxmin = xaxis->FindBin(Xmin);
      int bxmax = xaxis->FindBin(Xmax);
      int bymin = yaxis->FindBin(Ymin);
      int bymax = yaxis->FindBin(Ymax);
      std::cout << "bins are~ xmin: " << bxmin << ", xmax: " << bxmax << ", ymin: " << bymin << ", and ymax: " << bymax << std::endl;
      for(int bx = bxmin; bx < bxmax; bx++){
	for(int by = bymin; by < bymax; by++){
	  val = hist2->GetBinContent(bx, by);
	  std::cout << "val is " << val << std::endl;
	}
      }
    }
    else {}
    return val;
  }
};


BinHistoFunc_New obj = new BinHistoFunc_New("/home/rek81/userArea/CMSSW_10_2_2/src/trigger_turn_on/Final_for_Analysis_Note/SingleMuon/HTcut900/outputs/triggerRatePlots_RunE.root", "HTTrigNum");
//BinHistoFunc_New obj("/home/rek81/userArea/CMSSW_10_2_2/src/trigger_turn_on/Final_for_Analysis_Note/SingleMuon/HTcut900/outputs/triggerRatePlots_RunE.root", "HTTrigNum");
float a = obj.GetBinContent();
//return;
//BinHistoFunc_New (){};
float a = obj.GetBinContentByAxis(1000, 1500);
//BinHistoFunc_New obj2d =  BinHistoFunc_New("../2DhistoPlot/Hists_2dtest.root", "avgMassvsEta1");
//float a = obj2d.GetBinContent();
//float a = obj2d.GetBinContentByAxis(50, 100, -1.5, 1.5);
