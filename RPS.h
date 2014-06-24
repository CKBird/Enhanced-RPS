//Rock Paper Scissor Lizard Spock

#ifndef RPS_H
#define RPS_H

#include<fstream>
#include<string>

using namespace std;

class AIOptions
{
public:
	AIOptions();
	void setBasicAI();
	int getBasicAI();
	void setCounterAI(int past);
	int getCounterAI();
	
private:
	int selection;
};

class gamePlay
{
public:
	gamePlay();
	void playTheGame(int playerChoice, int computerChoice);

private:
	int winner;
	float bot1;
	float bot2;
	float played;
	float tied;
};

#endif