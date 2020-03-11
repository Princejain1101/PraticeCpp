#include <iostream>
#include "tictactoelib.h"

int main(){
	std::cout<<"hello"<<std::endl;

	std::cout<<"Enter player 1 name"<<std::endl;
	string p1name;
	cin >> p1name;
	std::cout<<"Enter player 2 name"<<std::endl;
	string p2name;
	cin >> p2name;
	player p1(p1name);
	player p2(p2name);

	game g(p1, p2);

	int index;
	while(1){
		std::cout<<g.getPlayer().getName()<<"'s turn"<<std::endl;
		std::cout<<"enter index: ";
		cin >> index;

		g.playNextMove(step(index));
		status result = g.getResult();

		if(result == win  || result == lose || result == draw) break;
	}
}
