#include <iostream>
using namespace std;

void combat() {
    cout << "1. Attaque !" << endl << "2. Capture" << endl << "3. Fuite" << endl;
    string choice;
    cin >> choice;
    if (choice=="1") {
        attaque();
    }
    if (choice=="2") {
        capture();
    }
    if (choice=="3") {
        fuite();
    }
}

void attaque() {
    cout << "Tu as attaqué !" << endl;
}

void capture(){
    cout << "Tu as capturé le pokimac !" << endl;
}

void fuite() {
    cout << "Tu as fuit... !" << endl;
}
