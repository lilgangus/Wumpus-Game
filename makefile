CC=g++ -std=c++11 -g
exe=asm4


# Complete the makefile
# Your code here: 
$(exe): bats.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o armor.o
	$(CC) bats.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o armor.o -o $(exe)

bats.o: bats.cpp
	$(CC) -c bats.cpp 

event.o: event.cpp
	$(CC) -c event.cpp 

game.o: game.cpp
	$(CC) -c game.cpp 

gold.o: gold.cpp
	$(CC) -c gold.cpp 

main.o: main.cpp
	$(CC) -c main.cpp 

room.o: room.cpp
	$(CC) -c room.cpp 

stalactites.o: stalactites.cpp
	$(CC) -c stalactites.cpp 

wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp 

armor.o: armor.cpp
	$(CC) -c armor.cpp
	
clean: 
	rm -f *.out *.out *.o $(exe)