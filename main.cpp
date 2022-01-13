#include <iostream>
#include <cstring>
#include<locale>
using namespace std;

#include "poki-start.h"
#include "main.h"

int main() {
    setlocale(LC_CTYPE, "fra");
    string name;
    pokimac mainPoki;
    greeting(name);
    starterChoice(name, mainPoki);
    return 0;
}
