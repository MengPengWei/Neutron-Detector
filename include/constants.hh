
#ifndef CONSTANTS_HH
#define CONSTANTS_HH 

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include <iostream>


constexpr G4double worldSize=80*cm;//世界尺寸50*cm
constexpr G4double repeatUnits = 1;
constexpr G4double standardSize = 20*cm;            //标准尺寸20cm        （长宽）

//厚度
constexpr G4double windowsZ=1.2*mm;//入射窗厚度
constexpr G4double windowsBehindZ=0.1*um;//窗后统计单元厚度

constexpr G4double transforZ=0.1*um;//转换层厚度
constexpr G4double supportPlateZ=0.1*mm;//基板厚
constexpr G4double driftChamberZ=8*mm;   //漂移室厚度   （混合气体） 
constexpr G4double rotate = 90;
constexpr G4double normalY=cos(rotate*deg);//法线方向的y分量
constexpr G4double normalZ=sin(rotate*deg);//法线方向的x分量
constexpr G4double B10_Abundance =19.8;//B10含量;
    
constexpr G4double windowPosition=3*cm;                             //入射窗位置
constexpr G4double GunPointDirZ=13*cm;                              //发射位置在入射窗前
constexpr G4double GunYRange=0;//[-1,1],-1为底边沿， 1为顶边沿,0为中心

constexpr G4double Lamda =2.0;//波长 单位A
constexpr G4double GunEnergy=(0.286/Lamda)*(0.286/Lamda);//能量
//结构开关  false
constexpr G4bool IsWindows=true,IsWindowsBehind=true,IsMultilayer=true,IsLND=false;
//打印信息开关
constexpr G4bool PrintALL=false;


constexpr G4double He3_Den=10*1.77e-5*mg/cm3;





#endif
