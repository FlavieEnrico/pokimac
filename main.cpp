#include <iostream>
#include <fstream>
#include <cstring>
#include<locale>
#include <windows.h>
#include <mmsystem.h>
#include<thread>
using namespace std;

#include "poki-start.h"
#include "main.h"
#include "combat.h"

int main() {
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1100, 700, TRUE);

    setlocale(LC_CTYPE, "fra");
    string name;
    Pokimac mainPoki, opponentPoki;
    opponentPoki.name = "Chenipan";
    opponentPoki.health =12;
    thread music([]() {
    PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_SYNC);
    });
    greeting(name);
    starterDisplay(name, mainPoki);
    /*thread music2([]() {
    PlaySound(TEXT("combat.wav"), NULL, SND_FILENAME | SND_SYNC);
    });*/
    combat(mainPoki, opponentPoki, opponentPoki.health);
    return 0;
}
