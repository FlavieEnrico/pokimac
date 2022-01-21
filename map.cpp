#include <iostream>
#include <cstring>
#include "main.h"
#include "consoleUtils.hpp"
#include "map.h"
#include "pokidex.h"
#include "combat.h"
using namespace std;

/// Créer la carte de jeu ///
void fillMap(char* tab,const int mapWidth,const int mapHeight){

    // fill my char tab with specific pattern
    for (unsigned int j=0; j<(mapHeight); j++) {
        for (unsigned int i=0; i<(mapWidth); i++) {
            tab[j*(mapWidth)+i] = (i%(mapWidth-1) == 0 || j%(mapHeight-1) == 0) ?  '#' : '.';
        }
    }
}

/// Initialiser la position du joueur ///
void initializePlayer(Player *sacha, const int mapWidth,const int mapHeight){
    sacha->position.x = mapWidth/2; // Le joueur commence au centre de la map
    sacha->position.y = mapHeight/2;
    sacha->skin = '@';
}

/// afficher la carte ///
void displayMap(Player *sacha, char* tab) {
    ConsoleUtils::setCursorPos(0, 0);
    for (unsigned int j=0; j<height; j++) {
        for (unsigned int i=0; i<width; i++) {
            std::cout << tab[j*width+i];
        }
        std::cout << std::endl;
    }

    ConsoleUtils::setCursorPos(sacha->position.x, sacha->position.y);//on positionne le curseur de la console à la position du joueur
    std::cout << sacha->skin; // Output '@' at my position
}

/// Mouvement du joueur ///
void playerMove(Player *sacha, char* tab){
    bool exitLoop = false;
		while (!exitLoop) {
            bool special = false;

			//// Pokimacs part ///

            for (int i=0;i<nbOpponents;i++){
                randomMoveGenerator(&opponents[i],i, sacha, tab, width, height);
                ///// Si je vais sur la même case qu'un pokémon
                    if ((opponents[i].position.x == sacha->position.x)&&(opponents[i].position.y == sacha->position.y)){
                        exitLoop = true;
                        ConsoleUtils::clear();
                        combat(mainPoki, opponents[i], i, opponents[i].health);
                    }
			}

			//// Player part ///

			int c = ConsoleUtils::getChar(&special);

			Coordonnees oldSachaPos = sacha->position;

			if(special) {
				switch (c) {
					case ConsoleUtils::KEY_UP: if(sacha->position.y>1) --sacha->position.y; break;
					case ConsoleUtils::KEY_DOWN: if(sacha->position.y<height-2) ++sacha->position.y; break;
					case ConsoleUtils::KEY_LEFT: if(sacha->position.x>1) --sacha->position.x; break;
					case ConsoleUtils::KEY_RIGHT: if(sacha->position.x<width-2) ++sacha->position.x; break;
					default: break;
				}
			} else if (c == ' ') {
				 exitLoop = true;
			}

			if(oldSachaPos.x != sacha->position.x || oldSachaPos.y != sacha->position.y) {

            ConsoleUtils::setCursorPos(oldSachaPos.x, oldSachaPos.y);
            cout << tab[oldSachaPos.y*width+oldSachaPos.x]; // Clean up my current location by showing what is in my tab
            ConsoleUtils::setCursorPos(sacha->position.x, sacha->position.y);
            cout << sacha->skin; // Output '@' at my position
			}


		} // fin while

}

/// Générer des coordonées aléatoires ///
// sert pour donner une position aléatoire aux différents pokemons sur la carte //
Coordonnees randomCoordinateGenerator(const int mapWidth,const int mapHeight){

    Coordonnees randomPos;
    randomPos.x = rand()%(mapWidth-1);
    randomPos.y = rand()%(mapHeight-1);

    return randomPos;
}

/// Générer un pokemon "ennemi" sur la carte ///
void initializePokimac(Pokimac *any_pokimac, Player *sacha,const int mapWidth,const int mapHeight) {
    do {
        any_pokimac->position = randomCoordinateGenerator(mapWidth, mapHeight);
    } while(((any_pokimac->position.x == sacha->position.x)&&(any_pokimac->position.y == sacha->position.y))||(any_pokimac->position.x == 0)||(any_pokimac->position.y == 0)||(any_pokimac->position.x == mapWidth-1)||(any_pokimac->position.y == mapHeight-1));
    // si le pokemon a les memes coordonnées que le joueur, ou s'il est sur la bordure, on génère d'autres coordonnées

    ConsoleUtils::setCursorPos(any_pokimac->position.x, any_pokimac->position.y);//on positionne le curseur de la console à la position du pokemon
    cout << any_pokimac->skin; // Output 'C' at pokemon position
}


/// placer tous les pokémons ennemi sur la carte

void putPokimacsOnMap(){
    for (int i=0;i<nbOpponents;i++){
        Pokimac choosen_one = randomChooseOpponentPoki(pokidex);
        opponents[i]=choosen_one;
        initializePokimac(&opponents[i],&sacha,width,height);
    }
}

/// Le pokemon se déplace d'une case aléatoirement sur la carte ///
void randomMoveGenerator(Pokimac *any_pokimac,int index, Player *sacha, char* tab, const int mapWidth, const int mapHeight){

    Coordonnees oldPokiPos = any_pokimac->position;

    int rdchoice = rand()%5; // choix entre 4 directions

    switch (rdchoice){
        case 0:
            if(any_pokimac->position.x>1)--any_pokimac->position.x;
            break;
        case 1:
            if(any_pokimac->position.y>1)--any_pokimac->position.y;
            break;
        case 2:
            if(any_pokimac->position.x<width-2)++any_pokimac->position.x;
            break;
        case 3:
            if(any_pokimac->position.y<height-2)++any_pokimac->position.y;
            break;
         default:
            break;
      }

      //mettre à jour l'affichage de la position du pokimac
        if(oldPokiPos.x != any_pokimac->position.x || oldPokiPos.y != any_pokimac->position.y) {

            ConsoleUtils::setCursorPos(oldPokiPos.x, oldPokiPos.y);
            cout << tab[oldPokiPos.y*mapWidth+oldPokiPos.x]; // Clean up my current location by showing what is in my tab
            ConsoleUtils::setCursorPos(any_pokimac->position.x, any_pokimac->position.y);
            cout << any_pokimac->skin; // Output skin of pokimac at cursor position

            ConsoleUtils::setCursorPos(sacha->position.x, sacha->position.y);

            ///// Si je vais sur la même case que le joueur
            if ((any_pokimac->position.x == sacha->position.x)&&(any_pokimac->position.y == sacha->position.y)){
                    ConsoleUtils::clear();
                    combat(mainPoki, *any_pokimac,index, any_pokimac->health);
            }

        }
}
