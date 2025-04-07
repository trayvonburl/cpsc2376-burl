#include "Game.h"
#include <iostream>

// Board size
const int ROWS = 6;
const int COLS = 7;

Game::Game() 
{
    board = std::vector<std::vector<Token>>(ROWS, std::vector<Token>(COLS, EMPTY));
    currentPlayer = PLAYER_1; //Player 1 starts game
    currentStatus = ONGOING;   // Initial game state is ongoing
}

// Checks if the column has a valid move
bool Game::isValidMove(int col) const 
{
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

// Move for the current player
bool Game::makeMove(int col) 
{
    if (!isValidMove(col)) 
    {
        return false;  // Invalid move if the column is full or off grid
    }

    // Places the token in the lowest row of the column that is empty
    for (int row = ROWS - 1; row >= 0; --row) 
    {
        if (board[row][col] == EMPTY)
        {
            board[row][col] = currentPlayer;
            return true;
        }
    }
    return false;
}


Status Game::checkGameStatus() const 
{
    // Check for win
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            if (board[row][col] != EMPTY) 
            {
                Token currentToken = board[row][col];

                // Horizontal 
                if (col + 3 < COLS &&
                    board[row][col] == board[row][col + 1] &&
                    board[row][col] == board[row][col + 2] &&
                    board[row][col] == board[row][col + 3]) 
                {
                    return (currentToken == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
                }

                // Vertical 
                if (row + 3 < ROWS &&
                    board[row][col] == board[row + 1][col] &&
                    board[row][col] == board[row + 2][col] &&
                    board[row][col] == board[row + 3][col]) 
                {
                    return (currentToken == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
                }

                // Diagonal 
                if (row + 3 < ROWS && col + 3 < COLS &&
                    board[row][col] == board[row + 1][col + 1] &&
                    board[row][col] == board[row + 2][col + 2] &&
                    board[row][col] == board[row + 3][col + 3]) 
                {
                    return (currentToken == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
                }

                // Diagonal
                if (row - 3 >= 0 && col + 3 < COLS &&
                    board[row][col] == board[row - 1][col + 1] &&
                    board[row][col] == board[row - 2][col + 2] &&
                    board[row][col] == board[row - 3][col + 3]) 
                {
                    return (currentToken == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
                }
            }
        }
    }

    // Checks for empty spaces
    for (int col = 0; col < COLS; ++col) 
    {
        if (board[0][col] == EMPTY) 
        {
            return ONGOING;
        }
    }

    return DRAW;
}

// Updates the game after a player's move
void Game::play(int col) 
{
    if (makeMove(col)) 
    {
        currentStatus = checkGameStatus();
        // Switch player if the game is still ongoing
        if (currentStatus == ONGOING) 
        {
            currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        }
    }
}

// Current game status
Status Game::status() const 
{
    return currentStatus;
}

// Displays the game board
void Game::display() const 
{
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            std::cout << static_cast<char>(board[row][col]) << " ";
        }
        std::cout << std::endl;
    }
}

// << operator to print the board
std::ostream& operator<<(std::ostream& os, const Game& game) 
{
    game.display();
    return os;
}
