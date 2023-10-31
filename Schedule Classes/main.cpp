#include <iostream>
#include <fstream>
#include <string>
#include "UC.h"
#include "StudentClass.h"
#include "CSV.h"
#include "Menu.h"

using namespace std;
int main() {
    CSV cs= CSV();
    auto cl=cs.loadClassesperUCfromCSV();
    for(auto i:cl){
        cout<<i.first;
    }


    return 0;
}