//
// Created by antero on 30-10-2023.
//

#include "Menu.h"
#include "UC.h"
#include "CSV.h"
#include <stdexcept>
#include <cassert>



void Menu::run() {

            cout << "╒═════════════════════════════════════════════╕\n"
                    "│                   Menu                      │\n"
                    "╞═════════════════════════════════════════════╡\n"
                    "│  Schedules                              [1] │\n"
                    "│  UCs                                    [2] │\n"
                    "╘═════════════════════════════════════════════╛\n"
                    "                                               \n";

            string cmd;
            getline(cin, cmd);
            int operation = stoi(cmd);
            if(operation==1) {
                schedules();
            }
            else if(operation==2) {
                UCs();
            }
        }



void Menu::schedules() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  AllSchedules                           [1] │\n"
            "│  SearchByStudent                        [2] │\n"
            "│  Back                                   [3] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    int operation = stoi(cmd);
    if(operation==1) {
        schedulebyyear();
    }
    else if(operation==2) {
        UCs();
    }
    else if(operation==3) {
        for (int i = 0; i < 50; i++) {
            cout << '\n';
        }
        run();
    }
}

void Menu::UCs() {}

void Menu::schedulebyyear() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  1stYear                                [1] │\n"
            "│  2ndYear                                [2] │\n"
            "│  3rdYear                                [3] │\n"
            "│  Back                                   [4] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    int operation = stoi(cmd);
    if(operation==4) {schedules();}
    if(operation==1 || operation==2 || operation==3) {
        schedulebyClass(operation);
    }

}

void Menu::schedulebyClass(int year) {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    if(year==1) { //sketch
        set<string> classcodes;

        cout << "╒═════════════════════════════════════════════╕\n"
                "│                  Schedules                  │\n"
                "╞═════════════════════════════════════════════╡\n"
                "│  1LEIC01  [1]              1LEIC09     [9]  │\n"
                "│  1LEIC02  [2]              1LEIC010    [10] │\n"
                "│  1LEIC03  [3]              1LEIC011    [11] │\n"
                "│  1LEIC04  [4]              1LEIC012    [12] │\n"
                "│  1LEIC05  [5]              1LEIC013    [13] │\n"
                "│  1LEIC06  [6]              1LEIC014    [14] │\n"
                "│  1LEIC07  [7]              1LEIC015    [15] │\n"
                "│  1LEIC08  [8]              1LEIC016    [16] │\n"
                "│                 Back [17]                   │\n"
                "╘═════════════════════════════════════════════╛\n"
                "                                               \n";
    }

    string cmd;
    getline(cin, cmd);
    int operation = stoi(cmd);
}