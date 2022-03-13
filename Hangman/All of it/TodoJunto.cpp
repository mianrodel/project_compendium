#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

class Hangman
{
private:
	string word; //Computer Picked Word
	char letter; //User Inputed Letter

	//Dificulty
	int games; //Number of Games to make Game Harder
public:
	Hangman(); //Constructor
	Hangman(const Hangman &obj); //Copy Constructor
	Hangman(string, char, int); //Constructor Overload
	~Hangman(); //Destructor
	//Setters
	void setWord(string); //Change given word
	void setLetter(char); //Change the letters
	void setNumberGames(int); //Change number of games played
	//Getters
	const string getWord(); //Get given word
	const char getLetter(); //Get the letter
	const int getNumberGames(); //Get number of games played
	//List Methods
	const vector<string> fileLineExtractor(string); //Reads the file and extracts all words on it
	void wordPicker(vector<string>); //Word randomizer
	const bool letterValidator(char*); //Validates the letter as a char and nothing else (Like a number)
	const bool checkifisWordLetter(const char * userLetter, char * underLines);
private:
	//Super Secret Methods
	static const bool wordSizeValidator(string); //Verifies the size of chosen word
};
class Player : public Hangman
{
private:
	int health; //Player's Health
	int score; //Player's Score
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
class states : public Player
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
	void setOptionsState(int); //Changes the options inputed in main menu
	void setunderLineState(char); //Changes the state of the underlines


	//Getters
	const bool getStartState(); //Get the state of the menu
	const bool getGameRunningState(); //Get the state of the game
	const int getOptionsState(); //Get the options inputed in Main Menu
	const char * getUnderLineState(); //Get the underline
	//AskState
	void askMenuOptionInput(); //Prompt of Main Menu
	void askLetterInput(); //Prompt of game

	//Show
	void showPlayerHealthState(); //Show the Player's Health State
	void showPlayerScoreState();  //Show the Player's Score State
	void showUnderscoreState(); //Show the Game's UnderLineState
	void showWinState(); //Show if win
	void showLooseState(); //Show if loose
	void showStartState(); //Show the game start
	void showGameRunningState(); //Show the game running/playing state

	//Bool
	bool checkIfWinState(); //Checks if the game is won

	//Resetters
	void doWinState();
	void doLooseState();

	//Destructor
	~states();
};
Hangman::Hangman() //Original Constructor
{
	this->word = " ";
	this->letter = ' ';
	this->games = 0;
}
/*
	////////////////////CopyConstructorb Info:
	Lets say that we live in a Distopyan Mega City where doctors could make clones of us by using only a little fragment of ourselves.
	Could you say that in order for them to make identical copies of ourselves, wouldn't doctors need a fragment of ourselves: Our DNA?
	Well this method does just that: It asks for an object of the same type and extracts the necessary information for the class to work.
*/
Hangman::Hangman(const Hangman &copyConstructor) { //Copy Constructor
	this->word = copyConstructor.word;
	this->letter = copyConstructor.letter;
	this->games = copyConstructor.games;
}
/*
	//////////////////Overloading Constructor Info:
	You know, they say that your DNA is what ends up stating what traits you would have in life.
	But with all things related to human life, we could, in the future, try and decide which traits would we rather ourselves or others have.
	That is what this method does: It asks for some user inputs (A string, a character and an integer) and sets them to their respective variables
	in order for the class to work properly.
*/
Hangman::Hangman(string word, char letter, int games) //Overload Constructor
{
	this->word = word;
	this->letter = letter;
	this->games = games;
}

//Setters
/*
	/////////////////Setters Info:
	Lets say that you are playing this game for a couple of minutes; then, you get bored and would like to change the ammount of lives and score you got...
	wouldn't that be a nice feature?
	Well, setters are here to aid you! For their sole purpose is to change the values of variables!

	Example:
	Lets say you have a score of 0 pts. And you find out that if you get 1,000,000 pts you get to fight the boss of the game, wouldn't it be neat to be able to
	go from 0pts to 1,000,000 pts in a sec?

	Developers' Note: First there is no boss! Secondly, the setters are recommended to be used outside of the class for security meassures.
*/
void Hangman::setWord(string word) //Word Setter
{
	this->word = word;
}
void Hangman::setLetter(char letter) { //Letter Setter
	this->letter = letter;
}
void Hangman::setNumberGames(int games) { //Number of Games Setter
	this->games = games;
}

//Getters
/*
	/////////////////////Getters Info:
	You are walking to your work one day, and notices a familar face in the distance. Yes, you know that person, his name is Vlad. You know
	from past experience that Vlad tends to ask you for an equal cut of your personal salary. Yet, Vlad is a person like everyone around you; hence,
	you know it would be wise to keep the actual balance off his hands. So you could, at that moment, tell him that you have the money but its of limits.
	This method does just that!
*/
const string Hangman::getWord() //Word Getter
{
	return(this->word);
}
const char Hangman::getLetter() { //Letter Getter
	return(this->letter);
}
const int Hangman::getNumberGames() { //Number of Games Getter
	return (this->games);
}


//FILES
/*
	/////////////////////fileLineExtractor Info:
	Well, lets say, that you open up a book and start reading. After a while, you notice some words you don't know the definition of some words; hence, you decide to
	mark them and copy them to a piece of paper: creating a list of words.

	This method does just that, but instead of reading books, it reads files.
	The methods asks as a parameter a file location; then, it uses it to open the file using a mysterious and friendly library calles fstream.
	It creates a new type of string-array that has no fixed value using another library called vectors.
	Then the method envokes a while-loop that will run until the end of the file with the help of the getLine method. This method is able of reading the file line by line!
	And lastly, it adds the read line to the string-array created with the help of vectors!
*/
const vector<string> Hangman::fileLineExtractor(string location) { //Extracts the word of file. Havent tested
	fstream file(location);
	vector<string> words;
	string line;
	while (getline(file, line)) {
		words.push_back(line);
	}
	return words;
}

/*
	/////////////////////////////WordPicker Info:
	Imagine that you have a deck of 10 cards. You decide to try and shuffle those 10 cards 3 times so that you could see if the first card of the top of the deck
	will be the same those 3 times.
	This method does just that, but instead with cards it does it with 10++ words. It first sets an integer variable to a number between 0-9, for the fact that there
	are 10 words and arrays start at 0.
	Then, it picks one of those 10 words using the integer variable, while always checking that it is a 3 letter word.
*/
void Hangman::wordPicker(vector<string> words) { //Picks a word from the extracted list
	do {
		int chosenWord = rand() % words.size();
		this->word = words.at(chosenWord);
	} while (wordSizeValidator(this->word) != true);
	return;
}
/*
	////////////////checkifWordLetter:
	The function asks function asks for a letter, and a char that will be the underlines. It will vefify if the letter given is in the word and if
	so it will check if the letter hasn't been typed before. If not, then the underlines are edited to show the inputed letter.
	If the letter was in the word, it returns true. If not, well... We are going to a wild ride!
*/
const bool Hangman::checkifisWordLetter(const char * userLetter, char * underlines) {
	int counter = 0;
	this->letter = userLetter[0];
	for (int i = 0; i < (this->word.size()); i++) {//3
		if (this->word[i] == this->letter) {
			counter++;
			if (underlines[i] != this->letter) {
				underlines[i] = this->letter;
			}
			else {
				break;
			}
		}
	}
	if (counter > 0) {
		return true;
	}
	else {
		return false;
	}
}

//Validate
/*
	//////////////////////////letterValidator Info:
	Imagine that you are a professor at a university and you get to evaluate a code that gets to validate letters. Maybe test letters or letters inputed by the user...
	After some time of checking that code and running for a couple of times, a blast of wind gets to just happen at the same time, at that exact time to be more precise,
	when you want to input a character... Your coffee cup starts levitating and bashes one of the keys of the computer! (Don't worry the computer is fine) The key it
	pressed wasn't any key, it was a number... You then notice that the cup starts levitating once again and presses enter! Boooooo! The code crashes.

	This method checks if the input is a real letter so that flying cups may not break the program.
	It returns true if it is a letter, false otherwise.
*/
const bool Hangman::letterValidator(char * letter) { //Validates if input is letter
	if ((*letter >= 'a' && *letter <= 'z') || (*letter >= 'A' && *letter <= 'Z')) {
		return true;
	}
	return false;
}
/*
	//////////////////////////WordSize Validator:
	Words aside, this method checks if the requested word is really of size 3.
	It returns true if it is, false otherwise.
*/
const bool Hangman::wordSizeValidator(string word) { //Validates if chosen word is of size 3 chars
	if (word.size() == 3) {
		return true;
	}
	return false;
}

//Destructor
Hangman::~Hangman()
{

}
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
	this->score = this->score + 10 * (this->getNumberGames() + 1); //Ex. If there have two games played: score + (number of letters found with letter)*10*2
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
void states::setGameRunningState(bool state) { //GameRunningState Changer
	this->gameRunningState = state;
}
void states::setOptionsState(int in) { //MenuOptionState Changer
	this->menuOptionState = in;
}
void states::setunderLineState(char c) { //underLineState Changer
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
const bool states::getGameRunningState() { //Get Game Running State (If the game has started)
	return(this->gameRunningState);
}
const int states::getOptionsState() { //Get Options State (Menu options)
	return(this->menuOptionState);
}
const char * states::getUnderLineState() { //Get the underLine char array
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
	} while (cin >> this->menuOptionState && this->menuOptionState != 1 && this->menuOptionState != 2); //n
	cin.clear();
	return;
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
		if (checkifisWordLetter(userLetter, (this->underLineState)) != true) {
			playerGameDmg();
		}
		else {
			playerScoreDificultyModifier();
		}
	}
	else {
		cout << "Given input is not correct!" << endl;
		system("pause");
	}
	cin.clear();
	return;
}


//ShowStates
/*

*/
//void states::showNumberofWords(){
//	cout << "Number of accepted words in file: " << 
//}
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
	cout << "You've played well! How did you know the word was " << getWord() << "?" << endl;
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
	for (int i = 0; i < getWord().size(); i++) {//3
		if (this->underLineState[i] == getWord()[i]) {
			counter++;
		}
	}
	if (counter == getWord().size()) {
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
void states::doWinState() {
	setHealth(7);
	setNumberGames(getNumberGames() + 1);
	this->gameRunningState = false;
	this->underLineState[0] = '_';
	this->underLineState[1] = '_';
	this->underLineState[2] = '_';
	this->underLineState[3] = '\0';

}
void states::doLooseState() {
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
int main()
{

	srand(time(NULL));
	states thisGame;
	vector<string> wordList = thisGame.fileLineExtractor("Words.txt");
	while (thisGame.getStartState() == true) {//n
		thisGame.playerHealthDificultyModifier();
		thisGame.showStartState();
		thisGame.askMenuOptionInput();
		if (thisGame.getOptionsState() == 1) {
			thisGame.setGameRunningState(true);
			thisGame.setOptionsState(-1);
		}
		else if (thisGame.getOptionsState() == 2) {
			thisGame.setStartSate(false);
			thisGame.setOptionsState(-1);
		}
		else {
			cout << "Wrong Input! Try again!\n";
		}
		thisGame.wordPicker(wordList);
		system("CLS");
		while (thisGame.getGameRunningState() == true) {//n
			thisGame.showGameRunningState();
			thisGame.showPlayerHealthState();
			thisGame.showPlayerScoreState();
			thisGame.showUnderscoreState();
			thisGame.askLetterInput();
			if (thisGame.checkIfWinState() == true) {
				thisGame.showWinState();
				thisGame.doWinState();
				system("pause");
			}
			else if (thisGame.checkIfWinState() == false && thisGame.getHealth() <= 0) {
				thisGame.showLooseState();
				thisGame.doLooseState();
				system("pause");
			}
			system("CLS");
		}
	}
}
