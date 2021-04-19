#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <deque>

#include "header.h"

using namespace std;


int main() {

    cout << "Generuojami 1000, 10 000, 100 000, 1 000 000, 10 000 000 ilgio sarasai... \n" << flush;
    
    generuotiSarasa(1000);
    generuotiSarasa(10000);
    generuotiSarasa(100000);
    generuotiSarasa(1000000);
    generuotiSarasa(10000000);

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

    cout << "Testuojama std::vector konteineris \n \n" << flush;

    matuotiLaikaVector(studentai1, 1000);
    vector<student>().swap(studentai1);

    matuotiLaikaVector(studentai2, 10000);
    vector<student>().swap(studentai2);

    matuotiLaikaVector(studentai3, 100000);
    vector<student>().swap(studentai3);

    matuotiLaikaVector(studentai4, 1000000);
    vector<student>().swap(studentai4);
    
    matuotiLaikaVector(studentai5, 10000000);
    vector<student>().swap(studentai5);
    

    list<student> studentai1L, studentai2L, studentai3L, studentai4L, studentai5L;
    cout << "Testuojama std::list konteineris \n \n" << flush;

    matuotiLaikaList(studentai1L, 1000);
    studentai1L.clear();

    matuotiLaikaList(studentai2L, 10000);
    studentai2L.clear();

    matuotiLaikaList(studentai3L, 100000);
    studentai3L.clear();

    matuotiLaikaList(studentai4L, 1000000);
    studentai4L.clear();

    matuotiLaikaList(studentai5L, 10000000);
    studentai5L.clear();

    cout << "Testuojama std::deque konteineris \n \n" << flush;

    deque<student> studentai1D, studentai2D, studentai3D, studentai4D, studentai5D;

    matuotiLaikaDeque(studentai1D, 1000);
    studentai1D.clear();

    matuotiLaikaDeque(studentai2D, 10000);
    studentai2D.clear();

    matuotiLaikaDeque(studentai3D, 100000);
    studentai3D.clear();

    matuotiLaikaDeque(studentai4D, 1000000);
    studentai4D.clear();

    matuotiLaikaDeque(studentai5D, 10000000);
    studentai5D.clear();



    return 0;
}


























