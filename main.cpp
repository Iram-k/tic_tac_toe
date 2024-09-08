#include <iostream>
#include <limits.h>

using namespace std;

char board[3][3];  // Tic-Tac-Toe board

// Function to print the Tic-Tac-Toe board
void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
}

// Function to map user input (1-9) to board coordinates
pair<int, int> getCoordinates(int move) {
    return {(move - 1) / 3, (move - 1) % 3};
}

// Function to check if there are any empty cells on the board
bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

// Function to evaluate the current board state
int evaluate() {
    // Checking for Rows for X or O victory
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'O')
                return +10;
            else if (board[row][0] == 'X')
                return -10;
        }
    }

    // Checking for Columns for X or O victory
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'O')
                return +10;
            else if (board[0][col] == 'X')
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O')
            return +10;
        else if (board[0][0] == 'X')
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'O')
            return +10;
        else if (board[0][2] == 'X')
            return -10;
    }

    // Else if none have won then return 0
    return 0;
}

// Minimax function to find the best move
int minimax(int depth, bool isMax) {
    int score = evaluate();

    // If Maximizer has won the game, return score
    if (score == 10)
        return score - depth;

    // If Minimizer has won the game, return score
    if (score == -10)
        return score + depth;

    // If there are no more moves and no winner, it's a tie
    if (!isMovesLeft())
        return 0;

    // If this is the maximizer's move
    if (isMax) {
        int best = INT_MIN;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check if cell is empty
                if (board[i][j] == ' ') {
                    // Make the move
                    board[i][j] = 'O';

                    // Call minimax recursively and choose the maximum value
                    best = max(best, minimax(depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }

    // If this is the minimizer's move
    else {
        int best = INT_MAX;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check if cell is empty
                if (board[i][j] == ' ') {
                    // Make the move
                    board[i][j] = 'X';

                    // Call minimax recursively and choose the minimum value
                    best = min(best, minimax(depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

// Function to find the best possible move for the computer
pair<int, int> findBestMove() {
    int bestVal = INT_MIN;
    pair<int, int> bestMove = {-1, -1};

    // Traverse all cells, evaluate minimax function for all empty cells, and return the cell with optimal value
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Check if cell is empty
            if (board[i][j] == ' ') {
                // Make the move
                board[i][j] = 'O';

                // Compute evaluation function for this move
                int moveVal = minimax(0, false);

                // Undo the move
                board[i][j] = ' ';

                // If the value of the current move is more than the best value, update best
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// Function to check for a winner
char checkWinner() {
    int score = evaluate();
    if (score == 10)
        return 'O';
    else if (score == -10)
        return 'X';
    return ' ';
}

// Main function to play the game
void playGame() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';  // Initialize the board with empty spaces

    bool humanTurn = true;
    char winner = ' ';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    printBoard();

    while (isMovesLeft() && winner == ' ') {
        if (humanTurn) {
            int move;
            cout << "Your turn (X). Enter a number between 1 and 9: ";
            cin >> move;
            pair<int, int> coords = getCoordinates(move);
            if (board[coords.first][coords.second] == ' ') {
                board[coords.first][coords.second] = 'X';
                humanTurn = false;
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        } else {
            cout << "Computer's turn (O)..." << endl;
            pair<int, int> bestMove = findBestMove();
            board[bestMove.first][bestMove.second] = 'O';
            humanTurn = true;
        }

        printBoard();
        winner = checkWinner();
    }

    if (winner != ' ')
        cout << winner << " wins!" << endl;
    else
        cout << "It's a tie!" << endl;
}

int main() {
    playGame();
    return 0;
}
