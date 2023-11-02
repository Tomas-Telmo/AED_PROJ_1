#include "Menu.h"
#include <algorithm>
#include <iomanip>

void Menu::skiplines() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
}

void Menu::run() {
    cout <<"Welcome to the schedule app menu! What do you wish to do?"<<endl;
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                    Menu                     │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│ > Look through database                 [1] │\n"
            "│ > Quick Search database                 [2] │\n"
            "│ > Modify database                       [3] │\n"
            "│                                             │\n"
            "│                                             │\n"
            "│                                   >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";

    string cmd;
    getline(cin, cmd);
    if (cmd=="q") quit();

    while(cmd!="1" && cmd!="2"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    //if(cmd=="q") cmd="3";
    int operation = stoi(cmd);

    switch (operation) {
        case 1:
            LookThroughDataBase();
            break;
        case 2:
            QuickSearchDatabase();
            break;
        case 3:
            cout<<"soon";                                               //TODO EDIT
            break;
    }
}

//LOOK THROUGH DATA BASE
void Menu::LookThroughDataBase() {
    skiplines();

    cout << "╒═════════════════════════════════════════════╕\n"
            "│            Look through database            │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│ > 1st Year                              [1] │\n"
            "│ > 2nd Year                              [2] │\n"
            "│ > 3rd Year                              [3] │\n"
            "│                                             │\n"
            "│ >Back [0]                         >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);

    if (cmd=="q") quit();

    while(cmd!="0" && cmd!="1" && cmd!="2" && cmd!="3" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    //if(cmd=="q") cmd="3";
    int operation = stoi(cmd);

    switch (operation) {
        case 1:
            UCperYear("1");
            break;
        case 2:
            UCperYear("2");                                               //TODO EDIT
            break;
        case 3:
            UCperYear("3");
            break;
        case 0:
            run();
            break;
    }

}


void Menu::UCperYear(const std::string& year) {

    ifstream classesPerUCFile;

    //classesPerUCFile.open("classes_per_uc.csv", ios::in);
    classesPerUCFile.open("C:\\Users\\Utilizador\\OneDrive\\Ambiente de Trabalho\\code\\CLion stuff\\PROJETO AED1\\cmake-build-default\\classes_per_uc.csv");

    if (!classesPerUCFile.is_open()) {
        cerr << "ERROR: UNABLE TO OPEN CLASSE PER UC FILE " << endl;
    }
    string dummy;
    string line;
    string UC_code;
    string class_code;

    set <string> UCcode_set;
    string givenclass = year + "LEI";

    getline(classesPerUCFile, dummy); //skip 1st line

    while (getline(classesPerUCFile, line)) {
        stringstream ss(line);

        getline(ss, UC_code, ',');
        getline(ss, class_code, 'C');

        if( class_code == givenclass){
            UCcode_set.insert(UC_code);
        }
    }

    classesPerUCFile.close();

    skiplines();

    int i=0;
    cout << "╒═════════════════════════════════════════════╕\n";
    cout << "│                 YEAR " << year << "                      │\n";
    cout << "╞═════════════════════════════════════════════╡\n"
            "│                                             │\n";

    for (string ucc : UCcode_set) {
        i++;
        string temp = ucc.substr(0, 2);
        if( temp == "UP" ){
            cout <<"│  "<<ucc<<"                                      │\n";
        }
        else cout << "│  "<<ucc<<"                                   │\n";

    }

    cout << "│  Current number of UCs: "<<i<<"                   │\n"
            "│                                             │\n"
            "│  >Type Uc code to view an uc                │\n"
            "│                                             │\n"
            "│  >Back [0]                        >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";

    string cmd;
    getline(cin, cmd);

    if(cmd=="q") quit();
    if (cmd=="0") LookThroughDataBase();

    bool flag = false;
    for(string uccode : UCcode_set){
        if(cmd == uccode ){
            flag = true;
        }

    }
    if(!flag){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    UC uc(cmd,{},{});
    ClassesPerUC(uc,year);

}


void Menu::ClassesPerUC(UC uc,string year) {
    uc.Make();
    skiplines();

    int nclasses=0;
    int nstudents=0;
    cout << "╒═════════════════════════════════════════════╕\n";
    cout << "│                 "<< uc.getUCCode() <<"                    │\n";
    cout << "╞═════════════════════════════════════════════╡\n"
            "│                                             │\n";

    for (auto stc : uc.getStudentClassSet()) {
        nclasses++;
        nstudents += stc.getCapacity();
        cout << "│  "<<stc.getCode()<<"                                    │\n";

    }

    cout <<  "│                                             │\n"
             "│  Current number of classes: "<<nclasses<<"              │\n"
             "│  Current number of students: "<<nstudents<<"             │\n"
             "│                                             │\n"
             "│  >Type class code to view a class           │\n"
             "│                                             │\n"
             "│  >Back [0]                        >Quit [q] │\n"
             "╘═════════════════════════════════════════════╛\n"
             "                                           \n";

    string cmd;
    getline(cin, cmd);

    if(cmd=="q") quit();
    if (cmd=="0") UCperYear(year);

    bool flag = false;
    for(auto classcode : uc.getStudentClassSet()){
        if(cmd == classcode.getCode() ){
            flag = true;
        }

    }

    if(!flag){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    scheduleORstudents(cmd,uc,year);
}


void Menu::scheduleORstudents(std::string classcode, UC uc, std::string year) {
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n";
    cout << "│                "<< classcode <<"                      │\n";
    cout << "╞═════════════════════════════════════════════╡\n"
            "│  Schedule                               [1] │\n"
            "│  Student list                           [2] │\n"
            "│                                             │\n"
            "│  Back [0]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";

    string cmd;
    getline(cin, cmd);

    if(cmd=="q") quit();

    int operation = stoi(cmd);

    switch (operation) {
        case 0:
            ClassesPerUC(uc, year);
            break;
        case 1:
            classSchedule(classcode,uc,year);
            break;
        case 2:
            classStudentList(classcode,uc,year);
            break;
    }
}


void Menu::classSchedule(std::string classcode, UC uc, std::string year) {
    skiplines();

    StudentClass SC = StudentClass(classcode, {}, {});
    if(SC.readClassesFile()){
        SC.printSchedule();
    }

    string cmd;
    getline(cin, cmd);

    if(cmd=="q") quit();
    if (cmd=="0") scheduleORstudents(classcode, uc, year);
}


void Menu::classStudentList(std::string classcode, UC uc, std::string year) {
    skiplines();
    set <Student> students;

    for(auto stc: uc.getStudentClassSet()) {
        if(stc.getCode() == classcode){
            students = stc.getStudentSet();
            break;
    }


    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│                                             │\n";


    for (Student st : students) {

        cout << "│      " << st.getName() << setw(20-st.getName().length())<<" "<<st.getCode()<<"          │\n";

    }

    cout << "│  Back [0]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
    string cmd;

    getline(cin, cmd);
    while(cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    if(cmd=="q") quit();
    if (cmd=="0") scheduleORstudents(classcode, uc, year);
}
}

//-----------------------------------------QUICK-SEARCH----------------------------------------------------------------------
void Menu::QuickSearchDatabase() {
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                Quick Search                 │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Get schedule                           [1] │\n"
            "│                                             │\n"
            "│                                             │\n"
            "│  Back [0]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    while (cmd != "1" && cmd != "0" && cmd != "q") {
        cout << "Choose a valid option \n";
        getline(cin, cmd);
    }

    if (cmd == "q") cmd = "4";
    int operation = stoi(cmd);
    switch (operation) {
        case 1:
            Schedules1();
            break;
        case 2:
            //todo maybe add more like uc min
            break;
        case 0:
            run();
            break;
        case 4:
            quit();
            break;
    }
}

void Menu::Schedules1() {
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Search by Class                        [1] │\n"
            "│  Search by Student                      [2] │\n"
            "│                                             │\n"
            "│  Back [0]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="0" && cmd!="q"){
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
        case 0:
            QuickSearchDatabase();
            break;
        case 4:
            quit();
            break;
    }
}

void Menu::SearchByClass() {
    skiplines();
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
    skiplines();

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
//--------------------------------------------------------(124)Students------------------------------------------------------

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
            "│   Minimum UC's                          [4] │\n"
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
            OfACourse();
            break;
        case 3:
            StudentsByYear();

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
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│             Type the student UC             │\n"
            "│               (e.g:L.EIC021)                │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│            Type a Student Class             │\n"
            "│                                             │\n"
            "│               (e.g: 2LEIC11)                │\n"
            "│      2-year    LEIC-course  11-classNum     │\n"
            "│                                             │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd2;
    getline(cin, cmd2);
    StudentClass st = StudentClass(cmd2, {}, {});
    st.loadStudentsofAClass(cmd);
    st.printStudentsbyUCandClass(cmd);


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
    if(cmd=="q") quit();
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
            "│  At least "<<ans<<" students are                  "<<"│\n"
            "│  registered in the selected minimum UC's    │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";

}

void Menu::OfACourse() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│           Type the student Course           │\n"
            "│              (e.g:LEIC, LEM)                │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    StudentClass st = StudentClass("", {}, {});
    st.loadStudentsofACourse(cmd);
    st.printStudentsbyCourse(cmd);


}

void Menu::StudentsByYear() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                   Students                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│             Type the year you want          │\n"
            "│                   to check                  │\n"
            "│                                             │\n"
            "│                                    Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n";

    string cmd;
    int year;
    getline(cin, cmd);
    if (cmd=="q") quit();
    try{
        year=stoi(cmd);
    }catch(invalid_argument){
        CountByMinimumUC();
    }
    while(stoi(cmd)<0){
        cout<<"Choose a valid year: \n";
        getline(cin, cmd);
    }
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
    set <Student> students;

    getline(students_classes_file,dummy); //skip 1st line

    while(getline(students_classes_file,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,FileUCcode,',');
        getline(ss,FileClassCode);
        Student stu = Student(student_code,student_name);
        if(year == int(FileClassCode[0])-48){
            students.insert(stu);
        }
    }
    students_classes_file.close();


    skiplines();

    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│      Year: "<<year<<"                                │\n";


    for (Student st : students) {

        cout << "│      " << st.getName() << setw(20-st.getName().length())<<" "<<st.getCode()<<"          │\n";

    }

    cout << "│  Back [0]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
    getline(cin, cmd);
    while(cmd!="1" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") quit();
    if (cmd=="0") run();
}

void Menu::BiggestUC() {
    int max=0;
    set<string> ansUCCode;

    //get UC's
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
    map <string,int> UCs;

    getline(students_classes_file,dummy); //skip 1st line

    while(getline(students_classes_file,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,FileUCcode,',');
        getline(ss,FileClassCode);
        Student stu = Student(student_code,student_name);
        if(UCs.find(FileUCcode)==UCs.end()){
            UCs[FileUCcode]=0;
        }
        else{
            UCs[FileUCcode]=UCs[FileUCcode]+1;
        }
    }
    students_classes_file.close();
    for(auto p : UCs){
        if(p.second>max){
            ansUCCode.clear();
            ansUCCode.insert(p.first);
            max=p.second;
        }
        else if (p.second==max){
            ansUCCode.insert(p.first);
        }
    }

    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│      UC's with the most students            │\n";


    for (string UCc : ansUCCode) {

        cout << "│     "<<UCc<<"                                |\n";

    }

    cout << "│  Back [1]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";

}

//--------------------------------------------CLASSES---------------------------------------------------------------