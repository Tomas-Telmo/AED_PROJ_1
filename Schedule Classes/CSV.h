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



set<Student> loadStudentsfromCSV(const string &file);   //students_classes.csv

map<string, set<StudentClass>> loadClassesperUCfromCSV(const string &file); //set<uccode,classcode> from classes_per_uc.csv
set<Class> loadClassesfromCSV(const string &file);                  //classes.csv



#endif //PROJETO_AED_1_CSV_H