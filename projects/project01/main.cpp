#include <iostream>
#include <vector>
#include <limits>

using namespace std;


enum class GameState 
{
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

enum class Token 
{
    EMPTY = ' ',
    PLAYER_1 = 'X',
    PLAYER_2 = 'O'
};

const int ROWS = 6;
const int COLS = 7;


vector<vector<Token>> makeBoard() 
{
    return vector<vector<Token>>(ROWS, vector<Token>(COLS, Token::EMPTY));
}

void printBoard(const vector<vector<Token>>& board) 
{
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            cout << static_cast<char>(board[row][col]) << " ";
        }
        cout << endl;
    }
}


bool isValidMove(const vector<vector<Token>>& board, int col) 
{
    return board[0][col] == Token::EMPTY;
}

bool makeMove(vector<vector<Token>>& board, int col, Token token) 
{
    if (col < 0 || col >= COLS || !isValidMove(board, col)) 
    {
        return false;
    }


    for (int row = ROWS - 1; row >= 0; --row) 
    {
        if (board[row][col] == Token::EMPTY) 
        {
            board[row][col] = token;
            return true;
        }
    }

    return false;
}

GameState gameStatus(const vector<vector<Token>>& board) 
{
    
    for (int row = 0; row < ROWS; ++row) 
    {
        for (int col = 0; col < COLS; ++col) 
        {
            if (board[row][col] != Token::EMPTY) 
            {
                Token currentToken = board[row][col];

                
                if (col + 3 < COLS &&
                    board[row][col] == board[row][col + 1] &&
                    board[row][col] == board[row][col + 2] &&
                    board[row][col] == board[row][col + 3]) 
                {
                    return (currentToken == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }

                
                if (row + 3 < ROWS &&
                    board[row][col] == board[row + 1][col] &&
                    board[row][col] == board[row + 2][col] &&
                    board[row][col] == board[row + 3][col]) 
                {
                    return (currentToken == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }

               
                if (row + 3 < ROWS && col + 3 < COLS &&
                    board[row][col] == board[row + 1][col + 1] &&
                    board[row][col] == board[row + 2][col + 2] &&
                    board[row][col] == board[row + 3][col + 3]) 
                {
                    return (currentToken == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }

                
                if (row - 3 >= 0 && col + 3 < COLS &&
                    board[row][col] == board[row - 1][col + 1] &&
                    board[row][col] == board[row - 2][col + 2] &&
                    board[row][col] == board[row - 3][col + 3]) 
                {
                    return (currentToken == Token::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
                }
            }
        }
    }

   
    for (int col = 0; col < COLS; ++col) 
    {
        if (board[0][col] == Token::EMPTY) 
        {
            return GameState::ONGOING; 
        }
    }

    return GameState::DRAW;
}


void printRules() 
{
    cout << "Welcome to Trayvon's Connect Four!" << endl;
    cout << "Players take turns dropping a disc into one of the seven columns." << endl;
    cout << "The first player to connect four in a row wins." << endl;
    cout << "Enter a number between 0 and 6." << endl;
}

void playTurn(vector<vector<Token>>& board, Token token) 
{
    int col;
    bool validMove = false;

    while (!validMove) 
    {
        cout << "Enter a column (0-6): ";
        cin >> col;

        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Enter a number between 0 and 6." << endl;
        }
        else if (col < 0 || col >= COLS) 
        {
            cout << "Choose a column between 0 and 6." << endl;
        }
        else if (!makeMove(board, col, token)) 
        {
            cout << "Choose another column." << endl;
        }
        else 
        {
            validMove = true;
        }
    }
}

bool playAgain() 
{
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() 
{
    printRules();

    while (true) 
    {
        vector<vector<Token>> board = makeBoard();
        GameState gameState = GameState::ONGOING;
        Token currentPlayer = Token::PLAYER_1;

        while (gameState == GameState::ONGOING) 
        {
            printBoard(board);
            cout << (currentPlayer == Token::PLAYER_1 ? "Player 1 (X)'s turn" : "Player 2 (O)'s turn") << endl;
            playTurn(board, currentPlayer);
            gameState = gameStatus(board);

            if (gameState == GameState::PLAYER_1_WINS) 
            {
                printBoard(board);
                cout << "Player 1 (X) wins!" << endl;
            }
            else if (gameState == GameState::PLAYER_2_WINS) 
            {
                printBoard(board);
                cout << "Player 2 (O) wins!" << endl;
            }
            else if (gameState == GameState::DRAW) 
            {
                printBoard(board);
                cout << "Draw!" << endl;
            }

            currentPlayer = (currentPlayer == Token::PLAYER_1) ? Token::PLAYER_2 : Token::PLAYER_1;
        }

        if (!playAgain()) 
        {
            cout << "Thanks for playing, Play again!" << endl;
            break;
        }
    }

    return 0;
}
