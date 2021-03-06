#include "header1.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>

using namespace std;

void sortArray(vector<student> &studentai) {
    int n=studentai.size();
    sort(studentai.begin(), studentai.end(),
    [] (const student& s1, const student& s2) ->bool {return s1.vardas < s2.vardas;});
}

void readFromFile(vector<student> &studentai) {

    cout << "Irasykite .txt failo pavadinima:    " << flush;
    string s;
    try {
        cin >> s;
    } catch (exception e) {
        cout << "Ivyko klaida!" << endl;
    }

    int k = 0;

    ifstream in;
    try {
        in.open(s.c_str());
        if(!in.is_open())
            return;
    } catch (exception e) {
        cout << "Ivyko klaida! Failo atidaryti negalima!" << endl;
        cin >> s;
    }


    string t;
    getline(in, t);
    istringstream iss_temp(t);
    iss_temp >> t;
    iss_temp >> t;
    while(true) {
        iss_temp >> t;
        if(t.substr(0, 2) == "ND") {
            k++;
        } else {
            break;
        }
    }

    student temp; //Temporary student object

    string vardas, pavarde;
    vector <double> nd;
    int egz, t1;
    while (getline(in, t)) {
        istringstream iss(t);

        iss >> vardas >> pavarde;
        for(int i = 0; i < k; i++) {
            iss >> t1;
            nd.push_back(t1);
        }

        iss >> egz;

        temp.vardas = vardas;
        temp.pavarde = pavarde;
        temp.nd = nd;
        temp.egz = egz;
        studentai.push_back(temp);
    }

    in.close();
}

void rasytiRanka(vector<student> &studentai) {

    string s;
    string s2;
    student temp;

    cout << endl;
    cout << "***Jeigu daugiau studentu nera, iveskite * (zvaigzdute)***" << endl;
    cout << endl;
    while(s != "*") {
        cout << "Iveskite studento varda:  " << flush;
        try {
            cin >> s;
        } catch (exception e) {
            cout << "Ivyko klaida!" << endl;
        }
        if(s=="*")
            break;
        temp.vardas = s;
        cout << "Iveskite studento pavarde:  " << flush;
        try {
            cin >> temp.pavarde;
        } catch (exception e) {
            cout << "Ivyko klaida!" << endl;
        }
        cout << "***Jeigu daugiau namu darbu nera, iveskite * (zvaigzdute)***" << endl;
        cout << "Iveskite visus studento namu darbu rezultatus:  " << endl;
        while(true) {
            try {
                cin >> s2;
            } catch (exception e) {
                cout << "Ivyko klaida!" << endl;
            }
            if(!isNumber(s2)) {
                cout << "Skaicius negali tureti raidziu!" << endl;
            }
            else {
                if(s2=="*")
                break;
                temp.nd.push_back(atof(s2.c_str()));
            }
        }
        cout << "Iveskite egzamino rezultata:  " << flush;
        while(true) {
            try {
                cin >> s2;
            } catch (exception e) {
                cout << "Ivyko klaida!" << endl;
            }
            if(!isNumber(s2)) {
                cout << "Skaicius negali tureti raidziu!" << endl;
            }
            else {
                break;
            }
        }
        temp.egz = atof(s2.c_str());
        studentai.push_back(temp);
        cout << endl;
    }

}

void rasytiRezultatus(vector<student> &studentai) {
    sortArray(studentai);
    cout << setw(15) << left << fixed << "Vardas" << setw(15) <<  "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(15) << "Galutinis (med.)"  << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    double t = 0;
    int n;
    for(int i = 0; i < studentai.size(); i++) {
        t = 0;
        for(int j = 0; j < studentai[i].nd.size(); j++){
            t += studentai[i].nd[j];
        }
        t = t/studentai[i].nd.size();
        t = 0.4*t + 0.6*studentai[i].egz;
        cout << setw(15) << left << fixed << studentai[i].vardas;
        cout << setw(15) << left << fixed << studentai[i].pavarde;
        cout << setw(20) << setprecision(2) << left << fixed << t;
        cout << setprecision(2) << left << fixed << studentai[i].nd[studentai[i].nd.size() / 2]  << endl;
    } 
}

bool isNumber(const string& s) {
    if(s == "*")
        return true;

    return !s.empty() && find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}
