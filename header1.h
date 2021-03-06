#ifndef HEADER1_H 
#define HEADER1_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


struct student {
    std::string vardas;
    std::string pavarde;
    std::vector <double> nd;
    double egz = 0.0;
};

void sortArray(vector<student> &studentai);
void readFromFile(vector<student> &studentai);
void rasytiRanka(vector<student> &studentai);
bool isNumber(const string& s);
void rasytiRezultatus(vector<student> &studentai);





#endif /* HEADER_H */