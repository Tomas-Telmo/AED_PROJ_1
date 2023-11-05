#ifndef PROJETO_AED_1_STUDENTCLASS_H
#define PROJETO_AED_1_STUDENTCLASS_H

#include "Student.h"
#include <set>
#include <fstream>
#include <iostream>
#include "Class.h"
#include "list"

class StudentClass{

    set<Student> studentSet; /*!< A private set that stores Students*/
    string code; /*!< A private string that stores the Class Code*/
    list<Class> scheduleList; /*!< A private list that stores the Classes(Aulas), basicly a brute schedule*/


public:
    //!A Contructor for StudentClass(Turma)
    StudentClass() {};

    //! A Constructor for Class(Aula) with parameters
    //! \param code_
    //! \param studentSet_
    //! \param scheduleList_
    StudentClass(string code_, set<Student> studentSet_, list<Class> scheduleList_);

    //! A Copy Constructor for StudentClass(Turma)
    //! \param studentclass
    StudentClass(const StudentClass& studentclass);


    //!Getter for the StudentSet of a StudentClass(Turma)
    set <Student> getStudentSet() const;

    //!Getter for the code (ClassCode) of a StudentClass(Turma)
    string getCode() const;

    //! Getter for the current ocupation "capacity" of a StudentClass(Turma)
    int getCapacity() const;        //mudar nome para getOcuppation

    //! Getter for the ScheduleList of a StudentClass(Turma)
    //! \return list of Classes(Aulas)
    list<Class> getScheduleList() const;


    //! Function that reads the students_classes.csv to get the students of a StudentClass(turma) of a UC
    //! \param UCcode
    void readStudentsClassesFile(string UCcode);

    //! Function that reads the classes.csv to push_back the classes(aulas) in a list called scheduleList
    bool readClassesFile();

    //! Function that reads the classes.csv to push_back the classes(aulas) of a UC in a list called scheduleList
    //! \param UCcode
    //! \return
    bool readClassesFileForUC(string UCcode);

    //! Function that reads the classes.csv and places the Students of a StudentClass(Turma) of a UC in the studentSet
    //! \param UCCode
    void loadStudentsofAClass(string UCCode);

    //!Function that prints a Schedule
    void printSchedule();


    //! Function that returns the hour in XX:XX format after receiving a double
    //! \param num wich is type double
    //! \return string hour
    string fromdoubletohour(double num);

    //! Overload of the operator <
    //! \param other wich is a StudentClass
    //! \return a bollean value
    bool operator<( const StudentClass& other) const;
};
#endif //PROJETO_AED_1_STUDENTCLASS_H
