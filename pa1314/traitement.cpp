//
//  Created by Alex on 11/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include "arbres.h"
#include "importationArbre.h"
#include "string.h"
#include "traitement.h"
#include <iostream>

using namespace std;

char formatage(char mot[]){
	int i = 0;
	i = strlen(mot);
	cout << "strlen : " << i << endl;
	mot[i+1] = '\0';
	return  *mot;
}