#include <iostream>
#include <cstring>
using namespace std;

void greeting(string &name);
void starterChoice(string &name);

int main() {
    string name;
    greeting(name);
    starterChoice(name);
    return 0;
}

void greeting(string &name){
    cout << "Bienvenue nouveau dresseur ! On m'a dit qu'une potentielle nouvelle recrue commençait à se faire une réputation à Champy-Marny, mais je ne pensais pas te rencontrer de sitôt. D'ailleurs comment t'appelles-tu ?" << endl;
    cin >> name;
    cout << name << " ? Ravi de te rencontrer. Tu pourras m'appeler le Professeur, je t'accompagnerais dans le début de ton aventure. Sais-tu ce qu'est un PokImac ?" << endl;
    /* ici faire un y/n */ 
}

void starterChoice(string &name) {
    cout << "J'espère que tu es prêt à débuter ton aventure ! Mais avant ça, tu vas avoir l'opportunité de choisir ton premier pokimac. Il n'y a pas vraiment de bon choix ou de mauvais choix, " << name << ", le meilleur choix c'est celui que tu fais avec le coeur ! Laisse moi te les présenter." << endl;
    cout << "1. Bulbizarre. C'est pokimac de type Poison/Plante. Il passe son temps à faire la sieste sous le soleil. Il y a une graine sur son dos. Il absorbe les rayons du soleil pour faire doucement pousser la graine. Elle grandit avec lui depuis sa naissance." << endl;
    cout << "2. Salamèche. C'est un pokimac de type Feu. La flamme qui brûle au bout de sa queue indique l’humeur de ce Pokémon. Elle vacille lorsque Salamèche est content. En revanche, lorsqu’il s’énerve, la flamme prend de l’importance et brûle plus ardemment. Si cette flamme s’éteint, la vie de ce Pokémon s’éteindra elle aussi." << endl;
    cout << "3. Carapuce. C'est un pokimac de type Eau. La carapace de Carapuce ne sert pas qu’à le protéger. La forme ronde de sa carapace et ses rainures lui permettent d’améliorer son hydrodynamisme. Ce Pokémon nage extrêmement vite. Il se réfugie dans sa carapace et réplique en éclaboussant l’ennemi à la première occasion." << endl;
    cout << "Alors " << name << ", qui choisis-tu pour t'accompagner dans ton aventure ?" << endl;
    /* idem lecture de la réponse*/ 
}