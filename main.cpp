//Rock Paper Scissor Lizard Spock

#include <string>
#include <fstream>
#include <iostream>
#include "RPS.h"

using namespace std;

int main()
{
	int choice = 0;
	gamePlay gameplay;
	AIOptions aioptions1;
	AIOptions aioptions2;
	while(choice != -1) {
		cout << "Welcome to Rock-Paper-Scissors-Lizard-Spock!" << endl;
		cout << "\nPlease select an option from the menu to get started!" << endl;
		cout << "1: Play against Computer" << endl;
		cout << "2: See the Rules" << endl;
		cout << "3: See the About Page" << endl;
		cout << "4: Basic AI vs Basic AI" << endl;
		cout << "5: Other AI vs AI Matches" << endl;
		cout << "6: End the program" << endl;
		
		cin >> choice;
		
		if(choice == 1) {
			//Play the game here
			int again = 1;
			//gamePlay gameplay
			gameplay.setPlayerID(1);
			while(again == 1) {
				aioptions1.setBasicAI();
				int AIchoice = aioptions1.getAIChoice(); //Gets computer choice
				
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
				gameplay.playTheGame(playerChoice, AIchoice);
				cout << "Play Again? 1 for yes, 2 for no" << endl;
				cin >> again;
			}
			gameplay.printStats();
			gameplay.wipeGameStats();
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
		else if(choice == 4) { //40/40/20 Rate
			//Play the game here
			int again = 0;
			//gamePlay gameplay;
			gameplay.setPlayerID(0);
			while(again < 10000) {
				aioptions1.setBasicAI();
				int bot1 = aioptions1.getAIChoice();
				aioptions1.setBasicAI();
				int bot2 = aioptions1.getAIChoice();
				
				gameplay.playTheGame(bot1, bot2);
				again++;
			}
			gameplay.printStats();
			gameplay.wipeGameStats();
		}
		else if(choice == 5) {
			int subChoice = 0;
			cout << "Please select which match you would like to simulate" << endl;
			cout << "1: Counter AI vs Basic AI" << endl;
			cout << "2: Counter AI vs Counter AI" << endl;
			cout << "3: Basic AI vs Stubborn AI" << endl;
			cout << "4: Basic AI vs Planned AI" << endl;
			cout << "5: Counter AI vs Planned AI" << endl;
			cout << "6: Planned AI vs Planned AI" << endl;
			cout << "7: Basic AI vs MostPlayed AI" << endl;
			cout << "8: Planned AI vs MostPlayed AI" << endl;
			cout << "9: Counter AI vs MostPlayed AI" << endl;
			cout << "0: Main Menu" << endl;
			cin >> subChoice;
			
			if(subChoice == 1) { //Remains 40/40/20
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setCounterAI(bot2);
					bot1 = aioptions1.getAIChoice();
					aioptions1.setBasicAI();
					bot2 = aioptions1.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 2) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setCounterAI(bot2);
					aioptions2.setCounterAI(bot1);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 3) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setBasicAI();
					aioptions2.setStubbornAI();
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 4) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setBasicAI();
					aioptions2.setPlannedAI(again);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 5) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setCounterAI(bot2);
					aioptions2.setPlannedAI(again);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}			
			else if(subChoice == 6) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setPlannedAI(again);
					aioptions2.setPlannedAI(again);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 7) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setBasicAI();
					aioptions2.setMostPlayedAI(gameplay);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 8) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setPlannedAI(again);
					aioptions2.setMostPlayedAI(gameplay);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			else if(subChoice == 9) {
				int again = 0;
				int bot1 = 0;
				int bot2 = 0;
				//gamePlay gameplay;
				gameplay.setPlayerID(0);
				while(again < 10000) {
					aioptions1.setCounterAI(bot2);
					aioptions2.setMostPlayedAI(gameplay);
					bot1 = aioptions1.getAIChoice();
					bot2 = aioptions2.getAIChoice();
					
					gameplay.playTheGame(bot1, bot2);
					again++;
				}
				gameplay.printStats();
				gameplay.wipeGameStats();
			}
			//MUST ADD IN MOST PLAYED AI GAME HERE
			//MUST GET BOT1CHOICE INTO CORRECT SCOPE
			//ONLY BOT2 CAN BE MOSTPLAYEDAI
			else if(subChoice == 0) {
				cout << "Returning to Main Menu" << endl;
			}
			else
				cout << "Please enter either a number between 1 and 9" << endl;
		}
		else if(choice == 6) {
			choice = -1;
			cout << "Game Ended!\n" << endl;
		}
		else {
			cout << "Please enter a number between 1 and 5!\n" << endl;
			choice = 0;
		}
	}
	
	cout << "Program Closing...\n" << endl;
	return 0;
}