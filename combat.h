#include <cstring>
#include "main.h"

void attaque(Pokimac &mainPoki, Pokimac &opponentPoki);
int capture(Pokimac &opponentPoki);
void fuite();

void displayPoki(Pokimac &mainPoki, Pokimac &opponentPoki);

void combat(Pokimac &mainPoki, Pokimac &opponentPoki, int index, const int healthIni);
