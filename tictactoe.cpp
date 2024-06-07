#include <bits/stdc++.h>
using namespace std;
void printBoard(char board[3][3]) 
{
    cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
}
bool checkWin(char board[3][3], char player) 
{
    // Check basic row column win condition
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals win condition
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(char board[3][3])
 {
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}
//switching of players
void switchPlayer(char &player)
{
    player = (player == 'X') ? 'O' : 'X';
}
int main() 
{
    while (true) {
        // make the board ready
        char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        char currentPlayer = 'X';
        char winner = ' ';
        while (true) 
        {
            printBoard(board);
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1, 2, 3) or enter -1 to quit: ";
            //Players can enter -1 at any time during their turn to exit the game immediately
            cin >> row;
            if (row == -1) 
            {
                cout << "Game exited by player " << currentPlayer << "\n";
                return 0;
            }
            cin >> col;
            if (col == -1) 
            {
                cout << "Game exited by player " << currentPlayer << "\n";
                return 0;
            }
            // IF USER GIVES WRONG INPUT SHOW INVALID
            if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') 
            {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid move. Try again.\n";
                continue;
            }
            board[row-1][col-1] = currentPlayer;
            if (checkWin(board, currentPlayer)) 
            {
                winner = currentPlayer;
                break;
            }
            if (checkDraw(board)) 
            {
                break;
            }
            switchPlayer(currentPlayer);
        }
        printBoard(board);
        if (winner != ' ') 
        {
            cout << "Player " << winner << " wins!\n";
        } 
        else 
        {
            cout << "It's a draw!\n";
        }
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y') 
        {
            break;
        }
    }
    return 0;
}
