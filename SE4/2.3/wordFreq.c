#include "WordFreq.h"

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

LNode *node_create (void ){
	LNode *node=malloc(sizeof (LNode));
	node->next=NULL;
	node->num=1;
	
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


int verifyWord(Array *a, char *word){
	
	for(int i=0;i<a->used;i++){
		 if(strcmp(word, a->w[i]->word)==0)
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

				i=verifyWord(a, word);	
					
				if(i!=-1){
					a->w[i]->freq++;
					word=lineSplitNext();
				}
				else if(i==-1){
					//strcpy(w[j].word, word);
					word_arr_add(a, word);
					//a->w[j]->freq = 0;
					//a->w[j]->freq++;
					//j++;
					word=lineSplitNext();
					//w[j].freq=0;
				}
			}
		}
	}
}

void sortWord(Array *a){

	qsort(a->w, (a->used)-1, sizeof(WordFreq *), compareWord);

}

void sortFreq(Array *a){

	qsort(a->w, (a->used)-1, sizeof(WordFreq *), compareFreq);

}

WordFreq *search(Array *a, char c[]){

	return bsearch(c,a->w,(a->used)-1,sizeof(WordFreq *),compareW);
}

void wordFree(WordFreq *w){
	free (w);
}
void ArrayFree(Array *a){
	wordFree(*a->w);
	free(a);
}
