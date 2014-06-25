//Rock Paper Scissor Lizard Spock

#ifndef RPS_H
#define RPS_H

#include<fstream>
#include<string>

using namespace std;

class gamePlay
{
public:
	gamePlay();
	void playTheGame(int playerChoice, int computerChoice);
	void setPlayerID(int ID) 	{ playerID = ID; }
	int getPlayerID() 			{ return playerID; }
	void printStats();
	int getBot1Choice(int i)	{ return bot1Choice[i]; }
	void wipeGameStats();

private:
	int winner;
	float bot1;
	float bot2;
	float played;
	float tied;
	int playerID;
	int choiceStats[5][5];
	int bot1Choice[5];
	int bot2Choice[5];
	string types[5];
	string typesInit[5];
};

class AIOptions
{
public:
	AIOptions();
	void setBasicAI();
	void setCounterAI(int past); //Round 1; Random, Round 2+; Counters previous rounds
	void setStubbornAI();
	void setPlannedAI(int gameNum);
	void setMostPlayedAI(gamePlay gameplay);
	int getAIChoice();
	
private:
	int selection;
};

#endif