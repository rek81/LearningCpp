#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "TROOT.h"
#include "TSystem.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"


using namespace std;
class BinHistoFunc {
public:

  BinHistoFunc(std::string filename, std::string histname);
  //  Float_t BinHisto() const;
    //    std::cout << "in class" << std::endl;
  TFile *F = TFile::Open(std::string filename.c_str());
  TH1F *hist = (TH1F *)F->Get(std::string histname.c_str());
    int binsx = hist->GetNbinsX();
    //    std::cout << "hi" << std::endl;
  //  std::cout << F << std::endl;
    for(int b = 1; b < binsx; b++){
      
      Float_f valx = hist->GetBin(b);
      cstd::out << valx << std::endl;
      return valx;

    }
};

BinHistoFunc::BinHistoFunc("/home/rek81/userArea/CMSSW_10_2_2/src/trigger_turn_on/Final_for_Analysis_Note/SingleMuon/HTcut900/outputs/triggerRatePlots_RunE.root", "HTTrigNum"){
  std::cout << "hi" << std::endl;

}

      //} obj;
      //obj.BinHisto("/home/rek81/userArea/CMSSW_10_2_2/src/trigger_turn_on/Final_for_Analysis_Note/SingleMuon/HTcut900/outputs/triggerRatePlots_RunE.root", "HTTrigNum");

    //    return 0;


