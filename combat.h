#include <cstring>
#include "main.h"

void attaque(Pokimac *mainPoki, Pokimac *opponentPoki);
void attaqueEnnemi(Pokimac *mainPoki, Pokimac *opponentPoki);
int capture(Pokimac *opponentPoki, Pokimac *mainPoki);
void fuite(Pokimac *mainPoki);
void introCombat();

void displayPoki(Pokimac *mainPoki, Pokimac *opponentPoki);

void combat(Pokimac *mainPoki, Pokimac *opponentPoki, int index, const int healthIni);
