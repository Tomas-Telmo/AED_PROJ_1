
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
    string UcCode;
public:
    Class();
    Class(string weekday_, double starthour_, double duration_, string type_, string classcode_, string uccode_);
    Class(Class const &class_);

    string getWeekday();
    double getStarthour();
    double getDuration();
    string getType();
    string getClassCode();
    string getUcCode();

    void setBegining(string weekday_, double starthour_);
    void setDuration(double duration_);
    void setType(string type_);
    void setClassCode(string classcode_);
    void setUcCode(string code);

    bool operator<(Class other) const;

};

#endif //PROJETO_AED_1_CLASS_H
