#include "construction.hh"

  MyDetectorConstruction:: MyDetectorConstruction()
  {




  }
  MyDetectorConstruction::~MyDetectorConstruction()
  { }
  void MyDetectorConstruction::DefineMaterial()//定义材料
  {

   G4NistManager*nistManager=G4NistManager::Instance();
  //世界真空
  Galactic=nistManager->FindOrBuildMaterial("G4_Galactic");
  new G4Material("Galactic", 1., 1.01 * g / mole, 1.e-25*g/cm3,
                 kStateGas, 2.73 * kelvin, 3.e-18 * pascal);

   //Al
  Al= nistManager->FindOrBuildMaterial("G4_Al");//Al合金

   //混合气体
  C = nistManager->FindOrBuildElement("C");
  O = nistManager->FindOrBuildElement("O");
  Ar = nistManager->FindOrBuildElement("Ar");
      // CO2
  CO2 = new G4Material("CO2", 1.977 *mg / cm3, 2);
  CO2->AddElement(C, 1);
  CO2->AddElement(O, 2);
  ArCO2_90_10 = new G4Material("ArCO2_90_10", 1.8014866 *mg /cm3,  2);
  ArCO2_90_10->AddElement(Ar, 0.90);
  ArCO2_90_10->AddMaterial(CO2, 0.10);

   //碳化硼
   G4Isotope*B10=new G4Isotope("B10",5,10,10.*g/mole);    
   G4Isotope*B11=new G4Isotope("B11",5,11,11.*g/mole);
  B=new G4Element("enrich Boron","B",2);
  B->AddIsotope(B10,B10_Abundance*perCent);
  B->AddIsotope(B11,(100-B10_Abundance)*perCent);
  //G4cout<<"96%B4C"<<G4endl;
  //硼膜
  B4C=new G4Material("B4C",2.52*g/cm3,2);//2.52
  B4C->AddElement(B,4);
  B4C->AddElement(C,1);


  //He3
    G4Isotope* He3 = new G4Isotope("He3", 2, 3, 3.016*g/mole);
    G4Element* elHe3 = new G4Element("Helium-3", "He3", 1);
    elHe3->AddIsotope(He3, 1.0);
    //密度    3.016*g/mole  / 22.4*dm3/mol      标准密度0.134643      0.1torr      0.134643/7600
    He3GasMat = new G4Material("Helium-3 Gas", He3_Den, 1);       //1torr=1/760   1.77e-5
    He3GasMat->AddElement(elHe3, 1);

    G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  //获取定义好的物质
  //auto default_Material,MixGas_Material,B4C_Material,Al_Material;
    default_Material = G4Material::GetMaterial("Galactic");
   MixGas_Material = G4Material::GetMaterial("ArCO2_90_10");
   B4C_Material = G4Material::GetMaterial("B4C");
   Al_Material=G4Material::GetMaterial("G4_Al");







   //设置各个层的物质成分

      WorldMat=default_Material;
      WindowMat=Al_Material;
      WindowsBehindMat=MixGas_Material;
      SupportPlateMat=Al_Material;
      TransforMat=B4C_Material;
      DriftChamberMat=MixGas_Material;
  if (!default_Material || !MixGas_Material||!B4C_Material||!Al_Material||!He3GasMat)
  {
    G4ExceptionDescription msg;
    msg << "Cannot retrieve materials already defined."; 
    G4Exception("B4DetectorConstruction::DefineVolumes()",
      "MyCode0001", FatalException, msg);


  }
  }
void MyDetectorConstruction:: ConstructWindows()//窗结构
{

  auto windowsSize=standardSize;
 
    solidWindows
    = new G4Box("windows",           // its name
               windowsSize/2, windowsSize/2, windowsZ/2); // its size
                         
   logicWindows
    = new G4LogicalVolume(
                 solidWindows,           // its solid
                 WindowMat,          // its material
                 "windows");         // its name
                                   
   physWindows
    = new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0.,0.,windowPosition),  // at (0,0,0)
                 logicWindows,          // its logical volume                         
                 "windows",        // its name
                 logicWorld,                // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 true);  // checking overlaps 

  

}
void MyDetectorConstruction::ConstructWindowsBehind()//窗后薄层结构
{
   
    auto windowsBehindSize=standardSize;
      auto windowsBehindPosition=windowPosition-(windowsZ+windowsBehindZ)/2;

     solidScatter=
              new G4Box("Scatter",windowsBehindSize/2,windowsBehindSize/2,windowsBehindZ/2);
      logicScatter=
              new G4LogicalVolume(solidScatter,WindowsBehindMat,"Scatter");
       physScatter=
              new G4PVPlacement(0,G4ThreeVector(0,0,windowsBehindPosition),logicScatter,
                   "Scatter",logicWorld,false,0,true);
       



}
void MyDetectorConstruction::ConstructSupportPlate()//支撑板结构
{

  
  auto SupportPlateXY=standardSize;
  auto SupportPlateLay=-(transforZ+driftChamberZ)/2-supportPlateZ;

  solidSupportPlate=new G4Box("SupportPlate",standardSize/2,standardSize/2,supportPlateZ/2); 

          logicSupportPlate=new G4LogicalVolume(
        solidSupportPlate,
        SupportPlateMat,
        "SupportPlate"
            );
            for(int i=0;i<2;i++)
            {
   G4double layerPosition = (i % 2 == 0) ? SupportPlateLay : -SupportPlateLay;
      new G4PVPlacement(
      0,                                                 // no rotation
      G4ThreeVector(0., 0., layerPosition) ,
      logicSupportPlate,                                           // its logical volume
      "SupportPlate",                                            // its name
      Room_LV,                                           // its mother  volume
      false,                                             // no boolean operation
      0,                                                 // copy number
      true);   



            }



}
void MyDetectorConstruction::ConstructTransfor()//转换层结构
{

              auto TransforXY=standardSize;
              auto TransforLay=(transforZ+driftChamberZ)/2;
   solidTransfor= new G4Box("Transfor",                                              // its name
                             TransforXY / 2, TransforXY / 2, transforZ / 2 ); // its size
 logicTransfor = new G4LogicalVolume(
      solidTransfor,        // its solid
      TransforMat,         // its material
      "Transfor");          // its name

  //physTransfor =new G4PVPlacement(
                for(int i=0;i<2;i++)
          {
            G4double layerPosition = (i % 2 == 0) ? TransforLay : -TransforLay;
      new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0,0,layerPosition),  // at (0,0,0)
                 logicTransfor,          // its logical volume                         
                 "Transfor",          // its name
                 Room_LV,                // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 true);  // checking overlaps 
                
          }
}
void MyDetectorConstruction::ConstructDriftChamber()//漂移室结构
{
  auto DriftChamberXY=standardSize;
 // auto DriftChamberLay=(supportPlateZ+transforZ)/2;
  solidDriftChamber = new G4Box("DriftChamber",                                              // its name
                             standardSize / 2, standardSize / 2, driftChamberZ / 2 ); // its size
 logicDriftChamber = new G4LogicalVolume(
      solidDriftChamber,        // its solid
      DriftChamberMat,         // its material
      "DriftChamber");          // its name

 physDriftChamber = new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0,0,0),  // at (0,0,0)
                 logicDriftChamber,          // its logical volume                         
                 "DriftChamber",          // its name
                 Room_LV,                // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 true);  // checking overlaps 
fScoringVolume=logicDriftChamber;

}
void MyDetectorConstruction::ConstructMultilayer()//多层结构
{


    auto RoomXY=standardSize;   
    auto RoomZ=(supportPlateZ+transforZ+driftChamberZ)*repeatUnits; 
    //auto RoomLay=RoomZ/2-driftChamberZ;//位于第一层的B4C上层
    auto RoomLay=0;

      G4Rotate3D RoomroX(-(90-rotate)*deg,G4ThreeVector(1,0,0));//旋转
      G4Translate3D RoomScint(G4ThreeVector(0.,0.,-RoomLay));//平移量
      G4Transform3D RoomDet=RoomroX*RoomScint;
    auto Room_SV 
    = new G4Box("Room",           // its name
                 RoomXY/2, RoomXY/2, RoomZ/2); // its size

      Room_LV
    = new G4LogicalVolume(
                 Room_SV,           // its solid
                 DriftChamberMat,          // its material
                 "Room");         // its name

    auto Room_PV
    = new G4PVPlacement(
                 RoomDet,                //  rotation
                 //G4ThreeVector(0.,0.,RoomLay),  // at (0,0,0)
                 Room_LV,          // its logical volume                         
                 "Room",        // its name
                 logicWorld,                // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 true);  // checking overlaps 



ConstructSupportPlate();//支撑层
ConstructTransfor();//转换层
ConstructDriftChamber();//漂移层


}

void MyDetectorConstruction::LND_He3()//    LND监测器
{

solidHe3=new G4Box("LND_He3",           // its name
                 105*mm/2, 105*mm/2, 19.1*mm/2);



logicHe3=new G4LogicalVolume(solidHe3,He3GasMat,"LND_He3");


physHe3=new G4PVPlacement(
                 0,                //  rotation
                 G4ThreeVector(0.,0.,0),  // at (0,0,0)
                 logicHe3,          // its logical volume                         
                 "LND_He3",        // its name
                 logicWorld,                // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 true);  // checking overlaps 





}



  G4VPhysicalVolume*MyDetectorConstruction::Construct()//主结构
  {
      DefineMaterial();


         solidWorld=new G4Box("World",worldSize/2,worldSize/2,worldSize/2);
      logicWorld=new G4LogicalVolume(solidWorld,WorldMat,"World");

       physWorld=
       new G4PVPlacement(0,
                          G4ThreeVector(0,0,0),
                          logicWorld,
                          "World",
                          0,
                          false,//no boolean operation
                          0,
                          true
       );
       if(IsLND)
      LND_He3();
       if(IsWindows)
       ConstructWindows();
        if(IsWindowsBehind)
       ConstructWindowsBehind();
     if(IsMultilayer)
       ConstructMultilayer();
       return physWorld;

  }
 void MyDetectorConstruction::ConstructSDandField()
 {
   MySensitiveDetector*sensDet=new MySensitiveDetector("SensitiveDetector");
      
   
   // logicDriftChamber->SetSensitiveDetector(sensDet);
    

 }
