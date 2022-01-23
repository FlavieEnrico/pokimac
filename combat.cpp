#include <iostream>
#include <cstring>
#include <windows.h>
#include <algorithm> //rotate func
#include <locale>
#include <random>
#include <ctime>
using namespace std;

#include "main.h"
#include "combat.h"
#include "consoleUtils.hpp"
#include "map.h"
#include "pokidex.h"

void combat(Pokimac *mainPoki, Pokimac *opponentPoki, int index, const int healthIni) {
    displayPoki(mainPoki, opponentPoki);
    int captureSuccess=0;
    cout << "1. Attaque !" << endl << "2. Capture" << endl << "3. Fuite" << endl;
    string choice;
    cin >> choice;
    if (choice=="1") {
        attaque(mainPoki, opponentPoki);
        if (opponentPoki->health>0) {
            Sleep(1000);
            ConsoleUtils::clear();
            attaqueEnnemi(mainPoki, opponentPoki);
            Sleep(1000);
            ConsoleUtils::clear();
            combat(mainPoki, opponentPoki, index, healthIni);
        }
        else {
            mainPoki->health=60;
        }
    }
    else if (choice=="2") {
        if (opponentPoki->health < healthIni/2) {
            captureSuccess=capture(opponentPoki, mainPoki);
            if (captureSuccess==-1) {
                Sleep(1000);
                ConsoleUtils::clear();
                attaqueEnnemi(mainPoki, opponentPoki);
                Sleep(1000);
                ConsoleUtils::clear();
                combat(mainPoki, opponentPoki, index, healthIni);
            }
        }
        else {
            cout << "Le pokémon n'est pas assez affaibli pour être capturé !" << endl;
            Sleep(1000);
            ConsoleUtils::clear();
            combat(mainPoki, opponentPoki, index, healthIni);
        }
    }
    else if (choice=="3") {
        fuite(mainPoki);
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
    if (nbOpponents <= 0) {
        win(name);
    }
    nbOpponents--;
    Pokimac *blank = new Pokimac;
    opponents[nbOpponents] = *blank;
    resumeGame();
}

int randomGenerate(int proba) {
    srand(time(0));
    int chanceCapture;
    chanceCapture=rand()%(proba);
    return chanceCapture;
}

void attaqueEnnemi(Pokimac *mainPoki, Pokimac *opponentPoki) {
    displayPoki(mainPoki, opponentPoki);
    cout << opponentPoki->name << " a attaqué !" << endl;
    int plusOuMoins=randomGenerate(2);
    int ptDegats;
    if (plusOuMoins==1) {
        ptDegats=opponentPoki->level - randomGenerate(opponentPoki->level);
        mainPoki->health = mainPoki->health - ptDegats;
        cout << "Tu as perdu " << ptDegats << " points de vie !" << endl;
    }
    else {
        ptDegats=opponentPoki->level - randomGenerate(opponentPoki->level);
        mainPoki->health = mainPoki->health + ptDegats;
        cout << "Tu as perdu " << ptDegats << " points de vie !" << endl;
    }
    if (mainPoki->health<=0){
        ConsoleUtils::clear();
        cout << "Ton Pokimac n'a plus de vie... Game Over." <<endl;
        cout << "Veux-tu refaire une partie ? (y/n) (non par défaut)" << endl;

        char choice ='n'; // non par défaut
        cin >> choice;

    if (choice == 'y') {
        startGame();
    } else {
        cout << endl;
        cout << "Merci d'avoir joué !"<<endl;
        asciiArt();
        exit(0);
    }
    }
}

void attaque(Pokimac *mainPoki, Pokimac *opponentPoki) {
    cout << "Tu as attaqué !" << endl;
    int plusOuMoins=randomGenerate(2);
    int ptDegats;
    if (plusOuMoins==1) {
        ptDegats=mainPoki->level - randomGenerate(mainPoki->level);
        opponentPoki->health = opponentPoki->health - ptDegats;
        cout << "Tu as infligé " << ptDegats << " points de dégâts !" << endl;
    }
    else {
        ptDegats=mainPoki->level + randomGenerate(mainPoki->level);
        opponentPoki->health = opponentPoki->health - ptDegats;
        cout << "Tu as infligé " << ptDegats << " points de dégâts !" << endl;
    }
}

int capture(Pokimac *opponentPoki, Pokimac *mainPoki){
    int chanceCapture;
    chanceCapture=randomGenerate(4);
    if (chanceCapture==2) {
        cout << "Tu as capturé le pokimac !" << endl;
        mainPoki->health=60;
        return 1;
    }
    else {
        cout << "Le pokimac s'est échappé de la pokeball ! Essaie encore." << endl;
        return -1;
    }
}

void fuite(Pokimac *mainPoki) {
    cout << "Tu as pris la fuite... " << endl;
    mainPoki->health=60;
}

void introCombat() {
    cout << "Un combat est sur le point de commencer ! Que vas-tu faire ?" << endl;
}

void displayPoki(Pokimac *mainPoki, Pokimac *opponentPoki) {
    cout << endl << endl << mainPoki->name << "                  " << opponentPoki->name << endl;
    cout << "   " << mainPoki->health << "                          " << opponentPoki->health << endl << endl;
}
