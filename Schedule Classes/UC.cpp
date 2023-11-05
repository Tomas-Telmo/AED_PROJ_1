#include "UC.h"
#include <sstream>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

UC::UC(string UcCode_,set<StudentClass> class_set_, list<StudentClass> class_list_ ) {
    this->UcCode = UcCode_;
    this->studentclassSet = class_set_;
    this->studentclassList = class_list_;
}

UC::UC(const UC &uc) {
    this->studentclassSet = uc.studentclassSet;
    this->UcCode = uc.UcCode;
    this->studentclassList = uc.studentclassList;
}

string UC::getUCCode() const {
    return this->UcCode;
}

set<StudentClass> UC::getStudentClassSet() const {
    return this->studentclassSet;
}

list<StudentClass> UC::getStudentClassList() const {
    return this->studentclassList;
}

int UC::getNumberOfClasses() const {
    return this->studentclassSet.size();
}

void UC::setUcCode(string uccode) {
    this->UcCode = uccode;
}

void UC::setUcClasses(set<StudentClass> UcClasses_) {
    this->studentclassSet = UcClasses_;
}

void UC::addStudentClass(StudentClass stdtClass) {
    this->studentclassSet.insert(stdtClass);
}

bool UC::operator<(const UC &other) const {
    return this->UcCode < other.UcCode;
}

//read file classes per uc -------> COMES FIRST!!!
void UC::readClassesPerUCFile() {
    ifstream classesPerUCFile;

    classesPerUCFile.open("classes_per_uc.csv", ios::in);
    //classesPerUCFile.open("C:\\Users\\Utilizador\\OneDrive\\Ambiente de Trabalho\\code\\CLion stuff\\PROJETO AED1\\cmake-build-default\\classes_per_uc.csv");

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
            studentclassList.push_back(StudentClass(class_code, {},{}));
        }

    }

    classesPerUCFile.close();
}

//read file student classes

void UC::readStudentsClassesFile() {
    auto it = studentclassList.begin();

    while (it != studentclassList.end()) {
        StudentClass temp (*it);
        temp.readStudentsClassesFile(UcCode);
        temp.readClassesFile();
        studentclassSet.insert(temp);
        it++;
    }

}

//make

void UC::Make() {
    this->readClassesPerUCFile();
    this->readStudentsClassesFile();
}






list<StudentClass> UC::freeStudentClasses(){
    list<StudentClass> ans;
    this->readStudentsClassesFile();
    for(auto i : this->getStudentClassSet()){
        i.readStudentsClassesFile(i.getCode());
        cout<<i.getCode()<<' '<<i.getCapacity();
        if(i.getCapacity()<MAX_STUDENTS)ans.push_back(i);
    }
    ans.sort([](const StudentClass& std1, const StudentClass& std2) {
        return std1.getCapacity() < std2.getCapacity();
    });
    return ans;
}

