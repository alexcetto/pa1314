//
//  word.cpp
//  projet_algo
//
//  Created by Alex on 13/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#include <iostream>
#include "importationArbre.h"
#include "arbres.h"
#include "word.h"
#include <ctype.h>
using namespace std;

wordStart sentence[10] = {};


// Allocation mémoire pour un mot.
wordStart createWord(){
    wordStart newWord = (wordStart)malloc(sizeof(wordStart));
    return newWord;
}


// Ecrit dans la console tous les mots de la phrase
void readSentence(wordStart sentence){
    int i = 0;
    wordStart temp = NULL;
    while(i < 50){
        temp = &sentence[i];
        cout << temp->mot;
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
    readSentence(nword);
}

// Simple fonction de saisie pour entrer chaque mot.
// Dès qu'un //(espace) étoile est saisi, le programme écrit le mot dans la phrase.
void writeword(){
    wordStart newWord = createWord();
    int i = 0;
    char c = 'c';
    
    //while (!isspace(c) || !isblank(c)) {
    while (c != '*') {
        cin >> c;
        newWord->mot[i] = c;
        i++;
    }
    
    newWord->mot[i-1] = '\0';
    writeSentence(newWord);
    
    //readWord(newWord);
}

// Un programme qui lit les mot qu'on lui envoie.
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