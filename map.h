#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

//taille de la carte
extern int width;
extern int height;
extern char* tab;

Coordonnees randomCoordinateGenerator(const int mapWidth,const int mapHeight);
void initializePokimac(Pokimac any_pokimac, Player *sacha,const int mapWidth,const int mapHeight);
void randomMoveGenerator(Pokimac *any_pokimac, Player *sacha, char* tab, const int mapWidth,const int mapHeight);

void fillMap(char* tab,const int mapWidth,const int mapHeight);
void initializePlayer(Player *sacha, const int mapWidth,const int mapHeight);
void displayMap(Pokimac *any_pokimac, Player *sacha, char* tab);
void playerMove(Pokimac *any_pokimac, Player *sacha, char* tab);




#endif // MAP_H_INCLUDED
