CC = g++
CFLAGS = -iquote./include -Wall -g -O0 -std=c++11

all: dispatcher.o Memory_mng.o Process_mng.o Process.o Resources_mng.o
	$(CC) -o ./bin/dispatcher dispatcher.o Memory_mng.o Process_mng.o \
	Process.o Resources_mng.o $(CFLAGS)
	make clear

dispatcher.o:
	$(CC) -c ./src/dispatcher.cpp $(CFLAGS)

Memory_mng.o:
	$(CC) -c ./src/Memory_mng.cpp $(CFLAGS)

Process_mng.o:
	$(CC) -c ./src/Process_mng.cpp $(CFLAGS)

Process.o:
	$(CC) -c ./src/Process.cpp $(CFLAGS)

Resources_mng.o:
	$(CC) -c ./src/Resources_mng.cpp $(CFLAGS)

run:
	./bin/dispatcher ./doc/processes.txt

clear:
	rm -rf *.o
