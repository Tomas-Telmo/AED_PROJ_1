#ifndef PROJETO_AED_1_UC_H
#define PROJETO_AED_1_UC_H

#include <iostream>
#include <string>
#include <set>
#include <list>
#include "StudentClass.h"

using namespace std;

class UC{
    string UcCode;
    set<StudentClass> studentclassSet;
    list<StudentClass> studentclassList;
    int MAX_STUDENTS = 28;


public:
    //UC();
    UC(string UcCode_, set<StudentClass> class_set, list<StudentClass> class_list);
    UC(UC const &uc);

    string getUCCode() const;
    set<StudentClass> getStudentClassSet() const;
    list<StudentClass> getStudentClassList()const;
    int getNumberOfClasses() const;

    void setUcCode(string uccode);
    void setUcClasses(set<StudentClass> UcClasses_);

    void addStudentClass(StudentClass Class);

    void readClassesPerUCFile();
    void readStudentsClassesFile();
    void Make();
    bool operator<(const UC& other) const;

    list<StudentClass> freeStudentClasses();

};

#endif //PROJETO_AED_1_UC_H
