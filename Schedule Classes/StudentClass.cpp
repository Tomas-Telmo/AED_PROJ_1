#include <sstream>
#include "StudentClass.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>



StudentClass::StudentClass(string code_, set<Student> studentSet_, list<Class> scheduleList_){
    this->code = code_;
    this->studentSet = studentSet_;
    this->scheduleList = scheduleList_;
}

StudentClass::StudentClass(const StudentClass &studentclass) {
    this->code = studentclass.code;
    this->studentSet = studentclass.studentSet;
}

set <Student> StudentClass::getStudentSet() const {
    return this->studentSet;
}

list<Class> StudentClass::getScheduleList() const{
    return scheduleList;
}

string StudentClass::getCode() const {
    return this->code;
}

int StudentClass::getCapacity() const {
    return this->studentSet.size();
}

void StudentClass::setCode(string code_) {
    this->code = code_;
}

void StudentClass::setStudents(set<Student> students_) {
    this->studentSet = students_;
}

void StudentClass::addStudent(Student student) {
    this->studentSet.insert(student);
}

bool StudentClass::operator<(const StudentClass &other) const {
    return this->code < other.code;
}


void StudentClass::readStudentsClassesFile(string UCcode) {

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


    getline(students_classes_file,dummy); //skip 1st line

    while(getline(students_classes_file,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,FileUCcode,',');
        getline(ss,FileClassCode);

        if(FileUCcode == UCcode){
            if(code == FileClassCode){
                Student student(student_code,student_name);
                studentSet.insert(student);
            }
        }
    }
    students_classes_file.close();
}

void StudentClass::readClassesFile() {
    ifstream classes_file;
    classes_file.open("classes.csv");

    set<Class> Classes;
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

        std::string startHourStr, durationStr;

        getline(ss, startHourStr, ',');
        getline(ss, durationStr, ',');
        getline(ss, type, ',');

        starthour = stod(startHourStr);
        duration = stod(durationStr);

        if (code == classCode) {
            
            Class cl = Class(weekday, starthour, duration, type, classCode, UcCode);
            scheduleList.push_back(cl);
        }
    }
    scheduleList.sort();
    classes_file.close();
}

void StudentClass::printSchedule() {
    cout << "╒═════════════════════════════════════════════╕\n"
            "│                  Schedule                   │\n"
            "╞═════════════════════════════════════════════╡\n"
            "│               Turma: "<<code<<"                │\n";

    // Define the weekdays in the desired order
    vector<string> weekdays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (const string& weekday : weekdays) {
        int len = 42-weekday.length();
        cout << "│      " << weekday << " "<<setw(len)<<"│\n";

        for (auto cls : scheduleList) {
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

    cout << "│  Back [1]                          Quit [q] │\n"
            "╘═════════════════════════════════════════════╛\n"
            "                                           \n";
}

string StudentClass::fromdoubletohour(double num) {
    int hours = num/1;
    int mins = (num - hours)*60;
    if (mins!=0) {
        return to_string(hours) + ":" + to_string(mins) ;
    }
    return to_string(hours) + ":00";

}


