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
		int random = rand() % 2 + 1;
		if(random == 1 && past != 1) {
			past--;
			selection = past;
		}
		else if(random == 1 && past == 1) {
			past = 5;
			selection = past;
		}
		else if(random == 2 && past < 4) {
			past = past + 2;
			selection = past;
		}
		else if(random == 2 && past == 4) {
			past = 1;
			selection = past;
		}
		else if(random == 2 && past == 5) {
			past = 2;
			selection = past;
		}
	}
}

int AIOptions::getCounterAI() {
	return selection;
}

gamePlay::gamePlay() {
	winner = -1;
	bot1 = 0.0;
	bot2 = 0.0;
	played = 0.0;
	tied = 0.0;
} //evaluate constructor

void gamePlay::playTheGame(int playerChoice, int computerChoice) { 	//input to this function will be ints of what each character played
																	//Will print game stats (X beat Y with X)
	string player, computer;
	if(playerChoice == 1)
		player = "Scissors";
	else if(playerChoice == 2)
		player = "Paper";
	else if(playerChoice == 3)
		player = "Rock";
	else if(playerChoice == 4)
		player = "Lizard";
	else
		player = "Spock";
		
	if(computerChoice == 1)
		computer = "Scissors";
	else if(computerChoice == 2)
		computer = "Paper";
	else if(computerChoice == 3)
		computer = "Rock";
	else if(computerChoice == 4)
		computer = "Lizard";
	else
		computer = "Spock";
		
	cout << "Bot 1 Chose: " << player << endl;
	cout << "Bot 2 Chose: " << computer << endl;
	
	//Decide Winner
	//1 Scissors, beats paper and lizard, loses too spock and rock
	//2 Paper, beats spock and rock, loses to lizard and scissors
	//3 Rock, beats lizard and scissors, loses to spock and paper
	//4 Lizard, beats spock and paper, loses to rock and scissors
	//5 Spock, beats scissors and rock, loses to paper and lizard
	
	//Player wins, return 1
	//Computer wins, return 2
	//Tie, return 3
	
	if(playerChoice == 1) {
		if(computerChoice == 2 || computerChoice == 4) 
			winner = 1;
		else if(computerChoice == 3 || computerChoice == 5)
			winner = 2;
		else
			winner = 3;
	}
	else if(playerChoice == 2) {
		if(computerChoice == 3 || computerChoice == 5)
			winner = 1;
		else if(computerChoice == 1 || computerChoice == 4)
			winner = 2;
		else
			winner = 3;
	}
	else if(playerChoice == 3) {
		if(computerChoice == 1 || computerChoice == 4) 
			winner = 1;
		else if(computerChoice == 2 || computerChoice == 5)
			winner = 2;
		else
			winner = 3;
	}
	else if(playerChoice == 4) {
		if(computerChoice == 2 || computerChoice == 5)
			winner = 1;
		else if(computerChoice == 1 || computerChoice == 3)
			winner = 2;
		else
			winner = 3;
	}
	else if(playerChoice == 5) {
		if(computerChoice == 1 || computerChoice == 3)
			winner = 1;
		else if(computerChoice == 2 || computerChoice == 4)
			winner = 2;
		else
			winner = 3;
	}
	else
		winner = 0;
		
	//Display Results
	
	if(winner == 1) {
		cout << "Bot 1 won!\n" << endl;
		bot1++;
		played++;

	}
	else if(winner == 2) {
		cout << "Bot 2 won!\n" << endl;
		bot2++;
		played++;
	}
	else if(winner == 3) {
		cout << "They tied!\n" << endl;
		tied++;
		played++;
	}
	else
		cout << "ERROR!\n" << endl;
		
	//Display Stats
	cout << "Games Bot 1 won: " << bot1 << " -- Percentage: " << (bot1/played)*100 << "%" << endl;
	cout << "Games Bot 2 won: " << bot2 << " -- Percentage: " << (bot2/played)*100 << "%" << endl;
	cout << "Games they tied: " << tied << " -- Percentage: " << (tied/played)*100 << "%" << endl;
	cout << "Total played: " << played << endl << endl;
}