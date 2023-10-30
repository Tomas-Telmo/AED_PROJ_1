#ifndef PROJETO_AED_1_STUDENT_H
#define PROJETO_AED_1_STUDENT_H

#include <iostream>
#include <string>


using namespace std;

class Student {
    string code;
    string name;

public:
    //Student();
    Student(string code_, string name_);
    Student(Student const &student);

    string getCode() const;
    string getName() const;

    void setCode(string code_);
    void setName(string name_);

    bool operator<(const Student& other)const;

    string getStudentNameByCode(string code);
    string getStudentCodeByName(string name);
};


#endif //PROJETO_AED_1_STUDENT_H
