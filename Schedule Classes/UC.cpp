#include "UC.h"
#include <sstream>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

UC::UC(){}

UC::UC(int UCCode_){
    this->UCCode=UCCode_;
}

int UC::getNumberOfClasses() {
    return this->numberOfClasses;
}

string UC::getUCCode() {
    return this->UCCode;
}

void UC::readUCFile(const string &filename) {
    ifstream sfile;

    if (!sfile.is_open()) {
        string line;
        while (getline(sfile, line)) {
            set<string> createdUCs;
            istringstream iss(line);
            string uccode;
            string classcode;
            iss >> uccode >> classcode;
            if(createdUCs.find(uccode)!=createdUCs.end() ){
                createdUCs.insert(uccode);
            }
            sfile.close();
        }
    } else {
        cerr << "Error: Unable to open the file " << filename << endl;
    }
}