#include "Student.h"


Student::Student(string code_, string name_) {
    this->code = code_;
    this->name = name_;
}

Student::Student(const Student &student) {
    this->code = student.code;
    this->name = student.name;
}

string Student::getCode() const {
    return this->code;
}

string Student::getName() const {
    return this->name;
}

void Student::setCode(string code_) {
    this->code = code_;
}

void Student::setName(std::string name_) {
    this->name = name_;
}

bool Student::operator<(const Student &other) const {
    return this->code < other.code;
}
