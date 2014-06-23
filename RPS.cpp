//Rock Paper Scissor Lizard Spock

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "RPS.h"

using namespace std;

//Beginning of function definitions and class definitions

AIOptions::AIOptions() {
	selection = 0;
} //RPS Player constructor

void AIOptions::setBasicAI() {
	//set selection here for basic AI (100% random)
	int random = rand() % 5 + 1; //Different variable allows for more use of random number later if needed
	selection = random;
}

int AIOptions::getBasicAI() {
	//returns basic AI selection to main
	return selection;
}

void AIOptions::setCounterAI(int past) {
	if(past == 0) {
		int random = rand() % 5 + 1;
		selection = random;
	}
	else {
		if(past == 1)
			selection = 5;
		else {
			past--;
			selection = past;
		}
	}
}

int AIOptions::getCounterAI() {
	return selection;
}

Evaluate::Evaluate() {
	winner = -1;
} //evaluate constructor

int Evaluate::getWinner(int player, int computer) {
	//1 Scissors, beats paper and lizard, loses too spock and rock
	//2 Paper, beats spock and rock, loses to lizard and scissors
	//3 Rock, beats lizard and scissors, loses to spock and paper
	//4 Lizard, beats spock and paper, loses to rock and scissors
	//5 Spock, beats scissors and rock, loses to paper and lizard
	
	//Player wins, return 1
	//Computer wins, return 2
	//Tie, return 3
	
	if(player == 1) {
		if(computer == 2 || computer == 4) 
			winner = 1;
		else if(computer == 3 || computer == 5)
			winner = 2;
		else
			winner = 3;
	}
	else if(player == 2) {
		if(computer == 3 || computer == 5)
			winner = 1;
		else if(computer == 1 || computer == 4)
			winner = 2;
		else
			winner = 3;
	}
	else if(player == 3) {
		if(computer == 1 || computer == 4) 
			winner = 1;
		else if(computer == 2 || computer == 5)
			winner = 2;
		else
			winner = 3;
	}
	else if(player == 4) {
		if(computer == 2 || computer == 5)
			winner = 1;
		else if(computer == 1 || computer == 3)
			winner = 2;
		else
			winner = 3;
	}
	else if(player == 5) {
		if(computer == 1 || computer == 3)
			winner = 1;
		else if(computer == 2 || computer == 4)
			winner = 2;
		else
			winner = 3;
	}
	else
		winner = 0;
	
	return winner;
}