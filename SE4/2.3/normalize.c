#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "normalize.h"

char *lineSave(char line[]){
	
	char *temp;
	temp = (char *)malloc(strlen(line));
	strcpy(temp, line);

	return temp;
}

char *normalize( char *word ){
	int lenght = strlen(word);
	char *temp = NULL;

	temp = lineSave(word);
	
	if (word == NULL){printf("Erro!\n"); return 0;}

	if((word[0] & 0xff) >= 0xc2 && (word[0] & 0xff) < 0xc3 || word[0] == 0x2d){

		if (word[0] == 0x2d){

			for(int i=0; i<lenght; i++){

			temp[i] = word[i+1];
			
			}
		}
		else
		for(int i=0; i<lenght; i++){

			temp[i] = word[i+2];
		}
	}
	
	if((word[lenght-1] & 0xff) >= 0xc2 && (word[lenght-1] & 0xff) < 0xc3 || word[lenght-1] == 0x2d){

		temp[lenght-1] = '\0';
	}

	return temp;
}