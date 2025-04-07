#include <iostream>
#include "game.h"

int main() 
{
    Game game;  // Constructs new game

    while (game.status() == ONGOING) 
    {
        std::cout << game;  // Prints board
        int col;
        std::cout << "Player " << (game.status() == PLAYER_1_WINS ? "1 (X)" : "2 (O)") << "'s turn\n";
        std::cout << "Enter a column (0-6): ";
        std::cin >> col;

        game.play(col);  // Makes a move

        // Checks for game status
        if (game.status() == PLAYER_1_WINS) 
        {
            std::cout << game;
            std::cout << "Player 1 (X) wins!" << std::endl;
        }
        else if (game.status() == PLAYER_2_WINS) 
        {
            std::cout << game;
            std::cout << "Player 2 (O) wins!" << std::endl;
        }
        else if (game.status() == DRAW) 
        {
            std::cout << game;
            std::cout << "Draw!" << std::endl;
        }
    }

    return 0;
}