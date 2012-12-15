a.out: myProgram.o StudentImplementation.o TreeImplementation.o
	gcc myProgram.o StudentImplementation.o TreeImplementation.o -Wall

myProgram.o: myProgram.c TreeInterface.h TreeType.h StudentInterface.h StudentType.h 
	gcc -c myProgram.c -Wall

StudentImplementation.o: StudentImplementation.c StudentInterface.h StudentType.h
	gcc -c StudentImplementation.c -Wall

TreeImplementation.o: TreeImplementation.c TreeInterface.h TreeType.h
	gcc -c TreeImplementation.c -Wall

clean:
	rm *.o

















