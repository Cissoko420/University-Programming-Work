#ifndef WORDFREQ_H
#define WORDFREQ_H

#define MAX_WORD_SIZE 25
#define MAX_LINE_SIZE 3219
#define MAX_WORDS 701058
#define BLOCK_SIZE 8

typedef struct{
char *word;
int freq;
} WordFreq;

typedef struct{
WordFreq **w;
int space;
int used;

} Array;

//WordFreq words[MAX_WORDS];

WordFreq* word_arr_create( char *d );
void arr_create( void );
void word_arr_add( Array *a, char *d);

int compareWord(const void * ptr1, const void * ptr2);
int compareW(const void * ptr1, const void * ptr2);
int compareFreq(const void * ptr1, const void * ptr2);
int verifyWord( char *word, WordFreq *w);

void fillWords(FILE *fd, WordFreq *w);

void sortWord(WordFreq *w);
void sortFreq(WordFreq *w);
WordFreq *search(char c[], WordFreq *w);
void wordsFree(WordFreq *w);

#endif
