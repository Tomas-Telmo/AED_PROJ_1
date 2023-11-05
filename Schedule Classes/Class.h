
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
    //!A Contructor for Class(Aula)
    Class();

    //!A Constructor for Class(Aula)
    /**
     *
     * @param weekday_
     * @param starthour_
     * @param duration_
     * @param type_
     * @param classcode_
     * @param uccode_
     */
    Class(string weekday_, double starthour_, double duration_, string type_, string classcode_, string uccode_);

    //!A Copy Constructor for Class(Aula)
    Class(Class const &class_);

    //!Getter for the weekday of a Class(Aula)
    string getWeekday();

    //!Getter for the starthour of a Class(Aula)
    double getStarthour();

    //!Getter for the duration of a Class(Aula)
    double getDuration();

    //!Getter for the type of a Class(Aula)
    string getType();

    //!Getter for the Class Code of a Class(Aula)
    string getClassCode();

    //!Getter for weekday of a Class(Aula)
    string getUcCode();


    //!Overload of the operator <
    bool operator<(Class other) const;

};

#endif //PROJETO_AED_1_CLASS_H
