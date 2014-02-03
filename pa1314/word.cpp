//
//  word.cpp
//  projet_algo
//
//  Created by Alex on 13/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include <iostream>
#include <ctype.h> // Fonctions sur les caractères
//#include <ncurses.h>
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
// Méthode en prévision de l'algo  de complétion par placement dans la phrase
void writeSentence(wordStart nword){
    int i = 0;
    // n'importe quoi, à refaire
    while (sentence[i] != NULL) {
        i++;
    }
    sentence[i] = nword;
    //readSentence(nword);
}


void showSearch(wordStart nword){
    char *localword = nword->mot;
    *localword = formatage(localword);
    cout << recherchePartielle(localword, truc);
    
}

// Simple fonction de saisie pour entrer chaque mot.
// Dès qu'un //(espace) étoile est saisi, le programme écrit le mot dans la phrase.
void writeword(){
    wordStart newWord = createWord();
    
    //initscr();
    
    int i = 0;
    char c = 'c';
    //while (!isspace(c) || !isblank(c)) {
    while (c != '*') {
        cin >> c;
        //c = getchar();
        newWord->mot[i] = c;
        i++;
        if(c == '.'){
            return;                 // Transformer en phrase suivante
        } else if(c == '#'){
            readSentence(sentence);
        }
    }
    
    newWord->mot[i-1] = '\0';
    newWord->nblettres = i;
    showSearch(newWord);
    writeSentence(newWord);
    
    writeword();
    //readWord(newWord);
    //endwin();
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