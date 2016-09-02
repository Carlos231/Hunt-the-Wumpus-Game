Hunt_wumpus: Hunt_wumpus.o game.o room.o event.o bats.o gold.o pit.o wumpus.o
	g++ Hunt_wumpus.o game.o room.o event.o bats.o gold.o pit.o wumpus.o -o Hunt_wumpus
Hunt_wumpus.o: Hunt_wumpus.cpp
	g++ Hunt_wumpus.cpp -c
game.o: game.cpp
	g++ game.cpp -c
room.o: room.cpp
	g++ room.cpp -c 
event.o: event.cpp
	g++ event.cpp -c
bats.o: bats.cpp
	g++ bats.cpp -c
gold.o: gold.cpp
	g++ gold.cpp -c
pit.o: pit.cpp
	g++ pit.cpp -c
wumpus.o: wumpus.cpp
	g++ wumpus.cpp -c
clean:
	rm -f a.out *.o Hunt_wumpus
