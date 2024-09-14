CFLAGS = -g -Wall
CC = g++

objects = main.o procControl.o persistance.o node.o hashtable.o vigniere.o

main: $(objects)
	$(CC) -o main $(objects)

main.o: main.cpp procControl.cpp persistance.cpp node.cpp hashtable.cpp vigniere.cpp

.PHONY : clean
clean: 
	rm main $(objects)