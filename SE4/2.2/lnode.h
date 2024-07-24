#ifndef LNODE_H
#define LNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct lNode{		// Nó de lista ligada
	struct lNode *next; 	// ligação na lista
	int num;				// número de linha da ocorrência
} LNode;

typedef struct{				// Descritor de uma lista ligada
	LNode *head, *tail; 	// ponteiros para o início e fim da lista
} List;

List* create_list();
void list_add_head(List* list, int num);
int lSearch(List* list, int num);
void lPrint(List* list);
void lFree(List* list);

#endif
