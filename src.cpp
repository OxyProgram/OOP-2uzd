#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "stdlib.h"
#include <fstream>
#include <sstream>

#include "header1.h"

using namespace std;

int main() {

    vector <student> studentai;

    cout << "Pasirinkite duomenu ivedimo formata: " << endl;
    cout << "1. Nuskaityti duomenis is isorinio .txt failo\n2. Irasyti duomenis ranka. " << endl;
    cout << "Jusu pasirinkimas:     " << flush;
    string c;
    cin >> c;

    while(true) {
        if(c == "1") {
            readFromFile(studentai);
            c = "";
            break;
        } else if(c == "2") {
            rasytiRanka(studentai);
            c = "";
            break;
        } else {
            cout << "Iveskite 1 arba 2!    " << flush;
            cin >> c;
        }
    }

    rasytiRezultatus(studentai);

    return 0;
}






























