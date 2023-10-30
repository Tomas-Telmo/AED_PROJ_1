//
// Created by antero on 28-10-2023.
//

#include "CSV.h"



set<Student> loadStudentsfromCSV(const string &file) {  //students_classes.csv
    ifstream students_classes_file;
    students_classes_file.open(file);

    string line;
    string student_code;
    string student_name;
    set<Student> Students;


    if (!students_classes_file.is_open()) {
        cerr << "ERROR: Unable to open the file " << endl;
    }

    getline(students_classes_file, line); //skip 1st line

    while (getline(students_classes_file, line)) {
        stringstream ss(line);

        getline(ss, student_code, ',');
        getline(ss, student_name, ',');


        Student st = Student(student_code, student_name);
        Students.insert(st);

    }
    return Students;
}


map<string, set<StudentClass>> loadClassesperUCfromCSV(const string &file) { //set<uccode,classcode> from classes_per_uc.csv
    ifstream classes_per_uc_file;
    classes_per_uc_file.open(file);

    map<string, set<StudentClass>> UCclasses;
    string line;
    string uccode;
    string classcode;

    if (!classes_per_uc_file.is_open()) {
        cerr << "ERROR: Unable to open the file " << endl;
    }

    getline(classes_per_uc_file, line);

    while (getline(classes_per_uc_file, line)) {
        stringstream ss(line);

        getline(ss, uccode, ',');
        getline(ss, classcode, ',');

        bool uc_already_in = false;
        for(auto p: UCclasses) {
            if (p.first==uccode) {
               // UCclasses[uccode].insert(StudentClass(classcode));
                uc_already_in = true;
            }
        }
        //if(!uc_already_in) {
        //    UCclasses[uccode]={classcode};
        //}

    }
    return UCclasses;
}


set<Class> loadClassesfromCSV(const string &file) {
    ifstream classes_file;
    classes_file.open(file);

    set<Class> Classes;
    string line;
    string weekday;
    double starthour;
    double duration;
    string type;
    string classCode;
    string UcCode;

    if (!classes_file.is_open()) {
        cerr << "ERROR: Unable to open the file " << endl;
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

        Class cl= Class(weekday, starthour, duration, type, classCode, UcCode);
        Classes.insert(cl);

    }
    return Classes;
}
