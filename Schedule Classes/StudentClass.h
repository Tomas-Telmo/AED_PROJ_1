#ifndef PROJETO_AED_1_STUDENTCLASS_H
#define PROJETO_AED_1_STUDENTCLASS_H

#include "Student.h"
#include <set>
#include <fstream>
#include <iostream>

class StudentClass{


    set<Student> students;
    int capacity;
    string code;
    //possivelmente mais atributos se criamos a classe UC ou nao

public:
    StudentClass();
    StudentClass(set<Student> students_, int capacity_, int code_);

    set <Student> getStudents();

    string getCode();
    int getCapacity();

    //bool operator<(const Student& other) const; ns se é para dar overload aqui ou no student, fiz no student
    void readFile(ifstream &filename);

    void readFile(const string &filename);
};
#endif //PROJETO_AED_1_STUDENTCLASS_H
