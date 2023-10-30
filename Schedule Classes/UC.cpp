#include "UC.h"
#include <sstream>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

UC::UC(string UcCode_,set<StudentClass> class_set_, list<StudentClass> class_list_ ) {
    this->UcCode = UcCode_;
    this->class_set = class_set_;
    this->class_list = class_list_;

}

UC::UC(const UC &uc) {
    this->class_set = uc.class_set;
    this->UcCode = uc.UcCode;
    this->class_list = uc.class_list;
}

string UC::getUCCode() const {
    return this->UcCode;
}

set<StudentClass> UC::getClassSet() const {
    return this->class_set;
}

list<StudentClass> UC::getClassList() const {
    return this->class_list;
}

int UC::getNumberOfClasses() const {
    return this->class_set.size();
}

void UC::setUcCode(string uccode) {
    this->UcCode = uccode;
}

void UC::setUcClasses(set<StudentClass> UcClasses_) {
    this->class_set = UcClasses_;
}

void UC::addStudentClass(StudentClass stdtClass) {
    this->class_set.insert(stdtClass);
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
            class_list.push_back(StudentClass(class_code,{}));
        }

    }
}

//read file student classes

void UC::read_StudentsClassesFile(ifstream &filename) {
    auto it = class_list.begin();

    while (it != class_list.end()) {
        StudentClass temp (*it);
        temp.readFile(filename,UcCode);
        class_set.insert(temp);
        it++;
    }

}
