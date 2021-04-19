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
#include "windows.h"
#include "psapi.h"


#include "header.h"

using namespace std;

void nuskaitytiDuomenis(vector<student> &studentai, int n) {
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
    studentai.shrink_to_fit();
    in.close();
    cout << "Failas uzdarytas" << endl;
}

void rusiuotiSarasa(vector<student> &studentai) {
    sort(studentai.begin(), studentai.end(),
    [] (const student& s1, const student& s2) ->bool {return s1.vid < s2.vid;});
}

void rusiuotiStudentus(vector<student> &studentai, vector<student> &kieti, vector<student> &blogi) {
    for(student &s: studentai) {
        if(s.vid >= 5) {
            kieti.push_back(s);
        } else {
            blogi.push_back(s);
        }
    }
    kieti.shrink_to_fit();
    blogi.shrink_to_fit();
}

void isvestiSarasa(vector<student> &studentai, string name) {
    ofstream of(name + ".txt");
    for(student &s: studentai) {
        of << setw(20) << left << s.vardas;
        of << setw(20) << left << s.pavarde;
        of << setw(20) << left << s.vid << endl;
    }
    of.close();
}

void generuotiSarasa(int n) {
    string name = "studentai";
    name += to_string(n);
    name += ".txt";
    ofstream of(name);
    string s1, s2;
    double t1, e;
    mt19937 mt(19937);
    uniform_int_distribution<int> dist(0, 10);
    for(int i = 0; i < n; i++) {
        srand(time(0));
        s1 = "Vardas" + to_string(i);
        s2 = "Pavarde" + to_string(i);
        of << setw(15) << left << s1 << setw(15) << left << s2;
        t1 = dist(mt);
        of << setw(15) << left << t1;
        e = dist(mt);
        of << setw(15) << left << e << "\n";
    }
    of.close();
    cout << to_string(n) + "  sarasas sugeneruotas" << "\n" << flush;

}

void matuotiLaikaVector(vector<student> &studentai, int n) {

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

    vector<student> blogi(n);
    t1 = high_resolution_clock::now();
    rusiuotiStudentusVector(studentai, blogi);
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

    vector<student>().swap(blogi);

    cout << to_string(n) + " dydzio saraso testas uztruko:  " + to_string(laikas) << flush;
    cout << "\n" << flush;
    cout << "-----------------------------------------------------------------\n" << flush;


}



