#include "Player.h"



/*
	Like the Hangman Class, the Player Class is another box; yet, this one is an extension of the fundamental holy box (Hangman Class). 
	It has some things that need the fundamental box to work, and it also has some things that make it different!
	For instance this box has all that is related to players: Health, Score...; as well, some methods that modify such values.
*/

//Constructors
/*
	/////////////////////Original Constructor:
	I think that by now you would know how this portion of the code works!
	Nevertheless, this constructor initializes the value of the Player's Health to 10 and his or her score to 0!
*/
Player::Player()
{
	this->health = 10;
	this->score = 0;
}
/*
	///////////////////Overload Constructor:
	O_O Ok...
	This constructor asks for two inputs (int, int) and sets their value to health and score respectively
*/
Player::Player(int health, int score) { //Const Overload
	this->health = health;
	this->score = score;
}
/*
	///////////////////Copy Constructor:
	>_< I'm angry...!
	This constructor asks for an object of the same class and sets the object's health to this object's health, same with the score.
*/
Player::Player(const Player &copyConstructor) { //Copy Const
	this->health = copyConstructor.health;
	this->score = copyConstructor.score;
}

//Setters
/*
	:( Not Found
*/
void Player::setHealth(int hp) { // Changes Player's HP
	this->health = hp;
}
void Player::setScore(int sc) { //Changes Player's Score
	this->score = sc;
}

//Getters
/*
	:( Not Found
*/
const int Player::getHealth() { //Get Player's Health
	return (this->health);
}
const int Player::getScore() { //Get Player's Score
	return (this->score);
}


//Mitigation
/*
	////////////////////////playerGameDmg:
	Imagine that your are playing a game and for each time there need's to be basic-code background explaining, you loose 1 point of health in it.
	This is what this method does! :)
*/
void Player::playerGameDmg() {
	this->health = this->health - 1;
}

//Dificulty Modifiers
/*
	/////////////////////////playerScoreDifficultyModifier:
	Nowadays there are some games that if you beat them, you can start it all again with the same character at a Higher Dificulty.
	This function lets you to earn more points after each beaten round.
*/
void Player::playerScoreDificultyModifier() { 
	this->score = this->score + 10 * (this->getNumberGames()+1); //Ex. If there have two games played: score + (number of letters found with letter)*10*2
}
/*
	///////////////////////playerHealthDificultyModifier:
	Nowadays there are some games that if you beat them, you can start it all again with the same character at a Higher Dificulty.
	This function makes the game harder after each beaten round, by decreasing the Health gained at the start of the next ground. The health decreases in intervals.
*/
void Player::playerHealthDificultyModifier() {
	if (getNumberGames() >= 0 && getNumberGames() <= 3) {
		this->health = 10;
	}
	else if (getNumberGames() >= 4 && getNumberGames() <= 6) {
		this->health = 7;
	}
	else if (getNumberGames() >= 7 && getNumberGames() <= 9) {
		this->health = 5;
	}
	else {
		this->health = 3; //Hehe
	}
}

//Destructor
Player::~Player()
{
}
