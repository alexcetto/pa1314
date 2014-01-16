//
//  Word.h
//  projet_algo
//
//  Created by Alex on 13/01/2014.
//  Copyright (c) 2013 Alex&Olivier. All rights reserved.
//

#ifndef projet_algo_word_h
#define projet_algo_word_h

typedef struct mot{
    char mot[50];
    int nblettres;
    int place;
} structword, * wordStart  ;

wordStart createWord();
void writeword();
void readWord(wordStart nword);
void writeSentence(wordStart nword);
#endif
