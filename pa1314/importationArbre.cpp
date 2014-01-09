//
//  importationArbre.h
//  projet_algo
//
//  Created by Olivier on 09/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include <iostream>
#include "importationArbre.h"
using namespace std;

// Initialisation du mot avec \0 à la fin
char * init_mot(char mot[])
{
	int j=0;

	for (j = 0; j < LONGUEUR_MOT; j++)
	{
		mot[j]='\0';
	}

	return &(mot[0]);
}

// Construction de l'arbre à partir du .txt
ptarbre constructionArbre(ptarbre arbre) 
{
	FILE* dico = NULL;

	dico = fopen("dico.txt", "r");

	if (dico != NULL)
	{
		cout << "L'ouverture a réussi !\n";
		char mot[LONGUEUR_MOT];
		mot = init_mot(mot);
			while(fgets(mot, LONGUEUR_MOT, dico) != NULL)
			{
				arbre = ajout(mot, arbre);
			}
		fclose(dico);
	}
	else
	{
		cout << "Echec de l'ouverture....\n";
		arbre = NULL;
	}

	return arbre;
}