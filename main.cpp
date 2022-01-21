#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <stdlib.h>
using namespace std;

#include "consoleUtils.hpp"
#include "main.h"
#include "poki-start.h"
#include "pokidex.h"
#include "combat.h"
#include "map.h"



Pokimac bulbizarre,salameche,carapuce,chenipan,aspicot,ratata,pichu,taupiqueur,magicarpe,ronflex,abo,rondoudou,psykokwak,magneton;
Pokimac mainPoki;
Pokimac pokidex[14];

int nbOpponents = 5;
const int nb = 5;
Pokimac opponents[nb];

//taille de la carte
int width = 24;
int height = 12;

char* tab = new char[width*height];
Player sacha;

string name;

int music=1;

void BackgroundMusic() {
    PlaySound(NULL, 0, 0);
    if(music==1) {
        PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else if(music==2) {
        PlaySound(TEXT("combat.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else if(music==3) {
        PlaySound(TEXT("balade.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void startGame() {
    ConsoleUtils::clear();
    displayMap(&sacha,tab);
    putPokimacsOnMap();
    playerMove(&sacha,tab);
}

void resumeGame() {
    music=3;
    BackgroundMusic();

    ConsoleUtils::clear();
    displayMap(&sacha,tab);

    for (int i=0;i<nbOpponents;i++){
        ConsoleUtils::setCursorPos(opponents[i].position.x, opponents[i].position.y);//on positionne le curseur de la console à la position du pokemon
        cout << opponents[i].skin; // Output 'C' at pokemon position
    }
    playerMove(&sacha,tab);
}

void win(string name){
    ConsoleUtils::clear();
    cout << "Il n'y a plus de pokimacs sur la carte. Bravo " << name << " ! Tu es arrivé.e au bout du jeu :D" <<endl;
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

int main() {

    srand(time(0)); //generate random numbers

    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1100, 700, TRUE);

    setlocale(LC_CTYPE, "fra");


    createPokidex(); // Remplissage infos pokimacs

    // Création du joueur //
    initializePlayer(&sacha,width,height);
    fillMap(tab,width,height);

    thread MusicThread(BackgroundMusic);
    MusicThread.join();

    greeting(name);
    starterDisplay(name, mainPoki);

    music=3;
    BackgroundMusic();

    Sleep(1000);
    startGame();

    // important free my allocated memory
    free(tab);

    return 0;
}
