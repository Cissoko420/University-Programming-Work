#ifndef TNODE_H
#define TNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WordFreq.h"
#include "lnode.h"

typedef struct tNode{ // Nó de árvore binária de pesquisa
 struct tNode *left, *right; // ligações às subárvores
 WordFreq *ref; // acesso ao descritor de uma palavra
} TNode;

int tScan( TNode *root, int(*action)(WordFreq *wf, void *context),void *context );
TNode *sortedListToBalancedTree(TNode **listRoot, int n);
void tAdd (TNode **rp , char *s );
void tSearch (TNode *r , char *s );
void tPrint(TNode *r , int maxOccur);

TNode *treeToSortedList( TNode *r, TNode *link );
void tDelete( TNode *r );

#endif