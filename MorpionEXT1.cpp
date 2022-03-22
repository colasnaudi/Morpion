/*
 Programme : Morpion
 But : Jeu du morpion
 Date de dernière modification : 10 Novembre 2021
 Auteur : Colas NAUDI
 Remarques : Code conforme à l'algorithme données en cours
*/

#include <iostream>
#include "ligneColonne.h"
using namespace std;

void afficheMorpion(char tab[3][3]);

int determinerLigne(string saisieJoueur, int& Ligne);
int determinerColonne(string saisieJoueur, int& Colonne);

int main (void)
{
    /////////////////////////////////
    // V A R I A B L E S
    string prenomJ1;
    string prenomJ2;
    char symboleJ1;
    char symboleJ2;
    int ligne;
    int colonne;
    string choixJoueur;
    char tab[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    unsigned short int nbTour = 0;
    bool abandon = false;
    string gagnant;
    string perdant;
    bool estGagne = false;
    bool casePrise;
    string dernierJoueur;
    /////////////////////////////////
    // T R A I T E M E N T S

    //Affichage des règles
    cout << "---------------- M O R P I O N ----------------" << endl;
    cout << endl;
    cout << "Jeu avec 2 joueurs humains et une grille de 9 cases : 3 lignes et 3 colonnes." << endl;
    cout << "Chaque joueur joue a tour de role." << endl;
    cout << "Le but du jeu est d'aligner, avant son adversaire, 3 symboles identiques, horizontalement, verticalement ou en diagonale" << endl;
    cout << endl;
    cout << "La partie se termine :" << endl;
    cout << "- quand l'un des joueurs a aligne ses 3 symboles, et il gagne," << endl;
    cout << "- quand la grille est complete, et il y a egalite (pas de gagnant)" << endl;
    cout << "- quand l'un des joueurs abandonne, et c'est alors l'autre joueur qui gagne." << endl;
    cout << "Chaque joueur a donc son propre symbole." << endl;
    cout << endl;
    cout << "Dans cette version du Morpion, une phrase prealable de personnalisation permet a chaque joueur de saisir son prenom et le symbole choisi pour jouer." << endl;
    cout << "Lorsqu'arrive son tour de jouer, un joueur peut :" << endl;
    cout << "- saisir la position de la case ou placer son symbole, sous la forme LigneColonne (exemple : 12 pour Ligne 1, Colonne 2)" << endl;
    cout << "- saisir A (ou a) pour abandonner le jeu" << endl;
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;

    //Phase de personnalisation
    cout << "- - -   Phase de personnalisation  - - -" << endl;
    cout << endl;
    cout << "JOUEUR 1, entrez votre prenom : ";
    cin >> prenomJ1;
    cout <<  prenomJ1 << ", entrez votre symbole (1 lettre ou 1 chiffre) : ";
    cin >> symboleJ1;
    do
    {
        cout << "JOUEUR 2, entrez votre prenom : ";
        cin >> prenomJ2;
    } while (prenomJ2==prenomJ1);
    cout << prenomJ2 << ", entrez votre symbole (1 lettre ou 1 chiffre), autre que '" << symboleJ1 << "' : ";
    cin >> symboleJ2;

    //Jeu du morpion
    while (true)
    {
        nbTour++;

        //Affichage du morpion
        cout << "Tour numero " << nbTour << endl;
        cout << endl;
        cout << "[ " << tab[0][0] << " | " << tab[0][1] << " | " << tab[0][2] << " ]" << endl;
        cout << "[ " << tab[1][0] << " | " << tab[1][1] << " | " << tab[1][2] << " ]" << endl;
        cout << "[ " << tab[2][0] << " | " << tab[2][1] << " | " << tab[2][2] << " ]" << endl;

        //Saisie du joueur 1
        if(nbTour%2!=0)
        {
            cout << "--> " << prenomJ1 << ", entrez :" << endl;
            cout << endl;
            do
            {
                cout << "Une coordonnee (LigneColonne, ex. : 12 pour Ligne 1, Colonne 2), ou bien A(bandonner)" << endl;
                cout << endl;
                cout << "Votre choix ? : ";
                cin >> choixJoueur;

                determinerLigne(choixJoueur, ligne);
                determinerColonne(choixJoueur, colonne);
                casePrise = false;
                if ((tab[ligne][colonne]==symboleJ1)||(tab[ligne][colonne]==symboleJ2))
                {
                    casePrise = true;
                }

            }while ((casePrise==true)||!((choixJoueur=="A")||(choixJoueur=="11")||(choixJoueur=="12")||(choixJoueur=="13")||(choixJoueur=="21")||(choixJoueur=="22")||(choixJoueur=="23")||(choixJoueur=="31")||(choixJoueur=="32")||(choixJoueur=="33")));

            if (choixJoueur == "A")
            {
                abandon = true;
                perdant = prenomJ1;
                gagnant = prenomJ2;
                break;
            }
            dernierJoueur = prenomJ1;
        }
        //Saisie du joueur 2
        else 
        {
            cout << "--> " << prenomJ2 << ", entrez :" << endl;
            cout << endl;
            do
            {
                cout << "Une coordonnee (LigneColonne, ex. : 12 pour Ligne 1, Colonne 2), ou bien A(bandonner)" << endl;
                cout << endl;
                cout << "Votre choix ? : ";
                cin >> choixJoueur;

                determinerLigne(choixJoueur, ligne);
                determinerColonne(choixJoueur, colonne);
                casePrise = false;
                if ((tab[ligne][colonne]==symboleJ1)||(tab[ligne][colonne]==symboleJ2))
                {
                    casePrise = true;
                }

            }while ((casePrise==true)||!((choixJoueur=="A")||(choixJoueur=="11")||(choixJoueur=="12")||(choixJoueur=="13")||(choixJoueur=="21")||(choixJoueur=="22")||(choixJoueur=="23")||(choixJoueur=="31")||(choixJoueur=="32")||(choixJoueur=="33")));

            if (choixJoueur == "A")
            {
                abandon = true;
                perdant = prenomJ2;
                gagnant = prenomJ1;
                break;
            }
            dernierJoueur = prenomJ2;
        }

        //Si le joueur n'abandonne par et que le nombre de tour est impair alors on ajoute le symbole du joueur 1
        if((choixJoueur!="A")&&(!(nbTour%2==0)))
        {
            tab[ligne][colonne] = symboleJ1;
        }
        //Sinon si le joueur n'abandonne pas on ajoute celui du joueur 2
        else if (choixJoueur!="A")
        {
            tab[ligne][colonne] = symboleJ2;
        }

        //Recherche d'une ligne gagnante
        if(nbTour >= 5)
        {
            //Verification lignes horizontales
            if (tab[0][0]==tab[0][1])
            {
                if((tab[0][1]!=' ')&&(tab[0][1]==tab[0][2]))
                {
                    cout << endl << "11" << endl;
                    estGagne = true;
                }
            }
            
            if((estGagne == false) && (tab[1][0]==tab[1][1]))
            {
                if((tab[1][1]!=' ')&&(tab[1][1]==tab[1][2]))
                {
                    cout << endl << "12" << endl;
                    estGagne = true;
                }
            }

            if((estGagne == false) && (tab[2][0]==tab[2][1]))
            {
                if((tab[2][1]!=' ')&&(tab[2][1]==tab[2][2]))
                {
                    cout << endl << "13" << endl;
                    estGagne = true;
                }
            }

            //Verification lignes verticales
            if ((estGagne == false) && (tab[0][0]==tab[1][0]))
            {
                if((tab[1][0]!=' ')&&(tab[1][0]==tab[2][0]))
                {
                    cout << endl << "21" << endl;
                    estGagne = true;
                }
            }
            
            if((estGagne == false) && (tab[0][1]==tab[1][1]))
            {
                if((tab[1][1]!=' ')&&(tab[1][1]==tab[2][1]))
                {
                    cout << endl << "22" << endl;
                    estGagne = true;
                }
            }

            if((estGagne == false) && (tab[0][2]==tab[1][2]))
            {
                if((tab[1][2]!=' ')&&(tab[1][2]==tab[2][2]))
                {
                    cout << endl << "23" << endl;
                    estGagne = true;
                }
            }

            //Verification diagonales
            if((estGagne == false) && (tab[0][0]==tab[1][1]))
            {
                if((tab[1][1]!=' ')&&(tab[1][1]==tab[2][2]))
                {
                    cout << endl << "31" << endl;
                    estGagne = true;
                }
            }

            if((estGagne == false) && (tab[0][2]==tab[1][1]))
            {
                if((tab[1][1]!=' ')&&(tab[1][1]==tab[2][0]))
                {
                    cout << endl << "32" << endl;
                    estGagne = true;
                }
            }
        }

        //Afficher le dernier tableau
        if ((estGagne == true) || (nbTour == 9))
        {
            cout << endl;
            cout << "[ " << tab[0][0] << " | " << tab[0][1] << " | " << tab[0][2] << " ]" << endl;
            cout << "[ " << tab[1][0] << " | " << tab[1][1] << " | " << tab[1][2] << " ]" << endl;
            cout << "[ " << tab[2][0] << " | " << tab[2][1] << " | " << tab[2][2] << " ]" << endl;
            break;
        }
    }

    //Affichage du gagant
    cout << endl;
    cout << "- - -   Fin de la partie   - - - " << endl;
    cout << endl;

    if(abandon == true)
    {
        cout << "Partie gagnee par " << gagnant << " suite a l'abandon de " << perdant << " au Tour numero " << nbTour << endl;
    }
    else if ((abandon == false)&&(nbTour==10))
    {
        cout << "Egalite (pas de gagnant) car grille complete" << endl;
    }
    else
    {
        cout << "Partie gagnee par " << dernierJoueur << " au Tour numero " << nbTour << endl;
    }
    
    return 0;
}

void afficheMorpion(char tab[3][3])
{
    for (unsigned short int ligne = 0; ligne < 5 ; ligne++)
    {
        if (ligne % 2 != 0 )            {cout << endl << "---|---|---" << endl;}

        else
        {
            for (unsigned short int colonne = 0; colonne < 5 ; colonne++)
            {
                if (colonne % 2 == 0)   {cout << " " << tab[ligne/2][colonne/2] << " ";}
                else                    {cout << "|";}
            }
        }
    }
}

int determinerColonne(string saisieJoueur, int& Colonne)
{
    switch (saisieJoueur[1])
    {
    case '1':
        Colonne = 0;
        break;
    case '2':
        Colonne = 1;
        break;
    case '3':
        Colonne = 2;
        break;
    }
    return Colonne;
}

int determinerLigne(string saisieJoueur, int& Ligne)
{
    switch (saisieJoueur[0])
    {
    case '1':
        Ligne = 0;
        break;
    case '2':
        Ligne = 1;
        break;
    case '3':
        Ligne = 2;
        break;
    }
    return Ligne;
}