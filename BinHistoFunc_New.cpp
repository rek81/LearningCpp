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
  //  void *hist;
  //  TH1F *hist;
  TH1F *hist1;
  TH2F *hist2;
  TH3F *hist3;
  //  string type;
  BinHistoFunc_New(std::string filename, std::string histname){
    F = TFile::Open(filename.c_str());
    //    hist = (TH1F *)F->Get(histname.c_str());
    //    hist2 = (TH2F *)F->Get(histname.c_str());
    if (dynamic_cast<TH1F*> ((TH1F *)F->Get(histname.c_str()))) {TH1F* hist = (TH1F *)F->Get(histname.c_str())}
    else if (dynamic_cast<TH2F*> ((TH2F *)F->Get(histname.c_str()))) {TH2F* hist = (TH2F *)F->Get(histname.c_str())}
      //string histstring = histname.c_str();
    //    type = histtype.c_str();   
  };

  //  float GetBinContent(void){ 
  float GetBinContent(){ 
    float val;
    //    if (dynamic_cast<TH1F*> (hist = F->Get(histstring))){
    //    if {
      int binsx = hist->GetNbinsX();
      std::cout << "hi" << std::endl;
      std::cout << binsx << std::endl;
      for(int b = 1; b < binsx; b++){
	val = hist->GetBinContent(b);
	std::cout << "val is " << val << std::endl;
	std::cout << "bin is " << b << std::endl;
      };
    } else if (type=="2D"){
      int binsx = hist2->GetNbinsX();
      int binsy = hist2->GetNbinsY();
      for(int bx = 1; bx < binsx; bx++){
	for(int by = 1; by < binsy; by++){
	  float val = hist2->GetBinContent(bx, by);
	  std::cout << "val is " << val << std::endl;
	};
      };
    }
    else {}
    return val; 
  };
  float GetBinContentByAxis(float xmin = 0 , float xmax = 0 , float ymin = 0, float ymax = 0) {
    float val;
    if (type=="1D"){ 
      float Xmin = xmin;
      float Xmax = xmax;
      TAxis *xaxis = hist->GetXaxis();
      int bxmin = xaxis->FindBin(Xmin);
      int bxmax = xaxis->FindBin(Xmax);
      for(int bx = bxmin; bx < bxmax; bx++){
	val = hist->GetBinContent(bx);
	std::cout << "val is " << val << std::endl;
      }
    }
    else if (type=="2D"){
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
  };
};


BinHistoFunc_New obj =  BinHistoFunc_New("/home/rek81/userArea/CMSSW_10_2_2/src/trigger_turn_on/Final_for_Analysis_Note/SingleMuon/HTcut900/outputs/triggerRatePlots_RunE.root", "HTTrigNum");
float a = obj.GetBinContent();
//float a = obj.GetBinContentByAxis(1000, 1500);
//BinHistoFunc_New obj2d =  BinHistoFunc_New("2D", "../2DhistoPlot/Hists_2dtest.root", "avgMassvsEta1");
//float a = obj2d.GetBinContent();
//float a = obj2d.GetBinContentByAxis(50, 100, -1.5, 1.5);
