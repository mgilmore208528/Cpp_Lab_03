// Lab3_1.cpp : tic tack toe game.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
char X = 'X';
char O = 'O';
char EMPTY = ' ';
string TIE = "TIE";
int NUM_SQUARES = 9;


int _tmain(int argc, _TCHAR* argv[])
{
	char human = NULL;
	char computer = NULL;
	char turn = X;
	char board[9];
	int move = NULL;


	display_instruct();
	computer, human = pieces();
	new_board();
	display_board();

	while (!winner())
	{
		if (turn == human)
		{
			move = human_move(human);
			board[move] = human;
		}
		else
		{
			move = computer_move(board, computer, human);
			board[move] = computer;
		}
		display_board(board);
		turn = next_turn(turn);
		the_winner = winner(board);
		congrat_winner(the_winner, computer, human);
	}
		return 0;
}

void new_board(char board[])
{
	for (int i = 0; i < NUM_SQUARES; i++)
	{
		board[i] = ' ';
	
	}
}

void display_board(char board[])
{
	cout << board[0] << "|" << board[1] << '|' << board[2] << endl;
	cout << "-----";
	cout << board[3] << "|" << board[4] << '|' << board[5] << endl;
	cout << "-----";
	cout << board[6] << "|" << board[7] << '|' << board[8] << endl;
}


int human_move(char board[], char human)
{
	//Get human move.
	int move = NULL;
	while (board[move] != ' ');
	{
		move = ask_number("Where will you move? (0 - 8):", 0, NUM_SQUARES);
		if(move != ' ')
		{
		cout << "\nThat square is already occupied, foolish human.  Choose another.\n";
		}
	}
	cout << "Fine...";
	return move
}