#include "Menu.h"
#include <algorithm>
#include <iomanip>

void Menu::skiplines() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
}

void Menu::run() {

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

    while(cmd!="1" && cmd!="2" && cmd!="3"){
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
            ModifyDatabase();
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
            UCperYear("2");
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

    classesPerUCFile.open("classes_per_uc.csv", ios::in);
    //classesPerUCFile.open("C:\\Users\\Utilizador\\OneDrive\\Ambiente de Trabalho\\code\\CLion stuff\\PROJETO AED1\\cmake-build-default\\classes_per_uc.csv");

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
            "│ > Schedule                              [1] │\n"
            "│ > Student list                          [2] │\n"
            "│                                             │\n"
            "│ >Back [0]                         >Quit [q] │\n"
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
        if (stc.getCode() == classcode) {
            students = stc.getStudentSet();
            break;
        }
    }

    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│      NAME                UP                 │\n";


    for (Student st : students) {

        cout << "│      " << st.getName() << setw(20-st.getName().length())<<" "<<st.getCode()<<"          │\n";

    }

    cout << "│                                             │\n"
            "│                >Descending[1]               │\n"
            "│  >Back [0]                        >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
    string cmd;

    getline(cin, cmd);
    while(cmd!="0" && cmd!="q" && cmd!="1"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    if(cmd=="q") quit();
    if(cmd=="1") classStudentListDescending(classcode, uc, year, students);
    if (cmd=="0") scheduleORstudents(classcode, uc, year);

}

void Menu::classStudentListDescending(string classcode,UC uc,string year,set<Student> students) {
    skiplines();
    list<Student> lstdnts;
    for(auto ss:students) {
        lstdnts.push_back(ss);
    }
    lstdnts.sort(Student::descending);



    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Students                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│      NAME                UP                 │\n";


    for (Student st : lstdnts) {

        cout << "│      " << st.getName() << setw(20-st.getName().length())<<" "<<st.getCode()<<"          │\n";

    }

    cout << "│                                             │\n"
            "│                 Ascending[1]                │\n"
            "│  >Back [0]                        >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
    string cmd;

    getline(cin, cmd);
    while(cmd!="0" && cmd!="q" && cmd!="1"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    if(cmd=="q") quit();
    if(cmd=="1") classStudentList(classcode, uc, year);
    if (cmd=="0") scheduleORstudents(classcode, uc, year);
}

//-----------------------------------------QUICK-SEARCH----------------------------------------------------------------------
void Menu::QuickSearchDatabase() {
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                Quick Search                 │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│ >Get schedule                           [1] │\n"
            "│ >UC with the gretest number of students [2] │\n"
            "│ >Students registered in at least n UCs  [3] │\n"
            "│                                             │\n"
            "│  >Back [0]                        >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    while (cmd != "1" && cmd != "0" && cmd !="2" && cmd != "3" && cmd != "q") {
        cout << "Choose a valid option \n";
        getline(cin, cmd);
    }

    if (cmd == "q") cmd = "4";
    int operation = stoi(cmd);
    switch (operation) {
        case 0:
            run();
            break;
        case 1:
            Schedules1();
            break;
        case 2:
            BiggestUC();
            break;
        case 3:
            CountByMinimumUC();
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
            "│ > Search by Class                       [1] │\n"
            "│ > Search by Student                     [2] │\n"
            "│                                             │\n"
            "│  >Back [0]                        >Quit [q] │\n"
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
            "│                                   >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    StudentClass SC = StudentClass(cmd, {}, {});
    if(SC.readClassesFile()){
        SC.printSchedule();
    }else{
        cout<< "Student Class not found.\n\nBack [0]\nQuit[q]\n";
    }
    getline(cin, cmd);
    while(cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    if(cmd=="q") quit();
    if (cmd=="0") Schedules1();
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
            "│   >Back [0]                       >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;

    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") quit();
    int operation = stoi(cmd);

    switch (operation) {
        case 1:
            searchByStudentUP();
            break;
        case 2:
            searchByStudentName();
            break;
        case 0:
            Schedules1();
            break;
    }
    getline(cin, cmd);

    if(cmd=="q") quit();
    if (cmd=="0") Searchbystudent();
}

void Menu::searchByStudentName() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│           >Type the student Name to         │\n"
            "│               see his Schedule              │\n"
            "│     (Only use letters from the alphabet)    │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    Student st1 = Student("",cmd);
    st1.loadClassesperUCofStudentUsingNAME();
    if(st1.getName()!="-1"){
    st1.loadSchedule();
    st1.printSchedule();
    }
    else{
        cout<<"Student not found\n>Back[0]\n>Quit[q]";
    }
    getline(cin, cmd);
    while(cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="0") Schedules1();
    if(cmd=="q") quit();
}

void Menu::searchByStudentUP() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedules                  │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│            >Type the student UP             │\n"
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
    if(st1.getName()!="-1"){
    st1.loadSchedule();
    st1.printSchedule();
    }else{
        cout<<"Student not found\n>Back[0]\n>Quit[q]";
    }
    getline(cin, cmd);
    while(cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="0") Schedules1();
    if(cmd=="q") quit();
}

//----------------------------------------------------------MODIFY DATABASE-------------------------------------------------

void Menu::ModifyDatabase() {
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│              Modify Database                │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│ >Add Student                            [1] │\n"
            "│ >Remove Student                         [2] │\n"
            "│ >Switch Student                         [3] │\n"
            "│                                             │\n"
            "│  >Back [0]                        >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    if (cmd=="q") quit();
    if(cmd=="0") run();

    while(cmd!="1" && cmd!="2" && cmd!="3"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }

    int operation = stoi(cmd);

    switch (operation) {
        case 1:
            addStudent();
            break;
        case 2:
            RemoveStudentMenu();
            break;
    }
}




void Menu::RemoveStudentMenu() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│               Remove Student                │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│                                             │\n"
            "│          >Type the student UPcode           │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);

    cout << "╒═════════════════════════════════════════════╕\n"
            "│               Remove Student                │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│                                             │\n"
            "│           >Type the student Name            │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd2;
    getline(cin, cmd2);

    cout << "╒═════════════════════════════════════════════╕\n"
            "│               Remove Student                │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│            >Type the student UC             │\n"
            "│               (e.g:L.EIC021)                │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd3;
    getline(cin, cmd3);
    bool flag = removeStudent(cmd, cmd2, cmd3);
    if(flag) {
        cout << "╒═════════════════════════════════════════════╕\n"
                "│               Remove Student                │\n"
                "╞═════════════════════════════════════════════╡\n"
                "│                                             │\n"
                "│   "<<cmd2<<" has been removed from "<<cmd3<<" │\n"
                "│ >Back [0]                         >Quit [q] │\n"
                "╘═════════════════════════════════════════════╛\n"
                "                                               \n";
        getline(cin, cmd);
        while(cmd!="q" && cmd!="0"){
            cout<<"Choose a valid option \n";
            getline(cin, cmd);
        }
        if (cmd=="q") quit();
        if (cmd=="0") RemoveStudentMenu();
    }
    else if(!flag) {
        skiplines();
        cout<<"Not a valid UPcode/Name/UC\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while(cmd!="0" && cmd!="q"){
            cout<<"Choose a valid option \n";
            getline(cin, cmd);
        }
        if(cmd=="0") ModifyDatabase();
        if(cmd=="q") quit();


    }


}

void Menu::quit() {
    exit(0);
}
//--------------------------------------------------------(124)Students------------------------------------------------------





void Menu::CountByMinimumUC() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                Minimum Of UCs               │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│  Choose the minimum:                        │\n"
            "│                                             │\n"
            "│                                   >Quit [q] │\n"
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
            "│  >Back[0]                         >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    getline(cin, cmd);
    while(cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="0")QuickSearchDatabase();
    else if(cmd=="q")quit();
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
            "│    UC with the gretest number of students   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│                                             │\n";


    for (string UCc : ansUCCode) {

        cout << "│     "<<UCc<<"                                │\n";

    }

    cout << "│                                             │\n"
            "│ >Back [0]                         >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
    string cmd;
    getline(cin, cmd);
    while(cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") quit();
    if (cmd=="0") QuickSearchDatabase();

}

bool Menu::removeStudent(string code, string name, string UcCode) {
    std::ifstream arquivo_original("students_classes.csv");
    std::ofstream arquivo_temporario("temp.csv");

    bool flag=false;
    if (!arquivo_original.is_open() || !arquivo_temporario.is_open()) {
        std::cerr << "Erro ao abrir os ficheiros." << std::endl;
        quit();
    }

    std::string linha;
    while (std::getline(arquivo_original, linha)) {
        std::stringstream linha_stream(linha);
        std::string up, nm, uc, classcode;

        if (std::getline(linha_stream, up, ',') &&
            std::getline(linha_stream, nm, ',') &&
            std::getline(linha_stream, uc, ',') &&
            std::getline(linha_stream, classcode)) {

            // Verifica se a linha corresponde aos critérios de exclusão
            if (up!= code || nm != name || uc != UcCode) {
                arquivo_temporario << linha << std::endl;
            }
            else flag=true;
        }
    }

    arquivo_original.close();
    arquivo_temporario.close();

    remove("students_classes.csv");
    // Renomeie o arquivo temporário para o nome do arquivo original
    rename("temp.csv", "students_classes.csv");
    return flag;

}

//--------------------------------------------CLASSES---------------------------------------------------------------


void Menu::addStudent() {
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│              Add Student to UC              │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│   Use UP                                [1] │\n"
            "│   Use Name                              [2] │\n"
            "│                                             │\n"
            "│                                             │\n"
            "│   >Back [0]                       >Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;

    getline(cin, cmd);
    while(cmd!="1" && cmd!="2" && cmd!="0" && cmd!="q"){
        cout<<"Choose a valid option \n";
        getline(cin, cmd);
    }
    if(cmd=="q") quit();
    int operation = stoi(cmd);

    switch (operation) {
        case 1:
            if (addStudentByUP()) {
                cout << "Done!\n>Back[0]\n>Quit[q]";
                getline(cin, cmd);
                while (cmd != "0" && cmd != "q") {
                    cout << "Choose a valid option \n";
                    getline(cin, cmd);
                }
                if (cmd == "q") quit();
                else addStudent();
            } else {
                addStudent();
            }
            break;
        case 2:
            if (addStudentByName()) {
                cout << "Done!\n>Back[0]\n>Quit[q]";
                getline(cin, cmd);
                while (cmd != "0" && cmd != "q") {
                    cout << "Choose a valid option \n";
                    getline(cin, cmd);
                }
                if (cmd == "q") quit();
                else addStudent();
            } else {
                addStudent();
            }
            break;
    }
}
bool Menu::addStudentByName() {
    int studentUCs = 0;
    string UCcode;
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│              Add Student to UC              │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│            >Type the student Name           │\n"
            "│                                             │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    Student st1 = Student("", cmd);
    try {

        st1.getUPByName();
        st1.loadClassesperUCofStudentUsingNAME();
    } catch (logic_error) {
        return false;
    }
    if (st1.getName() == "-1") {
        cout << "Student not found\n\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while (cmd != "0" && cmd != "q") {
            cout << "Choose a valid option \n";
            getline(cin, cmd);
        }
        if (cmd == "0") addStudent();
        if (cmd == "q") quit();
        return false;
    }
    studentUCs = st1.getUCandClasses().size();
    if (studentUCs >= 7) {
        cout << "A student cant be registered in more than 7 UCs\n\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while (cmd != "0" && cmd != "q") {
            cout << "Choose a valid option \n";
            getline(cin, cmd);
        }
        if (cmd == "0") addStudent();
        if (cmd == "q") quit();
        return false;
    }
    //check if student is already in UC
    for(auto i: st1.getUCandClasses()) {
        if (i.first == UCcode) {
            cout << "Student already registered in this UC\n>Back[0]\n>Quit[q]";
            getline(cin, cmd);
            while(cmd!="0" && cmd!="q"){
                cout<<"Choose a valid option \n";
                getline(cin, cmd);
            }
            if(cmd=="0") addStudent();
            if(cmd=="q") quit();
            return false;
        }
    }
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│              Add Student to UC              │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│              >Type the UC code              │\n"
            "│                                             │\n"
            "│                (e.g:L.EIC001)               │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    getline(cin, cmd);
    if(!searchUC(cmd)){
        cout<<"UC not found\n\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while(cmd!="0" && cmd!="q"){
            cout<<"Choose a valid option \n";
            getline(cin, cmd);
        }
        if(cmd=="0") addStudent();
        if(cmd=="q") quit();
        return false;
    }
    UCcode=cmd;
    UC uc = UC(UCcode, {}, {});
    uc.Make();
    list<StudentClass> freeClasses= uc.freeStudentClasses();
    if(freeClasses.end()->getCapacity()-freeClasses.end()->getCapacity()>=4){
        return false;
    }
    writeToFile(st1.getCode(),st1.getName(),UCcode,freeClasses.begin()->getCode());
    return true;
}
bool Menu::addStudentByUP(){
    int studentUCs=0;
    string UCcode;
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│              Add Student to UC              │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│            >Type the student UP             │\n"
            "│                                             │\n"
            "│               (e.g:202012345)               │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    string cmd;
    getline(cin, cmd);
    Student st1 = Student(cmd,"");
    try{
        st1.getNameByUP();
        st1.loadClassesperUCofStudentUsingNAME();
    }catch(logic_error) {
        return false;
    }
    if(st1.getName()=="-1"){
        cout<<"Student not found\n\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while(cmd!="0" && cmd!="q"){
            cout<<"Choose a valid option \n";
            getline(cin, cmd);
        }
        if(cmd=="0") addStudent();
        if(cmd=="q") quit();
        return false;
    }
    studentUCs=st1.getUCandClasses().size();
    if(studentUCs>=7){
        cout<<"A student cant be registered in more than 7 UCs\n\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while(cmd!="0" && cmd!="q"){
            cout<<"Choose a valid option \n";
            getline(cin, cmd);
        }
        if(cmd=="0") addStudent();
        if(cmd=="q") quit();
        return false;
    }
    //check if student is already in UC
    for(auto i: st1.getUCandClasses()) {
        if (i.first == UCcode) {
            cout << "Student already registered in this UC\n>Back[0]\n>Quit[q]";
            getline(cin, cmd);
            while(cmd!="0" && cmd!="q"){
                cout<<"Choose a valid option \n";
                getline(cin, cmd);
            }
            if(cmd=="0") addStudent();
            if(cmd=="q") quit();
            return false;
        }
    }
    skiplines();
    cout << "╒═════════════════════════════════════════════╕\n"
            "│              Add Student to UC              │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│              >Type the UC code              │\n"
            "│                                             │\n"
            "│                (e.g:L.EIC001)               │\n"
            "│                                             │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                               \n";
    getline(cin, cmd);
    if(!searchUC(cmd)){
        cout<<"UC not found\n\n>Back[0]\n>Quit[q]";
        getline(cin, cmd);
        while(cmd!="0" && cmd!="q"){
            cout<<"Choose a valid option \n";
            getline(cin, cmd);
        }
        if(cmd=="0") addStudent();
        if(cmd=="q") quit();
        return false;
    }
    UCcode=cmd;
    UC uc = UC(UCcode, {}, {});
    uc.Make();
    list<StudentClass> freeClasses= uc.freeStudentClasses();
    if(freeClasses.end()->getCapacity()-freeClasses.end()->getCapacity()>=4){
        return false;
    }
    writeToFile(st1.getCode(),st1.getName(),UCcode,freeClasses.begin()->getCode());
    return true;
}

void Menu::writeToFile(string studentCode, string studentName, string UCCode, string classCode) {
    ofstream fileSC;                                    //of a student
    fileSC.open("students_classes.csv", std::ios::app);

    if (!fileSC.is_open()) {
        cerr << "ERROR: UNABLE TO OPEN STUDENT CLASSES FILE " << endl;
        return;
    }
    fileSC<<studentCode<<','<<studentName<<','<<UCCode<<','<<classCode<<'\n';
}

bool Menu::searchUC(string UcCode) {
    ifstream classesPerUCFile;

    classesPerUCFile.open("classes_per_uc.csv", ios::in);

    if(!classesPerUCFile.is_open()){
        cerr << "ERROR: UNABLE TO OPEN CLASSES PER UC FILE " << endl;
    }

    string dummy;
    string line;
    string UC_code;
    string class_code;

    getline(classesPerUCFile, dummy); //skip 1st line

    while(getline(classesPerUCFile, line)) {
        stringstream ss(line);

        getline(ss,UC_code,',');
        getline(ss,class_code);

        if(UC_code == UcCode){
            return true;
        }

    }

    classesPerUCFile.close();
    return false;
}