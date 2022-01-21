#ifndef POKIDEX_H_INCLUDED
#define POKIDEX_H_INCLUDED

extern Pokimac pokidex[14];
extern Pokimac opponents[5];
extern int nbOpponents;

void createPokidex();
Pokimac randomChooseOpponentPoki(Pokimac *pokidex);

#endif // POKIDEX_H_INCLUDED
