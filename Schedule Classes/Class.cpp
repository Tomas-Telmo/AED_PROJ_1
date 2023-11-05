
#include "Class.h"
#include <map>

Class::Class(string weekday_, double starthour_, double duration_, string type_, string classcode_, string uccode_) {
    this->weekday = weekday_;
    this->starthour = starthour_;
    this->duration = duration_;
    this->type = type_;
    this->classCode = classcode_;
    this->UcCode = uccode_;
}

Class::Class(const Class &class_) {
    this->weekday = class_.weekday;
    this->starthour = class_.starthour;
    this->duration = class_.duration;
    this->type = class_.type;
    this->classCode = class_.classCode;
    this->UcCode = class_.UcCode;
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
    return this->UcCode;
}




bool Class::operator<(Class other) const {
    map<string ,int> week;
    week["Monday"]=1;
    week["Tuesday"]=2;
    week["Wednesday"]=3;
    week["Thursday"]=4;
    week["Friday"]=5;

    // First, compare weekdays
    if (week[weekday] < week[other.getWeekday()]) {
        return true;
    } else if (week[weekday] > week[other.getWeekday()]) {
        return false;
    } else {
        // If weekdays are equal, compare start hours
        return starthour < other.getStarthour();
    }
}

