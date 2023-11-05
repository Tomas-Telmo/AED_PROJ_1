/**
 * @file UC.h
 * @brief Defines the UC class, representing a Curricular Unit.
 */

 #ifndef PROJETO_AED_1_UC_H
#define PROJETO_AED_1_UC_H

#include <iostream>
#include <string>
#include <set>
#include <list>
#include "StudentClass.h"

using namespace std;

class UC{
    /**
     * @class UC
     * @brief Represents a Curricular Unit (UC).
     *
     * The UC class encapsulates information about a Curricular Unit, including its code,
     * associated student classes, and various operations related to managing and analyzing these classes.
     */

    string UcCode; /*!< A private set that stores Students*/
    set<StudentClass> studentclassSet; /*!< A private set that stores Students*/
    list<StudentClass> studentclassList; /*!< A private set that stores Students*/
    int MAX_STUDENTS = 28; /*!< A private integer that represents the máx number of students a StudentClass(Turma) can have*/


public:
    /**
     * @brief Constructor for UC with parameters.
     *
     * @param UcCode_ The code of the UC.
     * @param class_set_ A set of StudentClasses(Turmas).
     * @param class_list_ A list of StudentClass(Turmas).
     */
    UC(string UcCode_, set<StudentClass> class_set, list<StudentClass> class_list);

    /**
     * @brief Copy constructor for UC.
     *
     * @param uc The UC object to be copied.
     */
    UC(UC const &uc);

    /**
     * @brief Getter for the code (UcCode) of the UC.
     *
     * @return The code of the UC.
     */
    string getUCCode() const;

    /**
     * @brief Get the set of associated StudentClass.
     *
     * @return A set of StudentClass.
     */
    set<StudentClass> getStudentClassSet() const;

    //! Getter for the studentclassList of a UC
    //! \return
    list<StudentClass> getStudentClassList()const;

    //! Function that returns the size of the studentclassSet
    //! \return integer number of classes
    int getNumberOfClasses() const;

    //! Function that inserts a StudentClass(Turma) in the studentclassSet
    //! \param Class
    void addStudentClass(StudentClass Class);

    //!Function that reads the StudentClasses(Turmas) of a UC directly from the classes_per_uc.csv file
    void readClassesPerUCFile();

    /**
     * @brief Read student classes information from files.
     */
    void readStudentsClassesFile();

    /**
     * @brief Perform necessary operations to set up UC data.
     */
    void Make();

    //! //! Overload of the operator < that sorts by UCcode
    //! \param other wich is a UC
    //! \return a boolean value
    bool operator<(const UC& other) const;

    //! Function that returns a sorted list of StudentClasses(Turmas) with less Students registered than the maximum
    //! \return list of StudentClasses(Turmas), sorted by number of Students
    list<StudentClass> freeStudentClasses();

};

#endif //PROJETO_AED_1_UC_H
