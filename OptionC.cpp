#include "header.h"

void OptionC(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop) {
	char token;
	char whoWon;
	int index = 0;
	int randomNum = rand() % 10 + 1;
	int computer;
	computer = 0;
    string response;
	if (randomNum % 2 == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	if (option == 'c' || option == 'C') {
		if (playerX == "" || playerO == "") {
			GetPlayers(playerX, playerO, computer);
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
        cout << endl << "Would you like to play again? (Yes/No) : ";
        cin >> response;
        if (response == "yes" || response == "Yes") {
            stop = true;
        } else if(response == "no" || response == "No"){
            stop = false;
        }
		system("pause");
        system("cls");
	}	
}