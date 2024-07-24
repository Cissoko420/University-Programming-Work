#include "lnode.h"

List* create_list(){

	List* l = malloc(sizeof(List));
	l->head= NULL;
	l->tail= NULL;
	return l;
}



void list_add_head(List* list, int num){

	LNode* node, *a, *n;
	for( node = list->head; node != NULL && node->num < num; a = node, node = node->next )
		;
	//node = create_node2(num);
	n = malloc(sizeof(*n));
	n->num = num;
	n->next = node;
	list->tail = n;
	if(node == list->head)
		list->head = n;
	else
		a->next = n;
	//list->head = node;
	//list->head->next=list->tail;	
}

/*void list_add_tail(List* list, int num){

	LNode* node;
	if(list->head == NULL)
	{
		list_add_head(list, num);
		return;
	}
	else
	node = create_node(&node,num);
	list->tail = node;
	//list->head->next=list->tail;
	
}*/

int lSearch(List* list, int num){

	LNode *p;
	for(p = list->head; p != NULL && p->num < num; p = p->next)
		;
	return p != NULL && p->num == num;

}

void lPrint(List *list)
{
	LNode *p;
	for(p = list->head; p != NULL; p = p->next){
		printf("%d\n", p->num);
	}
	putchar('\n');
}

void lFree(List *list){

	while(list->head != NULL)
	{
		List* n = list;
		list->head = list->head->next;
		free(n);
	}
}
