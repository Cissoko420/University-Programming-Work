#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define MAX_NAME_SIZE 1270
//#define MAX_LINE_SIZE 1000

char *lineSplitFirst( char line[] );
char *lineSplitNext( void );
int utf8SetLower( char *symb );
char *atoh(char *ascii_ptr, char *hex_ptr,int len);
char *normalize( char *word );
int utf8Length (char a[],int i);
int charLeadingOnes(char value[]);
void printBytes( char a[], int i, int n);
char *normalize( char *word );
void separatorUnify( char str[] );

char *lineGet(void){

	FILE *fp;
	char *line = NULL;
	size_t read;
	size_t len = 0;
	fp = fopen("A_Capital.txt", "r");
	
	if (fp == NULL)
    	exit(EXIT_FAILURE);	

    while((read = getline(&line, &len, fp)) != -1){
		if (line[read] == '\n'){
			return line;
		}
	}
	return line;
}

char *lineGetFirst(void){

	FILE *fp;
	char *line = NULL;
	size_t read;
	size_t len = 0;
	fp = fopen("A_Capital.txt", "r");
	
	if (fp == NULL)
    	exit(EXIT_FAILURE);	

    read = getline(&line, &len, fp);
		if (line[read] == '\n'){
			return line;
		}
		return line;
	}


char *lineSave(char line[]){
	
	char *temp;
	temp = (char *)malloc(strlen(line));
	strcpy(temp, line);

	return temp;
}

char *lineSplitFirst( char line[] ){
	char *tok=NULL;
	char  *spl=" \t\n.,;:?!—()\"-{}", *term="\0";
	if(line == NULL ) return NULL;
	tok= strtok(line, spl);
	strcat(tok, term);
	return tok; 
}

char *lineSplitNext(void){
	char  *spl=" \t\n.,;:?!—()\"-{}", *term="\0", *tok;
	tok = strtok( NULL, spl);
	if(tok == NULL) return NULL;
	strcat(tok, term);
	return tok; 
}


int utf8SetLower( char *symb ){
	 
	 if(symb[0] == '\xc3'){
        if(symb[1] < '\xa0' )
            symb[1] = symb[1] + '\x20'; 
	 }
	 else{
        return utf8Length (symb, 0);
    }
    return utf8Length (symb, 0);
}	

int utf8Length (char a[],int i){
	
	char s[CHAR_BIT];
	
	int h=0;
	for(int j = 7; j >= 0; j--) {

    	s[h] =( a[i] >> j ) & 1 ? 1 : 0;
    	printf("%d",s[h]);
    	h++;
	}
	printf("\n");
	return charLeadingOnes(s);	
}


int charLeadingOnes(char value[]){

	int count =0;
    int size=CHAR_BIT;
   
    for (int i=0; i<size ;i++){
		if(value[i]==0)
			return count;
		else if(value[i]==1){
			count++;
		}
	}
	return count;
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

void separatorUnify( char str[] ){
	if( str == NULL  ){ 
		printf("Erro no nome!");
		return;
	}
		
	char nome[MAX_NAME_SIZE];
	char *tok, *spl = " \t\n", *esp =" ";
	
	tok = strtok( str, spl ); // retorna um ponteiro
	strcpy( nome, tok );
	tok = strtok( NULL, spl );
	
	while( tok != NULL ){
		strcat( nome, esp ); // acrescenta do espaço
		strcat( nome, tok ); // acrescenta da nova palavra
		tok = strtok( NULL, spl ); // vai buscar a proxima palavra
	}
	strcpy(str, nome);
	

}

int main(){
	
  	char *line=NULL;
  	int  num=0;
  	char *norm1;

    char *temp;
   char *next;
    

    line = lineGetFirst();
    	temp = lineSplitFirst(line);
    	norm1 = normalize(temp);
    	printf ("%s\n", norm1);
    	if(temp != '\0')
    	printf("%p\n", &temp);
    	//printf("%s\n",temp);

   /*
    next = lineGet();




   	next=lineSplitNext();
    printf("%p\n", &next);
    
    char linha[10]="À";
    num=utf8SetLower(linha);
    printf("%s\n",linha);
	printf("%d\n", num);*/
    
    return 0;
}
