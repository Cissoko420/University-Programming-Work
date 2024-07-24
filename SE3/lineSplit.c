#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lineSplit.h"

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

char *lineSplitFirstCMD( char line[] ){
	char *tok=NULL;
	char  *spl=" \t\n.,;:?!()\"{}«»", *term="\0";
	if(line == NULL ) return NULL;
	tok= strtok(line, spl);
	strcat(tok, term);
	return tok; 
}