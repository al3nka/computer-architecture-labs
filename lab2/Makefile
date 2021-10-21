flags = -c -Wall

all: main

clean:
	rm -rf main *.o

calculator.o : calculator.cpp
	g++ $(flags) calculator.cpp

interface.o: interface.cpp
	g++ $(flags) interface.cpp

libcalculator.a: calculator.o
	ar cr libcalculator.a calculator.o

main: interface.o libcalculator.a
	g++ interface.o -L. -lcalculator -o main