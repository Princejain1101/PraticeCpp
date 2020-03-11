#include "tictactoelib.h"

winlinesset winLinesForN(size_t n){
        switch(n){
                case 0: return {row1, col1, diag};
                case 1: return {row1, col2};
                case 2: return {row1, col3, diag_c};
                case 3: return {row2, col1};
                case 4: return {row2, col2, diag, diag_c};
                case 5: return {row2, col3};
                case 6: return {row3, col1, diag_c};
                case 7: return {row3, col2};
                case 8: return {row3, col3, diag};
                default: return {};
        }

}

bool board::checkBoundary(int x, int y){
	if(x<0 || x>=n  || y<0 || y>=n) return false;
	return true;
}

void board::reset() {
	for(auto &row: mat) {
		row = vector<fillers>(n, empty);
	}
}

void board::display() {
	std::cout<<std::endl;
	int rowi=0; 
	int coli=0;
	for(auto &row: mat) {
		coli=0;
		for(auto &col: row) {
			if(col==-1) std::cout<<"X, ";
			if(col==1) std::cout<<"O, ";
			if(col==0) std::cout<<rowi*n+coli+1<<", ";
			coli++;
		}
		std::cout<<std::endl;
		rowi++;
	}
	std::cout<<std::endl;
}

status board::makeMove(step &&m, fillers player){
	int x = m.x; 
	int y = m.y;
	if(!checkBoundary(x, y)) return outOfBox;  // check if move is out of Bounds

	if(mat[x][y] != empty) return filled;  // check if the position is already filled.

	playerturn = player;

	mat[x][y] = playerturn; // mark that position for the current player.

	// check row
	size_t count = 0;
	for(size_t index = 0; index < n; ++index){
		if(mat[x][index] == playerturn) ++count;
		else break;
	}
	if(count == n) return win;

	count = 0;
	for(size_t index = 0; index < n; ++index){
		if(mat[index][y] == playerturn) ++count;
		else break;
	}
	if(count == n) return win;

	count = 0;
	for(size_t index = 0; index < n && x == y; ++index){
		if(mat[index][index] == playerturn) ++count;
		else break;
	}
	if(count == n) return win;

	count = 0;
	for(size_t index = 0; index < n && (n-x-1 == y); ++index){
		if(mat[n-index-1][index] == playerturn) ++count;
		else break;
	}
	if(count == n) return win;

	return undefined;
}


void game::playNextMove(step&& m){
	status st = bd.makeMove(std::move(m), playerturn);
	if(st == outOfBox) {std::cout<<"out of box"<<std::endl; return;}
	if(st == filled) {std::cout<<"wrong move, already played"<<std::endl; return;}
	bd.display();
	if(st == win) {
		if(bd.getPlayer()==1) {
			p1.addWins();
			p1st = win;
		}
		else {
			p2.addWins();
			p1st = lose;
		}
	} else {
		if(playerturn == player1) { 
			p2.removeWinLines(winLinesForN(m.x*3+m.y)); 
		}
		else{ 
			p1.removeWinLines(winLinesForN(m.x*3+m.y));
		}
		if(p2.getWinLinesCount() == 0 && p1.getWinLinesCount() == 0) p1st = draw;
		else p1st = undefined;
	}

	playerturn = playerturn == player1 ? player2 : player1;
	nturns++;
}

void game::playStoredMoves(){
	for(auto& m: moves) {
		playNextMove(std::move(m));
		if(p1st == win) break;
	}
}

status game::getResult(){
	if(p1st == win) {
		std::cout<<p1.getName()<<" won and "<<p2.getName()<<" lost"<<std::endl;
		return win;
	}	
	if(p1st == lose) {
		std::cout<<p2.getName()<<" won and "<<p1.getName()<<" lost"<<std::endl;
		return lose;
	}	
	if(p1st == draw) { std::cout<<"game draw"<<std::endl; return draw;}
	if(p1st == undefined) std::cout<<"next move"<<std::endl;
	return p1st;
}



