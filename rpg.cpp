#include "rpg.h"




//*******************************************************************************************************************************************************************************//
//***************************************** methodes de la classe personnage****************************************************************************************************//
//******************************************************************************************************************************************************************************//
// destructeur
Personnage::~Personnage() {}

// constructeur par défaut
Personnage::Personnage() : m_vie(), m_mana(), m_arme(),m_magie(), m_nomPersonnage()
{}

//constructeur surchargé
Personnage::Personnage(string nomPersonnage) : m_vie(100), m_mana(100),m_arme("épée rouillée", 12),m_magie("boule de feu de niveau 1",5), m_nomPersonnage(nomPersonnage)
{}

Personnage::Personnage(string nomPersonnage, int ptsVie,int ptsMana, string nomArme, int degatsArme, string nomMagie,int degatsMagie) : m_nomPersonnage(nomPersonnage),m_vie(ptsVie),m_mana(ptsMana),m_arme(nomArme,degatsArme),m_magie(nomMagie,degatsMagie)
{}

// méthode permettant d'attaquer une cible
void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
}


// méthode permettant d'attaquer une cible avec un sort magique
void Personnage::attaquer_magique(Personnage &cible)
{
    if (m_mana>=m_magie.getDegats())
    {
        m_mana -=m_magie.getDegats();
        if (m_mana <0)
        {
          m_mana =0;
        }
        cible.recevoirDegats(m_magie.getDegats());
    }
    else
    {
      cout << "Vous n'avez plus assez de mana, buvez une potion ! " << endl;
    }
    return;
}

// méthode permettant d'infliger des degats
void Personnage::recevoirDegats(int nbDegats)
{
  //On enlève le nombre de dégâts reçus à la vie du personnage
    m_vie -= nbDegats;

    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
}

// fonction permettant de donner les points de vies d'un personnage
 int Personnage::getPointdeVie() const
{
  return m_vie;
}

//méthode permettant a un personnage de gagner des points de vies
void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}


//méthode permettant a un personnage de gagner des points de mana
void Personnage::boirePotionDeMana(int quantitePotion)
{
    m_mana += quantitePotion;

    if (m_mana > 100) //Interdiction de dépasser 100 de vie
    {
        m_mana = 100;
    }
}

//méthode permettant a un personnage de changer d'arme
void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

//methode pour changer de sort
void Personnage::changerSort(string nomNouveauSort, int degatsNouveauSort)
{
    m_magie.changer(nomNouveauSort, degatsNouveauSort);
}


// méthode donnant les informations courantes sur un personnage
void Personnage::afficherEtat() const
{
  cout << "                                                           " << endl;
  cout << m_nomPersonnage << " statut : " << endl;
  cout <<"************************************************************" << endl;
  cout << "* Points de vie  *       "<< m_vie << endl ;
  cout <<"************************************************************" << endl;
  cout << "* Points de mana *       "<< m_mana << endl ;
  cout <<"************************************************************" << endl;
  cout << "* Sort           *       "<< m_magie.getNomSort() << endl;
  cout <<"************************************************************" << endl;
  cout << "* Dégats du sort *       "<< m_magie.getDegats() << endl;
  cout <<"************************************************************" << endl;
  cout << "* Arme           *       "<< m_arme.getNomArme()<< endl;
  cout <<"************************************************************" << endl;
  cout << "* Dégats arme    *       "<< m_arme.getDegats() << endl;
  cout <<"************************************************************" << endl;
  cout << "                                                           " << endl;
}

// éthode renvoyant un booléen sur l'état de vie d'un personnage
bool Personnage::estVivant() const
{
    return m_vie > 0;
}
//*******************************************************************************************************************************************************************************//
//***************************************** fin methodes de la classe personnage****************************************************************************************************//
//******************************************************************************************************************************************************************************//




//*******************************************************************************************************************************************************************************//
//***************************************** methodes de la classe arme ****************************************************************************************************//
//******************************************************************************************************************************************************************************//

//destructeur
Arme::~Arme(){}

//constructeur par défaut
Arme::Arme() : m_nom("Épée rouillée"), m_degats(10)
{}
// constructeur surchargé
Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{}

// accesseur utilisée dans la classe personnage pour connaitre les dégats provoqués par l'arme d'un personnage
int Arme::getDegats() const
{
    return m_degats;
}
// accesseur utilisée dans la classe personnage pour connaitre le nom de l'arme d'un personnage
string Arme::getNomArme() const
{
  return m_nom;
}

// accesseur utilisée dans la classe permettant de changer l'arme d'un personnage
void Arme::changer(string nom, int degats)
{
    m_nom = nom;
    m_degats = degats;
    return;
}
// accesseur utilisée dans la classe personnage afficher le nom et les degats d'une arme
void Arme::afficher() const
{
    cout << "Arme : " << m_nom << " (Dégâts : " << m_degats << ")" << endl;
    return;
}
//*******************************************************************************************************************************************************************************//
//***************************************** fin methodes de la classe arme ****************************************************************************************************//
//******************************************************************************************************************************************************************************//


//*******************************************************************************************************************************************************************************//
//***************************************** debut  methodes de la classe magie ****************************************************************************************************//
//******************************************************************************************************************************************************************************//

// methode de la classe magie
//constructeur par défauts
Magie::Magie() : m_nom("boule de feu de niveau 1") ,m_degats(5)
{};
// constructeur surchargé
Magie::Magie(string nom_sort,int degats) : m_nom(nom_sort), m_degats(degats)
{};

//methodes utiles
void Magie::changer(string nom, int degats)
{
  m_nom = nom;
  m_degats = degats;
  return;
};

void Magie::afficher()
{
  cout << "le nom du sort est : " << m_nom << "(dégats : "<< m_degats<< ")" << endl;
};

int Magie::getDegats() const
{
  return m_degats;
};

string Magie::getNomSort() const
{
  return m_nom;
};
//

//*******************************************************************************************************************************************************************************//
//***************************************** fin methodes de la classe magie ****************************************************************************************************//
//******************************************************************************************************************************************************************************//


//*******************************************************************************************************************************************************************************//
//***************************************** debut methodes de la classe Guerrier ****************************************************************************************************//
//******************************************************************************************************************************************************************************//

Guerrier::Guerrier() :  Personnage("goliath",200,200,"épée de fer",32,"boule de feu de niveau 1",5)
{}
Guerrier::Guerrier(string nomPersonnage, int ptsVie,int ptsMana, string nomArme, int degatsArme, string nomMagie,int degatsMagie): Personnage( nomPersonnage, ptsVie, ptsMana,  nomArme, degatsArme,nomMagie, degatsMagie)
{}

//méthode permettant a un personnage de gagner des points de vies
void Guerrier::boirePotionDeVie(int quantitePotion)
{

    m_vie += quantitePotion;


    if (m_vie > 200) //Interdiction de dépasser 100 de vie
    {
        m_vie = 200;
    }
}


//méthode permettant a un personnage de gagner des points de mana
void Guerrier::boirePotionDeMana(int quantitePotion)
{
    m_mana += quantitePotion;

    if (m_mana > 200) //Interdiction de dépasser 100 de vie
    {
        m_mana = 200;
    }
}

//*******************************************************************************************************************************************************************************//
//***************************************** fin methodes de la classe Guerrier ****************************************************************************************************//
//******************************************************************************************************************************************************************************//



//*******************************************************************************************************************************************************************************//
//***************************************** debut methodes de la classe Ogre ****************************************************************************************************//
//******************************************************************************************************************************************************************************//
Ogre::Ogre() : Personnage("Ogre des montagnes",250,250,"Massue",20,"crie féroce",10)
{}
Ogre::Ogre(string nomPersonnage, int ptsVie,int ptsMana, string nomArme, int degatsArme, string nomMagie,int degatsMagie): Personnage( nomPersonnage, ptsVie, ptsMana,  nomArme, degatsArme,nomMagie, degatsMagie)
{};
//méthode permettant a un personnage de gagner des points de vies
void Ogre::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 250) //Interdiction de dépasser 100 de vie
    {
        m_vie = 250;
    }
}


//méthode permettant a un personnage de gagner des points de mana
void Ogre::boirePotionDeMana(int quantitePotion)
{
    m_mana += quantitePotion;

    if (m_mana > 250) //Interdiction de dépasser 100 de vie
    {
        m_mana = 250;
    }
}

//*******************************************************************************************************************************************************************************//
//***************************************** fin methodes de la classe Ogre ****************************************************************************************************//
//******************************************************************************************************************************************************************************//




//lit le fichier conetnat le nom des armes et leur degats
// puis les ranges dans un vecteur de string de la forme
// nom arme, degats, nom arme, degats, nom arme, degats ...
// autres fonctions de remplissage fonctionnent de la même manière
vector<string> lecture_fichiers_donnees( string chemin )
{
  ifstream mon_flux(chemin);
  string ligne;
  vector<string> liste;
  while (getline(mon_flux,ligne))
  {
    liste.push_back(ligne);
  }
  return liste;
}


int action_joueur(int compte_tour)
{
  int choix_Joueur;
  cout << "        " << endl;
  cout << "***************************************" << endl;
  cout << "*      Action du joueur : tour "<< compte_tour<< "      *"<< endl;
  cout << "***************************************" << endl;
  cout <<"Que voulez vous faire ? " << endl;
  cout <<"1) attaquer un joueur avec votre arme " << endl;
  cout <<"2) attaquer un joueur avec votre magie " << endl;
  cout <<"3) changer d'arme" << endl;
  cout <<"4) changer de sort" << endl;
  cout <<"5) boire une potion de vie" << endl;
  cout <<"6) boire une potion de mana" << endl;
  cin >> choix_Joueur;
//  system("clear");
  return choix_Joueur;
}


int choix_personnage_a_attaquer()
{
  int joueur_a_attaquer;
  cout << "Quel joueur voulez vous attaquer" << endl;
  cout << "1) goliath" << endl;
  cout << "2) Ogre" << endl;
  cin >> joueur_a_attaquer;
  return joueur_a_attaquer;
}

void afficher_statuts(int compte_tour, Personnage joueur1, Guerrier goliath, Ogre Ogre)
{
  cout << "                                  " << endl;
  cout << "***************************************" << endl;
  cout << "*status des joueurs à la fin du tour "<<compte_tour <<"*" << endl;
  cout << "***************************************" << endl;
  joueur1.afficherEtat();

  // affiche les status des personnages
  if (goliath.estVivant())
  {
    goliath.afficherEtat();
  };
  if (Ogre.estVivant())
  {
    Ogre.afficherEtat();
  };
}

void notice()
{
  int choix;
  cout << "Souhaitez vous lire la notice? Taper sur le nombre correspondant" << endl;
  cout << "1) Oui" << endl;
  cout << "2) Non" << endl;
  cin >> choix ;
  if (choix ==1 )
  {
    cout << "Vous allez vous retrouver dans l'arène avec le héros légendraire Goliath ainsi qu'un ogre. Votre objectif est de tuer l'ogre avec l'aide de Goliath" << endl;
    cout << "Toutefois, Goliath ne souhaite pas rentrer victorieux à vos cotés, il souhaite garder la vedette" << endl;
    cout << "Ainsi, sous certaines conditions il se mettra à vous attaquer avec L'ogre."<< endl;
    cout << " Votre objectif est donc de tuer l'ensemble des personnes présentent dans l'arène." << endl;
    cout << "                  "<< endl;
    cout << "Pour se faire vous avez à disposition des armes et des sors Vous pouvez changer d'arme et de sors à tout moment."<< endl;
    cout << "Cependant tous ces changements se font de manière aléatoire ! Faites donc attention !" << endl;
    cout << "Enfin, des potions de mana et de soins sont disponibles, mais encore une fois certaines sont piégées et obtenues de manière aléatoires !" << endl;
    cout << "" << endl;
    cout << "BONNE CHANCE !" << endl;
    cout << " " << endl;
    cout << " " << endl;
  }
  string choix2;
  cout << "Appuyez sur entrer pour continuer"<< endl;
  getline(cin,choix2);
  system("clear");
}
