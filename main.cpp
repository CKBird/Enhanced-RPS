//Rock Paper Scissor Lizard Spock
//1st: 	Design a simple program that will play the game with the user
//		User will choose 1 of the 5 inputs from given list by using number key
//		Computer will randomly choose
//		**Create normal RPS player as well if interested
//2nd:	Add different AI choices who choose different moves
//		"Extra Lottery Ticket" type AI
//		Stubborn Player type AI (Always chooses one of two)
//		Always chooses one to counter last user input (Default to rock on turn 1)
//		Chooses based on players sequence
//		Chooses based on player's most picked, and beats it
//		Etc. Make up more as you go
//3rd:	Have two AIs battle against eachother
//		Calculate Results based on 10k games
//		Design bots to mimic types of people and determine which strategy
//			is the best

#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <cstdio>
#include "RPS.h"

using namespace std;

int main()
{
	int choice = 0;
	AIOptions aioptions;
	Evaluate evaluate;
	while(choice != -1) {
		cout << "Welcome to Rock-Paper-Scissors-Lizard-Spock!" << endl;
		cout << "\nPlease select an option from the menu to get started!" << endl;
		cout << "1: Play against Computer" << endl;
		cout << "2: See the Rules" << endl;
		cout << "3: See the About Page" << endl;
		cout << "4: End the program" << endl;
		cout << "5: Basic AI vs Basic AI" << endl;
		
		cin >> choice;
		
		if(choice == 1) {
			//Play the game here
			int again = 1;
			float won = 0.0, lost = 0.0, tied = 0.0, played = 0.0;
			while(again == 1) {
				aioptions.setBasicAI();
				int AIchoice = aioptions.getBasicAI(); //Gets computer choice
				
				int playerChoice = 0;
				while(playerChoice == 0) {
					cout << "\nPlease select from the following options" << endl;
					cout << "1 for Scissors" << endl;
					cout << "2 for Paper" << endl;
					cout << "3 for Rock" << endl;
					cout << "4 for Lizard" << endl;
					cout << "5 for Spock" << endl;
					cin >> playerChoice;
					if(playerChoice != 1 && playerChoice != 2 && playerChoice != 3 && playerChoice != 4 && playerChoice != 5) {
						cout << "Please select a valid choice!\n" << endl;
						playerChoice = 0;
					}
				}
				int winner = evaluate.getWinner(playerChoice, AIchoice);
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
					
				if(AIchoice == 1)
					computer = "Scissors";
				else if(AIchoice == 2)
					computer = "Paper";
				else if(AIchoice == 3)
					computer = "Rock";
				else if(AIchoice == 4)
					computer = "Lizard";
				else
					computer = "Spock";
					
				cout << "You Chose: " << player << endl;
				cout << "Computer Chose: " << computer << endl;
				
				if(winner == 1) {
					cout << "You won!\n" << endl;
					won++;
					played++;
					cout << "Play again? 1 for yes, 0 for no" << endl;
					cin >> again;
				}
				else if(winner == 2) {
					cout << "You lost!\n" << endl;
					lost++;
					played++;
					cout << "Play again? 1 for yes, 0 for no" << endl;
					cin >> again;
				}
				else if(winner == 3) {
					cout << "You tied!\n" << endl;
					tied++;
					played++;
					cout << "Play again? 1 for yes, 0 for no" << endl;
					cin >> again;
				}
				else
					cout << "ERROR!\n" << endl;
			}
			cout << "Games won: " << won << " -- Percentage: " << (won/played)*100 << "%" << endl;
			cout << "Games lost: " << lost << " -- Percentage: " << (lost/played)*100 << "%" << endl;
			cout << "Games tied: " << tied << " -- Percentage: " << (tied/played)*100 << "%" << endl;
			cout << "Total played: " << played << endl << endl;
		}
		else if(choice == 2) {
			cout << "\nThe rules are simple!" << endl;
			cout << "Rock beats lizard and scissors, but loses to spock and paper" << endl;
			cout << "Paper beats spock and rock, but loses to lizard and scissors" << endl;
			cout << "Scissors beats paper and lizard, but loses too spock and rock" << endl;
			cout << "Lizard beats spock and paper, but loses to rock and scissors" << endl;
			cout << "Spock beats scissors and rock, but loses to paper and lizard\n" << endl;
		}
		else if(choice == 3) {
			cout << "Program Written By Christopher Bird on June 23rd, 2014\n" << endl;
		}
		else if(choice == 4) {
			choice = -1;
			cout << "Game Ended!\n" << endl;
		}
		else if(choice == 5) {
			//Play the game here
			int again = 0;
			float won = 0.0, lost = 0.0, tied = 0.0, played = 0.0;
			while(again < 10000) {
				aioptions.setBasicAI();
				int bot1 = aioptions.getBasicAI(); //Gets computer choice
				
				aioptions.setBasicAI();
				int bot2 = aioptions.getBasicAI();
				
				int winner = evaluate.getWinner(bot1, bot2);
				string player, computer;
				if(bot1 == 1)
					player = "Scissors";
				else if(bot1 == 2)
					player = "Paper";
				else if(bot1 == 3)
					player = "Rock";
				else if(bot1 == 4)
					player = "Lizard";
				else
					player = "Spock";
					
				if(bot2 == 1)
					computer = "Scissors";
				else if(bot2 == 2)
					computer = "Paper";
				else if(bot2 == 3)
					computer = "Rock";
				else if(bot2 == 4)
					computer = "Lizard";
				else
					computer = "Spock";
					
				cout << "Bot 1 Chose: " << player << endl;
				cout << "Bot 2 Chose: " << computer << endl;
				
				if(winner == 1) {
					cout << "Bot1 won!\n" << endl;
					won++;
					played++;
					again++;
				}
				else if(winner == 2) {
					cout << "Bot1 lost!\n" << endl;
					lost++;
					played++;
					again++;
				}
				else if(winner == 3) {
					cout << "They tied!\n" << endl;
					tied++;
					played++;
					again++;
				}
				else
					cout << "ERROR!\n" << endl;
			}
			cout << "Games Bot1 won: " << won << " -- Percentage: " << (won/played)*100 << "%" << endl;
			cout << "Games Bot1 lost: " << lost << " -- Percentage: " << (lost/played)*100 << "%" << endl;
			cout << "Games they tied: " << tied << " -- Percentage: " << (tied/played)*100 << "%" << endl;
			cout << "Total played: " << played << endl << endl;
		}
		else {
			cout << "Please enter a number between 1 and 5!\n" << endl;
			choice = 0;
		}
	}
	
	cout << "Program Closing...\n" << endl;
	return 0;
}