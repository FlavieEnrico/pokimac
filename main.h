#ifndef NOM_DU_FICHIER_H
#define NOM_DU_FICHIER_H

#include <iostream>
using namespace std;
#include <string>

typedef struct {
    int x;
    int y;
} Coordonnees;

typedef struct {
    Coordonnees position;
    char skin;
} Player;

struct Attaque {
    string name;
    int degats;
    string type;
};

struct Pokimac {
    string name;
    int health;
    int level;
    Coordonnees position;
    char skin;
    string type;
    Attaque attaques;
};

extern Attaque flammeche;
extern Pokimac bulbizarre,salameche,carapuce,chenipan,aspicot,ratata,pichu,taupiqueur,magicarpe,ronflex,abo,rondoudou,psykokwak,magneton;
extern Pokimac mainPoki;
extern Player sacha;
extern string name;

extern int music;

void BackgroundMusic();
void startGame();
void resumeGame();
void win(string name);

#endif
