#ifndef _TICTACTOE_LIB_H_
#define _TICTACTOE_LIB_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
enum status{
	win, lose, draw, filled, outOfBox, undefined
};

enum fillers { player1=-1, empty=0, player2=1};

enum winlines: unsigned int { row1=1, row2=2, row3=3, col1=4, col2=5, col3=6, diag=7, diag_c=8};

struct winlineshash{
	size_t operator()(const winlines& wl) const{
		return static_cast<size_t>(wl);
	}
};

// also works
// typedef unordered_set<winlines, hash<int> > winlinesset;
typedef unordered_set<winlines, winlineshash > winlinesset;

winlinesset winLinesForN(size_t n);

struct step{
	int x, y;
	step(size_t a): x((a-1)/3), y((a-1)%3) {}
	step(const step& m) { x = m.x; y = m.y; }
	step(step&& m) { if(this != &m) x = std::move(m.x); y = std::move(m.y); }
	step& operator=(step&& m) {
		if(this == &m) return *this;
		x = std::move(m.x);
		y = std::move(m.y);
		return *this;
	}
};

class board{
	const int n = 3;
	vector<vector<fillers> > mat;
	bool checkBoundary(int x, int y);
	fillers playerturn;
public:
	board():mat(n, vector<fillers>(n,empty)), playerturn(player1) {}
	
	void reset();

	void display();

	int getPlayer() { return playerturn==player1 ? 1 : 2;}
		
	status makeMove(step &&m, fillers);

};

class player {
	string name;
	int id;
	size_t games;
	size_t wins;
	winlinesset wls;
public:
	player(string _name):name(_name){
		fillWinLines();
	}
	//void setName(const string& s) { 
	//	std::cout<<"const string&"<<std::endl;
	//	name = s;
	//}
	void setName(string&& s) { 
		std::cout<<"string&&"<<std::endl;
		name = std::move(s);
	}
	string getName() {return name;}
	int getId() { return id;}
	void addGame() { ++games;}
	void addWins() { ++wins;}
	size_t getGames() { return games;}
	size_t getWins() { return wins;}
	size_t getLoses() { return games - wins;}
	void fillWinLines() { wls = {row1, row2, row3, col1, col2, col3, diag, diag_c}; }
	size_t getWinLinesCount() { return wls.size(); }
	void removeWinLines(winlinesset wl) { 
		for(auto &w: wl){
			wls.erase(w); 
		}
	}
	bool operator==(const player& p){ if (p.name == name) return true; else return false;}
};

class game{
	board bd;
	player p1, p2;
	status p1st;
	vector<step> moves;
	fillers playerturn;
	size_t nturns;
public:
	game(player _p1, player _p2):p1(_p1), p2(_p2), bd(), moves(), p1st(undefined), playerturn(player1) {
		p1.addGame(); p2.addGame();
		p1.fillWinLines();
		p2.fillWinLines();
		bd.display();
		nturns=0;
	}
	
	void playNextMove(step&& m);

	void storeMoves(vector<step>&& moves);

	void playStoredMoves();

	status getResult();

	player getPlayer() { if(playerturn == player1) return p1; else return p2;}
		
};

#endif
