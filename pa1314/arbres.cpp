//
//  arbres.cpp
//  projet_algo
//
//  Created by Alex on 08/12/2013.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//
#include <iostream>
#include "arbres.h"
using namespace std;

ptarbre creationArbreTest(void)
{

	/*Initialisation a NULL*/
	ptarbre b1 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b2 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b3 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b4 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b5 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b6 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b7 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b8 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b9 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b10 = (ptarbre) malloc(sizeof(maillon));
	ptarbre b11 = (ptarbre) malloc(sizeof(maillon));


    /*Construction de l'arbre*/
	b1->c = 'c';
	b1->fils = b2;
	b1->frere = NULL;

	b2->c = 'a';
	b2->frere = b4;
	b2->fils = b3;

	b3->c = '\0';
	b3->fils= NULL;
	b3->frere = NULL;

	b4->c ='e';
	b4->fils = b5;
	b4->frere  = NULL;

	b5->c = '\0';
	b5->fils = NULL;
	b5->frere = b6;

	b6->c = 'c';
	b6->fils = b7;
	b6->frere = b9;

	b7->c = 'i';
	b7->fils = b8;
	b7->frere = NULL;

	b8->c = '\0';
	b8->fils = NULL;
	b8->frere = NULL;

	b9->c = 'l';
	b9->fils = b10;
	b9->frere = NULL;

	b10->c = 'a';
	b10->fils = b11;
	b10->frere = NULL;

	b11->c = '\0';
	b11->frere = NULL;
	b11->fils = NULL;
    
    return b1;
}

ptarbre creationarbre(){
	ptarbre arbre = NULL;
	return arbre;
}

ptarbre creer_noeud(char alpha, ptarbre frere, ptarbre fils)
{
	ptarbre aux;
	aux = (ptarbre)malloc(sizeof(maillon));
	aux->c = alpha;
	aux->frere = frere;
	aux->fils = fils;

	return aux;
}

// Ca marche
void affichage(char mot[], int i, ptarbre arbre){
	if(arbre == NULL) return;

	mot[i] = arbre->c;

	if(arbre->c == '\0') 
		{
			cout << mot << endl;
			affichage(mot, i, arbre->frere);
		}
	else {
		affichage(mot, i+1, arbre->fils);
		affichage(mot, i, arbre->frere);
	}
}

bool recherche(char mot[], ptarbre arbre){
	if(arbre == NULL) return false;
	if(mot[0] == arbre->c){
		if(mot[0] == '\0') return true;
		else return recherche(&mot[1], arbre->fils);
	} else {
		if(arbre->c > mot[0]){
			return false;
		} else {
			return recherche(mot, arbre->frere);
		}
		return recherche(mot, arbre->frere);
	}
}

ptarbre ajout(char mot[], ptarbre arbre){
	if(arbre == NULL){
		int i = 0;
		ptarbre nouveau;
		ptarbre suivant;
		while(mot[i] != '\0' && i<= 49){
			nouveau = creer_noeud(mot[i], NULL, suivant);
			nouveau = suivant;
			i++;
		}
		affichage(mot, 0, nouveau);
		cout << "arbre fait" << endl;
		return nouveau;
	}
	if(mot[0] == arbre->c && mot[0] != '\0'){
		arbre->fils = ajout(&mot[1], arbre->fils);
	} else {
		if(mot[0] > arbre->c){
			arbre->frere = ajout(mot, arbre->frere);
		} else if(mot[0] < arbre->c) {
			arbre->frere = arbre;
			return arbre; 
		}
	}
}



