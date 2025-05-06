# Project 04 – Connect 4

## 🕹️ Description

This is a turn-based grid game written in C++ using SDL2. Two players take turns placing colored tokens into a 7x6 grid. The first to align four tokens in a row horizontally, vertically, or diagonally wins. If the board fills up without a winner, the game ends in a draw.

All game logic is fully encapsulated in the `Game` class, which includes methods like `play()`, `status()`, and `draw(SDL_Renderer*)`. Input and SDL2 rendering are handled separately in `main.cpp` to keep logic and UI cleanly separated.

## 🎮 Controls

- **← / →**: Move the column selector
- **Enter / Space**: Drop a token in the selected column
- **Mouse click**: Drop a token into the clicked column
- **Press `R`**: Restart the game
- **Press `Esc`**: Exit the game

## 🧪 Screenshot

![Screenshot](![Screenshot 2025-05-05 223945])
## ✨ Extra Features

- Keyboard and mouse input support
- Visual highlight of the selected column
- Game can be restarted mid-session with `R`
- Clean 60 FPS SDL2 rendering
- Object-oriented logic using `std::vector`
- `Game` class includes:
  - `play(int col)`
  - `status() const`
  - `draw(SDL_Renderer*) const`
  - `reset()`
  - Enum-based state tracking (`Status`, `Token`)

---
