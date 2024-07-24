#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>

#include "wordFreq.h"
#include "lineSplit.h"
#include "normalize.h"

void wordReady (WordFreq *w);
void wordCommand(char cmdLine[], WordFreq *w);
void delay(int number_of_seconds);
int numWords;
int temp = 0;

void wordReady (WordFreq *w){
	printf("\n\n/***********************************/\n List of commands:\n\n -- Alphabetic Sort  \t\t [a]\n -- Word Frequency  \t\t [w]\n -- Most Frequent Words \t [+]\n -- Least Frequent Words \t [-]\n -- Exit the program  \t \t [q]\n\n    Please-> ");
	char c[MAX_LINE_SIZE];		
	while(temp == 0){

		scanf(" %[^\n]s", c);
		wordCommand( c, w);
		
		if(temp > 2) break;
	}
}

void wordCommand(char cmdLine[], WordFreq *w){

	WordFreq *line;
	int number;
	char *c1, *word;
	

	if(cmdLine == NULL) return;
	
	word = lineSplitFirstCMD(cmdLine);
		
	switch(/**cmdLine*/*word){

		case 'a':

			printf("\nAlphabetic Sort\n\n");
			sortWord(w);
			for(int i = 0; i< numWords; i++){
				printf("%s %d\n", w[i].word, w[i].freq);
			}
			wordReady(w);
			break;

		case 'w':
			word = lineSplitNext();
			//printf("\n");
			sortWord(w);
			line =(WordFreq *) search(word, w); 
			if(line != NULL)
				printf("\nWord frenquency %d\n", w->freq);		
			else 
				printf("The word doesn't exist\n");
			wordReady(w);
			break;

		case '+':
			word = lineSplitNext();
			number =  atoi(word); 				//converte "string" para int atoi()
			printf("\nMost Frequent Words\n");
			sortFreq(w);
			for (int i = numWords-1; i >= numWords-number; i--){
				printf(" %s %d\n", w[i].word, w[i].freq);
			}
			wordReady(w);
			break;
		
		case '-':
			word = lineSplitNext();
			number =  atoi(word);		
			printf("\nLeast Frequent Words\n\n");		
			sortFreq(w);
			for (int i = 0; i < number; i++){
				printf("%s %d\n", w[i].word, w[i].freq);
			}
			wordReady(w);
			break;	

		case 'q':
		
			printf("Deleting...\n \n");
			printf("\n**Quit command processed. Bye.**\n");
			system("clear");
			wordsFree(w);
			exit (0);

		default:
			printf("\nPlease, insert a valid command\n");
			wordReady(w);
			break;

	}


}

int main(int argc, char* argv[]){
	
	char *d=NULL;
	
	setlocale(LC_ALL,"pt_PT.UTF-8");
	
	for(int i = 1; i < argc; ++i)
	{
		char * str = argv[i];
		printf("%s\n", str);
	}
	
	FILE *fp;

	printf("Reading File, Please Wait...\n");
	fp= fopen("A_Capital.txt","r");

	if(fp==NULL){
		perror("Error openning file");
		return(-1);
	}
	arr_create();
	WordFreq *word =NULL;

	
	fillWords(fp, word);
	wordReady(word);
	
	//return 0;
}


