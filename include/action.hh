#ifndef ACTION_HH
#define ACTION_HH
#include "G4VUserActionInitialization.hh"
// #include "G4ParticleGun.hh"
// #include "G4SystemOfUnits.hh"
// #include "G4ParticleTable.hh"
#include "generator.hh"
#include "run.hh"
#include "event.hh"
#include "stepping.hh"



class MyActionInitialization:public G4VUserActionInitialization
{
    public:
    MyActionInitialization();
    ~MyActionInitialization();
  
    virtual void BuildForMaster() const;
    virtual void Build() const;
 
   private:
G4ParticleGun* fparticleGun;


};


#endif