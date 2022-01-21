#include <cstring>
#include "main.h"

void attaque(Pokimac &mainPoki, Pokimac &opponentPoki);
void capture(Pokimac &opponentPoki, const int healthIni);
void fuite();

void displayPoki(Pokimac &mainPoki, Pokimac &opponentPoki);

void combat(Pokimac &mainPoki, Pokimac &opponentPoki, int index, const int healthIni);
