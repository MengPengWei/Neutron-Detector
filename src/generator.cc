  #include "generator.hh"
  
  
    MyPrimaryGenerator::MyPrimaryGenerator()
    {
        fParticleGun=new G4ParticleGun(1);
       particleDefinition=G4ParticleTable::GetParticleTable()->FindParticle("neutron");
       fParticleGun->SetParticleDefinition(particleDefinition);
       fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1)); //changed by shell
       fParticleGun->SetParticleEnergy(GunEnergy*eV); 
      //fParticleGun->SetParticleLamda
      G4cout<<"GunEnergy"<<GunEnergy*eV<<G4endl;
      auto GunPointDirY=GunYRange*sin(rotate*deg)*standardSize/2;
       fParticleGun->SetParticlePosition(G4ThreeVector( 0 ,GunPointDirY ,GunPointDirZ) ); //发射位置
  

    }
 MyPrimaryGenerator::~MyPrimaryGenerator(){delete fParticleGun;}

 void MyPrimaryGenerator::GeneratePrimaries(G4Event*anEvet){


    fParticleGun->GeneratePrimaryVertex(anEvet);
    
    

 }
  