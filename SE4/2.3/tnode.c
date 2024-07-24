#include "tnode.h"


int tScan( TNode *root, int(*action)(WordFreq *wf, void *context),void *context ){
	
	int i =0;
		while(i<MAX_FILE_NAME){
			action(root->occur->head,context);
			i++;
		} 
}

TNode *sortedListToBalancedTree(TNode **listRoot, int n) {
	if( n == 0 )
		return NULL;
	TNode *leftChild = sortedListToBalancedTree(listRoot, n/2);
	TNode *parent = *listRoot;
	parent->left = leftChild;
	*listRoot = (*listRoot)->right;
	parent->right = sortedListToBalancedTree(listRoot, n-(n/2 + 1) );
	return parent;
}

void tAdd (TNode **rp , char *s ){
		if(*rp=NULL){
			TNode *n = malloc(sizeof(*n));
			n->ref->word = strdup(s);
			n->ref->occur->head->num=1;
			n->left=NULL;
			n->right=NULL;
			n->ref->freq = 0;
			create_list();
			*rp=n;
			return;
		}

		if(strcmp(s,(*rp)->ref->word)==0)
			++(*rp)->ref->freq;
		else
			tAdd(strcmp(s,(*rp)->ref->word)<0 ? &(*rp)->left : &(*rp)->right , s);
	}
	
void tSearch (TNode *r , char *s ){
	while(r!=NULL){
		if(strcmp(s,r->ref->word)==0)
			return r->ref->freq;
		else if(strcmp(s,r->ref->word)<0)
			return tSearch (r->left, s );
		else
			return tSearch (r->right, s );
	}
	return -1;
}


void tPrint(TNode *r , int maxOccur){
	while(r!=NULL && r->ref->occur->head->num<=maxOccur){
		printf("%s %d %d, \n",r->ref->word,r->ref->freq, r->ref->head->num);
	}
	tPrint(r->left,maxOccur);
	tPrint(r->right,maxOccur);
}

TNode *treeToSortedList( TNode *r, TNode *link ){
	TNode * p;
	if( r == NULL ) return link;
		p = treeToSortedList( r->left, r );
		r->left = NULL;
		r->right = treeToSortedList( r->right, link );
	return p;
}
void tDelete( TNode *r ){
	if( r == NULL ){
		return;
	}
	tDelete( r->left );
	tDelete( r->right );
	free( r );
}
