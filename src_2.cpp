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

#include "header.h"

using namespace std;

void nuskaitytiDuomenis(vector<student> &studentai, int n) {
    string name = "studentai";
    name += to_string(n);
    name += ".txt";
    ifstream in(name);
    try {
        if(!in.is_open())
            throw new exception;
    } catch (exception e) {
        cout << "failas neatidarytas!" << endl;
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

    // while (getline(in, t)) {
    //     istringstream iss(t);

    //     iss >> vardas >> pavarde;
    //     iss >> t1;
    //     cout << vardas + "  " <<pavarde;

    //     iss >> egz;
    //     temp.vardas = vardas;
    //     temp.pavarde = pavarde;
    //     temp.vid = t1*0.4 + egz*0.6;
    //     studentai.push_back(temp);
    // }
    in.close();
    cout << "Failas uzdarytas" << endl;
}

void rusiuotiSarasa(vector<student> &studentai) {
    sort(studentai.begin(), studentai.end(),
    [] (const student& s1, const student& s2) ->bool {return s1.vid < s2.vid;});
}

void rusiuotiStudentus(vector<student> &studentai, vector<student> &kieti, vector<student> &blogi) {
    for(student s: studentai) {
        if(s.vid >= 5) {
            kieti.push_back(s);
        } else {
            blogi.push_back(s);
        }
    }
}

void isvestiSarasa(vector<student> &studentai, string name) {
    ofstream of(name + ".txt");
    for(student s: studentai) {
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
    for(int i = 0; i < n; i++) {
        s1 = "Vardas" + to_string(i);
        s2 = "Pavarde" + to_string(i);
        of << setw(15) << left << s1 << setw(15) << left << s2;
        t1 = 1 + rand() % 10;
        of << setw(15) << left << t1;
        e = 1 + rand() % 10;
        of << setw(15) << left << e << "\n";
    }
    of.close();
    cout << "sarasas sugeneruotas" << "\n" << flush;

}