#ifndef STEPPING_HH
#define STEPPING_HH
#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.hh"
#include "event.hh"
#include "run.hh"
class MySteppingAction: public G4UserSteppingAction
{
   public:
   MySteppingAction(MyEventAction*eventAction);
   ~MySteppingAction();
virtual void UserSteppingAction(const G4Step*);

private:

  MyEventAction*fEventAction;
  const MyDetectorConstruction*fdetectorConstruction;
  // G4double StepEdep;
  // G4String particleName,PrevolumeName,PreMatName;
};


#endif