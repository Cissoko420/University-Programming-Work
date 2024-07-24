#ifndef WORDFREQ_H
#define WORDFREQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordFreq.h"
#include "lineSplit.h"
#include "tnode.h"
#include "lnode.h"

#define MAX_WORD_SIZE 25
#define MAX_LINE_SIZE 3219
#define MAX_WORDS 701058
#define BLOCK_SIZE 8

typedef struct{ // Descritor de uma palavra
char *word; // aponta palavra armazenada em memória alojada dinamicamente
int freq;// número de ocorrências
List occur; // descritor da lista com o os números de linha onde há ocorrência
} WordFreq;

//WordFreq words[MAX_WORDS];

WordFreq* word_arr_create( char *d );
Array *arr_create( void );
void word_arr_add( Array *a, char *d);

int compareWord(const void * ptr1, const void * ptr2);
int compareW(const void * ptr1, const void * ptr2);
int compareFreq(const void * ptr1, const void * ptr2);
int verifyWord(Array *a, char *word);

void fillWords(FILE *fd, Array *a);

void sortWord(Array *a);
void sortFreq(Array *a);
WordFreq *search(Array *a, char c[]);
void wordFree(WordFreq *w);
void ArrayFree(Array *a);

#endif
