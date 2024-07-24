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

void wordReady (Array *a);
void wordCommand(char cmdLine[], Array *a);
void delay(int number_of_seconds);
int temp = 0;

void wordReady (Array *a){
	printf("\n\n/***********************************/\n List of commands:\n\n -- Alphabetic Sort  \t\t [a]\n -- Word Frequency  \t\t [w]\n -- Most Frequent Words \t [+]\n -- Least Frequent Words \t [-]\n -- Exit the program  \t \t [q]\n\n    Please-> ");
	char c[MAX_LINE_SIZE];		
	while(temp == 0){

		scanf(" %[^\n]s", c);
		wordCommand(c, a);
		
		if(temp > 2) break;
	}
}

void wordCommand(char cmdLine[], Array *a){
	
	WordFreq *line;
	int number;
	char *c1, *word;
	

	if(cmdLine == NULL) return;
	
	word = lineSplitFirstCMD(cmdLine);
		
	switch(/**cmdLine*/*word){

		case 'a':

			printf("\nAlphabetic Sort\n\n");
			sortWord(a);
			for(int i = 0; i< a->used; i++){
				printf("%s %d\n", a->w[i]->word, a->w[i]->freq);
			}
			wordReady(a);
			break;

		case 'w':
			word = lineSplitNext();
			//printf("\n");
			sortWord(a);
			line =(WordFreq *) search(a, word); 
			if(line != NULL)
				for (int i =0; i< a->used;i++){
					if(strcmp(word,a->w[i]->word)==0){
						printf("\nWord frenquency %d\n", a->w[i]->freq );		
					}
				}
			else 
				printf("The word doesn't exist\n");
			wordReady(a);
			break;

		case '+':
			word = lineSplitNext();
			number =  atoi(word); 				//converte "string" para int atoi()
			printf("\nMost Frequent Words\n\n");
			sortFreq(a);
			for (int i = a->used-1; i >= a->used-number; i--){
				printf(" %s %d\n", a->w[i]->word, a->w[i]->freq);
			}
			wordReady(a);
			break;
		
		case '-':
			word = lineSplitNext();
			number =  atoi(word);		
			printf("\nLeast Frequent Words\n\n");		
			sortFreq(a);
			for (int i = 0; i < number; i++){
				printf("%s %d\n", a->w[i]->word, a->w[i]->freq);
			}
			wordReady(a);
			break;	

		case 'q':
		
			printf("Deleting...\n \n");
			printf("\n**Quit command processed. Bye.**\n");
			system("clear");
			ArrayFree(a);
			exit (0);

		default:
			printf("\nPlease, insert a valid command\n");
			wordReady(a);
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
	//arr_create();
	WordFreq *word =NULL;
	Array *aux = arr_create();
	
	fillWords(fp, aux);
	wordReady(aux);
	
	//return 0;
}


