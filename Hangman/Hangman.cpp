#include "Hangman.h"

/*
	/////////////////CLASS INFO:
	This class is like a box, a very specific box; the first of its kind.
	Yeah, please look at it as box! And if I may, what is the purpose of a box?
	To cntain things: games, books, clothes; hey, even from sciccors to crayons, in an orderly order. Tell me, when have you seen a disorganized box?
	Well, this class does just that: To organize the code.
	But not just any code! No, no, no! The fundamental code of the our version of the game 'Hangman'! You can also call it the core!
	So, if we were to create this game... What things would be needed in order for the prototype of the game to work?
	In our case, this class deals with the word that computer will use to deal with the player, the letter which the player will play and an accountability of the games played.
	More so, lets say you would like to play again, wouldn't it be boring for the computer deal with the same word it did the first time? Well, the necessary code to
	read a list of multiple words and pick one of them at 'random'!
	Of course, these words and user typed letters will be verified! We wouldn't someone to get harmed on the process, would we?
*/

//Constructors
/*
	//////////////////Original Constructor Info:
	This method could be thougth of as, the first words a baby would say.
	Try to think of it like this, a baby is born. Would you say that, at his or her current state, the baby would have the answers of the world that we live in?
	Would this baby know how to do math, read, talk, walk or work? Hey, not even he or she would know how to play games!
	The only way this baby would learn this things, is if they were taught to he or she at first.
	This method does just that: It teaches the class the fundamental values that it must have for it to work!
*/
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
Hangman::Hangman(string word,char letter, int games) //Overload Constructor
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