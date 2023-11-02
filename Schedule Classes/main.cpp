#include <iostream>
#include <fstream>
#include <string>
#include "UC.h"
#include "Menu.h"




using namespace std;
int main() {
/*
    UC uc = UC("L.EIC001", {},{});

    uc.readClassesPerUCFile();
    uc.readStudentsClassesFile();
    //-------------------------------

    cout << uc.getStudentClassSet().size()<<endl;
    cout << uc.getStudentClassList().size()<<endl;

    for(const auto& stc : uc.getStudentClassSet()){

        cout<< "turma: "<< stc.getCode() << " tem "<< stc.getStudentSet().size() << " alunos" << endl;

        for (auto c : stc.getScheduleList()) {
            cout<<c.getUcCode()<<' '<<c.getWeekday()<<' '<<c.getStarthour()<<' '<< c.getType()<<'\n';

        }
        //for(const auto& st : stc.getStudents()){
        //   cout<< st.getCode()<<','<<st.getName()<<endl;
        //}

    }

    //--------------------------------------------------------------

    Student st = Student("", "Manuel Serafim");
    st.loadClassesperUCofStudentUsingNAME();
    for(auto p:st.getUCandClasses()) {
        cout<<p.first<<p.second<<'\n';
    }
    st.loadSchedule();
    for(auto p:st.getSchedule()) {
        cout<<p.getWeekday()<<p.getUcCode()<<'\n';
    }
    cout<<"\n\n\n\n\n";
    st.printSchedule();*/

    Menu menu=Menu();
    menu.run();
    return 0;

}
