#ifndef WORDFREQ_H
#define WORDFREQ_H

#define MAX_WORD_SIZE 25
#define MAX_LINE_SIZE 3219
#define MAX_WORDS 701058
#define BLOCK_SIZE 8
#include "lnode.h"

typedef struct{
	char *word;
	int freq;
	List occur;
} WordFreq;

//WordFreq words[MAX_WORDS];

WordFreq* word_create( char *d );
WordFreq *list_add( WordFreq *w , char *d);
WordFreq* first_word();
int compareWord(const void * ptr1, const void * ptr2);
int compareW(const void * ptr1, const void * ptr2);
int compareFreq(const void * ptr1, const void * ptr2);
int verifyWord(WordFreq *w, char *word);
int usedspace(WordFreq *w);
void fillWords(FILE *fd, WordFreq *w);
void sortWord(WordFreq *w);
void sortFreq(WordFreq *w);
WordFreq *search(WordFreq *w, char c[]);
void wordFree(WordFreq *w);

#endif
