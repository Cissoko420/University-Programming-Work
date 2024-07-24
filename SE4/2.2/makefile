a.out: main.o wordFreq.o normalize.o lineSplit.o lnode.o
	gcc main.o wordFreq.o normalize.o lineSplit.o lnode.o

main.o: main.c wordFreq.h normalize.h lineSplit.h lnode.h	
	gcc -c -g -std=c99 main.c 

wordFreq.o: wordFreq.c wordFreq.h
	gcc -c -g -std=gnu99 wordFreq.c	

lnode.o: lnode.c lnode.h
	gcc -c -g -std=gnu99 lnode.c

normalize.o: normalize.c normalize.h
	gcc -c -g -std=c99 normalize.c

lineSplit.o: lineSplit.c lineSplit.h
	gcc -c -g lineSplit.c		
	
clean:
	rm -f *.o a.out

debug: a.out
	insight a.out A_Capital.txt
