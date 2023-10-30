#ifndef PROJETO_AED_1_UC_H
#define PROJETO_AED_1_UC_H

#include <iostream>
#include <string>
#include <set>
#include "StudentClass.h"

using namespace std;

class UC{
    string UcCode;
    set<StudentClass> UcClasses;

public:
    UC();
    UC(string UcCode_, set<StudentClass> UcClasses_) ;
    UC(UC const &uc);

    string getUCCode();
    set<StudentClass> getUcClasses();
    int getNumberOfClasses();

    void setUcCode(string uccode);
    void setUcClasses(set<StudentClass> UcClasses_);

    void addStudentClass(StudentClass Class);

    void read_ClassesPerUCFile(ifstream &filename);
    void read_StudentsClassesFile(ifstream &filename);

    bool operator<(const UC& other) const;
};

#endif //PROJETO_AED_1_UC_H
