#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
        EventEdep.resize(3, std::vector<G4double>(3, 0.0));
        EventLength.resize(3, std::vector<G4double>(3, 0.0));

} 
MyEventAction::~MyEventAction(){}
void MyEventAction::BeginOfEventAction(const G4Event*event)
{  
eventID=event->GetEventID();
for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                EventEdep[i][j] = 0.0;
                EventLength[i][j] = 0.0;
            }

}



}
void MyEventAction::EndOfEventAction(const G4Event*)
{
  
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    G4int numberID=0,RowsID=0,ColsID=0;

for(int jj=0;jj<2;jj++)
{
    for (int ii=0;ii<3;ii++)
    {
    analysisManager->FillNtupleDColumn(1, numberID, EventEdep[jj][ii]);numberID++;
    analysisManager->FillNtupleDColumn(1, numberID, EventLength[jj][ii]);numberID++;
    }

}
        analysisManager->AddNtupleRow(1);   

// //D层
//     //双粒子
//             analysisManager->FillNtupleDColumn(1, numberID, EventEdep[RowsID][ColsID]);numberID++;
//             analysisManager->FillNtupleDColumn(1, numberID, EventLength[RowsID][ColsID]);numberID++;
//     //Li7
//             analysisManager->FillNtupleDColumn(1, numberID, EventEdep[RowsID][ColsID]);numberID++;
//             analysisManager->FillNtupleDColumn(1, numberID, EventLength[RowsID][ColsID]);numberID++;
//     //alpha
//             analysisManager->FillNtupleDColumn(1, numberID, EventEdep[RowsID][ColsID]);numberID++;
//             analysisManager->FillNtupleDColumn(1, numberID, EventLength[RowsID][ColsID]);numberID++;

// //T层       
//     //双粒子
//             analysisManager->FillNtupleDColumn(1, numberID, EventEdep[RowsID][ColsID]);numberID++;
//             analysisManager->FillNtupleDColumn(1, numberID, EventLength[RowsID][ColsID]);numberID++;
//     //Li7

//             analysisManager->FillNtupleDColumn(1, numberID, EventEdep[RowsID][ColsID]);numberID++;
//             analysisManager->FillNtupleDColumn(1, numberID, EventLength[RowsID][ColsID]);numberID++;
//     //alpha

//             analysisManager->FillNtupleDColumn(1, numberID, EventEdep[RowsID][ColsID]);numberID++;
//             analysisManager->FillNtupleDColumn(1, numberID, EventLength[RowsID][ColsID]);numberID++;

//       


    analysisManager->FillNtupleDColumn(2,0,Lamda);
    analysisManager->FillNtupleDColumn(2,1,GunEnergy);
    analysisManager->FillNtupleDColumn(2,2,B10_Abundance);
    analysisManager->FillNtupleDColumn(2,3,repeatUnits );
    analysisManager->FillNtupleDColumn(2,4,driftChamberZ);
    analysisManager->FillNtupleDColumn(2,5,transforZ);
    analysisManager->FillNtupleDColumn(2,6,supportPlateZ);
    analysisManager->FillNtupleDColumn(2,7,rotate );
            analysisManager->AddNtupleRow(2); 

            
}
