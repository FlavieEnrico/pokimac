#ifndef NOM_DU_FICHIER_H
#define NOM_DU_FICHIER_H

#include <string>
#include <cstring>

typedef struct {
    int x;
    int y;
} Coordonnees;

struct Pokimac {
    char* name;
    int health;
    int level;
    Coordonnees position;
    char skin;
};

extern Pokimac bulbizarre,salameche,carapuce,chenipan,aspicot,ratata,pichu,taupiqueur,magicarpe,ronflex,abo,rondoudou,psykokwak,magneton;

void createPokidex();

void BackgroundMusic();
#endif
