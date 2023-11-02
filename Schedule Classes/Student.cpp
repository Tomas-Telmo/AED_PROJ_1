#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include "Student.h"
#include "Menu.h"

Student::Student(string code_, string name_) {
    this->code = code_;
    this->name = name_;
}

Student::Student(const Student &student) {
    this->code = student.code;
    this->name = student.name;
}

string Student::getCode() const{
    return this->code;
}

string Student::getName() const {
    return this->name;
}

list<pair<string,string>> Student::getUCandClasses() {
    return UCandClasses;
}

list<Class> Student::getSchedule() {
    return schedule;
}

void Student::setCode(string code_) {
    this->code = code_;
}

void Student::setName(std::string name_) {
    this->name = name_;
}

bool Student::operator<(const Student &other) const {
    return this->code < other.code;
}

void Student::getNameByUP() {
    ifstream fileSC;                                    //of a student
    fileSC.open("students_classes.csv");

    if (!fileSC.is_open()) {
        cerr << "ERROR: UNABLE TO OPEN STUDENT CLASSES FILE " << endl;
        return;
    }

    string line;
    string student_code;
    string student_name;
    string UCcode;
    string ClassCode;


    getline(fileSC,line); //skip 1st line

    while(getline(fileSC,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,UCcode,',');
        getline(ss,ClassCode);

        if(code == student_code){
            name = student_name;
        }
    }
    fileSC.close();
}



void Student::loadClassesperUCofStudentUsingNAME() {    //creates a list of pairs <uccode, classcode>
    ifstream fileSC;                                    //of a student
    fileSC.open("students_classes.csv");

    if (!fileSC.is_open()) {
        cerr << "ERROR: UNABLE TO OPEN STUDENT CLASSES FILE " << endl;
        return;
    }
    bool found=false;
    string line;
    string student_code;
    string student_name;
    string UCcode;
    string ClassCode;


    getline(fileSC,line); //skip 1st line

    while(getline(fileSC,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,UCcode,',');
        getline(ss,ClassCode);



        if(name == student_name){
            UCandClasses.push_back(pair(UCcode, ClassCode));
            found= true;
        }
    }
    if(!found){
        this->name="-1";
    }
    fileSC.close();
}

void Student::loadSchedule() {
    ifstream classes_file;
    classes_file.open("classes.csv");

    string line;
    string weekday;
    double starthour;
    double duration;
    string type;
    string classCode;
    string UcCode;

    if (!classes_file.is_open()) {
        cerr << "ERROR: UNABLE TO OPEN CLASSES FILE" << endl;
    }

    getline(classes_file, line);

    while (getline(classes_file, line)) {
        stringstream ss(line);

        getline(ss, classCode, ',');
        getline(ss, UcCode, ',');
        getline(ss, weekday, ',');

        string startHourStr, durationStr;

        getline(ss, startHourStr, ',');
        getline(ss, durationStr, ',');
        getline(ss, type, ',');

        starthour = stod(startHourStr);
        duration = stod(durationStr);

        for (auto p : UCandClasses) {
            if (UcCode==p.first && classCode == p.second) {
                Class cl = Class(weekday, starthour, duration, type, classCode, UcCode);
                schedule.push_back(cl);
            }
        }
    }
    schedule.sort();
    classes_file.close();
}

void Student::printSchedule() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedule                   │\n"
            "╞═════════════════════════════════════════════╡\n";
    cout<<  "│              Name:  "<<name<<" "<<setw(27-name.length())<<"│\n";

    // Define the weekdays in the desired order
    vector<string> weekdays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (const string& weekday : weekdays) {
        int len = 42-weekday.length();
        cout << "│      " << weekday << " "<<setw(len)<<"│\n";

        for (auto cls : schedule) {
            if (cls.getWeekday() == weekday) {
                string starthourstr = fromdoubletohour(cls.getStarthour());
                string endhourstr = fromdoubletohour(cls.getStarthour()+cls.getDuration());
                string hours = starthourstr + "-" + endhourstr;
                int len2 = 10-cls.getUcCode().length();
                int len3=15-hours.length();
                cout << "│           " << cls.getUcCode()<<setw(len2)<< "  ";
                cout<< hours<<setw(len3);
                cout<<cls.getType()<<" "<<setw(11) <<"│"<<'\n';

            }
        }
    }

    cout << "│  Back [0]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
}


string Student::fromdoubletohour(double num) {
    int hours = num/1;
    int mins = (num - hours)*60;
    if (mins!=0) {
        return to_string(hours) + ":" + to_string(mins) ;
    }
    return to_string(hours) + ":00";

}









