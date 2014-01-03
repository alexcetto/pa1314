//
//  arbres.h
//  projet_algo
//
//  Created by Alex on 08/12/2013.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#ifndef projet_algo_arbres_h
#define projet_algo_arbres_h

// Description de nos arbres, avec une lettre, un frère et un fils
typedef struct arbre{
    char c          ;
    struct arbre * frere;
    struct arbre * fils ;
} maillon, * ptarbre  ;



ptarbre creationarbre();
void affichage(char mot[], int i, ptarbre arbre);
bool recherche(char mot[], ptarbre arbre);
ptarbre ajout(char mot[], ptarbre arbre);

#endif
