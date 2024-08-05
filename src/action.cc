  #include "action.hh"
  
  
    MyActionInitialization::MyActionInitialization()
    {}
 MyActionInitialization::~MyActionInitialization(){}
 void MyActionInitialization::BuildForMaster() const{
  

MyRunAction*runAction=new MyRunAction();
SetUserAction(runAction);


 }
   
  void MyActionInitialization::Build() const {

  
    MyPrimaryGenerator*generator=new MyPrimaryGenerator();
    SetUserAction(generator);
    MyRunAction*runAction=new MyRunAction();
    SetUserAction(runAction);

     MyEventAction*eventActon=new MyEventAction(runAction);
     SetUserAction(eventActon);
     MySteppingAction*steppingActon=new MySteppingAction(eventActon);
     SetUserAction(steppingActon);
    
  }