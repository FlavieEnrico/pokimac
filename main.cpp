#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include <windows.h>
#include <mmsystem.h>
#include<thread>
using namespace std;

#include "main.h"
#include "poki-start.h"
#include "combat.h"

Pokimac bulbizarre,salameche,carapuce,chenipan,aspicot,ratata,pichu,taupiqueur,magicarpe,ronflex,abo,rondoudou,psykokwak,magneton;
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

    createPokidex();

    Pokimac mainPoki, opponentPoki;
    opponentPoki.name = "Chenipan";
    opponentPoki.health =12;
    thread MusicThread(BackgroundMusic);
    MusicThread.join();
    greeting(name);
    starterDisplay(name, mainPoki);
    music=2;
    BackgroundMusic();
    combat(mainPoki, opponentPoki, opponentPoki.health);
    return 0;
}
