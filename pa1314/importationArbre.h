//
//  importationArbre.h
//  projet_algo
//
//  Created by Olivier on 09/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#ifndef __importationArbre_h__
#define __importationArbre_h__

#define LONGUEUR_MOT 50

#include "arbres.h"

// char* init_mot(char mot[]);
ptarbre constructionArbre(void);
void enregistrer_dico(char nom[], char mot[], int i, ptarbre arbre);



#endif