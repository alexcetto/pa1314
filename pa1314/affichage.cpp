//
//  affichage.cpp
//  projet_algo
//
//  Created by Alex on 11/12/2013.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include "affichage.h"
#include "arbres.h"
#include "importationArbre.h"
#include <iostream>

using namespace std;

void menu(){
	int choix = 0;
	cout << "1. Fonctions de dictionnaire" << endl;
	cout << "2. Fonctions de mots" << endl;
	cout << "3. Fonctions d'écriture" << endl;
    cout << "4. Importation d'un dico" << endl;
    cout << "5. Enregistrer l'arbre dans un dico" << endl;
	cout << "Indiquez votre choix" << endl; 
	cin >> choix;
	direction(choix);
}


int direction(int c){
	char mot[27];
    char nom[50];
    ptarbre b1 = creationArbreTest();
    ptarbre b2;
	switch (c) {
        case 1:
            cout << "Entrez un mot : ";
            cin >> mot;
            b2 = ajout(mot, b2);
            cout << "Affichage en cours..." << endl;
            affichage(mot, 0, b2);
            break;
        case 2:
        	cout << "Faites quelque chose.";
            break;
        case 3:
            affichage(mot, 0, b1);
            break;
        case 4:
            cout << "Importation de dico.txt en cours..." << endl;
            affichage(mot, 0, constructionArbre(b1));
            break;
        case 5:
            affichage(mot, 0, b1);
            cout << "Entrez le nom du dico :" <<endl;
            cin >> nom;
            remove(nom);
            enregistrer_dico(nom, mot, 0, b1);
            break;
        default:
            break;
    }
    
    return 0;
}