//
// Created by antero on 26-10-2023.
//

#include "Class.h"

Class::Class(string weekday_, double starthour_, double duration_, string type_, string classcode_, string uccode_) {
    this->weekday = weekday_;
    this->starthour = starthour_;
    this->duration = duration_;
    this->type = type_;
    this->classCode = classcode_;
    this->uCcode = uccode_;
}

Class::Class(const Class &class_) {
    this->weekday = class_.weekday;
    this->starthour = class_.starthour;
    this->duration = class_.duration;
    this->type = class_.type;
    this->classCode = class_.classCode;
    this->uCcode = class_.uCcode;
}

string Class::getWeekday() {
    return this->weekday;
}

double Class::getStarthour() {
    return this->starthour;
}

double Class::getDuration() {
    return this->duration;
}

string Class::getType() {
    return this->type;
}

string Class::getClassCode() {
    return this->classCode;
}

string Class::getUcCode() {
    return this->uCcode;
}


void Class::setBegining(string weekday_, double starthour_) {
    this->weekday = weekday_;
    this->starthour = starthour_;
}

void Class::setDuration(double duration_) {
    this->duration = duration_;
}

void Class::setType(string type_) {
    this->type = type_;
}

void Class::setUcCode(string code) {
    this->uCcode = code;
}

void Class::setClassCode(string classcode_) {
    this->classCode = classcode_;
}



