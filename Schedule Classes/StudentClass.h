#ifndef PROJETO_AED_1_STUDENTCLASS_H
#define PROJETO_AED_1_STUDENTCLASS_H

#include "Student.h"
#include <set>
#include <fstream>
#include <iostream>
#include "Class.h"
#include "list"

class StudentClass{
    set<Student> studentSet;
    string code;
    list<Class> scheduleList;

public:
    StudentClass() {};
    StudentClass(string code_, set<Student> studentSet_, list<Class> scheduleList_);
    StudentClass(const StudentClass& studentclass);

    set <Student> getStudentSet() const;
    string getCode() const;
    int getCapacity() const;
    list<Class> getScheduleList() const;

    void setCode(string code_);
    void setStudents(set<Student> students_);

    void addStudent(Student student);
    bool operator<( const StudentClass& other) const;
    void readStudentsClassesFile(string UCcode);
    void readClassesFile();

    void printSchedule();

    string fromdoubletohour(double num);
};
#endif //PROJETO_AED_1_STUDENTCLASS_H
