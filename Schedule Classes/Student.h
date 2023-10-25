//
// Created by antero on 25-10-2023.
//

#ifndef PROJETO_AED_1_STUDENT_H
#define PROJETO_AED_1_STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    int code;
    string name;

public:
    Student(int code, string name);
    int getCode() const;
    string getName() const;



};


#endif //PROJETO_AED_1_STUDENT_H
