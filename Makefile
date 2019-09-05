output: main.o Barbarian.o Character.o Menu.o BlueMen.o HarryPotter.o Medusa.o Vampire.o BattleQueue.o DeathQueue.o
	g++ -std=c++11 main.o Barbarian.o Character.o Menu.o BlueMen.o HarryPotter.o Medusa.o Vampire.o BattleQueue.o DeathQueue.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

BattleQueue.o: BattleQueue.cpp BattleQueue.hpp
	g++ -std=c++11 -c BattleQueue.cpp

DeathQueue.o: DeathQueue.cpp DeathQueue.hpp
	g++ -std=c++11 -c DeathQueue.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp



zip:
	zip Project4_McGrath_Alexander.zip *.cpp *.hpp *.pdf *.txt Makefile 

clean:
	rm *.o output

#target: dependencies
#   action
