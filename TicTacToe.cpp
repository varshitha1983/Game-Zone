#include <iostream>
#include <vector>
#include <iostream>
#include <vector>

// Function to display the Tic Tac Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool checkFull(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There's an empty cell, the board is not full
            }
        }
    }
    return true; // All cells are filled, the board is full
}

// Function to make a player's move
void makeMove(std::vector<std::vector<char>>& board, int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        std::cout << "Invalid move. Try again.\n";
    }
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

    char currentPlayer = 'X';

    while (true) {
        // Display the board
        displayBoard(board);

        // Get player move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Make the move
        makeMove(board, row, col, currentPlayer);

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a draw
        if (checkFull(board)) {
            displayBoard(board);
            std::cout << "The game is a draw!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}


