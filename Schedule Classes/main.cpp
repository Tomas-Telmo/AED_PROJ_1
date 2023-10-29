#include <iostream>
#include <fstream>
#include <string>
#include "UC.h"
#include "StudentClass.h"
#include "CSV.h"

using namespace std;
int main() {
    /*ifstream classes_per_uc_file;
    ifstream students_classes_file;
    UC uc = UC("L.EIC001", {});

    //read and parse 1st file-------------

    classes_per_uc_file.open("/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/classes_per_uc.csv");

    if (!classes_per_uc_file.is_open()) {
        cerr << "ERROR:CLASSES_PER_UC DIDNT OPEN" << std::endl;
    }


    uc.read_ClassesPerUCFile(classes_per_uc_file);
    classes_per_uc_file.close();

    //read and parse 2nd file------------

    students_classes_file.open("/home/antero/Desktop/FEUP_UBUNTO/AED/proj_aed_git/Schedule Classes/students_classes.csv");

    if (!students_classes_file.is_open()) {
        cerr << "ERROR:STUDENTS_CLASSES DIDNT OPEN" << std::endl;
    }

    uc.read_StudentsClassesFile(students_classes_file);
    students_classes_file.close();

    //-------------------------------



    cout << uc.getUcClasses().size()<<endl;

    for(const auto& stc : uc.getUcClasses()){
        cout<< stc.getStudents().size();  //???? EMPTY FOR SOME REASON
        for(const auto& st : stc.getStudents()){
            cout<< st.getCode()<<','<<st.getName()<<endl;
        }
    }
    */


    return 0;
}