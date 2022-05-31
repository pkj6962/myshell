myshell: myshell.o
	gcc -W -o myshell myshell.o

myshell.o: myshell.c myshell.h 
	gcc -c myshell.c 

clean: 
	rm *.o myshell 

