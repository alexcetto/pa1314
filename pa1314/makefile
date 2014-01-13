# définition des cibles particulières
.PHONY: clean 
 
# désactivation des règles implicites
.SUFFIXES:
 
# définition des variables
CXX = g++
CXXFLAGS = -Wall
 
 
 
# all
all: main.o arbres.o affichage.o importationArbre.o traitement.o word.o
	$(CXX) $^ -o exec $(CXXFLAGS)
 
main.o: affichage.h arbres.h importationArbre.h traitement.h word.h
 
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)
 
 
# clean
clean:
	rm -rf *.o
 
# mrproper
#mrproper: clean
#	rm -rf exec