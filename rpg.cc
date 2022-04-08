#include "rpg.h"




int main()
{
  // déclaration des variables
  string nom_Personnage;
  string enter;
  int choix_Joueur(0);
  int joueur_a_attaquer(0);
  int compte_tour(0);
  srand((unsigned int)time(0));
  vector<string> liste_armes(0),liste_sort(0), liste_potions_vie(0),liste_potion_mana(0);


  // lit le fichier contenant les armes et leur dégats
  // de même pour les sorts et les différentes potions
  liste_armes = lecture_fichiers_donnees("armes.dat");
  liste_sort = lecture_fichiers_donnees("sortilege.dat");
  liste_potion_mana = lecture_fichiers_donnees("potionMagie.dat");
  liste_potions_vie = lecture_fichiers_donnees("potionDeVie.dat");

  notice();



  cout << "Quel est le nom de votre personnage ? " << endl;
  cin>> nom_Personnage;
  system ("clear");


  // création du joueur et des deux ennemies
  // on utilise 3 constructeurs differents
  Personnage joueur1(nom_Personnage);
  Guerrier goliath;
  Ogre Ogre;

  // affiche les particicpants au point de départ
  cout << "***************************************" << endl;
  cout << "* Initialisation : statuts des joueurs *" << endl;
  cout << "***************************************" << endl;
  joueur1.afficherEtat();
  goliath.afficherEtat();
  Ogre.afficherEtat();



  // début de la boucle du jeu
  do {


    compte_tour++;
    cout << "              " << endl;
    cout << "**** Appuyez sur entrer pour passer au tour " << compte_tour<< " ****"<< endl;
    getline(cin,enter);
    system("clear");

    choix_Joueur = action_joueur(compte_tour);
    system("clear");


    switch (choix_Joueur) // en fonction de l'action choisit plusieurs cas son possibles
    {
      // choix de l'attque avec l'arme
      case 1:
          // on choisit alors quel adverse attaquer
          joueur_a_attaquer = choix_personnage_a_attaquer();
          system("clear");
          switch (joueur_a_attaquer)
                {
                  // Cas ou l'on souahaite attaqur goliath
                  case 1:
                          if (goliath.estVivant())
                            {
                              joueur1.attaquer(goliath);
                              cout << "vous avez attaqué goliath avec votre arme " << endl;
                            }
                          else
                            {
                              cout << "Goliath est mort, ça ne sert donc à rien" << endl;
                            }
                  break;
                  // cas ou l'on shouaiate attaquer l'ogre
                  case 2:
                          if (Ogre.estVivant())
                            {
                              joueur1.attaquer(Ogre);
                              cout << "vous avez attaqué l'ogre avec votre arme" << endl;
                            }
                          else
                            {
                              cout << "L'ogre est mort, ça ne sert donc à rien" << endl;
                            }
                 break;
                 // cas par defuat ne renvoyant rien
                 default:
                 exit(0.);
                }
      break;

      // choix de l'attaque par magie
      case 2 :
      joueur_a_attaquer = choix_personnage_a_attaquer();
      system("clear");
      switch (joueur_a_attaquer)
      {
        case 1:
        joueur1.attaquer_magique(goliath);
        cout << "vous avez attaqué goliath avec votre sort  " << endl;
        break;
        case 2:
        joueur1.attaquer_magique(Ogre);
        cout << "vous avez attaqué l'ogre avec votre sort " << endl;
        break;

        default:
        exit(0.);
      }
      break;


      // changer d'arme
      case 3:
      cout << "Vous avez choisi de changer d'armes !" << endl;
      int changement_arme_joueur; // indice donnant la position du nom de l'arme selcetionnée
      changement_arme_joueur = rand() % 199; // indice aléatoire
      if( changement_arme_joueur %2 == 1) // on fat en sorte qu'il soit pair car le vecteur est construit de maniere nom arme, degats, nom arme, degats etc...
      {
        changement_arme_joueur-=1;
      };
      // fonction permmettant le changement d'arme
      joueur1.changerArme(liste_armes[changement_arme_joueur],stoi(liste_armes[changement_arme_joueur+1]));
      cout << "Vous avez obtenu la nouvelle arme : " <<liste_armes[changement_arme_joueur]<< endl;
      cout << "elle produit : " <<stoi(liste_armes[changement_arme_joueur+1]);
      cout << " dégats" << endl;
      break;


      // changer de sort
      case 4:
      cout << "Vous avez choisi de changer de sort !" << endl;
      int changement_sort_joueur;
      changement_sort_joueur = rand() % 199;
      if( changement_sort_joueur %2 == 1)
      {
        changement_sort_joueur-=1;
      };
      joueur1.changerSort(liste_sort[changement_sort_joueur],stoi(liste_sort[changement_sort_joueur+1]));
      cout << "Vous avez obtenu le nouveau sort : " << liste_sort[changement_sort_joueur]<< endl;
      cout << "il produit : " << stoi(liste_sort[changement_sort_joueur+1]);
      cout << " dégats" << endl;
      break;


      // boire potion de vie
      case 5:
      int potion_vie_joueur1;
      potion_vie_joueur1 = rand()% 199;
      if (potion_vie_joueur1 %2 ==1)
      {
        potion_vie_joueur1--;
      };
      joueur1.boirePotionDeVie(stoi(liste_potions_vie[potion_vie_joueur1+1]));
      cout << "Vous avez bu la potion : " <<liste_potions_vie[potion_vie_joueur1]<< endl;
      cout << "vous récupérez: " << stoi(liste_potions_vie[potion_vie_joueur1+1]);
      cout << " points de vie" << endl;
      break;


      // boire potion de mana
      case 6:
      int potion_mana_joueur;
      cout << "Vous avez choisi de boire une potion de mana !" << endl;
      potion_mana_joueur = rand() % 199;
      if( potion_mana_joueur %2 == 1)
      {
        potion_mana_joueur-=1;
      };
      joueur1.boirePotionDeMana(stoi(liste_potion_mana[potion_mana_joueur+1]));
      cout << "Vous avez bu la potion : " <<liste_potion_mana[potion_mana_joueur]<< endl;
      cout << "vous récupérez: " << stoi(liste_potion_mana[potion_mana_joueur+1]);
      cout << " points de mana" << endl;
      break;

      // defautlt case si ça ne fonctionne pas
      default:
      exit(0.);
    }



    // tour de goliath
    if (goliath.estVivant()) // verif que goliath est vivant puis son tour
    {
      cout << "         " << endl;
      cout << "C'est au tour de goliath :" << endl;
      int choix_goliath1;
      choix_goliath1 = rand()% 6 +1; // defini l'action de goliath selon les même propositions que pour le joueur 1
      switch (choix_goliath1)
      {
        // choix de l'attque avec l'arme
        case 1:
        // on choisit alors quel adverse attaquer
        if (goliath.getPointdeVie() >100 &&Ogre.estVivant())
        {
          goliath.attaquer(Ogre);
          cout << "goliath a attaqué l'ogre à l'aide de son arme" << endl;
        }
        else if(goliath.getPointdeVie() <100 && Ogre.estVivant())
        {
          int choix_goliath2 = rand()%2+1;
          switch (choix_goliath2)
          {
            case 1:
            goliath.attaquer(joueur1);
            cout << "goliath vous a attaqué à l'aide de son arme " << endl;
            break;

            case 2:
            goliath.attaquer(Ogre);
            cout << "goliath a attaqué l'ogre à l'aide son arme " << endl;
            break;

            default:
            exit(0.);
          }
        }
        else
        {
          goliath.attaquer(joueur1);
          cout << "goliath vous a attaqué à l'aide de son arme " << endl;
        }
        break;

        case 2 :
        // on choisit alors quel adverse attaquer
        if (goliath.getPointdeVie()>50 && Ogre.estVivant())
        {
          goliath.attaquer_magique(Ogre);
          cout << "goliath a attaqué l'ogre avec un sort ! "<< endl;
        }
        else if(goliath.getPointdeVie() <50 &&Ogre.estVivant())
        {
          int choix_goliath2 = rand()%2+1;
          switch (choix_goliath2)
          {
            case 1:
            goliath.attaquer_magique(joueur1);
            cout<< "Goliath a utilisé un sort sur vous !" << endl;
            break;

            case 2:
            goliath.attaquer_magique(Ogre);
            cout<< "Goliath a utilisé un sort sur l'ogre !" << endl;
            break;

            default:
            exit(0.);
          }
        }
        else
        {
          goliath.attaquer_magique(joueur1);
          cout << "Goliath vous a attaqué avec un sort "<< endl;
        }
        break;

        case 3:
        cout << "goliath a choisi de changer d'armes !" << endl;
        int changement_arme_goliath;
        changement_arme_goliath = rand() % 199;
        if( changement_arme_goliath %2 == 1)
        {
          changement_arme_goliath-=1;
        };
        goliath.changerArme(liste_armes[changement_arme_goliath],stoi(liste_armes[changement_arme_goliath+1]));
        cout << "goliath a obtenu la nouvelle arme : " << liste_armes[changement_arme_goliath]<< endl;
        cout << "elle produit : " << stoi(liste_armes[changement_arme_goliath+1]);
        cout << " dégats" << endl;
        break;

        case 4:
        int changement_sort_goliath;
        cout << "goliath a choisi de changer de sort !" << endl;
        changement_sort_goliath = rand() % 199;
        if( changement_sort_goliath %2 == 1)
        {
          changement_sort_goliath-=1;
        };
        goliath.changerSort(liste_sort[changement_sort_goliath],stoi(liste_sort[changement_sort_goliath+1]));
        cout << "goliath a obtenu le nouveau sort : " << liste_sort[changement_sort_goliath]<< endl;
        cout << "il produit : " << stoi(liste_sort[changement_sort_goliath+1]);
        cout << " dégats" << endl;
        break;

       case 5:
       int potion_vie_goliath;
       potion_vie_goliath = rand()% 199;
       if (potion_vie_goliath %2 ==1)
       {
         potion_vie_goliath--;
       };
       goliath.boirePotionDeVie(stoi(liste_potions_vie[potion_vie_goliath+1]));
       cout << "Goliath a bu la potion : " <<liste_potions_vie[potion_vie_goliath]<< endl;
       cout << "Il récupère : " << stoi(liste_potions_vie[potion_vie_goliath+1]);
       cout << " points de vie" << endl;
       break;


        case 6:
        int potion_mana_goliath;
        cout << "Goliath a choisi de boire une potion de mana !" << endl;
        potion_mana_goliath = rand() % 199;
        if( potion_mana_goliath %2 == 1)
        {
          potion_mana_goliath-=1;
        };
        goliath.boirePotionDeMana(stoi(liste_potion_mana[potion_mana_goliath+1]));
        cout << "Goliath a bu la potion : " <<liste_potion_mana[potion_mana_goliath]<< endl;
        cout << "Goliath récupère: " << stoi(liste_potion_mana[potion_mana_goliath+1]);
        cout << " points de mana" << endl;
        break;

        default:
        exit(0.);
      }
    }
    else // renvoie message d'erreur si il est mort
    {
      cout << "             " << endl;
      cout << "Goliath est mort il ne participe donc plus au combat " << endl;
    }


    // tour de l'ogre
    if (Ogre.estVivant()) // verification que l'ogre est vivant puis son tour
    {
      cout << "         " << endl;
      cout << "C'est au tour de l'ogre :" << endl;
      int choix_ogre1 = rand()% 6 +1; // defini l'action de goliath selon les même propositions que pour le joueur 1
      switch (choix_ogre1)
      {
        // choix de l'attque avec l'arme
        case 1:
        // on choisit alors quel adverse attaquer
        if (goliath.estVivant())
        {
          int choix_ogre2 = rand()%2+1;
          switch (choix_ogre2)
          {
            case 1:
            Ogre.attaquer(joueur1);
            cout << "L'ogre vous a attaqué à l'aide de son arme " << endl;
            break;

            case 2:
            Ogre.attaquer(goliath);
            cout << "L'ogre a attaqué goliath à l'aide son arme " << endl;
            break;

            default:
            exit(0.);
          }
        }
        else
        {
          Ogre.attaquer(joueur1);
          cout << "L'ogre vous a attaqué avec son arme" << endl;
        }
        break;


        case 2 :
        // on choisit alors quel adverse attaquer
        if (goliath.estVivant())
        {
          int choix_ogre2 = rand()%2+1;
          switch (choix_ogre2)
          {
            case 1:
            Ogre.attaquer_magique(joueur1);
            cout << "L'ogre vous a attaqué à l'aide d'un sort " << endl;
            break;

            case 2:
            Ogre.attaquer_magique(goliath);
            cout << "L'ogre a attaqué goliath à l'aide d'un sort " << endl;
            break;

            default:
            exit(0.);
          }
        }
        else
        {
          Ogre.attaquer_magique(joueur1);
          cout << "L'ogre vous a attaqué avec un sort !" << endl;
        }
        break;


        case 3:
        int changement_arme_Ogre;
        cout << "Ogre a choisi de changer d'armes !" << endl;
        changement_arme_Ogre = rand() % 199;
        if( changement_arme_Ogre %2 == 1)
        {
          changement_arme_Ogre-=1;
        };
        Ogre.changerArme(liste_armes[changement_arme_Ogre],stoi(liste_armes[changement_arme_Ogre+1]));
        cout << "L'ogre a obtenue la nouvelle arme : " << liste_armes[changement_arme_Ogre]<< endl;
        cout << "elle produit : " << stoi(liste_armes[changement_arme_Ogre+1]);
        cout << " dégats" << endl;
        break;

        case 4:
        int changement_sort_Ogre;
        cout << "L'Ogre a choisi de changer de sort !" << endl;
        changement_sort_Ogre = rand() % 199;
        if( changement_sort_Ogre %2 == 1)
        {
          changement_sort_Ogre-=1;
        };
        Ogre.changerSort(liste_sort[changement_sort_Ogre],stoi(liste_sort[changement_sort_Ogre+1]));
        cout << "Ogre a obtenu le nouveau sort : " << liste_sort[changement_sort_Ogre]<< endl;
        cout << "il produit : " << stoi(liste_sort[changement_sort_Ogre+1]);
        cout << " dégats" << endl;
        break;

        case 5:
        int potion_vie_Ogre;
        potion_vie_Ogre = rand()% 199;
        if (potion_vie_Ogre %2 ==1)
        {
          potion_vie_Ogre--;
        };
        Ogre.boirePotionDeVie(stoi(liste_potions_vie[potion_vie_Ogre+1]));
        cout << "L'ogre a bu la potion : " <<liste_potions_vie[potion_vie_Ogre]<< endl;
        cout << "il récupère: " << stoi(liste_potions_vie[potion_vie_Ogre+1]);
        cout << " points de vie" << endl;
        break;

        case 6:
        int potion_mana_Ogre;
        cout << "L'ogre a choisi de boire une potion de mana !" << endl;
        potion_mana_Ogre = rand() % 199;
        if( potion_mana_Ogre %2 == 1)
        {
          potion_mana_Ogre-=1;
        };
        Ogre.boirePotionDeMana(stoi(liste_potion_mana[potion_mana_Ogre+1]));
        cout << "Il a bu la potion : " <<liste_potion_mana[potion_mana_Ogre]<< endl;
        cout << "Il récupère : " << stoi(liste_potion_mana[potion_mana_Ogre+1]);
        cout << " points de mana" << endl;
        break;

        default:
        exit(0.);
      }
    }
    else //renvoie message d'erreur si il est mort
    {
      cout << "             " << endl;
      cout << "L'Ogre est mort il ne participe donc plus au combat " << endl;
    }

    // verififcation de victoire
    if (goliath.estVivant() == false && Ogre.estVivant()==false)
    {
      system("clear");
      cout <<"FELICITATION VOUS AVEZ GAGNE LA PARTIE"<< endl;
      exit(0.);
    }


    // affichage des status des personnages enore en liste.
    cout <<  "**** Appuyez sur entrer pour voir le statut des joueurs " << endl ;
    getline(cin,enter);

    afficher_statuts(compte_tour, joueur1, goliath, Ogre);



  } while(joueur1.estVivant()); // conditions de la boucle do


  // Message final si notre personnage est mort.
  cout << "VOUS AVEZ PERDU !" << endl;
  cout << "RELANCEZ LE PROGRAMME POUR REESSAYER" << endl;



return 0;
}
