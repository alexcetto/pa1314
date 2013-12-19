<?php

pta cherchertonton (pta arbre)
{
	arbre = arbre->père;

	if(arbre-> frère != NULL)
	{
		return(frère);
	}
	else
	{
		return(cherchertonton(arbre));
	}

}

Command renvoyer le nombre de remonté ?