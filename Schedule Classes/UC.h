#ifndef PROJETO_AED_1_UC_H
#define PROJETO_AED_1_UC_H

#include <iostream>
#include <string>
#include <set>
#include <list>
#include "StudentClass.h"

using namespace std;

class UC{
    string UcCode; /*!< A private set that stores Students*/
    set<StudentClass> studentclassSet; /*!< A private set that stores Students*/
    list<StudentClass> studentclassList; /*!< A private set that stores Students*/
    int MAX_STUDENTS = 28; /*!< A private integer that represents the máx number of students a StudentClass(Turma) can have*/


public:
    //! A Constructor for UC with parameters
    //! \param UcCode_
    //! \param class_set
    //! \param class_list
    UC(string UcCode_, set<StudentClass> class_set, list<StudentClass> class_list);

    //! A copy Constructor for UC
    //! \param uc
    UC(UC const &uc);

    //! Getter for the code (UcCode) of a UC
    //! \return
    string getUCCode() const;

    //! Getter for the studentclassSet of a UC
    //! \return
    set<StudentClass> getStudentClassSet() const;

    //! Getter for the studentclassList of a UC
    //! \return
    list<StudentClass> getStudentClassList()const;

    //! Function that returns the size of the studentclassset
    //! \return integer number of classes
    int getNumberOfClasses() const;

    //! Function that inserts a StudentClass(Turma) in the studentclassSet
    //! \param Class
    void addStudentClass(StudentClass Class);

    //!
    void readClassesPerUCFile();

    //!
    void readStudentsClassesFile();

    //!
    void Make();

    //!
    //! \param other
    //! \return
    bool operator<(const UC& other) const;


    list<StudentClass> freeStudentClasses();

};

#endif //PROJETO_AED_1_UC_H
