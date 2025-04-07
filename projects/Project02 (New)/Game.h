#pragma once

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

enum Status
{
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

enum Token
{
    EMPTY = ' ',
    PLAYER_1 = 'X',
    PLAYER_2 = 'O'
};

class Game
{
private:
    std::vector<std::vector<Token>> board;  // Vector representing the game board
    Token currentPlayer;                    // Current player's token
    Status currentStatus;                   // Current game status

    bool isValidMove(int col) const;        // Check if move is valid
    bool makeMove(int col);                 // Makes move for the current player
    Status checkGameStatus() const;         // Checks current game status

public:
    Game();  // Constructor
    void play(int col);  // Executes move for current player
    Status status() const;  // Returns current status
    void display() const;  // Displays game board

    // To print the game board
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif