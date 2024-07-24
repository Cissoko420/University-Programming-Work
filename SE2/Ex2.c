#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>

#define MAX_LINE_SIZE 3219
#define MAX_WORDS 701058
#define MAX_WORD_SIZE 3219
#define MAX_NAME_SIZE 1270


typedef struct{
char word[MAX_WORD_SIZE];
int freq;
} WordFreq;

WordFreq words[MAX_WORDS];

int numWords = 0;

void wordCommand( char* cmdLine );
void wordReady ();
int verifyWord( char *word);
char *lineSplitFirst( char line[] );
WordFreq findWord(char* word);
char *lineSave(char line[]);
char *numbFreq(WordFreq* wordF,char *word);
char *lineSplitNext(void);

void printWords(void){

	for(int i=0; i< numWords; i++){
		printf("%s %d\n", words[i].word, words[i].freq);
	} 
}

int compareWord(const void * ptr1, const void * ptr2){ 
	WordFreq *a = (WordFreq *) ptr1;
	WordFreq *b = (WordFreq *) ptr2;

	return strcoll(a->word, b->word);
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

int verifyWord( char *word){
	for(int i=0;i<MAX_WORDS;i++){
		if(strcoll(word, words[i].word)==0)
			return i;
		
		else if(strcoll("", words[i].word)==0)

			return -1;
	}
	return 0;
}

void fillWords(FILE *fd){
	char line[MAX_LINE_SIZE];
	char *word;
	int i=0, j=0;
	while(fgets(line, MAX_LINE_SIZE, fd)!=NULL){	

			if(strcoll(line,"") != 0 && strcoll(line,"\n") != 0 ){
				
				word=lineSplitFirst(line);

				while( word!=NULL){

					i=verifyWord(word);	
					
					if(i!=-1){
						words[i].freq++;
						word=lineSplitNext();
					}
					else if(i==-1){
						strcpy(words[j].word,word);
						words[j].freq++;
						word=lineSplitNext();
						j++;
						numWords++;	
				}
			}
		}
	}
}

void wordReady (){
	printf("\n\n\t\t List of commands:\n\n -- Alphabetic Sort  \t[a]\n -- Word Frequency  \t[w]\n -- Most Frequent Words  \t[+]\n -- Least Frequent Words \t[-]\n -- Exit the program  \t[q] \n Please");
	char c[MAX_LINE_SIZE];		
	while(1){
		printf("-> ");
		scanf(" %[^\n]s", c);	
		int len = strlen(c);
		wordCommand(c);
		if(len > 0) break;
	}
}

void wordCommand(char* cmdLine ){

	WordFreq *line;
	int number;
	char word[MAX_LINE_SIZE];

	if(cmdLine == NULL) return;

	switch(*cmdLine){

		case 'a':

			printf("Alphabetic Sort\n");
			qsort(words, numWords-1, sizeof(WordFreq), compareWord);
			for(int i = 0; i< numWords; i++){
				printf("%s %d\n", words[i].word, words[i].freq);
			}
			break;

		case 'w':
			
			scanf(" %[^\n]s", word);
			//printf("%s\n",word);
			//printWords();
			printf("\n\n");
			qsort(words, numWords, sizeof(WordFreq), compareWord);
			line =(WordFreq *) bsearch(&word,words,numWords,sizeof(WordFreq),compareW); //nao funciona
			if(line != NULL)
				printf("Word frenquency %d\n", words->freq);		
			else 
				printf("The word doesn't exist\n");
			break;

		case '+':
			
			scanf(" %d", &number);
			printf("Most Frequent Words\n");
			qsort(words, numWords-1, sizeof(WordFreq), compareFreq);
			for (int i = numWords-1; i >= numWords-number; i--){
				printf(" %s %d\n", words[i].word, words[i].freq);
			}
			break;
		
		case '-':
			
			scanf(" %d", &number);		
			printf("Least Frequent Words\n");		
			qsort(words, numWords-1, sizeof(WordFreq) , compareFreq);
			for (int i = 0; i < number; i++){
				printf("%s %d\n", words[i].word, words[i].freq);
			}
			break;	

		case 'q':
		
			printf("Deleting\n");
			printf("**Quit command processed. Bye.\n");
			break;

		default:
			printf("Please, insert a valid command\n");
			break;

	}


}

char *lineSplitFirst( char line[] ){
	char *tok=NULL;
	char  *spl=" \t\n.,;:?!—()\"-{}«»", *term="\0";
	if(line == NULL ) return NULL;
	tok= strtok(line, spl);
	strcat(tok, term);
	return tok; 
}

char *lineSplitNext(void){
	char  *spl=" \t\n.,;:?!—()\"{}«»", *term="\0", *tok;
	tok = strtok( NULL, spl);
	if(tok == NULL) return NULL;
	strcat(tok, term);
	return tok; 
}

int main(int argc, char* argv[]){
	
	setlocale(LC_ALL,"pt_PT.UTF-8");
	for(int i = 1; i < argc; ++i)
	{
		char * str = argv[i];
		printf("%s\n", str);
	}
	
	FILE *fp;
	
	fp= fopen("A_Capital.txt","r");
	if(fp==NULL){
		perror("Error openning file");
		return(-1);
	}
	fillWords(fp);
	wordReady();
	return 0;
}
