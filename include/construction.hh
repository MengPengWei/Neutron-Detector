#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include  "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4GenericMessenger.hh"
#include "G4PVReplica.hh"
#include "G4VisAttributes.hh"
 
#include "constants.hh"
#include "detector.hh"
class MyDetectorConstruction:public G4VUserDetectorConstruction

{

public:
  MyDetectorConstruction();
  ~MyDetectorConstruction();

  virtual G4VPhysicalVolume*Construct();
  G4LogicalVolume*GetScoringVolume() const{return fScoringVolume;}

private:
//solidVolume
G4Box*solidWorld,*solidWindows,
*solidWindowsBehind,*solidSupportPlate,*solidTransfor,*solidDriftChamber,
*solidScatter,
*solidRadiator,*solidDetector,*solidScintillator;
//logicalVolume
G4LogicalVolume*logicWorld,*logicWindows,
*logicWindowsBehind,*logicSupportPlate,*logicTransfor,*logicDriftChamber,
*logicScatter,
*logicRadiator,*logicDetector,*logicScintillator;
//VPhysicalVolume
G4VPhysicalVolume*physWorld,*physWindows,
*physWindowsBehind,*physSupportPlate,*physTransfor,*physDriftChamber,
*physScatter,
*physRadiator,*physDetector,*physScintillator;

G4Box*solidHe3;
G4LogicalVolume*logicHe3;
G4VPhysicalVolume*physHe3;
G4LogicalVolume *fScoringVolume;//标定
G4LogicalVolume *Room_LV;//复制体
G4GenericMessenger*fMessenger;//界面命令模块
//获取材料
 G4Material*Galactic,*Al,*B4C,*CO2,*ArCO2_90_10;//
 G4Element*C,*O,*Ar,*B; 
 //各结构材料

   G4Material* WorldMat,* WindowMat, *WindowsBehindMat,*SupportPlateMat,
   *TransforMat,*DriftChamberMat;

   G4Material*He3GasMat;
    
//各结构所在位置

     G4Material* default_Material,*MixGas_Material,*B4C_Material,*Al_Material;

private:
virtual void ConstructSDandField();
void DefineMaterial();

void ConstructWindows();//窗结构
void ConstructWindowsBehind();//窗后薄层结构
void ConstructMultilayer();
void ConstructSupportPlate();//支撑板结构
void ConstructTransfor();//转换层结构
void ConstructDriftChamber();//漂移室结构
void LND_He3();   //LND He3监测器

};

#endif