CXXFLAGS= -Wall -std=c++11 -g
CXXLIBS= -L /usr/lib/ -lboost_system -lboost_thread -lpthread -lboost_program_options

JOUEUR_FILES = $(shell find ./joueur -type f \( -iname \*.h -o -iname \*.cpp -o -iname \*.hpp \))
GAMES_FILES = $(shell find ./games -type f \( -iname \*.h -o -iname \*.cpp -o -iname \*.hpp \))

all:
	make dependencies
	make core

dependencies: ;

core:
	$(CXX) $(CXXFLAGS) main.cpp currentGame.h $(JOUEUR_FILES) $(GAMES_FILES) -o client $(CXXLIBS)

clean:
	rm -f client
