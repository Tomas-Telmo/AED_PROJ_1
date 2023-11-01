#ifndef PROJETO_AED_1_STUDENT_H
#define PROJETO_AED_1_STUDENT_H

#include <iostream>
#include <string>
#include <list>
#include "Class.h"


using namespace std;

class Student {
    string code;
    string name;
    list<pair<string,string>> UCandClasses;
    list<Class> schedule;

public:
    //Student();
    Student(string code_, string name_);
    Student(Student const &student);

    string getCode() const;
    string getName() const;
    list<pair<string,string>> getUCandClasses();
    list<Class> getSchedule();

    void setCode(string code_);
    void setName(string name_);

    void getNameByUC();

    void loadClassesperUCofStudentUsingNAME(); //turmas e ucs inscritas
    void loadClassesperUCofStudentUsingUP();    //turmas e ucs inscritas

    void loadSchedule();
    void printSchedule();

    string fromdoubletohour(double num);

    bool operator<(const Student& other)const;
};


#endif //PROJETO_AED_1_STUDENT_H
