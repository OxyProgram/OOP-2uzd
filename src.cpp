#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include <chrono>

#include "header.h"

using namespace std;


int main() {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    vector<student> studentai1, studentai2, studentai3, studentai4, studentai5;
    studentai1.reserve(1000);
    studentai1.reserve(10000);
    studentai1.reserve(100000);
    studentai1.reserve(1000000);
    studentai1.reserve(10000000);
    double laikas = 0.0;

    cout << "Generuojami 1000, 10 000, 100 000, 1 000 000, 10 000 000 ilgio sarasai... \n" << flush;
    
    generuotiSarasa(1000);
    generuotiSarasa(10000);
    generuotiSarasa(100000);
    generuotiSarasa(1000000);
    generuotiSarasa(10000000);

    matuotiLaika(studentai1, 1000);
    matuotiLaika(studentai2, 10000);
    matuotiLaika(studentai3, 100000);
    matuotiLaika(studentai4, 1000000);
    matuotiLaika(studentai5, 10000000);

    // Atlaisvinama atmintis
    vector<student>().swap(studentai1);
    vector<student>().swap(studentai2);
    vector<student>().swap(studentai3);
    vector<student>().swap(studentai4);
    vector<student>().swap(studentai5);

    return 0;
}


























