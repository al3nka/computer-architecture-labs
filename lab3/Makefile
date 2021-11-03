flags = -c -Wall

all: main

clean:
	rm -rf main *.o

main.o : main.cpp
	g++ $(flags) main.cpp

main: main.o
	g++ main.o -o main