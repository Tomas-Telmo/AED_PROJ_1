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

    void Edit();

    void Students();
    void OfAClass();
    void OfACourse();



    void LookThroughDataBase();
    void UCperYear(const string& year);
    void ClassesPerUC(UC uc, string year);
    void scheduleORstudents(string classcode, UC uc, string year);
    void classSchedule(string classcode, UC uc, string year);
    void classStudentList(string classcode, UC uc, string year);

    void quit();

};


#endif //PROJETO_AED_1_MENU_H
