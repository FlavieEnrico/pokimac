#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

#include "poki-start.h"
#include "consoleUtils.hpp"
#include "main.h"

void greeting(string *name){
    cout << "Bienvenue nouveau dresseur ! On m'a dit qu'une potentielle nouvelle recrue commen�ait � se faire une r�putation � Champy-Marny, mais je ne pensais pas te rencontrer de sit�t. D'ailleurs comment t'appelles-tu ?" << endl;
    cin >> *name;
    cout << *name << " ? Ravi de te rencontrer. Tu pourras m'appeler le Professeur, je t'accompagnerais dans le d�but de ton aventure. Sais-tu ce qu'est un PokImac (y/n) (yes par d�faut)?" << endl;
    string more;
    cin >> more;
	if (more=="n" || more=="N") {
        cout << "Un pokimac, c'est une sympathique petite bestiole un  peu sauvage qui se prom�ne partout dans les terres de Champy-Marny. Ton aventure consistera � te promener dans la ville et emp�cher la prolif�ration intempestive des pokimac. Apr�s, tu le fais de la mani�re que tu veux ; en les capturant, en gagnant le combat... Tu peux te d�placer sur la carte en utilisant les fl�ches directionnelles. Tu seras repr�sent� par le symbole '@' sur la carte. Les autres symboles sont des pokimacs !" << endl << endl;
       Sleep(1000);
    }
}

void starterDisplay(string *name, Pokimac *starterPoki) {
    cout << "J'esp�re que tu es pr�t � d�buter ton aventure ! Mais avant �a, tu vas avoir l'opportunit� de choisir ton premier pokimac. Il n'y a pas vraiment de bon choix ou de mauvais choix, " << *name << ", le meilleur choix c'est celui que tu fais avec le coeur ! Laisse moi te les pr�senter." << endl << endl;
    Sleep(1000);
    cout << "1. Bulbizarre. C'est pokimac de type Poison/Plante. Il passe son temps � faire la sieste sous le soleil. Il y a une graine sur son dos. Il absorbe les rayons du soleil pour faire doucement pousser la graine. Elle grandit avec lui depuis sa naissance." << endl << endl;
    Sleep(1000);
    cout << "2. Salam�che. C'est un pokimac de type Feu. La flamme qui br�le au bout de sa queue indique l�humeur de ce Pok�mon. Elle vacille lorsque Salam�che est content. En revanche, lorsqu�il s��nerve, la flamme prend de l�importance et br�le plus ardemment. Si cette flamme s��teint, la vie de ce Pok�mon s��teindra elle aussi." << endl << endl;
    Sleep(1000);
    cout << "3. Carapuce. C'est un pokimac de type Eau. La carapace de Carapuce ne sert pas qu�� le prot�ger. La forme ronde de sa carapace et ses rainures lui permettent d�am�liorer son hydrodynamisme. Ce Pok�mon nage extr�mement vite. Il se r�fugie dans sa carapace et r�plique en �claboussant l�ennemi � la premi�re occasion." << endl << endl;
    cout << "Alors " << *name << ", qui choisis-tu pour t'accompagner dans ton aventure ? (1/2/3)" << endl;
    starterChoice(starterPoki);
    ConsoleUtils::clear();
    cout << starterPoki->name << " a rejoint ton �quipe ! L'aventure peut commencer !" << endl;
}

void starterChoice(Pokimac *starterPoki) {

    string choice;
    cin >> choice;
	if (choice=="1") {
        *starterPoki = bulbizarre;
    }
    else if (choice=="2") {
        *starterPoki = salameche;
    }
    else if (choice=="3") {
        *starterPoki = carapuce;
    }
    else {
        cout << "Veuillez s�lectionner l'une des options disponibles." << endl;
        starterChoice(starterPoki);
    }
}
