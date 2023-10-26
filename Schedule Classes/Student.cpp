#include "Student.h"


Student::Student(int code_, string name_) {
    this->code = code_;
    this->name = name_;
}

int Student::getCode() const {return code;}
string Student::getName() const {return name;}

bool Student::operator<(const Student &other_student) const {
    return this->code > other_student.getCode();
}