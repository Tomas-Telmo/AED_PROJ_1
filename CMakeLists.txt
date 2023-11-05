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
        "Schedule Classes/Menu.cpp"
        "Schedule Classes/Menu.h"
)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)