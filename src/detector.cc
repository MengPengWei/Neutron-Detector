    #include "detector.hh"

       MySensitiveDetector:: MySensitiveDetector(G4String name):G4VSensitiveDetector(name)
       {

       }
       MySensitiveDetector::  ~MySensitiveDetector(){
        
       }

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep,G4TouchableHistory*ROhist)
 {
//      G4int evt=G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
//      G4AnalysisManager*analysisManager=G4AnalysisManager::Instance();
//      track=aStep->GetTrack();//得到track  
//      particleName = track->GetDynamicParticle()->GetParticleDefinition()->GetParticleName();
//      if(IsWindowsBehindScatter&&particleName=="neutron")
//      {

//           track=aStep->GetTrack();//得到track  
//           momentumDir=track->GetMomentumDirection();
//           PositionTrack=track->GetPosition();
//     analysisManager->FillH2(0,PositionTrack[0],PositionTrack[1]);
//     if(momentumDir[0]!=0||momentumDir[1]!=0)
//     {
//          analysisManager->FillH2(1,PositionTrack[0],PositionTrack[1]);
//     }    
   

//      }

     




}
