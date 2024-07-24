#include "lnode_1.h"

List* create_list()
{
	List* l = malloc(sizeof(List));
	l->head= NULL;
	l->tail= NULL;
	create_node();
	return l;
}

LNode* create_node()
{
	LNode* n = malloc(sizeof(LNode));
	
	if(n == NULL)
		return NULL;
	
	n->next = NULL;
	n->num = 0;
	return n;
}

void list_add_head(List *list, int num)
{
	LNode* node = create_node(num);
	node->next = list->head;
	//list->head = node->next;
	list->head = node;
	
}

void list_add_tail(List *list, int num)
{
	if(list->tail == NULL)
	{
		list_add_head(list, num);
		return;
	}
	
	LNode* node = create_node(num);
	list->tail = node->next;
	
	//list->tail = node;
	
}


void lSort(List *list, int num){
	LNode *p, a*, b*;

	for(p = *dp; p != NULL && p->num < l; a = p, p = p->next)
		;
	b = malloc(sizeof *b);
	b->num = l;
	b->next = p;
	if(p == *dp)
		*dp = d;
	else
		a->next = b;
	/*
	LNode* node = NULL, *temp = NULL;
    int tempNum;
    node = list->head;

    while(node != NULL)
    {
        temp=node; 
        while (temp->next != NULL)
        {
           if(temp->num > temp->next->num) 
            {
              tempNum = temp->num;
              temp->num = temp->next->num;
              temp->next->num = tempNum;
            }
         temp = temp->next;   
        }
        node = node->next;    
    }*/
}

List *lSearch(List *list, int num)
{
	/*LNode *p;
	for(p = h; p != NULL && p->num < l; p = p->next)
		;
	return p != NULL && p->num == l;*/
	for(; list->head; list->head = list->head->next)
	{
		if(list->head->num == num)
			return list;
	}
	
	return NULL;
}

/*int lRemHead(List *list, int num)
{
	if(list == NULL)
		return 0;
	List *l = list;
	l->head = list->head->next;
	l->head->num = num;
	free (l);
	return 1;
}

int lRemTail(List *list, int num)
{
	if(list == NULL)
		return 0;
	List *l = list;
	l->tail = list->tail->next;
	l->tail->num = num;
	free (l);
	return 1;
}
*/

static int list_count(LNode* list){
	
	int count = 0;

	for( ; list; list = list->next)
		count++;
		
	return count;
}

void lPrint(List *list)
{
	/*LNode *p;
	for(p = h; p != NULL; p = p->next){
		printf("%d", p->num);
	}
	putchar('\n');*/
	printf("{ ");
	while(list != NULL)
	{
		printf("%d ", list->head->num);
		list->head = list->head->next;
	}
	printf("}\n");
}

void lFree(List *list)
{
	/*LNode *p, *a;
	for(p = h; p != NULL; p = a){
		a = p->next;
		free(p);
	}*/
	while(list != NULL)
	{
		List* n = list;
		list->head = list->head->next;
		free(n);
	}
}
