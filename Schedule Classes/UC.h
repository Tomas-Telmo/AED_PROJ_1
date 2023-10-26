#ifndef PROJETO_AED_1_UC_H
#define PROJETO_AED_1_UC_H

#include <iostream>
#include <string>
#include <set>
#include "StudentClass.h"

using namespace std;

class UC{
    int numberOfClasses;
    string UCCode;
    set <StudentClass> UCClasses;

public:
    UC();
    UC(int UCCode_);
    int getNumberOfClasses();
    string getUCCode();
    void readUCFile(const string &filename);

};

#endif //PROJETO_AED_1_UC_H
