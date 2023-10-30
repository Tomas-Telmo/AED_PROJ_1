#include <iostream>
#include <fstream>
#include <string>
#include "UC.h"
#include "StudentClass.h"
#include "CSV.h"

using namespace std;
int main() {
    ifstream classes_per_uc_file;
    ifstream students_classes_file;

    UC uc = UC("L.EIC002", {},{});

    //read and parse 1st file-------------

    classes_per_uc_file.open("C:\\Users\\Utilizador\\OneDrive\\Ambiente de Trabalho\\code\\CLion stuff\\projeto1-AED\\Schedule Classes\\classes_per_uc.csv");

    if (!classes_per_uc_file.is_open()) {
        cerr << "ERROR:CLASSES_PER_UC DIDNT OPEN" << std::endl;
    }

    uc.read_ClassesPerUCFile(classes_per_uc_file);
    classes_per_uc_file.close();

    //read and parse 2nd file------------

    students_classes_file.open("C:\\Users\\Utilizador\\OneDrive\\Ambiente de Trabalho\\code\\CLion stuff\\projeto1-AED\\Schedule Classes\\students_classes.csv");

    if (!students_classes_file.is_open()) {
        cerr << "ERROR:STUDENTS_CLASSES DIDNT OPEN" << std::endl;
    }

    uc.read_StudentsClassesFile(students_classes_file);
    students_classes_file.close();

    //-------------------------------

    cout << uc.getClassSet().size()<<endl;
    cout << uc.getClassList().size()<<endl;

    for(const auto& stc : uc.getClassSet()){
        cout<< stc.getStudents().size()<<endl;  //funcemina
        for(const auto& st : stc.getStudents()){
            cout<< st.getCode()<<','<<st.getName()<<endl;
        }
    }

    return 0;
}