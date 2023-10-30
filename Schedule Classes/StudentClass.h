#ifndef PROJETO_AED_1_STUDENTCLASS_H
#define PROJETO_AED_1_STUDENTCLASS_H

#include "Student.h"
#include <set>
#include <fstream>
#include <iostream>

class StudentClass{
    set<Student> students;
    string code;

public:
    StudentClass() {};
    StudentClass(string code_, set<Student> students_);
    StudentClass(const StudentClass& studentclass);

    set <Student> getStudents() const;
    string getCode() const;
    int getCapacity() const;

    void setCode(string code_);
    void setStudents(set<Student> students_);

    void addStudent(Student student);
    bool operator<( const StudentClass& other) const;
    void readFile(ifstream &filename,string UCcode);
};
#endif //PROJETO_AED_1_STUDENTCLASS_H
