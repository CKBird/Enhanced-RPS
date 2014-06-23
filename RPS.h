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
	
private:
	int selection;
};

class Evaluate
{
public:
	Evaluate();
	int getWinner(int player, int computer);

private:
	int winner;
};

#endif