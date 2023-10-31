//
// Created by antero on 31-10-2023.
//
#include "UC.h"
#include "Menu.h"

void Menu::run() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                    Menu                     │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Schedules                              [1] │\n"
            "│  Edit                                   [2] │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";

    string cmd;
    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") cmd="3";
    int operation = stoi(cmd);
    switch (operation) {
        case 1:
            Schedules1();
            break;
        case 2:
            cout<<"soon";                                               //TODO EDIT
            break;
        case 3:
            quit();
            break;
    }
}

void Menu::Schedules1() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Search by Class                        [1] │\n"
            "│  Search by Student                      [2] │\n"
            "│                                             │\n"
            "│  Back [3]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="3" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") cmd="4";
    int operation = stoi(cmd);
    switch (operation) {
        case 1:
            SearchByClass();
            break;
        case 2:
            Searchbystudent();
            break;
        case 3:
            run();
            break;
        case 4:
            quit();
            break;
    }
}

void Menu::SearchByClass() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│            Type a Student Class             │\n"
            "│                                             │\n"
            "│               (e.g: 2LEIC11)                │\n"
            "│      2-year    LEIC-course  11-classNum     │\n"
            "│                                             │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    StudentClass SC = StudentClass(cmd, {}, {});
    SC.readClassesFile();
    SC.printSchedule();
    getline(cin, cmd);
    while(cmd!="1" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") cmd="2";
    int operation = stoi(cmd);
    switch (operation) {
        case 1:
            Schedules1();
            break;
        case 2:
            quit();
            break;
    }
}

void Menu::Searchbystudent() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│   Use UP                                [1] │\n"
            "│   Use Name                              [2] │\n"
            "│                                             │\n"
            "│                                             │\n"
            "│   Back [3]                         Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="3" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") cmd="4";
    int operation = stoi(cmd);

    switch (operation) {
        case 1:
            cout << "╒═════════════════════════════════════════════╕\n"
                    "│                  Schedules                  │\n"
                    "╞═════════════════════════════════════════════╡\n"
                    "│             Type the student UP             │\n"
                    "│             to see his Schedule             │\n"
                    "│               (e.g:202012345)               │\n"
                    "│                                             │\n"
                    "╘═════════════════════════════════════════════╛\n"
                    "                                               \n";
            getline(cin, cmd);
            cout << "soon";                                             //TODO
            break;
        case 2:
            cout << "╒═════════════════════════════════════════════╕\n"
                    "│                  Schedules                  │\n"
                    "╞═════════════════════════════════════════════╡\n"
                    "│           Type the student Name to          │\n"
                    "│               see his Schedule              │\n"
                    "│     (Only use letters from the alphabet)    │\n"
                    "│                                             │\n"
                    "╘═════════════════════════════════════════════╛\n"
                    "                                               \n";
            getline(cin, cmd);
            cout << "soon";                                             //TODO
            break;
        case 3:
            Schedules1();
            break;
        case 4:
            quit();
            break;
    }
}

void Menu::quit() {
}