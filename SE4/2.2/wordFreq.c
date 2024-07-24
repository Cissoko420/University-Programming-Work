#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordFreq.h"
#include "lineSplit.h"
#include "lnode.h"

WordFreq* word_create( char *d )
{
	WordFreq *w = (WordFreq*)malloc(sizeof(WordFreq));
	
	if(w == NULL)
		return NULL;	
	w->word=strdup(d);
	w->freq=1;
	w->occur->head=w[0];
	w->occur->tail=w[sizeof(WordFreq)];
	return w;
}

WordFreq *list_add( WordFreq *w , char *d){
	
	if(w->occur->head == NULL ){
		word_create(d);	
	}		
	while(w->occur->head!=w->occur->tail){	
		for(int i=0;i!=sizeof(word);i++){
			if(w->occur->head->num==0 && w->occur->head==w->word[i]){
			w->occur->head->num++;
			}
			else if(w->occur->head==w->word[i])
				w->freq++;
		}
		else w->occur->head=w->occur->head->next;	
	}
	return w;
}

int compareWord(const void * ptr1, const void * ptr2){ 
	WordFreq *a = *(WordFreq **) ptr1;
	WordFreq *b = *(WordFreq **) ptr2;

	return strcmp(a->word, b->word);
}

WordFreq* first_word()
{
    WordFreq w = (WordFreq)malloc(sizeof(WordFreq));

    if(w == NULL)
        return NULL;
    w->word=NULL;
    w->freq=1;
    w->occur->head=w[0];
    w->occur->tail=w[sizeof(WordFreq)];
    return w;
}

int compareW(const void * ptr1, const void * ptr2){ //compara com word recebida
	char *a = (char *) ptr1;
	WordFreq *b = *(WordFreq **) ptr2;
 
 	//printf("%s\n",b->word );
	return (strcmp(a, b->word));
}

int compareFreq(const void * ptr1, const void * ptr2){
	WordFreq *a = *(WordFreq **) ptr1;
	WordFreq *b = *(WordFreq **) ptr2;

	return (a->freq - b->freq);
}


int verifyWord(WordFreq *w, char *word){
	
	for(int i=0;i < w->word;i++){
		 if(strcmp(word, w[i]->word)==0)
			return i;
	}
	return -1;
}

int usedspace(WordFreq *w){
	int aux = 0;
	for (int i = 0; i < MAX_WORDS; i++){
		aux += w->freq;
	}
	return aux;
}

void fillWords(FILE *fd, WordFreq *w){
	char line[MAX_LINE_SIZE];
	char *word;
	int i=0, j=0, aux = 0;

	List* list = create_list();

	while(fgets(line, MAX_LINE_SIZE, fd)!=NULL){	
		aux++;
		if(strcoll(line,"") != 0 && strcoll(line,"\n") != 0 ){
				
			word=lineSplitFirst(line);

			while( word!=NULL){

				i=verifyWord(w, word);	
					
				if(i!=-1){
					w[i]->freq++;
					word=lineSplitNext();
					list_add_head(list, aux);
				}
				else if(i==-1){
					//strcpy(w[j].word, word);
					word_create(word);
					//a->w[j]->freq = 0;
					w[j]->freq++;
					list_add_head(list, aux);
					j++;
					word=lineSplitNext();
					//w[j].freq=0;
				}
			}
		}
	}
}

void sortWord(WordFreq *w){

	int used = usedspace(w);

	qsort(w, (used)-1, sizeof(WordFreq *), compareWord);

}

void sortFreq(WordFreq *w){

	int used = usedspace(w);

	qsort(w, (used)-1, sizeof(WordFreq *), compareFreq);

}

WordFreq *search(WordFreq *w, char c[]){

	int used = usedspace(w);

	return bsearch(c,w,(used)-1,sizeof(WordFreq *),compareW);
}

void wordFree(WordFreq *w){
	free (w);
}
