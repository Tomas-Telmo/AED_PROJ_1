#ifndef PROJETO_AED_1_STUDENTCLASS_H
#define PROJETO_AED_1_STUDENTCLASS_H

#include "Student.h"
#include <vector>

class StudentClass{
    vector <Student> students;
    int capacity;
    int code;
    //possivelmente mais atributos se criamos a classe UC ou nao

public:
    StudentClass();
    int getCapacity();
    int getCode();
    void readFile(string filename);

};
#endif //PROJETO_AED_1_STUDENTCLASS_H
