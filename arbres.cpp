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


// Description de nos arbres, avec une lettre, un frère et un fils
typedef struct arbre{
    char alpha          ;
    struct arbre * frere;
    struct arbre * fils ;
} t_maillon, * ptarbre  ;

int bienLeBonjour(){
    cout << "Bien le bonjour chez vous !";
    
    return 1;
}