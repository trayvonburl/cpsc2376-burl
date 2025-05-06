#include "game.h"
#include <algorithm>

const int ROWS = 6;
const int COLS = 7;

Game::Game() 
{
    board = std::vector<std::vector<Token>>(ROWS, std::vector<Token>(COLS, EMPTY));
    currentPlayer = PLAYER_1;
    currentStatus = ONGOING;
}

bool Game::isValidMove(int col) const 
{
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

bool Game::makeMove(int col) 
{
    if (!isValidMove(col)) return false;

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

void Game::play(int col) 
{
    if (currentStatus != ONGOING) return;
    if (makeMove(col)) 
    {
        currentStatus = checkGameStatus();
        if (currentStatus == ONGOING) {
            currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        }
    }
}

Status Game::checkGameStatus() const 
{
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            Token token = board[row][col];
            if (token == EMPTY) continue;

            // Horizontal
            if (col + 3 < COLS &&
                token == board[row][col + 1] &&
                token == board[row][col + 2] &&
                token == board[row][col + 3])
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;

            // Vertical
            if (row + 3 < ROWS &&
                token == board[row + 1][col] &&
                token == board[row + 2][col] &&
                token == board[row + 3][col])
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;

            // Diagonal down-right
            if (row + 3 < ROWS && col + 3 < COLS &&
                token == board[row + 1][col + 1] &&
                token == board[row + 2][col + 2] &&
                token == board[row + 3][col + 3])
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;

            // Diagonal up-right
            if (row - 3 >= 0 && col + 3 < COLS &&
                token == board[row - 1][col + 1] &&
                token == board[row - 2][col + 2] &&
                token == board[row - 3][col + 3])
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }

    for (int col = 0; col < COLS; ++col)
    {
        if (board[0][col] == EMPTY)
            return ONGOING;
    }

    return DRAW;
}

Status Game::status() const 
{
    return currentStatus;
}

Token Game::getCurrentPlayer() const 
{
    return currentPlayer;
}

void Game::reset() 
{
    for (auto& row : board) 
    {
        std::fill(row.begin(), row.end(), EMPTY);
    }
    currentPlayer = PLAYER_1;
    currentStatus = ONGOING;
}

void Game::draw(SDL_Renderer* renderer) const 
{
    const int CELL_SIZE = 100;
    const int MARGIN = 5;

    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            SDL_Rect rect = { col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE };
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &rect);

            Token token = board[row][col];
            if (token != EMPTY) {
                SDL_SetRenderDrawColor(renderer,
                    token == PLAYER_1 ? 255 : 255,
                    token == PLAYER_1 ? 0 : 255,
                    0, 255);
                SDL_Rect piece = { col * CELL_SIZE + MARGIN, row * CELL_SIZE + MARGIN,
                                   CELL_SIZE - 2 * MARGIN, CELL_SIZE - 2 * MARGIN };
                SDL_RenderFillRect(renderer, &piece);
            }
        }
    }
}