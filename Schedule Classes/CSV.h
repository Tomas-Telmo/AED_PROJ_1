//
// Created by antero on 28-10-2023.
//

#ifndef PROJETO_AED_1_CSV_H
#define PROJETO_AED_1_CSV_H

#include "UC.h"
#include "Class.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

class CSV {
    set<Class> classes;
    set<Student> students;
    map<string, set<StudentClass>> ucs;

public:
    CSV() {
        classes = loadClassesfromCSV();
        students = loadStudentsfromCSV();
        ucs = loadClassesperUCfromCSV();
    }

    set<Class> getClasses() { return classes;}
    set<Student> getStudent() { return students;}
    

    set<Class> loadClassesfromCSV();//classes.csv
    set<Student> loadStudentsfromCSV();   //students_classes.csv
    map<string, set<StudentClass>> loadClassesperUCfromCSV(); //set<uccode,classcode> from classes_per_uc.csv

    vector<Class> getSchedule(string); //string is the classcode



};


#endif //PROJETO_AED_1_CSV_H