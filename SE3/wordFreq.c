#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordFreq.h"
#include "lineSplit.h"

WordFreq* word_create( char *d )
{
	WordFreq *w = (WordFreq*)malloc(sizeof(WordFreq));
	
	if(w == NULL)
		return NULL;	
	w->word=strdup(d);
	w->freq=1;
	
	return w;
}

Array *arr_create( void ){
		Array *a=malloc(sizeof (Array));
		a->space = 0;
		a->used = 0;
		a->w = NULL ;
		return a;
}
	 

void word_arr_add( Array *a, char *d )
{	
	if(a == NULL ){
		printf("Error: Null arguments.\n");
		exit(-1);
	}
	
	if (a->space == a->used){
		a->w = realloc(a->w,(space += BLOCK_SIZE) * sizeof(*d->w));
		w[a->used++]=word_create(d);			
	}


}

int compareWord(const void * ptr1, const void * ptr2){ 
	WordFreq *a = (WordFreq *) ptr1;
	WordFreq *b = (WordFreq *) ptr2;

	return strcmp(a->word, b->word);
}

int compareW(const void * ptr1, const void * ptr2){ //compara com word recebida
	char *a = (char *) ptr1;
	WordFreq *b = (WordFreq *) ptr2;
 
 	//printf("%s\n",b->word );
	return (strcoll(a, b->word));
}

int compareFreq(const void * ptr1, const void * ptr2){
	WordFreq *a = (WordFreq *) ptr1;
	WordFreq *b = (WordFreq *) ptr2;

	return (a->freq  - b->freq);
}

static int cmpStrPtr( const void *a, const void *b ){
	return strcmp( *(char **)a, *(char **)b );
}

int verifyWord( char *word, Array *a){
	
	for(int i=0;i<a->used;i++){
		 if(strcmp(word, a->w[i]->word))==0)

			return i;
	}
	return -1;
}

void fillWords(FILE *fd, Array *a){
	char line[MAX_LINE_SIZE];
	char *word;
	int i=0, j=0;
	while(fgets(line, MAX_LINE_SIZE, fd)!=NULL){	

		if(strcoll(line,"") != 0 && strcoll(line,"\n") != 0 ){
				
			word=lineSplitFirst(line);

			while( word!=NULL){

				i=verifyWord(word, a);	
					
				if(i==-1){
					w[i].freq++;
					word=lineSplitNext();
				}
				else if(i!=-1){
					//strcpy(w[j].word, word);
					word_arr_add(a, word);
					w[j].freq = 0;
					w[j].freq++;
					j++;
					word=lineSplitNext();
					//w[j].freq=0;
				}
			}
		}
	}
}

void sortWord(WordFreq *w){

	qsort(w, numWords, sizeof(WordFreq), compareWord);

}

void sortFreq(WordFreq *w){

	qsort(w, numWords, sizeof(WordFreq), compareFreq);

}

WordFreq *search(char c[], WordFreq *w){

	bsearch(c,w,numWords,sizeof(WordFreq),cmpStrPtr);
}

void wordsFree(WordFreq *w){
	
	free(w->word);
	//free(w);
}
