#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include <windows.h>
#include <mmsystem.h>
#include<thread>
using namespace std;

#include "consoleUtils.hpp"
#include "main.h"
#include "poki-start.h"
#include "combat.h"
#include "map.h"

Pokimac bulbizarre,salameche,carapuce,chenipan,aspicot,ratata,pichu,taupiqueur,magicarpe,ronflex,abo,rondoudou,psykokwak,magneton;
Pokimac mainPoki;

//taille de la carte
int width = 24;
int height = 12;

char* tab = new char[width*height];

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

int main() {
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1100, 700, TRUE);

    setlocale(LC_CTYPE, "fra");
    string name;

    createPokidex(); // Remplissage infos pokimacs

    // Création du joueur //
    Player sacha;
    initializePlayer(&sacha,width,height);
    fillMap(tab,width,height);

    thread MusicThread(BackgroundMusic);
    MusicThread.join();

    greeting(name);
    starterDisplay(name, mainPoki);
    initializePokimac(chenipan,&sacha,width,height);

    music=3;
    BackgroundMusic();

    ConsoleUtils::clear();
    displayMap(&chenipan,&sacha,tab);
    playerMove(&chenipan,&sacha,tab);

    // important free my allocated memory
    free(tab);

    return 0;
}
