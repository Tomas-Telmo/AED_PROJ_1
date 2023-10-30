//
// Created by antero on 30-10-2023.
//

#ifndef PROJETO_AED_1_MENU_H
#define PROJETO_AED_1_MENU_H


#include "CSV.h"

class Menu {
    CSV csv = CSV();
public:
    void run();
    void schedules();
    void UCs();
    void schedulebyyear();
    void schedulebyClass(int);
};


#endif //PROJETO_AED_1_MENU_H
