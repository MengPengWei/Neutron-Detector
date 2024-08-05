#ifndef TEMPTREE_HH
#define TEMPTREE_HH

#include <TTree.h>

class temptree {
public:
    unsigned int  nLines;
    unsigned int EventID, ParentID, TrackID, StepID;
    static constexpr int Max=256;

    Char_t ParticleName[Max];   // Assuming particle name can be up to 255 characters + null terminator
    Char_t PreVolumeName[Max];  // Assuming volume names can be up to 255 characters + null terminator
    Char_t PostVolumeName[Max]; // Assuming volume names can be up to 255 characters + null terminator
    Char_t ProcessName[Max];    // Assuming process name can be up to 255 characters + null terminator

    // std::string ParticleName;
    // std::string PreVolumeName;
    // std::string PostVolumeName;
    // std::string ProcessName;


    Double_t PreKineticEnergy, PostKineticEnergy, StepEdep;
    Double_t PrePositionX, PrePositionY, PrePositionZ;
    Double_t PostPositionX, PostPositionY, PostPositionZ, StepLength;
    Double_t PreMomentumX, PreMomentumY, PreMomentumZ;
    Double_t PostMomentumX, PostMomentumY, PostMomentumZ;
    Double_t PreGlobalTime, PostGlobalTime, PreLocalTime, PostLocalTime;

    // std::vector<Char_t> ParticleName;
    // std::vector<Char_t> PreVolumeName;
    // std::vector<Char_t> PostVolumeName;
    // std::vector<Char_t> ProcessName;

    // std::vector<Double_t> PreKineticEnergy;
    // std::vector<Double_t> PostKineticEnergy;
    // std::vector<Double_t> StepEdep;
    // std::vector<Double_t> PrePositionX;
    // std::vector<Double_t> PrePositionY;
    // std::vector<Double_t> PrePositionZ;
    // std::vector<Double_t> PostPositionX;
    // std::vector<Double_t> PostPositionY;
    // std::vector<Double_t> PostPositionZ;
    // std::vector<Double_t> StepLength;
    // std::vector<Double_t> PreMomentumX;
    // std::vector<Double_t> PreMomentumY;
    // std::vector<Double_t> PreMomentumZ;
    // std::vector<Double_t> PostMomentumX;
    // std::vector<Double_t> PostMomentumY;
    // std::vector<Double_t> PostMomentumZ;
    // std::vector<Double_t> PreGlobalTime;
    // std::vector<Double_t> PostGlobalTime;
    // std::vector<Double_t> PreLocalTime;
    // std::vector<Double_t> PostLocalTime;

    void linktree1(TTree *t1) {



        t1->SetBranchAddress("EventID", &EventID);
        t1->SetBranchAddress("ParentID", &ParentID);
        t1->SetBranchAddress("TrackID", &TrackID);
        t1->SetBranchAddress("StepID", &StepID);

        t1->SetBranchAddress("ParticleName", &ParticleName);
        t1->SetBranchAddress("PreVolumeName", &PreVolumeName);
        t1->SetBranchAddress("PostVolumeName", &PostVolumeName);
        t1->SetBranchAddress("ProcessName", &ProcessName);

        t1->SetBranchAddress("PreKineticEnergy", &PreKineticEnergy);
        t1->SetBranchAddress("PostKineticEnergy", &PostKineticEnergy);
        t1->SetBranchAddress("StepEdep", &StepEdep);

        t1->SetBranchAddress("PrePositionX", &PrePositionX);
        t1->SetBranchAddress("PrePositionY", &PrePositionY);
        t1->SetBranchAddress("PrePositionZ", &PrePositionZ);
        t1->SetBranchAddress("PostPositionX", &PostPositionX);
        t1->SetBranchAddress("PostPositionY", &PostPositionY);
        t1->SetBranchAddress("PostPositionZ", &PostPositionZ);
        t1->SetBranchAddress("StepLength", &StepLength);

        t1->SetBranchAddress("PreMomentumX", &PreMomentumX);
        t1->SetBranchAddress("PreMomentumY", &PreMomentumY);
        t1->SetBranchAddress("PreMomentumZ", &PreMomentumZ);
        t1->SetBranchAddress("PostMomentumX", &PostMomentumX);
        t1->SetBranchAddress("PostMomentumY", &PostMomentumY);
        t1->SetBranchAddress("PostMomentumZ", &PostMomentumZ);


        t1->SetBranchAddress("PreGlobalTime", &PreGlobalTime);
        t1->SetBranchAddress("PostGlobalTime", &PostGlobalTime);
        t1->SetBranchAddress("PreLocalTime", &PreLocalTime);
        t1->SetBranchAddress("PostLocalTime", &PostLocalTime);



        
    }
    
    
    
    
    
    void linktree2(TTree *t2)
    {

        double All_EventEdep_D, All_EventLength_D, All_EventEdep_T, All_EventLength_T;

        double Li7_EventEdep_D, Li7_EventLength_D, Li7_EventEdep_T, Li7_EventLength_T;

        double alpha_EventEdep_D, alpha_EventLength_D, alpha_EventEdep_T, alpha_EventLength_T;

        // Connect branches to variables
        t2->SetBranchAddress("All_EventEdep_D", &All_EventEdep_D);
        t2->SetBranchAddress("All_EventLength_D", &All_EventLength_D);
        t2->SetBranchAddress("Li7_EventEdep_D", &Li7_EventEdep_D);
        t2->SetBranchAddress("Li7_EventLength_D", &Li7_EventLength_D);
        t2->SetBranchAddress("alpha_EventEdep_D", &alpha_EventEdep_D);
        t2->SetBranchAddress("alpha_EventLength_D", &alpha_EventLength_D);

        t2->SetBranchAddress("All_EventEdep_T", &All_EventEdep_T);
        t2->SetBranchAddress("All_EventLength_T", &All_EventLength_T);
        t2->SetBranchAddress("Li7_EventEdep_T", &Li7_EventEdep_T);
        t2->SetBranchAddress("Li7_EventLength_T", &Li7_EventLength_T);
        t2->SetBranchAddress("alpha_EventEdep_T", &alpha_EventEdep_T);
        t2->SetBranchAddress("alpha_EventLength_T", &alpha_EventLength_T);



    }

    
    void linktree3(TTree *D1)
    {

        double Neutron_Wavelength, Neutron_Energy, B10_percent, Lay,DriftChamber,Transfer,SupportPlate,Rotate;

    
        D1->SetBranchAddress("Neutron_Wavelength", &Neutron_Wavelength);
        D1->SetBranchAddress("Neutron_Energy", &Neutron_Energy);
        D1->SetBranchAddress("B10_percent", &B10_percent);
        D1->SetBranchAddress("Lay", &Lay);
        D1->SetBranchAddress("DriftChamber", &DriftChamber);
        D1->SetBranchAddress("Transfer", &Transfer);
        D1->SetBranchAddress("SupportPlate", &SupportPlate);
        D1->SetBranchAddress("Rotate", &Rotate);


    }


};

#endif // TEMPTREE_HH
