# makefile
# pokimac

CFLAGS :=-Wall

all: pokimacGame

pokimacGame: main.o combat.o map.o poki-start.o pokidex.o
	g++ -o pokimacGame main.o combat.o map.o poki-start.o pokidex.o -lwinmm

main.o: main.cpp consoleUtils.hpp main.h poki-start.h pokidex.h combat.h map.h 
	g++ -c $(CFLAGS) $^

combat.o: combat.cpp combat.h pokidex.h map.h main.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

map.o: map.cpp main.h map.h pokidex.h combat.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

poki-start.o: poki-start.cpp poki-start.h main.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

pokidex.o: pokidex.cpp main.h pokidex.h
	g++ -c $(CFLAGS) $^

clean:
	rm *.o
