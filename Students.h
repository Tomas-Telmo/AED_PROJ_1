//
// Created by antero on 25-10-2023.
//

#ifndef PROJETO_AED_1_STUDENT_H
#define PROJETO_AED_1_STUDENT_H

#include <string>
#include <vector>

struct Student {
    int studentcode;
    std::string studentname;
};

class Students {
        std::vector<Student> students;
    public:
        void readFromFile(FILE filename);
        void addToStudents(Student student);

};


#endif //PROJETO_AED_1_STUDENT_H
