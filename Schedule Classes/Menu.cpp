//
// Created by antero on 31-10-2023.
//

#include "Menu.h"
#include <algorithm>



void Menu::run() {

    cout << "╒═════════════════════════════════════════════╕\n"
            "│                    Menu                     │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Schedules                              [1] │\n"
            "│  Edit                                   [2] │\n"
            "│  Students                               [3] │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";

    string cmd;
    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="3" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") cmd="5";
    int operation = stoi(cmd);
    switch (operation) {
        case 1:
            Schedules1();
            break;
        case 2:
            cout<<"soon";                                               //TODO EDIT
            break;
        case 3:
            Students();
            break;
        case 5:
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
    if(SC.readClassesFile()){
        SC.printSchedule();
    }else{
        cout<< "Student Class not found.\n\nBack [1]\nQuit[q]\n";
    }
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
            searchByStudentUP();

            break;
        case 2:
            searchByStudentName();
            break;
        case 3:
            Schedules1();
            break;
        case 4:
            quit();
            break;
    }
}

void Menu::searchByStudentName() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│           Type the student Name to          │\n"
            "│               see his Schedule              │\n"
            "│     (Only use letters from the alphabet)    │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    Student st1 = Student("",cmd);
    st1.loadClassesperUCofStudentUsingNAME();
    st1.loadSchedule();
    st1.printSchedule();
    getline(cin, cmd);
    while(cmd!="1" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="1") Searchbystudent();
    if(cmd=="q") quit();
}

void Menu::searchByStudentUP() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│             Type the student UP             │\n"
            "│             to see his Schedule             │\n"
            "│               (e.g:202012345)               │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    Student st1 = Student(cmd,"");
    st1.getNameByUP();
    st1.loadClassesperUCofStudentUsingNAME();
    st1.loadSchedule();
    st1.printSchedule();
    getline(cin, cmd);
    while(cmd!="1" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="1") Searchbystudent();
    if(cmd=="q") quit();
}

void Menu::quit() {
    exit(0);
}

void Menu::Students() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                   Students                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│   Of a Class                            [1] │\n"
            "│   Of a Course                           [2] │\n"
            "│   Of a year                             [3] │\n"
            "│  Minimum UC's                           [4] │\n"
            "│                                             │\n"
            "│   Back [5]                         Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="3" && cmd!="4" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") quit();
    int operation = stoi(cmd);
    switch (operation) {
        case 1:
            OfAClass();
            break;
        case 2:
            Students();
            break;
        case 3:

            break;
        case 4:
            CountByMinimumUC();
            break;
        case 5:
            quit();
            break;
    }

}

void Menu::OfAClass() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│             Type the student UC             │\n"
            "│               (e.g:L.EIC021)                │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│             Type the student Class          │\n"
            "│                (e.g:L.EIC021)               │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd2;
    getline(cin, cmd2);


}

void Menu::CountByMinimumUC() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                Minimum Of UCs               │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Choose the minimum:                        │\n"
            "│                                             │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    try{
        stoi(cmd);
    }catch(invalid_argument){
        CountByMinimumUC();
    }
    while(stoi(cmd)<0){
        cout<<"Choose a valid number: \n";
        getline(cin, cmd);
    }
    if(cmd=="2") quit();
    int minimum = stoi(cmd);

    //get students
    ifstream students_classes_file;

    students_classes_file.open("students_classes.csv", ios::in);

    if (!students_classes_file.is_open()) {
        cerr << "ERROR: UNABLE TO OPEN STUDENT CLASSES FILE " << endl;
        return;
    }

    string dummy;
    string line;
    string student_code;
    string student_name;
    string FileUCcode;
    string FileClassCode;
    map <string,int> students;

    getline(students_classes_file,dummy); //skip 1st line

    while(getline(students_classes_file,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,FileUCcode,',');
        getline(ss,FileClassCode);
        Student stu = Student(student_code,student_name);
        if(students.find(student_code)==students.end()){
            students[student_code]=0;
        }
        else{
            students[student_code]=students[student_code]+1;
        }
    }
    students_classes_file.close();

    //Count
    int ans=0;
    for(auto i :students ){
        if(i.second>=minimum){
            ans++;
        }
    }
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                Minimum Of UCs               │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  At least "<<ans<<" students are                │\n"
                                 "│  registered in the selected minimum UC's    │\n"
                                 "│                                    Quit [q] │\n"
                                 "╘═════════════════════════════════════════════╛\n"
                                 "                                               \n";

}

