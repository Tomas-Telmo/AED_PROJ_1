#include "StudentClass.h"

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

void StudentClass::readFile(ifstream &filename) {
    //TODO
}