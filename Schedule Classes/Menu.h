//
// Created by antero on 31-10-2023.
//

#ifndef PROJETO_AED_1_MENU_H
#define PROJETO_AED_1_MENU_H
#include <cstdlib>
#include <list>
#include "UC.h"
#include <map>
#include <sstream>
#include <string>

class Menu {
public:
    void skiplines();
    void run();

    void QuickSearchDatabase();
    void Schedules1();
    void SearchByClass();
    void Searchbystudent();
    void searchByStudentName();
    void searchByStudentUP();
    void CountByMinimumUC();
    void StudentsByYear();
    void BiggestUC();

    void ModifyDatabase();
    void RemoveStudentMenu();

    void Students();
    void OfAClass();
    void OfACourse();



    void LookThroughDataBase();
    void UCperYear(const string& year);
    void ClassesPerUC(UC uc, string year);
    void scheduleORstudents(string classcode, UC uc, string year);
    void classSchedule(string classcode, UC uc, string year);
    void classStudentList(string classcode, UC uc, string year);
    void classStudentListDescending(string classcode,UC uc,string year,set<Student> students);

    void quit();

    bool removeStudent(string code, string name, string UcCode); //remove mesmo, nao experimentar senao perde-se info do ficheiro

};


#endif //PROJETO_AED_1_MENU_H
