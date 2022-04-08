#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class Magie
{
private:
  string m_nom;
  int m_degats;

public:
  //constructeur par défauts
  Magie();
  // constructeur surchargé
  Magie(string nom_sort,int degats);

  //methodes utiles
  void changer(string nom, int degats);
  void afficher();
  int getDegats() const;
  string getNomSort() const;

};

class Arme
{
    private:
    std::string m_nom;
    int m_degats;

    public:
    // constructeurs
    Arme(); // defauts
    Arme(std::string nom, int degats); // surchargé
    //destructeur
    ~Arme();
    // methodes de la classe armes
    void changer(std::string nom, int degats); // permet de changer d'arme
    void afficher() const;
    int getDegats() const;
    string getNomArme() const;
};


class Personnage
{
  protected :
  // attributs de la classe
   int m_vie;           // pts de vie du personnage
   int m_mana;          // mana du personnage
   string m_nomPersonnage;
   // notre personnage possède une arme de la classe arme et une magie de la classe magie
   Arme m_arme; // contient le nom de l'arme ainsi que le degats
   Magie m_magie;

   public :
   // Méthodes de la classe
   Personnage(); // constructeur de la classe
   Personnage( string nomPersonnage); // constructeur surchargé de la classe
   Personnage(string nomPersonnage, int ptsVie,int ptsMana, string nomArme, int degatsArme, string nomMagie,int degatsMagie);
   ~Personnage(); // destructeur
   void recevoirDegats(int nbDegats);
   void attaquer(Personnage &cible);
   void boirePotionDeVie(int quantitePotion);
   void boirePotionDeMana( int quantitePotion);
   void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
   void changerSort(std::string nomNouveauSort, int degatsNouveauSort);
   void afficherEtat() const;
   int getPointdeVie() const;
   void attaquer_magique(Personnage &cible);
   bool estVivant() const ;

};

class Guerrier : public Personnage
{

  public :
  Guerrier();
  Guerrier(string nomPersonnage, int ptsVie,int ptsMana, string nomArme, int degatsArme, string nomMagie,int degatsMagie);
  void boirePotionDeVie(int quantitePotion);
  void boirePotionDeMana( int quantitePotion);
};


class Ogre : public Personnage
{
  public :
  Ogre();
  Ogre(string nomPersonnage, int ptsVie,int ptsMana, string nomArme, int degatsArme, string nomMagie,int degatsMagie);
  void boirePotionDeVie(int quantitePotion);
  void boirePotionDeMana( int quantitePotion);
};



// focntions annexes
int action_joueur(int compte_tour);
int choix_personnage_a_attaquer();
vector<string> lecture_fichiers_donnees(string chemin);
vector<string> remplissage_vecteur_arme();
vector<string> remplissage_vecteur_sort();
vector<string> remplissage_vecteur_potion_mana();
vector<string> remplissage_vecteur_potion_vie();





/*void echange(double& c, double& b);

double fonctionMoyenne(vector<double> tableauNotes);

int nombreDeSecondes(int heures, int minutes = 0, int secondes = 0);

vector<vector<int>> remplisssageGrille(vector<vector<int>> grille);
*/
