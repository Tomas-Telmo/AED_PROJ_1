#include <sstream>
#include "StudentClass.h"
#include <iostream>



StudentClass::StudentClass(string code_, set<Student> students_){
    this->code = code_;
    this->students = students_;
}

StudentClass::StudentClass(const StudentClass &studentclass) {
    this->code = studentclass.code;
    this->students = studentclass.students;
}

set <Student> StudentClass::getStudents() const {
    return this->students;
}

string StudentClass::getCode() {
    return this->code;
}

int StudentClass::getCapacity() {
    return this->students.size();
}

void StudentClass::setCode(string code_) {
    this->code = code_;
}

void StudentClass::setStudents(set<Student> students_) {
    this->students = students_;
}

void StudentClass::addStudent(Student student) {
    this->students.insert(student);
}

bool StudentClass::operator<(const StudentClass &other) const {
    return this->code < other.code;
}

/*
void StudentClass::readFile(ifstream &filename, string class_code) {
    string dummy;
    string line;
    string student_code;
    string student_name;
    string UCcode;
    string FileClassCode;

    this->code = class_code;

    if (!filename.is_open()) {
        cerr << "ERROR: Unable to open the file " << endl;
        return;
    }

    getline(filename,dummy); //skip 1st line

    while(getline(filename,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,dummy,',');
        getline(ss,class_code,',');

        if(code == class_code){
            Student student(student_code,student_name);
            students.insert(student);

        }

    }

}
 */
