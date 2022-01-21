#include <iostream>
#include <cstring>
#include <windows.h>
#include <algorithm> //rotate func
using namespace std;

#include "main.h"
#include "combat.h"
#include "consoleUtils.hpp"
#include "map.h"
#include "pokidex.h"

void combat(Pokimac &mainPoki, Pokimac &opponentPoki, int index, const int healthIni) {
    displayPoki(mainPoki, opponentPoki);
    cout << "1. Attaque !" << endl << "2. Capture" << endl << "3. Fuite" << endl;
    string choice;
    cin >> choice;
    if (choice=="1") {
        attaque(mainPoki, opponentPoki);
        if (opponentPoki.health>0) {
            Sleep(1000);
            ConsoleUtils::clear();
            combat(mainPoki, opponentPoki, index, healthIni);
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
            combat(mainPoki, opponentPoki, index, healthIni);
        }
    }
    else if (choice=="3") {
        fuite();
        Sleep(1000);
        resumeGame();
    }
    else {
        cout << "Veuillez sélectionner l'une des options disponibles." << endl;
        Sleep(1000);
        ConsoleUtils::clear();
        combat(mainPoki, opponentPoki, index, healthIni);
    }
    //to start playing again
    Sleep(1000);
    rotate(opponents+index, opponents+index+1, opponents+nbOpponents);
    //Rotates the order of the elements in the range [first,last), in such a way that the element pointed by middle becomes the new first element.
    nbOpponents--;
    Pokimac *blank = new Pokimac;
    opponents[nbOpponents] = *blank;
    resumeGame();
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
