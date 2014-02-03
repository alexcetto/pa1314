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
#include "string.h"
#include "traitement.h"
#include "word.h"
#include <iostream>

using namespace std;

//test
char dicob[] = "/Users/alex/C_C++/projet_algo_xcode/pa1314/dico_complet2.txt";
ptarbre truc1 = constructionArbre(dicob, truc1);

void menu(ptarbre arbre){
    //system("clear");
	int choix = 0;
	cout << "1. Ajouter un mot" << endl;
	cout << "2. Recherche partielle" << endl;
	cout << "3. Affichage" << endl;
    cout << "4. Importation d'un dico" << endl;
    cout << "5. Enregistrement du dico" << endl;
    cout << "6. Test de l'écriture de mot" << endl;
	cout << "0. Quitter" << endl;
	cout << "Indiquez votre choix" << endl; 
	cin >> choix;
	direction(choix, arbre);
}

void direction(int c, ptarbre b2){
	char mot[27];
    char nom[500];
    // ptarbre b1 = creationArbreTest();
    // ptarbre b2 = NULL;
	switch (c) {
		case 0: return; 
        case 1:
            cout << "Entrez un mot : ";
            cin >> mot;
            *mot = formatage(mot);
            b2 = ajout(mot, b2);
            cout << "Affichage en cours..." << endl;
            affichage(mot, 0, b2);
            cout << "Entrez le nom du fichier destination :" << endl;
            cin >> nom;
            cout << "Sauvegarde en cours..." << endl;
            enregistrer_dico(nom, mot, 0, b2);
            break;
        case 2:
        	cout << "Entrez la base du mot à chercher : ";
        	cin >> mot;
        	recherchePartielle(mot, truc1, NULL, NULL);
            break;
        case 3:
            affichage(mot, 0, b2);
            break;
        case 4:
            cout << "Entrez le nom du dictionnaire à importer :" <<endl;
            cin >> nom;
            cout << "Importation de dico.txt en cours..." << endl;
            b2 = constructionArbre(nom, b2);
            cout << "Affichage du nouvel arbre..." << endl;
            affichage(mot, 0, b2);
            break;
        case 5:
            cout << "Entrez le nom du fichier destination :" << endl;
            cin >> nom;
            affichage(mot, 0, b2);
            remove(nom);
            cout << "Enregistrement en cours..." << endl;
            enregistrer_dico(nom, mot, 0, b2);
            break;
        case 6:
            writeword();
        default:
        	menu(b2);
            break;
    }
    menu(b2);
    return;
}