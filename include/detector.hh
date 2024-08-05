#ifndef DETECTOR_HH
#define DETECTOR_HH
#include "G4VSensitiveDetector.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicsOrderedFreeVector.hh"//
#include "G4PVReplica.hh"


#include "constants.hh"
class MySensitiveDetector:public G4VSensitiveDetector
{

public:
        MySensitiveDetector(G4String);
        ~MySensitiveDetector();
private:
virtual G4bool ProcessHits(G4Step *,G4TouchableHistory*);


private:
  G4String Steptime;

G4VPhysicalVolume *volumePre = nullptr;
G4VPhysicalVolume *volumePost = nullptr;
// get volume of the current step  得到当前step的volume
// auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
//复制体
 G4StepPoint* preStepPoint = nullptr;//前点
 G4VPhysicalVolume* currentVolume = nullptr;
 G4PVReplica* replicaVolume= nullptr ;//复制体
//  G4LogicalVolume* motherVolume,*daughterVolume = nullptr;//获取母体逻辑体
//  G4VPhysicalVolume* daughterVolume,* motherVolume = nullptr;
 G4String motherVolumeName,daughterVolumeName;//逻辑体名称   

//得到partic 与对应EventId 
G4Track *track = nullptr;
G4String particleName;
G4int eventID ;

//得到三维坐标

 G4ThreeVector PositionPre ;          //step前点坐标
 G4ThreeVector PositionPost;         //step后点坐标
 G4ThreeVector PositionTrack ;        //track坐标  （保存粒子完成一个step之后的最终状态的信息）
 G4double kinEnergy,TotalEnergy ;     //track的动能
 G4ThreeVector momentumDir,momentumStartDir; //动量
 
  G4double edep;
  G4String PreMaterialName, PostMaterialName,PreVolumeName,PostVolumeName;
  G4String PostPVName,PrePVName;
 G4String    ScatterAl,ScatterB4C,Scattergas;




};




#endif