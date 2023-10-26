#ifndef PROJETO_AED_1_STUDENT_H
#define PROJETO_AED_1_STUDENT_H

#include <iostream>
#include <string>


using namespace std;

class Student {
    int code;
    string name;

public:
    Student(int code_, string name_);
    int getCode() const;
    string getName() const;
    bool operator<(const Student &other_student) const;


};


#endif //PROJETO_AED_1_STUDENT_H
