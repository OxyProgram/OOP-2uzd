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

    int n;
    vector<student> studentai;
    studentai.reserve(n);
    double laikas = 0.0;

    cout << "Iveskite saraso dydi:  " << flush;
    try {
        cin >> n;
    } catch(exception e) {
        cout << "Pasirinktas blogas skaicius!" << "\n";
    }
    

    generuotiSarasa(n);

    auto t1 = high_resolution_clock::now();
    nuskaitytiDuomenis(studentai, n);
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    cout << "Failo nuskaitymas uztruko:  " << ms_double.count() << endl;
    laikas += ms_double.count();
    ms_double = std::chrono::milliseconds::zero();

    t1 = high_resolution_clock::now();
    rusiuotiSarasa(studentai);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Saraso rusiavimas su sort funkcija uztruko:  " << ms_double.count() << endl;
    laikas += ms_double.count();
    ms_double = std::chrono::milliseconds::zero();

    vector<student> kieti;
    vector<student> blogi;
    t1 = high_resolution_clock::now();
    rusiuotiStudentus(studentai, kieti, blogi);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Iraso padalijimas i du uztruko:  " << ms_double.count() << endl;
    laikas += ms_double.count();
    ms_double = std::chrono::milliseconds::zero();

    t1 = high_resolution_clock::now();
    isvestiSarasa(kieti, "kieti");
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Kietu studentu saraso irasymas i faila uztruko:  " << ms_double.count() << endl;
    laikas += ms_double.count();
    ms_double = std::chrono::milliseconds::zero();

    t1 = high_resolution_clock::now();
    isvestiSarasa(blogi, "blogi");
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Blogu studentu saraso irasymas i faila uztruko:  " << ms_double.count() << endl;
    laikas += ms_double.count();
    ms_double = std::chrono::milliseconds::zero();
    cout << endl;

    cout << to_string(n) + " dydzio saraso testas uztruko:  " + to_string(laikas) << endl;






    // Atlaisvinama atmintis
    vector<student>().swap(studentai);
    vector<student>().swap(kieti);
    vector<student>().swap(blogi);
    return 0;
}


























