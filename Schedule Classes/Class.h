//
// Created by antero on 26-10-2023.
//

#ifndef PROJETO_AED_1_CLASS_H
#define PROJETO_AED_1_CLASS_H

#include <string>
using namespace std;

class Class {
    string weekday;
    double starthour;
    double duration;
    string type;

    string classCode;
    string uCcode;
public:
    Class();
    Class(string weekday_, double starthour_, double duration_, string type_);
    string getWeekday(Class);
    double getStarthour(Class);
    double getDuration(Class);
    string getType(Class);
    string getClassCode(Class);
    string getUcCode(Class);
};

#endif //PROJETO_AED_1_CLASS_H
