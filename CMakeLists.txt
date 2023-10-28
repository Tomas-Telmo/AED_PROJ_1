cmake_minimum_required(VERSION 3.26)
project(Projeto_AED_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto_AED_1 "Schedule Classes/main.cpp"
        "Schedule Classes/Student.h"
        "Schedule Classes/Student.cpp"
        "Schedule Classes/StudentClass.h"
        "Schedule Classes/StudentClass.cpp"
        "Schedule Classes/UC.h"
        "Schedule Classes/UC.cpp"
        "Schedule Classes/Class.h"
        "Schedule Classes/Class.cpp"
)
