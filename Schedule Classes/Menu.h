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

class Menu {
public:
    void run();
    void Schedules1();
    void SearchByClass();
    void Searchbystudent();
    void searchByStudentName();
    void searchByStudentUP();
    void CountByMinimumUC();


    void Students();
    void OfAClass();

    void quit();

};


#endif //PROJETO_AED_1_MENU_H
