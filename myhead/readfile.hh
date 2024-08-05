
#ifndef READFILE_HH
#define READFILE_HH
void readfile(std::vector<std::string> &strArray){

    //string filename="/home/mpw/MyProject/A1detector/Filename/"+strArray.c_str()+"txt";
    string filename="/home/mpw/MyProject/A1detector/Filename/filename.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    std::string str;
    while (std::getline(file, str)) {
        strArray.push_back(str);
    }

    int num_files = strArray.size();
}
    #endif 