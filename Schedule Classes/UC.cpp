#include "UC.h"
#include <fstream>

void UC(){}

int UC::getNumberOfClasses() {
    return this->numberOfClasses;
}

string UC::getUCCode() {
    return this->UCCode;
}

void UC::readUCFile(const string &filename) {
    ifstream sfile;

    if(!filename.is_open()){
        cerr << "Error: Unable to open the file " << filename << endl;
        return;
    }
    string line;
    while (getline(sfile,line)){
        string uccode;
        string classcode;
        line<<uccode<<line;
        UC newUC(U)
    }
}