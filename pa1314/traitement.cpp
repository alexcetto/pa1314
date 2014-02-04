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
	unsigned long i = 0;
	i = strlen(mot);
	mot[i+1] = '\0';

	int j = 0;
	for(j=0 ; mot[i] == '\0' ; j++)
	{
		if (isalpha(mot[j]))
		{
			mot[j] = tolower(mot[j]);
		}
	}
	return  *mot;
}