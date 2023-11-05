/**
 * @file Menu.h
 * @brief Defines the Menu class.
 */
#ifndef PROJETO_AED_1_MENU_H
#define PROJETO_AED_1_MENU_H
#include <cstdlib>
#include <list>
#include "UC.h"
#include <map>
#include <sstream>
#include <string>

class Menu {
    /**
     * @class Menu
     * @brief Provides menu options and display functionalities for the program.
     */
public:
    //! Function that skips lines so that the menus don't get printed too close to each other
    void skiplines();

    //! Function that starts the menu on the console
    void run();

    //! Display function
    void QuickSearchDatabase();

    //! Display function
    void Schedules1();

    //! Display function
    void SearchByClass();

    //! Display function
    void Searchbystudent();

    //! Display function
    void searchByStudentName();

    //! Display function
    void searchByStudentUP();

    //! Display function
    void CountByMinimumUC();

    //! Display function
    void BiggestUC();

    //! Display function
    void ModifyDatabase();

    //! Display function
    void RemoveStudentMenu();


    //! Display function
    void LookThroughDataBase();

    //! Display function
    void UCperYear(const string& year);



    //! Display function
    //! \param uc
    //! \param year
    void ClassesPerUC(UC uc, string year);

    //! Display Function
    //! \param classcode
    //! \param uc
    //! \param year
    void scheduleORstudents(string classcode, UC uc, string year);

    //! Display function
    //! \param classcode
    //! \param uc
    //! \param year
    void classSchedule(string classcode, UC uc, string year);

    //! Display function
    void addStudent();

    //! Display function Ascending order
    //! \param classcode
    //! \param uc
    //! \param year
    void classStudentList(string classcode, UC uc, string year);

    //! Display function Descending order
    //! \param classcode
    //! \param uc
    //! \param year
    //! \param students
    void classStudentListDescending(string classcode,UC uc,string year,set<Student> students);


    //! Function that removes a Student from a UC
    //! \param code
    //! \param name
    //! \param UcCode
    //! \return a bool value, true if the student has been removed and false if there is no student to be removed
    bool removeStudent(string code, string name, string UcCode); //remove mesmo, nao experimentar senao perde-se info do ficheiro

    //! Function that writes in the students_classes.csv file the parameters
    //! \param studentCode
    //! \param studentName
    //! \param UCCode
    //! \param classCode
    void writeToFile(string studentCode, string studentName, string UCCode, string classCode);

    //! Function that checks out if a student can be registered in a new UC if its possible
    //! \return true if can be registered and false if doesn't
    bool addStudentByUP();

    bool addStudentByName();

    //! Function that checks if a UC exists
    //! \param UcCode
    //! \return true if exists, false if doesn't
    bool searchUC(string UcCode);

    //! Function that stops the execution
    void quit();
};


#endif //PROJETO_AED_1_MENU_H
