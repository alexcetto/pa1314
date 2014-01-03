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

ptarbre creationarbre(){
	ptarbre arbre = NULL;
	return arbre;
}

void affichage(char mot[], int i, ptarbre arbre){
	if(arbre == NULL) return;

	mot[i] = arbre->c;

	if(arbre->c == '\0') cout << mot << endl;
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
		while(mot[i] != '\0'){
			arbre->c = mot[i];
			// Reconstruit le nouvel arbre
			return arbre;
		}
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