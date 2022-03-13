#ifndef Player_H
#define Player_H
#include <iostream>
#include <cstdlib>
#include "Hangman.h"

using namespace std;
class Player: public Hangman
{
private:
	int health;
	int score;
public:
	Player(); //Player Constructor
	Player(int health, int score); //Player Overload
	Player(const Player &copyConstructor); //Player Copy Constructor
	
	//Setters
	void setHealth(int); //Modify Player's Health
	void setScore(int); //Modify Player's Score
	//Getters
	const int getHealth(); //Get player's Health
	const int getScore(); //Get player's score

	//Boss Mitigation
	void playerGameDmg(); //Dmg the game inflicts

	//Dificulty Modifiers
	void playerScoreDificultyModifier(); //Changes the score depending on the dificulty
	void playerHealthDificultyModifier(); //Changes the health depending on the dificulty

	//Destructor
	~Player();
};
#endif
