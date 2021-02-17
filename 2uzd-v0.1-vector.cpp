#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"

using namespace std;

struct student {
    string vardas;
    string pavarde;
    vector <double> nd;
    double egz = 0.0;
};

void rasytiRezultatusVidurkis(vector<student> &studentai);
void rasytiRezultatusMediana(vector<student> &studentai);
void braizytiLentele();
bool isNumber(const string& s);

int main() {

    vector <student> studentai;

    string s;
    string s2;
    student temp;
    cout << endl;
    cout << "***Jeigu daugiau studentu nera, iveskite * (zvaigzdute)***" << endl;
    cout << endl;
    while(s != "*") {
        cout << "Iveskite studento varda:  " << flush;
        cin >> s;
        if(s=="*")
            break;
        temp.vardas = s;
        cout << "Iveskite studento pavarde:  " << flush;
        cin >> temp.pavarde;
        cout << "***Jeigu daugiau namu darbu nera, iveskite * (zvaigzdute)***" << endl;
        cout << "Iveskite visus studento namu darbu rezultatus:  " << endl;
        while(true) {
            cin >> s2;
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
            cin >> s2;
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
    cout << "Skaiciuoti:   1. Vidurki   2. Mediana  " << flush;
    char c;
    cin >> c;
    if(c=='1')
        rasytiRezultatusVidurkis(studentai);
    else if(c=='2')
        rasytiRezultatusMediana(studentai);

    return 0;
}

void rasytiRezultatusVidurkis(vector<student> &studentai) {
    braizytiLentele();
    double t = 0;
    for(int i = 0; i < studentai.size(); i++) {
        t = 0;
        for(int j = 0; j < studentai[i].nd.size(); j++){
            t += studentai[i].nd[j];
        }
        t = t/studentai[i].nd.size();
        t = 0.4*t + 0.6*studentai[i].egz;
        cout << setw(15) << left << fixed << studentai[i].vardas;
        cout << setw(15) << left << fixed << studentai[i].pavarde;
        cout << setprecision(2) << left << fixed << t << endl;
    }
}

void rasytiRezultatusMediana(vector<student> &studentai) {
    braizytiLentele();
    double t = 0;
    int n;
    for(int i = 0; i < studentai.size(); i++) {
        sort(studentai[i].nd.begin(), studentai[i].nd.end());
        cout << setw(15) << left << fixed << studentai[i].vardas;
        cout << setw(15) << left << fixed << studentai[i].pavarde;
        cout << setprecision(2) << left << fixed << studentai[i].nd[studentai[i].nd.size() / 2]  << endl;
    }
}

void braizytiLentele() {
    cout << setw(15) << left << fixed << "Vardas";
    cout << setw(15) << left << fixed << "Pavarde";
    cout << setw(15) << left << fixed << "Galutinis (mediana)" << endl;
    cout << string(45, '-') << endl;
}

bool isNumber(const string& s) {

    if(s == "*")
        return true;

    return !s.empty() && find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();

}





