#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <sstream>
#include <random>

#include "header.h"

using namespace std;

void rusiuotiStudentusVector(vector<student>& studentai, vector<student>& blogi) {

    remove_copy_if(studentai.begin(), studentai.end(), blogi.begin(), isBlogas);

}


bool isBlogas(student &s) {
    return s.vid < 5;
}

