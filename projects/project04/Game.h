#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>

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
    std::vector<std::vector<Token>> board;
    Token currentPlayer;
    Status currentStatus;

    bool isValidMove(int col) const;
    bool makeMove(int col);
    Status checkGameStatus() const;

public:
    Game();
    void play(int col);
    Status status() const;
    void draw(SDL_Renderer* renderer) const;
    void reset();
    Token getCurrentPlayer() const;
};

#endif