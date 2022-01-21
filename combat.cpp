#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

#include "main.h"
#include "combat.h"
#include "consoleUtils.hpp"
#include "map.h"

void combat(Pokimac &mainPoki, Pokimac &opponentPoki, const int healthIni) {
    displayPoki(mainPoki, opponentPoki);
    cout << "1. Attaque !" << endl << "2. Capture" << endl << "3. Fuite" << endl;
    string choice;
    cin >> choice;
    if (choice=="1") {
        attaque(mainPoki, opponentPoki);
        if (opponentPoki.health>0) {
            Sleep(1000);
            ConsoleUtils::clear();
            combat(mainPoki, opponentPoki, healthIni);
        }
    }
    else if (choice=="2") {
        if (opponentPoki.health < healthIni/2) {
            capture(opponentPoki, healthIni);
        }
        else {
            cout << "Le pokémon n'est pas assez affaibli pour être capturé !" << endl;
            Sleep(1000);
            ConsoleUtils::clear();
            combat(mainPoki, opponentPoki, healthIni);
        }
    }
    else if (choice=="3") {
        fuite();
    }
    else {
        cout << "Veuillez sélectionner l'une des options disponibles." << endl;
        Sleep(1000);
        ConsoleUtils::clear();
        combat(mainPoki, opponentPoki, healthIni);
    }
    //to start playing again
    Sleep(1000);
    ConsoleUtils::clear();
    displayMap(&chenipan,&sacha,tab);
    createPokidex();
    initializePokimac(&chenipan,&sacha,width,height);
    playerMove(&chenipan,&sacha,tab);
}

void attaque(Pokimac &mainPoki, Pokimac &opponentPoki) {
    cout << "Tu as attaqué !" << endl;
    opponentPoki.health = opponentPoki.health - mainPoki.level;
    cout << "Tu as infligé " << mainPoki.level << " points de dégâts !" << endl;
}

void capture(Pokimac &opponentPoki, const int healthIni){
    cout << "Tu as capturé le pokimac !" << endl;
}

void fuite() {
    cout << "Tu as fui... " << endl;
}

void displayPoki(Pokimac &mainPoki, Pokimac &opponentPoki) {
    cout << endl << endl << mainPoki.name << "                  " << opponentPoki.name << endl;
    cout << "   " << mainPoki.health << "                          " << opponentPoki.health << endl << endl;
}
