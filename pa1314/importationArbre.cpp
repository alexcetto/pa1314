//
//  importationArbre.h
//  projet_algo
//
//  Created by Olivier on 09/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include <iostream>
#include "importationArbre.h"
#include "arbres.h"
using namespace std;

// Initialisation du mot avec \0 à la fin
// char * init_mot(char mot[])
// {
// 	int j=0;

// 	for (j = 0; j < LONGUEUR_MOT; j++)
// 	{
// 		mot[j]='\0';
// 	}

// 	return &(mot[0]);
// }

// Construction de l'arbre à partir du .txt
ptarbre constructionArbre(void) 
{
	FILE* dico = NULL;
	ptarbre arbre;

	dico = fopen("/Users/alex/C_C++/projet_algo_xcode/pa1314/dico_complet.txt", "r");

	if (dico != NULL)
	{
		cout << "L'ouverture a réussi !\n";
<<<<<<< HEAD
<<<<<<< HEAD
		char mot[LONGUEUR_MOT];
			while(fgets(mot, LONGUEUR_MOT, dico) != NULL)
=======
=======
>>>>>>> 6b1f1f63f29a28586b7dc2184c05c352fc1d82fd
		char mot[15];
		// mot = NULL;
		cout << "Test 1" << endl;
			while(fgets(mot, 15, dico) != NULL)
<<<<<<< HEAD
>>>>>>> 6b1f1f63f29a28586b7dc2184c05c352fc1d82fd
=======
>>>>>>> 6b1f1f63f29a28586b7dc2184c05c352fc1d82fd
			{
				cout << "Test 2" << endl;
				printf(mot);
				arbre = ajout(mot, arbre);
			}
		fclose(dico);
	} else {
		cout << "Echec de l'ouverture....\n";
		arbre = NULL;
	}

	return arbre;
}

void enregistrer_dico(char nom[], char mot[], int i, ptarbre arbre)
{
	// Ouverture du fichier
	FILE* fichier = NULL;

	fichier = fopen(nom, "a");
	if (fichier != NULL)
	{
		if(arbre == NULL) 
		{
			return;
		}
		mot[i] = arbre->c;

		if (mot[i] == '\0')
		{
			// Ecriture dans le fichier
			fputs(mot, fichier);
			fprintf(fichier, "\n");

			enregistrer_dico(nom, mot, i, arbre->frere);
		}
		else
		{
			enregistrer_dico(nom, mot, i+1, arbre->fils);
			enregistrer_dico(nom, mot, i, arbre->frere);
			
		}
	fclose(fichier);
	}
}
