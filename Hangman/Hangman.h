#ifndef Hangman_H
#define Hangman_H
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

/*	Lists of things to do:
	1. Constructor, Copy Constructor, Overload Constructor
	2. Destructor
	3. Setters
	4. Getters
	5. File Reader
	6. Line Grabber
	7. Letter Compare
	8. Player (Life, Powers, ...)
	9. Line Saver

*/
class Hangman
{
	private:
		//Aesthetics
		string word;
		char letter;

		//Dificulty
		int games;
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
	private:
		//Super Secret Methods
		static const bool wordSizeValidator(string); //Verifies the size of chosen word
};
#endif 

