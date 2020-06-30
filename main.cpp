#include "header.h"

int main() {

    int pointsForX, pointsForO;

	// Initializes the board
	char boardArray[][3] = { {}, {}, {} };
	// Initializes the option
	char option;
	// Initializes the name for playerX
	string playerX = "";
	// Initializes the name for playerO
	string playerO = "";
	// Displays the class header
	//  DisplayHeader();
	// Outputs the instructions
	OutputInstruct();
	// Fills the board with ' '
	InitBoard(boardArray);
	//Gets the player's option
	option = MainMenu(option, playerX, playerO);
	// Ends the game if they want to exit
	if (option == 'a' || option == 'A') {
		system("pause");
		return 0;
	} else {
		// Starts the game if they want to play
        //while (running) {
	    RunGame(boardArray, option, playerX, playerO, pointsForX, pointsForO);
      //  }
	
	}
} // End of main

// Start of RunGame
void RunGame(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO) {
	char token;
	char whoWon;
	int index = 0;
	int randomNum = rand() % 10 + 1;
	system("cls");
	if (randomNum % 2 == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	if (option == 'c' || option == 'C') {
		if (playerX == "" || playerO == "") {
			GetPlayers(playerX, playerO);
		}
		//InitBoard(boardArray);
		bool run = true;
		for (int i = 0; i < 16; i++) {
			DisplayBoard(boardArray);
			GetAndCheckInp(boardArray, token, playerX, playerO);
			index++;
			token = SwitchToken(token);
			if (CheckWin(boardArray) == 'X' || CheckWin(boardArray) == 'O') {
				whoWon = CheckWin(boardArray);
				i = 16;
			}
			system("cls");
		}
		CheckWin(boardArray);
		DisplayBoard(boardArray);
		OutputWinner(whoWon, playerX, playerO);
        if(whoWon == 'X') {
            pointsForX += 5;
            cout << endl << playerX << "\'s points : " << pointsForX << endl;
        } else if(whoWon == 'O'){
            pointsForO += 5;
            cout << endl <<  playerO << "\'s points : " << pointsForO << endl;
        }
      
		system("pause");
	}	else if (option == 'd' || option == 'D') {
		if (playerX == "" || playerO == "") {
			GetPlayers(playerX, playerO);
		}
		//InitBoard(boardArray);
		bool run = true;
		for (int i = 0; i < 16; i++) {
			DisplayBoard(boardArray);
			GetAndCheckInpComputer(boardArray, token, playerX, playerO);
			index++;
			token = SwitchToken(token);
			if (CheckWin(boardArray) == 'X' || CheckWin(boardArray) == 'O') {
				whoWon = CheckWin(boardArray);
				i = 16;
			}
			system("cls");
		}
		CheckWin(boardArray);
		DisplayBoard(boardArray);
		OutputWinner(whoWon, playerX, playerO);
         if(whoWon == 'X') {
            pointsForX += 5;
        } else if(whoWon == 'O'){
            pointsForO += 5;
        }
		system("pause");
	}
} // End of RunGame