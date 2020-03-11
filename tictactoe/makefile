all: out

out: main.o tictactoelib.o
	g++ -std=c++11 -o out main.o tictactoelib.o

main.o: main.cpp tictactoelib.h
	g++ -std=c++11 -c main.cpp

tictactoelib.o: tictactoelib.cpp tictactoelib.h
	g++ -std=c++11 -c tictactoelib.cpp

clean:
	rm out main.o tictactoelib.o
