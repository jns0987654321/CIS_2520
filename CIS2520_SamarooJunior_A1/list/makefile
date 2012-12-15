myProgram: myProgram.o StudentImplementation.o ListImplementation.o
	gcc myProgram.o StudentImplementation.o ListImplementation.o -o myProgram -Wall

myProgram.o: myProgram.c ListInterface.h
	gcc myProgram.c -o myProgram.o -c -Wall

StudentImplementation.o: StudentImplementation.c StudentInterface.h
	gcc StudentImplementation.c -o StudentImplementation.o -c -Wall

ListImplementation.o: ListImplementation.c ListInterface.h
	gcc ListImplementation.c -o ListImplementation.o -c -Wall

clean:
	rm ListImplementation.o
	rm StudentImplementation.o
	rm myProgram.o
	rm myProgram