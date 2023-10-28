#include "UC.h"
#include <sstream>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

UC::UC(string UcCode_, set<StudentClass> UcClasses_) {
    this->UcCode = UcCode_;
    this->UcClasses = UcClasses_;
}

UC::UC(const UC &uc) {
    this->UcClasses = uc.UcClasses;
    this->UcCode = uc.UcCode;
}

string UC::getUCCode() {
    return this->UcCode;
}

set<StudentClass> UC::getUcClasses() {
    return this->UcClasses;
}

int UC::getNumberOfClasses() {
    return this->UcClasses.size();
}

void UC::setUcCode(string uccode) {
    this->UcCode = uccode;
}

void UC::setUcClasses(set<StudentClass> UcClasses_) {
    this->UcClasses = UcClasses_;
}

void UC::addStudentClass(StudentClass stdtClass) {
    this->UcClasses.insert(stdtClass);
}

bool UC::operator<(const UC &other) const {
    return this->UcCode < other.UcCode;
}


//read file classes per uc -------> COMES FIRST!!!
void UC::read_ClassesPerUCFile(ifstream &filename) {
    string dummy;
    string line;
    string UC_code;
    string class_code;

    if(!filename.is_open()){
        cerr << "ERROR: Couldn't open the file " << endl;
    }

    getline(filename,dummy); //skip 1st line

    while(getline(filename,line)) {
        stringstream ss(line);

        getline(ss,UC_code,',');
        getline(ss,class_code);

        if(UC_code == UcCode){
            UcClasses.insert(StudentClass(class_code));
        }

    }
}

//read file student classes

void UC::read_StudentsClassesFile(ifstream &filename) {
    string dummy;
    string line;
    string student_code;
    string student_name;
    string UC_code;
    string class_code;

    if(!filename.is_open()){
        cerr << "ERROR: Unable to open the file " << endl;
    }

    getline(filename,dummy); //skip 1st line

    while(getline(filename,line)){
        stringstream ss(line);

        getline(ss,student_code,',');
        getline(ss, student_name, ',');
        getline(ss,UC_code,',');
        getline(ss,class_code);

        if(UC_code == UcCode){
            for(StudentClass stc : UcClasses ){
                if(stc.getCode() == class_code){
                    stc.addStudent(Student(student_code,student_name));
                }
            }
        }

    }
}

