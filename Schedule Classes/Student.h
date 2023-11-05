/**
 * @file Student.h
 * @brief Defines the Student class.
 */
#ifndef PROJETO_AED_1_STUDENT_H
#define PROJETO_AED_1_STUDENT_H

#include <iostream>
#include <string>
#include <list>
#include "Class.h"
#include <set>


using namespace std;

class Student {
    /**
     * @class Student
     * @brief Represents a Student.
     *
     */
    string code;/*!< A private string that stores the student UP code*/
    string name;/*!< A private string that stores the student Name*/
    list<pair<string,string>> UCandClasses;/*!< A private list with pairs <ucCode, classCode>, that way we can understant in wich StudentClass(Turma) of a UC the Student is*/
    list<Class> schedule;/*!< A private list that stores the Classes(Aulas), basicly a brute schedule*/


public:
    //! A Contructor for Class(Aula)
    //! \param code_
    //! \param name_
    Student(string code_, string name_);

    //! A Contructor for Class(Aula)
    //! \param student
    Student(Student const &student);

    //! Getter for the UP code of a Student
    //! \return
    string getCode() const;

    //! Getter for the Name of a Student
    //! \return
    string getName() const;

    //! Getter list of StudentClasses(Turma) of a Student
    //! \return
    list<pair<string,string>> getUCandClasses();

    //! Getter for the Schedule of a Student
    //! \return
    list<Class> getSchedule();



    //! Setter for the UP code of a Student
    //! \param code_
    void setCode(string code_);

    //! Setter for the UP code of a Student
    //! \param name_
    void setName(string name_);

    //!Function that searches for the name of a Student using the UP code
    /**
     * Search directly in the students_classes.csv file
     */
    void getNameByUP();

    //!Finds the StudentClasses(Turmas) of each UC of a Student using the Student Name
    /**
     * Creates a list of pairs <uccode, classcode>, called UCandClasses, directly from students_classes.csv file
     */
    void loadClassesperUCofStudentUsingNAME(); //turmas e ucs inscritas


    //!Creates the Schedule of a Student
    /**
     * Uses UCandClasses, created list to find the Classes(Aulas) that the student will have
     */
    void loadSchedule();

    //!Function that returns the hour in XX:XX format after receiving a double
    string fromdoubletohour(double num);

    //!Function that prints a Schedule
    void printSchedule();


    //!Overload of the operator < that sorts by name
    bool operator<(const Student& other)const;

    //!Bool function
    /**
     * Used to sort the list in the oposite order from Z to A
     */
    static bool descending(const Student& one, const Student& other);
};


#endif //PROJETO_AED_1_STUDENT_H
