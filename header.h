#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;


void DisplayHeader();
void OutputInstruct(); 
char MainMenu(char& option, string& playerX, string& playerO);
void InitBoard(char boardAr[][3]); // OUT - tic tac toe board
void DisplayBoard(const char boardAr[][3]); // IN - tic tac toe board
void GetPlayers(string& playerX, string& playerO, int option);
void RunGame(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop);
void GetAndCheckInp(char boardArr[][3], char token, string playerX, string playerO);
void GetAndCheckInpComputer(char boardArr[][3], char token, string playerX, string playerO);
char SwitchToken(char token); // IN - current player�s token ('X' or 'O')
char CheckWin(const char boardAr[][3]); // IN - tic tac toe board
void OutputWinner(char whoWon, string playerX, string playerO); 
void OptionC(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop);
void OptionD(char boardArray[][3], char option, string& playerX, string& playerO, int& pointsForX, int& pointsForO, bool& stop);

void OutputInstruct() {
	cout << "Hello and welcome to Tic-Tac-Toe!\n\n";
	Sleep(900);
} // End of OutputInstruct

// Start of MainMenu
char MainMenu(char& option, string& playerX, string& playerO) {
	int runOnce = 0;
	bool menu = true;
	int computer;
	computer = 0;
	while (menu) {
		if (runOnce == 0) {
			cout << "\t[ MAIN MENU: ]\n\n" << "A) Exit\n\nB) Set Player Names\n\nC) Play in Two Player Mode\n\n"
				<< "D) Play in One Player Mode\n\nEnter an option: ";
			cin >> option;
		} else {
			cout << "\t[ MAIN MENU: ]\n\n" << "A) Exit\n\nB) Change Player Names\n\nC) Play in Two Player Mode\n\n"
				<< "D) Play in One Player Mode\n\nEnter an option: ";
			cin >> option;
		}
		if (option == 'a' || option == 'A') {
			system("cls");
			cout << "Thank you for using my program.\n\n";
			return option;
			menu = false;
		}
		else if (option == 'b' || option == 'B') {
			GetPlayers(playerX, playerO, computer);
			runOnce++;
		}
		else if (option == 'c' || option == 'C') {
			return option;
			menu = false;
		}
		else if (option == 'd' || option == 'D') {
			return option;
			menu = false;
		}
	}
}  //End of MainMenu

// Start of GetPlayers
void GetPlayers(string& playerX, string& playerO, int option) {
	if (option == 0) {
	system("cls");
	cout << "Enter the name for player X : ";
	cin >> playerX;
	cout << endl;
	cout << "Enter the name for player O : ";
	cin >> playerO;
	cout << endl << endl;
	} else if (option == 1) {
	system("cls");
	cout << "Enter the name for player X : ";
	cin >> playerX;
	cout << endl;
	}
	

} // End of GetPlayers

// Start of InitBoard
void InitBoard(char boardArr[][3]) {
	for (int i = 0; i <= 2; i++) {
		for (int x = 0; x <= 2; x++) {
			boardArr[i][x] = ' ';
		}
	}
} // End of InitBoard

// Start of GetAndCheckInp
void GetAndCheckInp(char boardArr[][3], char token, string playerX, string playerO) {
	int x, y;
	if (token == 'X') {
		cout << playerX << "'s turn! What's your play?: ";
		cin >> x >> y;
		x -= 1;
		y -= 1;
		cout << "X: " << x << " Y: " << y << endl << endl;
		boardArr[x][y] = 'X';
	}	else if (token == 'O') {
		cout << playerO << "'s turn! What's your play?: ";
		cin >> x >> y;
		x -= 1;
		y -= 1;
		cout << "X: " << x << " Y: " << y << endl << endl;
		boardArr[x][y] = 'O';
	}
} // End of GetAndCheckInp

// Start of GetAndCheckInpComputer
void GetAndCheckInpComputer(char boardArr[][3], char token, string playerX, string playerO) {
	int x, y;
	bool empty = true;
	if (token == 'X') {
		cout << playerX << "'s turn! What's your play?: ";
		cin >> x >> y;
		x -= 1;
		y -= 1;
		boardArr[x][y] = 'X';
	} else if (token == 'O') {
		cout << playerO << " is thinking...";
		while (empty) {
			Sleep(1500);

		/* 	for(int x = 0; x < 3; x ++) {
				for(int y = 0; y < 3; y++) {
					for(int z = 0; z < 3; z++) {
						if(boardArr[x][y] == 'X' && boardArr[x+1][y+1] == 'X' && boardArr[x+2][x+2] == ' ') {
							boardArr[x+2][x+2] = 'O';
							empty = false;
						}
					}
				}
			}
 */

		// Checking horizontally
		if (boardArr[0][0] == 'X' && boardArr[0][1] == 'X' && boardArr[0][2] == ' ') {
			boardArr[0][2] = 'O';
			empty = false;
		} else if (boardArr[1][0] == 'X' && boardArr[1][1] == 'X' && boardArr[1][2] == ' ') {
			boardArr[1][2] = 'O';
			empty = false;
		} else if (boardArr[2][0] == 'X' && boardArr[2][1] == 'X' && boardArr[2][2] == ' ') {
			boardArr[2][2] = 'O';
			empty = false;
		} 
		// Checking Vertically 
		else if (boardArr[0][0] == 'X' && boardArr[1][0] == 'X' && boardArr[2][0] == ' ') {
		//return 'X';
			boardArr[2][0] = 'O';
			empty = false;
		}
		else if (boardArr[0][1] == 'X' && boardArr[1][1] == 'X' && boardArr[2][1] == ' ') {
		//return 'X';
			boardArr[2][1] = 'O';
			empty = false;
		}
		else if (boardArr[0][2] == 'X' && boardArr[1][2] == 'X' && boardArr[2][2] == ' ') {
		//return 'X';
			boardArr[2][2] == 'O';
			empty = false;
		} else if (boardArr[0][0] == 'X' && boardArr[1][1] == 'X' && boardArr[2][2] == ' ') {
				boardArr[2][2] = 'O';
			} else if (boardArr[0][2] == 'X' && boardArr[1][1] == 'X' && boardArr[2][0] == ' ') {
				boardArr[2][0] = 'O';
			}else {
			x = rand() % 3;
			y = rand() % 3;
			if (boardArr[x][y] == ' ') {
				boardArr[x][y] = 'O';
				empty = false;
				} else {
					empty = true;
				}
			}
		}	
	}
} // End of GetAndCheckInpComputer

// Start of SwitchToken
char SwitchToken(char token) {
	if (token == 'X') {
		token = 'O';
		return 'O';
	} else {
		token = 'X';
		return 'X';
	}
} // End of SwitchToken

// Start of CheckWin
char CheckWin(char boardArr[][3]) {

	// CHECKING FOR X
	// HORIZONTAL CHECKS :
	if (boardArr[0][0] == 'X' && boardArr[0][1] == 'X' && boardArr[0][2] == 'X') {
		return 'X';
	}
	else if (boardArr[1][0] == 'X' && boardArr[1][1] == 'X' && boardArr[1][2] == 'X') {
		return 'X';
	}
	else if (boardArr[2][0] == 'X' && boardArr[2][1] == 'X' && boardArr[2][2] == 'X') {
		return 'X';
	}

	// VERTICAL CHECKS :
	else if (boardArr[0][0] == 'X' && boardArr[1][0] == 'X' && boardArr[2][0] == 'X') {
		return 'X';
	}
	else if (boardArr[0][1] == 'X' && boardArr[1][1] == 'X' && boardArr[2][1] == 'X') {
		return 'X';
	}
	else if (boardArr[0][2] == 'X' && boardArr[1][2] == 'X' && boardArr[2][2] == 'X') {
		return 'X';
	}

	// DIAGONAL CHECKS :
	else if (boardArr[0][0] == 'X' && boardArr[1][1] == 'X' && boardArr[2][2] == 'X') {
		return 'X';
	}
	else if (boardArr[0][2] == 'X' && boardArr[1][1] == 'X' && boardArr[2][0] == 'X') {
		return 'X';
	}

	// CHECKING FOR O
	// HORIZONTAL CHECKS :
	else if (boardArr[0][0] == 'O' && boardArr[0][1] == 'O' && boardArr[0][2] == 'O') {
		return 'O';
	}
	else if (boardArr[1][0] == 'O' && boardArr[1][1] == 'O' && boardArr[1][2] == 'O') {
		return 'O';
	}
	else if (boardArr[2][0] == 'O' && boardArr[2][1] == 'O' && boardArr[2][2] == 'O') {
		return 'O';
	}

	// VERTICAL CHECKS :
	else if (boardArr[0][0] == 'O' && boardArr[1][0] == 'O' && boardArr[2][0] == 'O') {
		return 'O';
	}
	else if (boardArr[0][1] == 'O' && boardArr[1][1] == 'O' && boardArr[2][1] == 'O') {
		return 'O';
	}
	else if (boardArr[0][2] == 'O' && boardArr[1][2] == 'O' && boardArr[2][2] == 'O') {
		return 'O';
	}

	// DIAGONAL CHECKS :
	else if (boardArr[0][0] == 'O' && boardArr[1][1] == 'O' && boardArr[2][2] == 'O') {
		return 'O';
	}
	else if (boardArr[0][2] == 'O' && boardArr[1][1] == 'O' && boardArr[2][0] == 'O') {
		return 'O';
	} 

	// If the board is full, then it will return 't' for tie
	else {
		return 't';
	}
}  // End of CheckWin

// Start of OutputWinner
void OutputWinner(char whoWon, string playerX, string playerO) {
	if (whoWon == 'x' || whoWon == 'X') {
		cout << playerX << " has won the game! Congratulations!\n\n";
	}
	else if (whoWon == 'o' || whoWon == 'O') {
		cout << playerO << " has won the game! Congratulations!\n\n";
	}
	else if (whoWon == 't' || whoWon == 'T') {
		cout << "This is a tie game!\n\n";
	}
}

// Start of DisplayBoard
void DisplayBoard(const char boardAr[][3])
{
	// Variable initialized
	int row; 
	// Variable initialized
	int column;
	// Outputs the top bar
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n\n"; 
	// Start of for loop that will display the board
	for (row = 0; row < 3; row++)
	{
		// This will display each row
		cout << setw(7) << "[" << row + 1 << "][1] | " << "[" << row + 1;
		// This will display each row
		cout << "][2] | " << "[" << row + 1 << "][3]" << endl;
		// This will display each row
		cout << setw(14) << "|" << setw(9) << "|" << endl;
		// This will display each column
		for (column = 0; column < 3; column++)
		{
			// This will be display at the left of everything
			switch (column)
			{
				// This will display the right of the left column
			case 0: cout << row + 1 << setw(9) << boardAr[row][column];
				// This will seperate X and O
				cout << setw(4) << "|";
				break;
				// This will display on the right of the middle column
			case 1: cout << setw(4) << boardAr[row][column];
				// This will seperate X and O
				cout << setw(5) << "|";
				break;
				// This will show up on the left side of the board
			case 2: cout << setw(4) << boardAr[row][column] << endl;
				break;
				// If something failes, it will output an error message
			default: cout << "ERROR!\n\n";
			}
		}
		// Will display the pipes at the end of each column
		cout << setw(14) << "|" << setw(10) << "|\n";
		// An if statement that only runs two times
		if (row != 2)
		{
			// Splits the board twice
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
} // End of DisplayBoard