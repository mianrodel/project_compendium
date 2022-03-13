#ifndef states_H
#define states_H
#include "Hangman.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
class states: public Player
{
private:
	int menuOptionState;
	bool startState;
	bool gameRunningState;
	char underLineState[4];
public:
	//Constructors
	states(); //Main COnstructor
	states(const states &Obj); //Copy Constructor
	states(bool, bool, int, const char*);
	//Setters
	void setStartSate(bool); //Changes the state of the menu
	void setGameRunningState(bool); //Changes the state of the game condition
	void setOptionsState(int);
	void setunderLineState(char);

	
	//Getters
	const bool getStartState(); //Get the state of the menu
	const bool getGameRunningState(); //Get the state of the game
	const int getOptionsState();
	const char * getUnderLineState();
	//AskState
	void askMenuOptionInput();
	void askLetterInput();
	
	//Editors
	void editUnderlines(char * userLetter);
	
	//Show
	void showPlayerHealthState();
	void showPlayerScoreState();
	void showUnderscoreState();
	void showWinState(); //Show if win
	void showLooseState();
	void showStartState();
	void showGameRunningState();
	
	
	bool checkIfWinState();
	
	
	void doWinState();
	void doLooseState();
	
	//Destructor
	~states();
};
#endif
