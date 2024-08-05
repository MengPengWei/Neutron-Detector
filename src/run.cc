#include "run.hh"

  MyRunAction::MyRunAction() {


  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true); 
  
        analysisManager->CreateNtuple("t1","t1");




        analysisManager->CreateNtupleIColumn(0,"EventID");
        analysisManager->CreateNtupleIColumn(0,"ParentID");
        analysisManager->CreateNtupleIColumn(0,"TrackID");
        analysisManager->CreateNtupleIColumn(0,"StepID");  

        analysisManager->CreateNtupleSColumn(0,"ParticleName");   
        analysisManager->CreateNtupleSColumn(0,"PreVolumeName"); 
        analysisManager->CreateNtupleSColumn(0,"PostVolumeName");
        analysisManager->CreateNtupleSColumn(0,"ProcessName");

        analysisManager->CreateNtupleDColumn(0,"PreKineticEnergy");
        analysisManager->CreateNtupleDColumn(0,"PostKineticEnergy");
        analysisManager->CreateNtupleDColumn(0,"StepEdep");


        analysisManager->CreateNtupleDColumn(0,"PrePositionX");
        analysisManager->CreateNtupleDColumn(0,"PrePositionY");
        analysisManager->CreateNtupleDColumn(0,"PrePositionZ");
        analysisManager->CreateNtupleDColumn(0,"PostPositionX");
        analysisManager->CreateNtupleDColumn(0,"PostPositionY");
        analysisManager->CreateNtupleDColumn(0,"PostPositionZ");
        analysisManager->CreateNtupleDColumn(0,"StepLength");


        analysisManager->CreateNtupleDColumn(0,"PreMomentumX");
        analysisManager->CreateNtupleDColumn(0,"PreMomentumY");
        analysisManager->CreateNtupleDColumn(0,"PreMomentumZ");
        analysisManager->CreateNtupleDColumn(0,"PostMomentumX");
        analysisManager->CreateNtupleDColumn(0,"PostMomentumY");
        analysisManager->CreateNtupleDColumn(0,"PostMomentumZ");


        analysisManager->CreateNtupleDColumn(0,"PreGlobalTime");
        analysisManager->CreateNtupleDColumn(0,"PostGlobalTime");
        analysisManager->CreateNtupleDColumn(0,"PreLocalTime");
        analysisManager->CreateNtupleDColumn(0,"PostLocalTime");


        analysisManager->FinishNtuple(0); 
    
    
      analysisManager->CreateNtuple("t2","t2");
      //粒子在漂移层内的总能量沉积和步长
      analysisManager->CreateNtupleDColumn(1,"All_EventEdep_D");
      analysisManager->CreateNtupleDColumn(1,"All_EventLength_D");
      analysisManager->CreateNtupleDColumn(1,"Li7_EventEdep_D");
      analysisManager->CreateNtupleDColumn(1,"Li7_EventLength_D");
      analysisManager->CreateNtupleDColumn(1,"alpha_EventEdep_D");
      analysisManager->CreateNtupleDColumn(1,"alpha_EventLength_D");
      //粒子在转换层中的能量沉积和步长
      analysisManager->CreateNtupleDColumn(1,"All_EventEdep_T");
      analysisManager->CreateNtupleDColumn(1,"All_EventLength_T");
      analysisManager->CreateNtupleDColumn(1,"Li7_EventEdep_T");
      analysisManager->CreateNtupleDColumn(1,"Li7_EventLength_T");
      analysisManager->CreateNtupleDColumn(1,"alpha_EventEdep_T");
      analysisManager->CreateNtupleDColumn(1,"alpha_EventLength_T");
    analysisManager->FinishNtuple(1);

      analysisManager->CreateNtuple("C1","Constants");      //模拟的相关信息
      //粒子在漂移层内的总能量沉积和步长
      analysisManager->CreateNtupleDColumn(2,"Neutron_Wavelength");
      analysisManager->CreateNtupleDColumn(2,"Neutron_Energy");
      analysisManager->CreateNtupleDColumn(2,"B10_percent");
      analysisManager->CreateNtupleDColumn(2,"Lay");
      analysisManager->CreateNtupleDColumn(2,"Drift_Chamber");
      analysisManager->CreateNtupleDColumn(2,"Transfer");
      analysisManager->CreateNtupleDColumn(2,"SupportPlate");
      analysisManager->CreateNtupleDColumn(2,"Rotate");
    analysisManager->FinishNtuple(2);




    
    
    }




    MyRunAction::~MyRunAction(){}

  void  MyRunAction::BeginOfRunAction(const G4Run* run)
  {
    G4AnalysisManager*analysisManager=G4AnalysisManager::Instance();
	//   time_t timep;time (&timep);
  //  // char tmp[128];strftime(tmp,sizeof(tmp),"%H-%M.%S",localtime(&timep));
  //   G4String time = tmp;
    //   man->OpenFile(time+".root");


      std::ostringstream filename_oss;
filename_oss<<He3_Den;//密度
//filename_oss<<Lamda<<"Lamda";
      G4String str=filename_oss.str();
    analysisManager->OpenFile(str+".root");

if(PrintALL){
  std::fstream file;
  file.open("Particle_information.txt",std::ios::out|std::ios::app);
  file 
  << std::left 
  << std::setw(8) <<"EID"
  << std::setw(5) << "pID" 
  << std::setw(5) << "tID" 
  << std::setw(5) << "sID" 

  << std::setw(15) << "Name" 
  << std::setw(15) <<"PreVolumeName"
  << std::setw(15) << "PostVolumeName"
  << std::setw(20) << "ProcessName" 

  << std::setw(15) <<"PreKEnergy"
  << std::setw(15) << "PostKEnergy"
  << std::setw(15) << "StepEdep"


  // << std::setw(35) <<"PrePos"
  // << std::setw(35)<<"PostPos"
  << std::setw(15) <<"PrePosX"
  << std::setw(15) <<"PrePosY"
  << std::setw(15) <<"PrePosZ"
  << std::setw(15) <<"PostPosX"
  << std::setw(15) <<"PostPosY"
  << std::setw(15) <<"PostPosZ"
  << std::setw(15) << "StepLength"



//前后点动量
  // << std::setw(35)<< "PreMom "         
  // << std::setw(35)<< "PostMom "
  << std::setw(15)<< "PreMomX "         
  << std::setw(15) << "PreMomY "        
  << std::setw(15) << "PreMomZ "          
  << std::setw(15) << "PostMomX "         
  << std::setw(15) << "PostMomY"          
  << std::setw(15) << "PostMomZ "          


  << std::setw(15) <<"PreGTime"
  << std::setw(15) <<"PostGTime"
  << std::setw(15) <<"PreLTime"
  << std::setw(15) <<"PostLTime"


  << std::endl;
  file.close();
  
  }
  }
  void  MyRunAction:: EndOfRunAction(const G4Run*){

      G4AnalysisManager*analysisManager=G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile(false);






  }
