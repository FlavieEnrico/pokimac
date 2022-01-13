#include <iostream>
#include <cstring>
#include<locale>
#include <windows.h>
using namespace std;

#include "poki-start.h"
#include "main.h"

int main() {
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1100, 700, TRUE);

    setlocale(LC_CTYPE, "fra");
    string name;
    pokimac mainPoki;
    greeting(name);
    starterChoice(name, mainPoki);
    return 0;
}
