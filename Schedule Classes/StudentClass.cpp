#include <sstream>
#include "StudentClass.h"
#include <iostream>
#include <fstream>

StudentClass::StudentClass() {}
StudentClass::StudentClass(set <Student> students_,int capacity_,int code_){
    this->students = students_;
    this->capacity = capacity_;
    this->code = code_;
}

set <Student> StudentClass::getStudents() {
    return this->students;
}

string StudentClass::getCode() {
    return this->code;
}

int StudentClass::getCapacity() {
    return this->capacity;
}

void StudentClass::readFile(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open the file " << filename << endl;
        return;
    }
    else{
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string studentCode, studentName, ucCode, classCode;
        if (iss >> studentCode >> studentName >> ucCode >> classCode) {
            int code = stoi(studentCode);
            Student student(code, studentName);
            students.insert(student);
        }
      }
      file.close();
    }
}