//
//  affichage.cpp
//  projet_algo
//
//  Created by Alex on 11/12/2013.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include "affichage.h"
#include "arbres.h"
#include <iostream>

using namespace std;

void menu(){
	int choix = 0;
	cout << "1. Fonctions de dictionnaire" << endl;
	cout << "2. Fonctions de mots" << endl;
	cout << "3. Fonctions d'écriture" << endl;
	cout << "Indiquez votre choix" << endl; 
	cin >> choix;
	direction(choix);
}


int direction(int c){
	char mot[27];
	ptarbre arbre = creationarbre();
	switch (c) {
        case 1:
            cout << "Entrez un mot : ";
            cin >> mot;
            ajout(mot, arbre);
            break;
        case 2:
        	cout << "Faites quelque chose.";
            break;
        /*case 3:
            exercice3();
            break;
        case 4:
            exercice4();
            break;
        case 5:
            exercice5();
            break;*/
        default:
            break;
    }
    
    return 0;
}