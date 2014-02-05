//
//  word.cpp
//  projet_algo
//
//  Created by Alex on 13/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include <iostream>
#include <ctype.h> // Fonctions sur les caractères
#include <ncurses.h>
#include "importationArbre.h"
#include "arbres.h"
#include "word.h"
#include "traitement.h"
using namespace std;


wordStart sentence[proust] = {};
char dico[] = "/Users/alex/C_C++/projet_algo_xcode/pa1314/dico_complet2.txt";
ptarbre truc = constructionArbre(dico, truc);

// Allocation mémoire pour un mot.
wordStart createWord(){
    wordStart newWord = (wordStart)malloc(sizeof(wordStart));
    return newWord;
}

// Ecrit dans la console tous les mots de la phrase
void readSentence(wordStart sentence[]){
    int i = 0;
    //wordStart temp[] = {};
    while(i < proust && sentence[i] != NULL){
        if(i != 0){
            cout << ' ';
        }
        //temp = &sentence[i];
        cout << sentence[i]->mot;
        i++;
    }
}

// Enregistre la phrase au fur et à mesure en ajoutant les mots dans le tableau
// Méthode en prévision de l'algo  de complétion par placement dans la phrase ?
void writeSentence(wordStart nword){
    int i = 0;
    // n'importe quoi, à refaire
    while (sentence[i] != 0) {
        i++;
    }
    sentence[i] = nword;
    //readSentence(nword);
}


void showSearch(wordStart nword){
    char *localword = nword->mot;
    
    ptarbre miniarbre = creationarbre();
    
    *localword = formatage(localword);
    cout << "Mots affichés : "<< endl;
    recherchePartielle(localword, truc, 1, miniarbre);
    affichage(localword, 0, miniarbre);
    free(miniarbre);
}

// Simple fonction de saisie pour entrer chaque mot.
void writeword(){
    wordStart newWord = createWord();
    
    initscr();
    printw("********************** Programme de saisie de texte *******************");
    printw("\n");
    printw("** Entrez lettre après lettre pour voir les différentes propositions **");
    printw("\n");
    printw("******** Un espace termine le mot et un point termine la phrase *******");
    printw("\n");
    printw("***** Les chiffres 1 à 5 permettent de choisir la bonne complétion ****");
    printw("\n");
    cbreak();
    int i = 0;
    int c = 0;

    while (c != 46) { // Si le caractère est un point, fin de la phrase
        c = getch();
        if(c >= 97 && c <= 122){ // Si c'est une lettre de l'alphabet
            char aux = (char)c;
            newWord->mot[i] = aux;
            showSearch(newWord);    // Fais une recherche de complétion
            i++;
        } else if(c == 32){ // Espace signifie mot terminé
            newWord->nblettres = i;
            newWord->mot[i-1] = '\0';
            writeSentence(newWord);
            writeword();
        } else if(c >= 49 && c <= 53){
            c = c % 48; // Obtenir le choix correspondant à la touche tapée
            cout << c;
            // Choix de la complétion
        }// else if(c == ) // Suppr supprime la dernière lettre
        //else if // echappe retoune à main et écrit dans le fichier output
        refresh();
    }
    endwin();
}


// Un programme qui lit les mots qu'on lui envoie.
void readWord(wordStart nword){
    int length = (int)strlen(nword->mot);
    char c = 'c';
    int j = 0;
    
    while (c != '\0' && j < length) {
        cout << nword->mot[j];
        j++;
    }
    cout << endl;
}