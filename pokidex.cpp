#include "main.h"
#include "pokidex.h"

Pokimac randomChooseOpponentPoki(Pokimac *pokidex){
    int nb = rand()%(15);
    Pokimac choosen_one = pokidex[nb];
    return choosen_one;
}

void createPokidex(){
    //Pokimac bulbizarre;
    bulbizarre.name = "Bulbizarre";
    bulbizarre.health = 60;
    bulbizarre.level = 5;
    bulbizarre.skin = 'b';
    pokidex[0]=bulbizarre;

    //Pokimac salameche;
    salameche.name = "Salamèche";
    salameche.health = 60;
    salameche.level = 5;
    salameche.skin = 's';
    pokidex[1]=salameche;

    //Pokimac carapuce;
    carapuce.name = "Carapuce";
    carapuce.health = 60;
    carapuce.level = 5;
    carapuce.skin = 'c';
    pokidex[2]=carapuce;

    //Pokimac chenipan;
    chenipan.name = "Chenipan";
    chenipan.health = 40;
    chenipan.level = 1;
    chenipan.skin = 'C';
    pokidex[3]=chenipan;

    //Pokimac aspicot;
    aspicot.name = "Aspicot";
    aspicot.health = 42;
    aspicot.level = 2;
    aspicot.skin = 'a';
    pokidex[4]=aspicot;

    //Pokimac ratata;
    ratata.name = "Ratata";
    ratata.health = 30;
    ratata.level = 1;
    ratata.skin = 'r';
    pokidex[5]=ratata;

    //Pokimac pichu;
    pichu.name = "Pichu";
    pichu.health = 50;
    pichu.level = 8;
    pichu.skin = 'p';
    pokidex[6]=pichu;

    //Pokimac taupiqueur;
    taupiqueur.name = "Taupiqueur";
    taupiqueur.health = 45;
    taupiqueur.level = 7;
    taupiqueur.skin = 'T';
    pokidex[7]=taupiqueur;

    //Pokimac magicarpe;
    magicarpe.name = "Magicarpe";
    magicarpe.health = 30;
    magicarpe.level = 3;
    magicarpe.skin = 'm';
    pokidex[8]=magicarpe;

    //Pokimac ronflex;
    ronflex.name = "Ronflex";
    ronflex.health = 130;
    ronflex.level = 10;
    ronflex.skin = 'O';
    pokidex[9]=ronflex;

    //Pokimac abo;
    abo.name = "Abo";
    abo.health = 60;
    abo.level = 6;
    abo.skin = 'A';
    pokidex[10]=abo;

    //Pokimac rondoudou;
    rondoudou.name = "Rondoudou";
    rondoudou.health = 65;
    rondoudou.level = 8;
    rondoudou.skin = 'R';
    pokidex[11]=rondoudou;

    //Pokimac psykokwak;
    psykokwak.name = "Psykokwak";
    psykokwak.health = 55;
    psykokwak.level = 6;
    psykokwak.skin = 'P';
    pokidex[12]=psykokwak;

    //Pokimac magneton;
    magneton.name = "Magnéton";
    magneton.health = 100;
    magneton.level = 9;
    magneton.skin = 'M';
    pokidex[13]=magneton;
}




