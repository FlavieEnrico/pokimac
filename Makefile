# makefile
# pokimac

pokimac:	main.o map.o poki-start.o
	g++ -o pokimac main.o map.o poki-start.o -Wall

main.o: main.cpp main.h poki-start.h
	g++ -c main.cpp -Wall

map.o: map.cpp
	g++ -c map.cpp -Wall

poki-start.o: poki-start.cpp main.h pkoi-start.h
	g++ -c poki-start.cpp -Wall

clean:
	rm *.o
