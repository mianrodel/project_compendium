#include "states.h"
/*
	The Pre-Implementation Code of this whole Game:
	The states class sole purpose is to deal with all that is related to changes in the game; hence, the name.
	In other words, it means that all graphical, numerical, boolean, etc..., changes occur here. 
	This is done to clean the main!

	=O
*/

//Constructors
/*
	:( Not Found
*/
states::states() //Original Constuctor
{
	this->startState = true;
	this->gameRunningState = false;
	this->menuOptionState = -1;
	//Couldn't find another way to initialize these lines
	this->underLineState[0] = '_';
	this->underLineState[1] = '_';
	this->underLineState[2] = '_';
	this->underLineState[3] = '\0';
}
states::states(bool start, bool game, int options, const char * c) { //Overload Constructor
	this->startState = start;
	this->gameRunningState = game;
	this->menuOptionState = options;
	// Couldn't find another way to initialize these lines
	this->underLineState[0] = c[0];
	this->underLineState[1] = c[1];
	this->underLineState[2] = c[2];
	this->underLineState[3] = c[3];
}
states::states(const states &copy) { //Copy Constructor
	this->startState = copy.startState;
	this->gameRunningState = copy.gameRunningState;
	this->menuOptionState = copy.menuOptionState;
	// Couldn't find another way to initializes these lines
	this->underLineState[0] = copy.underLineState[0];
	this->underLineState[1] = copy.underLineState[1];
	this->underLineState[2] = copy.underLineState[2];
	this->underLineState[3] = copy.underLineState[3];
}

//Setters
/*
	:( Not Found
*/
void states::setStartSate(bool state) { //Program Start State Changer
	this->startState = state;
}
void states::setGameRunningState(bool state){ //GameRunningState Changer
	this->gameRunningState = state;
}
void states::setOptionsState(int in){ //MenuOptionState Changer
	this->menuOptionState = in;
}
void states::setunderLineState(char c){ //underLineState Changer
	this->underLineState[0] = c;
	this->underLineState[1] = c;
	this->underLineState[2] = c;
	this->underLineState[3] = c;
}

//Getters
/*
	:( Not Found
*/
const bool states::getStartState() { //Get Program Start State (If the program is running)
	return(this->startState);
}
const bool states::getGameRunningState(){ //Get Game Running State (If the game has started)
	return(this->gameRunningState);
}
const int states::getOptionsState(){ //Get Options State (Menu options)
	return(this->menuOptionState);
}
const char * states::getUnderLineState(){ //Get the underLine char array
	return(this->underLineState);
}

//AskStates
/*
	////////////////askMenuOptionInput:
	This function asks the user for an integer input (1,2) in the Main Menu.
	It has its validations to check wether the input was entered correctly in terms of wrong number and non-numeric characters
*/
void states::askMenuOptionInput() {
	do {
		cout << "What option would you like to choose from the menu?\nCHOICE: ";
	} while (cin >> this->menuOptionState && this->menuOptionState != 1 && this->menuOptionState !=2); //n
}
/*
	////////////////askLetterInput:
	This function asks the user for an char input in the Game.
	It has its validations to check wether the input was entered correctly in terms of letters
	If the user inputed a letter, the it calls a method from within
*/
void states::askLetterInput() {
	char * userLetter = new char;
	do {
		cout << "What letter would you like to play?\nCHOICE: ";
	} while (cin >> userLetter && letterValidator(userLetter) == false); //n
	if (letterValidator(userLetter) == true) {
		editUnderlines(userLetter);
	}
	else {
		cout << "Given input is not correct!" << endl;
		system("pause");
	}
	return;
}
/*
	////////////////editUnderlines:
	The function asks for a letter. It then evaluates if the letter is part of the chosen word and if so, it checks if letter was inputed in the past
	It also has a counter to check if the game will harm the player
*/
void states::editUnderlines(char * userLetter) {
	int counter = 0;
	setLetter(userLetter[0]);
	for (int i = 0; i < getWord().size(); i++) {//3
		if (getWord()[i] == getLetter()) {
			counter++;
			if (this->underLineState[i] != getLetter()) {
				this->underLineState[i] = getLetter();
				playerScoreDificultyModifier();
			}
			else {
				break;
			}
		}
	}
	if (counter == 0) {
		playerGameDmg();
	}
}

//ShowStates
/*
	///////////////showPlayerHealthState:
	This function shows the actual health of the player.
*/
void states::showPlayerHealthState() {
	cout << "PLAYER'S HEALTH: " << getHealth() << endl;
}
/*
	////////////////showPlayerScoreState:
	This function shows the actual score of the player
*/
void states::showPlayerScoreState() {
	cout << "PLAYER'S SCORE: " << getScore() << endl;
}

/*
	////////////////////showUnderscoreState:
	This function show the actual value of the under lines
*/
void states::showUnderscoreState() {
	cout << "<<<<<<<<<<<<<<< " << (this->underLineState[0]) << " " << (this->underLineState[1]) << " " << (this->underLineState[2]) << " >>>>>>>>>>>>>>>" << endl << endl;

}
/*
	//////////////////////showWinState:
	This function shows the text that will be written if player wins!
*/
void states::showWinState() {
		cout << "You have won round number " << getNumberGames() + 1 << "! " << endl;
		cout << "Your score is " << getScore() << "! " << endl;
}
/*
	////////////////////showLooseState:
	This function will show the text is one looses to the game
*/
void states::showLooseState() {
	cout << "You have lost the round! " << endl;
	cout << "Your score is " << getScore() << "! " << endl;
	cout << "Thank you for playing! " << endl;
}

/*
	/////////////////////showStartState:
	This function shows the Main Menu i.e(Start of the Game)
*/
void states::showStartState() {
	
	cout << "--------------------------------------------------------" << endl <<
		"-             Project Hangman Main Menu                -" << endl <<
		"--------------------------------------------------------" << endl;
	cout << "Number of Games Played: " << getNumberGames() << endl << endl;
	cout << "Options" << endl;
	cout << "1. Start Game\n2. Exit the Application\n";
}
/*
	///////////////////////showGameRunningState:
	This function shows the Game itself
*/
void states::showGameRunningState() {
	cout << "--------------------------------------------------------" << endl <<
		"-              Hangman Championship!                   -" << endl <<
		"--------------------------------------------------------" << endl << endl;
	cout << "To all men I appartain and, yet, by some I am shunned in disdain. " << endl <<
		"Poets fondle me and oogle me till they are insane, but no blows can cause me pain. " << endl <<
		"Cry and I crack, yawn and I moan; smile and I shall too laugh. What am I?" << endl;
}

//Bools
/*
	/////////////////////////checkIfWinState:
	This function checks wether the underlines equal chosen word. If so, the game is won. If not, well...
*/
bool states::checkIfWinState() {
	int counter = 0;
	for (int i = 0; i < getWord().size(); i++){//3
		if (this->underLineState[i] == getWord()[i]){
			counter++;
		}
	}
	if (counter == getWord().size()){
		return true;
	}
	return false;
}

//Hiden Mechanics
/*
	/////////////////////////doWinState and doLooseState:
	Works simiralily the same:
	It resets all edited values to their original
*/
void states::doWinState(){
	setHealth(7);
	setNumberGames(getNumberGames() + 1);
	this->gameRunningState = false;
	this->underLineState[0] = '_';
	this->underLineState[1] = '_';
	this->underLineState[2] = '_';
	this->underLineState[3] = '\0';

}
void states::doLooseState(){
	setHealth(10);
	setScore(0);
	setNumberGames(0);
	this->gameRunningState = false;
	this->underLineState[0] = '_';
	this->underLineState[1] = '_';
	this->underLineState[2] = '_';
	this->underLineState[3] = '\0';
}
//Destructors
states::~states()
{
}
