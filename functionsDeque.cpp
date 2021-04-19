#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <sstream>
#include <random>
#include <numeric>
#include <deque>
#include "windows.h"
#include "psapi.h"

#include "header.h"

using namespace std;

void nuskaitytiDuomenis(deque<student> &studentai, int n) {
    string name = "studentai";
    name += to_string(n);
    name += ".txt";
    ifstream in(name);
    if(in.fail()) {
        cout << "Failo atidaryti nepavyko!" << "\n";
        return;
    }

    student temp;
    string vardas, pavarde, l;
    double egz, t1;

    for(string l; getline(in, l); ) {
        istringstream iss(l);

        iss >> vardas >> pavarde >> t1 >> egz;

        temp.vardas = vardas;
        temp.pavarde = pavarde;
        temp.vid = t1*0.4 + egz*0.6;

        studentai.push_back(temp);
    }
    in.close();
    cout << "Failas uzdarytas" << endl;
}

void rusiuotiSarasa(deque<student> &studentai) {
    sort(studentai.begin(), studentai.end(),
    [] (const student& s1, const student& s2) ->bool {return s1.vid < s2.vid;});
}

void rusiuotiStudentus(deque<student> &studentai, deque<student> &blogi) {
    for(student &s: studentai) {
        if(s.vid < 5) {
            blogi.push_back(s);
        }
    }
    partition(studentai.begin(), studentai.end(), isBlogas);
}

void isvestiSarasa(deque<student> &studentai, string name) {
    ofstream of(name + ".txt");
    for(student &s: studentai) {
        of << setw(20) << left << s.vardas;
        of << setw(20) << left << s.pavarde;
        of << setw(20) << left << s.vid << endl;
    }
    of.close();
}

void matuotiLaikaDeque(deque<student> &studentai, int n) {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;    

    double laikas = 0.0;

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

    deque<student> blogi;
    t1 = high_resolution_clock::now();
    rusiuotiStudentus(studentai, blogi);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    cout << "Iraso padalijimas i du uztruko:  " << ms_double.count() << endl;
    laikas += ms_double.count();
    ms_double = std::chrono::milliseconds::zero();

    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
	double mem = virtualMemUsedByMe;
	double base = mem;

    cout << "Memory usage: " << mem / 1024 / 1024 << " MB" << endl;

    blogi.clear();

    cout << to_string(n) + " dydzio saraso testas uztruko:  " + to_string(laikas) << flush;
    cout << "\n" << flush;
    cout << "-----------------------------------------------------------------\n" << flush;


}