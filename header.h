#ifndef HEADER_H
#define HEADER_H

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
    string vardas;
    string pavarde;
    double vid = 0.0;
};

void nuskaitytiDuomenis(vector<student> &studentai, int n);
void rusiuotiSarasa(vector<student> &studentai);
void rusiuotiStudentus(vector<student> &studentai, vector<student> &kieti, vector<student> &blogi);
void isvestiSarasa(vector<student> &studentai, string name);
void generuotiSarasa(int n);
void matuotiLaika(vector<student> &studentai, int n);




#endif /* HEADER_H */
