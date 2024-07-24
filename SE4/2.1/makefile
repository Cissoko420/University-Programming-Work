a.out: list_main.o lnode.o
	gcc list_main.o lnode.o

list_main.o: list_main.c lnode.h	
	gcc -c -g -std=c99 list_main.c 
	
lnode.o: lnode.c lnode.h
	gcc -c -g -std=gnu99 lnode.c			
	
clean:
	rm -f *.o a.out

debug: a.out
	insight a.out 
