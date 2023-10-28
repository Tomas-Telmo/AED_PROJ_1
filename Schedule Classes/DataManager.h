//
// Created by antero on 28-10-2023.
//

#ifndef PROJETO_AED_1_DATAMANAGER_H
#define PROJETO_AED_1_DATAMANAGER_H

#include "UC.h"
#include "Class.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>

class DataManager {
    set<Class> classes;
    set<Student> students;
    map<string, set<StudentClass>> ucs;

    string classesPerUcFile;
    string classesFile;
    string studentsClassesFile;

public:
    DataManager(const string& ucFile, const string& classFile, const string& studentsFile): classesPerUcFile(ucFile), classesFile(classFile), studentsClassesFile(studentsFile) {
        ifstream students_classes_file;
        students_classes_file.open(studentsFile);

        string line;
        string student_code;
        string student_name;
        string UC_code;
        string class_code;

        if(!students_classes_file.is_open()){
            cerr << "ERROR: Unable to open the file " << endl;
        }

        getline(students_classes_file,line); //skip 1st line

        while(getline(students_classes_file,line)){
            stringstream ss(line);

            getline(ss,student_code,',');
            getline(ss, student_name, ',');
            getline(ss,UC_code,',');
            getline(ss,class_code);

            Student st = Student(student_code, student_name);
            students.insert(st);

            StudentClass SC = StudentClass(class_code,{});
            SC.addStudent(st);
            set<StudentClass> ssc;
            ssc.insert(SC);

            if(ucs.count(UC_code)==0) {                 //acho q o map ucs está a receber mal as keys e valores

                ucs[UC_code]=ssc;
            }
            else {
                auto u = ucs[UC_code].find(class_code);
                if (ucs[UC_code].find(class_code)==ucs[UC_code].end()) {
                    ucs[UC_code].insert(SC);
                }
                else if(u->getStudents().find(st)!=u->getStudents().end()) {
                    u->getStudents().insert(st);
                }
            }
        }
        students_classes_file.close();
        //read 2 other files after
    }
    set<Student> getStudents() {return students;}
    map<string, set<StudentClass>> getUcs() {return ucs;}
};


#endif //PROJETO_AED_1_DATAMANAGER_H
