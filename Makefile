# makefile
# pokimac

CFLAGS :=-Wall

all: pokimac

pokimac: main.o combat.o map.o poki-start.o pokidex.o
	g++ -o -lwinmm pokimac main.o combat.o map.o poki-start.o pokidex.o

main.o: main.cpp main.h poki-start.h pokidex.h combat.h map.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

combat.o: combat.cpp combat.h pokidex.h map.h main.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

map.o: map.cpp map.h pokidex.h combat.h main.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

poki-start.o: poki-start.cpp poki-start.h main.h consoleUtils.hpp
	g++ -c $(CFLAGS) $^

pokidex.o: pokidex.cpp pokidex.h main.hpp
	g++ -c $(CFLAGS) $^

clean:
	rm *.o
