#include <stdio.h>
#include <stdlib.h>
#include "lnode.h"

int main()
{
	List* list = create_list();
	/*list_add_tail(list, 1);
	list_add_tail(list, 2);
	list_add_tail(list, 3);
	list_add_tail(list, 4);
	list_add_tail(list, 5);
	list_add_tail(list, 6);*/
	list_add_head(list, 1);
	list_add_head(list, 2);
	list_add_head(list, 3);
	list_add_head(list, 4);
	list_add_head(list, 5);
	list_add_head(list, 5);
	list_add_head(list, 5);

	lPrint(list);
	printf("\n");
	
	if(lSearch(list, 3))
		printf("Existe\n");

	lFree(list);
	return 0;
}

