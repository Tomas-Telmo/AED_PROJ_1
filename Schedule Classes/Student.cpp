//
// Created by antero on 25-10-2023.
//

#include "Student.h"


Student::Student(int code_, string name_) {
    code = code_;
    name = name_;
}

int Student::getCode() const {return code;}
string Student::getName() const {return name;}
