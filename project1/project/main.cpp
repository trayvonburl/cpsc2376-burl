#include <iostream>
#include <vector>

const int gameBoardSize{ 10 };
enum class gamePieces { hiddenEmpty, revealedEmpty, hiddenMine, revealedMine };

struct gameSlot
{
	gamePieces piece{ gamePieces::hiddenEmpty };
	bool flagged{ false };
};

void displayRules();
void makeBoard(const std::vector<gameSlot>& gameBoard, bool revealMines = false);
void play(const std::vector<gameSlot>& gameBoard);


std::vector<gameSlot> boardSetup();
void changeGameState(std::vector<gameSlot>& gameBoard);
bool isGameDone(const std::vector<gameSlot>& gameBoard);

int countMines(int row, int column, const std::vector<gameSlot>& gameBoard);

int boardIndex(int row, int column);

int main()
{

	char playAgain{ 'y' };
	while (playAgain == 'y' || playAgain == 'Y')
	{
		std::vector<gameSlot>& gameBoard{ boardSetup() };
		while (!isGameDone(gameBoard))
		{
			makeBoard(gameBoard);
			play(gameBoard);
		}
		makeBoard(gameBoard);
		std::cout << "\nDo you wish to play another game? (y/n): ";
		std::cin >> playAgain;

	}
}

void displayRules()
{
    std::cout << "Welcome to the Minesweeper Game!\n";
    std::cout << "The Rules of the Game!:\n";
    std::cout << "1. Use numbers as clues to logically deduce mine locations.\n";
    std::cout << "2. Flag suspected mines and avoid clicking on them..\n";
    std::cout << "3. You will win by uncovering all non-mine squares or flagging all the mines correctly..\n";
    std::cout << "4. You will lose if you click on a square with a mine.\n";
}

void makeBoard(const std::vector<gameSlot>& gameBoard, bool revealMines)
{
	char rowName{ 'A' };
	int colName{ 1 };
	system("CLS");

	std::cout << "   ";
	for (int i{ 0 }; i < gameBoardSize; i++)
	{
		std::cout << colName << " ";
		colName++;
	}
	std::cout << std::endl;
	for (int row{ 0 }; row < gameBoardSize; row++)
	{

		std::cout << rowName << "| ";
		rowName++;
		for (int column{ 0 }; column < gameBoardSize; column++)
		{
			const gameSlot& slot = gameBoard[boardIndex(row, column)];
			if (slot.flagged)
			{
				std::cout << "f ";
			}
			else
			{
				std::cout << "r";
			}
			switch (gameBoard[boardIndex(row, column)].piece)
			{
			case gamePieces::hiddenEmpty:
				std::cout << "- ";
				break;
			case gamePieces::hiddenMine:
				if (revealMines) std::cout << "* ";
				else std::cout << "- ";
				break;
			case gamePieces::revealedMine:
				std::cout << "* ";
				break;
			case gamePieces::revealedEmpty:
			{
				int numNeighbors{ countMines(row, column, gameBoard) };

				if (numNeighbors == 0)
					std::cout << "  ";
				else
					std::cout << numNeighbors << " ";
				break;
			}

			}
		}
		std::cout << "\n";
	}
}

void play(const std::vector<gameSlot>& gameBoard)
{
	play(gameBoard, true);

	std::find_if(gameBoard.begin(), gameBoard.end(), [](const gameSlot& slot) {
		return slot.piece == gamePieces::revealedMine;

		if (slot == gamePieces::revealedMine)
		{
			std::cout << "The mine exploded!\n";
			std::cout << "Try again";
			return;
		}
	std::cout << "Great job clearing the mines!\n";
}



		int boardIndex(int row, int column)
		{
			return row * gameBoardSize + column;
		}

		void makeBoard(std::vector<gameSlot>&gameBoard)
		{

			char row{ 'Z' };
			int column{ -1 };
			int numRow{ 0 };
			do
			{
				while (row < 'A' || row > 'A' + gameBoardSize)
				{
					std::cout << "Choose a row: ";
					std::cin >> row;
				}
				numRow = row - 'A';
				while (column < 0 || column > gameBoardSize)
				{
					std::cout << "Choose a column: ";
					std::cin >> column;
					column--;
				}
			} while (gameBoard[boardIndex(numRow, column)].piece) == gamePieces::revealedEmpty);

	switch (gameBoard[boardIndex(numRow, column)].piece)
	{
	case gamePieces::hiddenEmpty:
		gameBoard[boardIndex(numRow, column)].piece) = gamePieces::revealedEmpty;
	break;
	case gamePieces::hiddenMine:
		gameBoard[boardIndex(numRow, column)].piece) = gamePieces::revealedMine;
		break;
	}
		}

		bool play(const std::vector<gameSlot>&gameBoard)
		{
			bool stillEmpty{ true };
			for (auto slot : gameBoard)
			{
				switch (slot)
				{
				case gamePieces::hiddenEmpty:
					stillEmpty = false;
					break;
				case gamePieces::revealedMine:
					return true;
					break;
				}
			}
			return stillEmpty;
		}

		int countMines(int row, int column, const std::vector<gamePieces>&gameBoard)
		{
			char action;
			std::cout << "Do you want to flag, unflag, or reveal the slot? ";
			std::cin >> action;
			{
				int mineCount{ 0 };
				for (int neighborRow{ -1 }; neighborRow <= 1; neighborRow++)
				{
					for (int neighborColumn{ -1 }; neighborColumn <= 1; neighborColumn++)
					{
						if ((neighborColumn != 0 || neighborRow != 0)
							&& row + neighborRow >= 0 && row + neighborRow < gameBoardSize
							&& column + neighborColumn >= 0 && column + neighborColumn < gameBoardSize
							&& (gameBoard[boardIndex(row + neighborRow, column + neighborColumn)] == gamePieces::hiddenMine
								|| gameBoard[boardIndex(row + neighborRow, column + neighborColumn)] == gamePieces::revealedMine))
						{
							mineCount++;
						}
					}
				}
				return mineCount;
			}