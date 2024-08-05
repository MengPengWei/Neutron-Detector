#ifndef EVENT_HH
#define EVENT_HH
#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "G4AnalysisManager.hh"
#include "run.hh"

#include "vector"
class MyEventAction: public G4UserEventAction
{
   public:
   MyEventAction(MyRunAction*);
   ~MyEventAction();
virtual void BeginOfEventAction(const G4Event*);
virtual void EndOfEventAction(const G4Event*);

void Add(G4double StepEdep,G4double StepLength,G4int i,G4int j){EventEdep[i][j]+=StepEdep;EventLength[i][j]+=StepLength;}

      G4int GetEventId(){return eventID;}
private:
   G4int eventID;

      std::vector<std::vector<G4double>> EventEdep;
      std::vector<std::vector<G4double>> EventLength;


};


#endif