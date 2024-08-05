#include "stepping.hh"


  MySteppingAction::MySteppingAction(MyEventAction*eventAction)
  {

   fEventAction=eventAction;


  }
   MySteppingAction::~MySteppingAction() {

    
 }
 void MySteppingAction::UserSteppingAction(const G4Step*step)
 {

  auto volumePre = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();//获取前点所在体积
  auto volumePost=step->GetPostStepPoint()->GetTouchableHandle()->GetVolume();//获取后点所在体积


//得到粒子名称，该step下的粒子的反应名称（后点）,前后点材料名称，体积名称
  G4String ParticleName,ProcessName,PreMatName,PostMatName,PostVolumeName,PreVolumeName;
const G4VProcess*StepProcess=step->GetPostStepPoint()->GetProcessDefinedStep();
 ProcessName=StepProcess->GetProcessName();
 ParticleName=step->GetTrack()->GetDynamicParticle()
                        ->GetParticleDefinition()->GetParticleName();


  if (volumePost == 0)
  {
   PreMatName = volumePre->GetLogicalVolume()->GetMaterial()->GetName();
   //得到前点物理触点所在体积的逻辑体内材料的名称
   PreVolumeName = volumePre->GetName();//得到前点触点所在体积的名称
   PostVolumeName = "OutOfWorld";//后点不存在
   
  }
  else
  {//得到前点逻辑体的材料名称
    PreMatName = volumePre->GetLogicalVolume()->GetMaterial()->GetName();  
     //得到前点所在体积名称
    PreVolumeName = volumePre->GetName();                 
    //得到后点逻辑体的材料名称
    PostMatName = volumePost->GetLogicalVolume()->GetMaterial()->GetName(); 
    PostVolumeName = volumePost->GetName();                              
  }


//得到各ID
G4int EventID,ParentID,TrackID,StepID;
  EventID=fEventAction->GetEventId();
  ParentID =step->GetTrack()->GetParentID();
  TrackID=step->GetTrack()->GetTrackID();
  StepID=step->GetTrack()->GetCurrentStepNumber();//得到当前步号   





   //得到step中的能量沉积和步长,做轨迹和能量分辨,保存并累计
    G4double StepEdep=step->GetTotalEnergyDeposit(); 
    G4double StepLength=step->GetStepLength();

    //step前后点动能、位置、动量
    G4double PreKineticEnergy=step->GetPreStepPoint()->GetKineticEnergy();
    G4double PostKineticEnergy=step->GetPostStepPoint()->GetKineticEnergy();
    G4ThreeVector PrePosition = step->GetPreStepPoint()->GetPosition();
    G4ThreeVector PostPosition =step->GetPostStepPoint()->GetPosition();
    G4ThreeVector PreMomentum=step->GetPreStepPoint()->GetMomentum();
    G4ThreeVector PostMomentum=step->GetPostStepPoint()->GetMomentum();

    //时间，全局时间
   // 
    G4double PreGlobalTime=step->GetPreStepPoint()->GetGlobalTime();
    G4double PostGlobalTime=step->GetPostStepPoint()->GetGlobalTime();
    G4double PreLocalTime=step->GetPreStepPoint()->GetLocalTime();
    G4double PostLocalTime=step->GetPostStepPoint()->GetLocalTime();

G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();



    analysisManager->FillNtupleIColumn(0, 0, EventID);
		analysisManager->FillNtupleIColumn(0, 1, ParentID);
		analysisManager->FillNtupleIColumn(0, 2, TrackID);
		analysisManager->FillNtupleIColumn(0, 3, StepID);

		analysisManager->FillNtupleSColumn(0, 4, ParticleName.c_str());
		analysisManager->FillNtupleSColumn(0, 5, PreVolumeName);
		analysisManager->FillNtupleSColumn(0, 6, PostVolumeName);
		analysisManager->FillNtupleSColumn(0, 7, ProcessName);

		analysisManager->FillNtupleDColumn(0, 8, PreKineticEnergy);
		analysisManager->FillNtupleDColumn(0, 9, PostKineticEnergy);
		analysisManager->FillNtupleDColumn(0, 10, StepEdep);

		analysisManager->FillNtupleDColumn(0, 11, PrePosition.getX());
		analysisManager->FillNtupleDColumn(0, 12, PrePosition.getY());
		analysisManager->FillNtupleDColumn(0, 13, PrePosition.getZ());
		analysisManager->FillNtupleDColumn(0, 14, PostPosition.getX());
		analysisManager->FillNtupleDColumn(0, 15, PostPosition.getY());
		analysisManager->FillNtupleDColumn(0, 16, PostPosition.getZ());
		analysisManager->FillNtupleDColumn(0, 17, StepLength);

		analysisManager->FillNtupleDColumn(0, 18, PreMomentum.getX());
		analysisManager->FillNtupleDColumn(0, 19, PreMomentum.getY());
		analysisManager->FillNtupleDColumn(0, 10, PreMomentum.getZ());
		analysisManager->FillNtupleDColumn(0, 21, PostMomentum.getX());
		analysisManager->FillNtupleDColumn(0, 22, PostMomentum.getY());
		analysisManager->FillNtupleDColumn(0, 23, PostMomentum.getZ());

	  analysisManager->FillNtupleDColumn(0, 24, PreGlobalTime);
		analysisManager->FillNtupleDColumn(0, 25, PostGlobalTime);
		analysisManager->FillNtupleDColumn(0, 26, PreLocalTime);     
		analysisManager->FillNtupleDColumn(0, 27, PostLocalTime);



	analysisManager->AddNtupleRow(0); 



G4int VolumeID,GroupID;
if(PreVolumeName=="DriftChamber"&&PostVolumeName=="DriftChamber")
{
      VolumeID=0;
      if(ParticleName=="Li7"||ParticleName=="alpha")
      {
        GroupID=0;
        fEventAction->Add(StepEdep,StepLength,VolumeID,GroupID);
      }

      if(ParticleName=="Li7")
      {
        GroupID=1;
        fEventAction->Add(StepEdep,StepLength,VolumeID,GroupID);

      }

      if(ParticleName=="alpha")
      {
        GroupID=2;
        fEventAction->Add(StepEdep,StepLength,VolumeID,GroupID);

      }

}
if (PreVolumeName == "Transfor" && PostVolumeName == "Transfor")
{
         VolumeID=1;
      if(ParticleName=="Li7"||ParticleName=="alpha")
      {
        GroupID=0;
        fEventAction->Add(StepEdep,StepLength,VolumeID,GroupID);
      }

      if(ParticleName=="Li7")
      {
        GroupID=1;
        fEventAction->Add(StepEdep,StepLength,VolumeID,GroupID);

      }

      if(ParticleName=="alpha")
      {
        GroupID=2;
        fEventAction->Add(StepEdep,StepLength,VolumeID,GroupID);

      }
}




if(PrintALL){


 std::fstream file;
  file.open("Particle_information.txt",std::ios::out|std::ios::app);
  file 
  << std::left 
  //得到各ID,粒子名称
  << std::setw(8) <<EventID
  << std::setw(5) << ParentID
  << std::setw(5) << TrackID
  << std::setw(5) << StepID

//前后点体积名称
  << std::setw(15) << ParticleName
  << std::setw(15) << PreVolumeName
  << std::setw(15) << PostVolumeName
  << std::setw(20) << ProcessName           //前点物理过程名称

//前后点动能
  << std::setw(15) <<PreKineticEnergy
  << std::setw(15) << PostKineticEnergy
  << std::setw(15) << StepEdep
//前后点位置
  // << std::setw(35)<<PrePosition
  // << std::setw(35) <<PostPosition
  << std::setw(15) <<PrePosition.getX()
  << std::setw(15) <<PrePosition.getY()
  << std::setw(15) <<PrePosition.getZ()
  << std::setw(15) <<PostPosition.getX()
  << std::setw(15) <<PostPosition.getY()
  << std::setw(15) <<PostPosition.getZ()
  << std::setw(15) << StepLength          //步长
//前后点动量
  // << std::setw(35) << PreMomentum         
  // << std::setw(35) << PostMomentum
  << std::setw(15) << PreMomentum.getX()         
  << std::setw(15) << PreMomentum.getY()         
  << std::setw(15) << PreMomentum.getZ()          
  << std::setw(15) << PostMomentum.getX()         
  << std::setw(15) << PostMomentum.getY()          
  << std::setw(15) << PostMomentum.getZ()         
  
  << std::setw(15) <<PreGlobalTime
  << std::setw(15) <<PostGlobalTime
  << std::setw(15) <<PreLocalTime
  << std::setw(15) <<PostLocalTime


  << std::endl;


}
}

