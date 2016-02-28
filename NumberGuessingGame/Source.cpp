#include <iostream>

using namespace std;


	int difficulty = 100;      //to what number do you want to get to
	char input = 'n';          //default to n because the loop will always happen if the input is n
	int lowerbound = 0;       //lowest possible number left
	int upperbound = difficulty + 1; //highest possible number left
	int myGuess = 0;          //the default guess that changes but needs to be initialized to 0
	int lastGuess = -1;        //last guess can be anything but it will change to whatever myGuess is

	bool MainMenu() {         //every game needs a main menu to start
		cout << "Welcome to the Game!!" << endl << endl;
		while (true) {        //while true means that there is a statement somewhere in there
			cout << "1) Play" << endl;
			cout << "2) Exit" << endl;
			cout << ">";
			cin >> input;

			if (input == '1') return true; //this will start playing the game
			else return false; //this will end the game I didn't put 2 because any other key than one should end the game to avoid errors
		}
	}
	//This next function is to initiate the game and start telling the story, or in this case, it's the instructions

	void ShowStory() {
		input = 'n';   //using the same input global variable, but it is resetting it to n to make sure that it is not y and right on the first try
		cout << "Once upon a time..." << endl;
		cout << "You thought of a number between 0 and " << difficulty << endl; //right now, difficulty has been initialized, eventually should change to user input
		while (input != 'y') { //right now it has explicitly been changed to n in this functions start
			cout << "Have you got one (y/n)? ";
			cin >> input;
			if (input != 'y') //basically anything but y will break the loop and move on
				cout << "Okay I'll wait a bit..." << endl;
		}

		cout << endl; //pretty printing
	}
	//This function puts all variables back to defaults making it easier to restart the game without problems

	void ResetGame() {
		lowerbound = 0;
		upperbound = difficulty + 1;
		input = 'n';
	}
	
	//this function is dynamically updated to try and get closer to the number guessed
	bool UpdateWorld() {
		myGuess = (lowerbound + upperbound) / 2; //example is 1 + 11 = 12, so first guess is 6

		if (lastGuess == myGuess) {
			cout << "Cheater!!!! =(" << endl; //this would mean that all guesses would be used up because the last guess is always the previous of my guess
			//if the previous of the guess is the same as the current, it means that the number cannot be divided anymore and the number doesn't actually exist
			return false; //quitting and breaking out of the game loop
		}
		lastGuess = myGuess;
		return true; //this means that the last guess would be the before and the game would be able to continue on because it is now returned true
	}
	void DrawGraphics() { //this is just a way to interact with the player, in this case through a menu
		cout << "I think it's " << myGuess << ". Am I right?" << endl;
		cout << "l) lower" << endl;
		cout << "h) higher" << endl;
		cout << "y) YES!" << endl;
	}

	//this function follows immediately after the previous one in main so it captures an input in the keyboard, therefore making a choice even if the previous 
	//function had no actual variables or data

	void GetInput() {
		cin >> input; //capturing after the previous function told the user to press something

		//The reactions to input
		switch (input) {
		case 'l': upperbound = myGuess; break; // changes it so the highest number in the guessing list is now the last guess eliminating a bunch of unneeded
			//guesses
		case 'h': lowerbound = myGuess; break; //same as lower, but this time with cutting off the lower numbers
		case 'y': cout << "Yay!!" << endl; break; //on the mark so no changes need to be made
		default: cout << "WTf?" << endl; break;
		}
	}
	//this function is used to solve the end of the game whether the player wants to play again or not
	bool GameOver() {
		cout << endl;
		cout << "That was pretty good, play again (y/n)?" << endl;
		cin >> input;

		if (input == 'y') return true;
		else return false;
	}
	//this function is the only one in main as it is used to bring it all together and keep running on a while loop until it breaks
	bool PlayGame() {
		ShowStory(); //instructions and everything shown only used to make sure the player starts the game

		ResetGame(); //make sure all values are on default

		while (input != 'y') { //this loop will do everything it needs to in order to get to the number you are thinking of and hit y
			UpdateWorld();

			DrawGraphics();

			GetInput();
		}
		return GameOver(); //in main, when this is returned true, the game will start all over again in this loop and it will go through all the functions again
	}

	int main() {
		while (MainMenu()) { //if this is false on the function, it just immediately breaks the loop, kind of like how you would say quit on a game
			while (PlayGame()); //same concept as above except it will only break on a false at the end of the play game function
		}

		system("pause");
		return 0;
	}
