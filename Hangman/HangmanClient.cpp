#include <string.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include "states.h"
//Ive been fucking days. I'm just cracking up.

using namespace std;

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
			else if(thisGame.checkIfWinState() == false && thisGame.getHealth() <= 0) {
				thisGame.showLooseState();
				thisGame.doLooseState();
				system("pause");
			}
			system("CLS");
		}
	}
	return 0;
}
