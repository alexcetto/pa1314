<?php

affichage(str début, pta arbre)
{
	if ( arbre -> c  == ‘\0’)
	{
		cout << début ;
		
		if(frêre != NULL)
		{
		affichage( début, frère) ;
		}
		else
		{
			if (cherchertonton != NULL)
			{
				debut = debut - caractère précédent ;
				affichage(début, cherchertonton(arbre));
			}
		}
	}
	else
	{
		affichage(début, fils) ;
	}

}
