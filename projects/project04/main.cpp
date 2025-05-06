#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "game.h"
#include <iostream>

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 600;
const int COLS = 7;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Connect 4 Game!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (!window)
    {
        std::cerr << "Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Game game;
    int selectedCol = 0;
    bool running = true;
    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN)
            {
                SDL_Keycode key = e.key.keysym.sym;

                if (key == SDLK_ESCAPE)
                    running = false;
                else if (key == SDLK_r)
                    game.reset();
                else if (key == SDLK_LEFT && selectedCol > 0)
                    --selectedCol;
                else if (key == SDLK_RIGHT && selectedCol < COLS - 1)
                    ++selectedCol;
                else if ((key == SDLK_RETURN || key == SDLK_SPACE) && game.status() == ONGOING)
                    game.play(selectedCol);
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && game.status() == ONGOING)
            {
                int mouseX = e.button.x;
                int col = mouseX / (SCREEN_WIDTH / COLS);
                game.play(col);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        game.draw(renderer);

        // Highlight selected column
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect highlight = { selectedCol * 100, 0, 100, SCREEN_HEIGHT };
        SDL_RenderDrawRect(renderer, &highlight);


        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}