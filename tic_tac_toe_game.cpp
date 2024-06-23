#include <iostream>  // Include the standard input-output stream library
using namespace std; // Use the standard namespace

// Function prototypes
void displayBoard(char board[3][3]);                   // Function to display the game board
void playerMove(char board[3][3], char currentPlayer); // Function to handle player moves
bool checkWin(char board[3][3], char currentPlayer);   // Function to check if the current player has won
bool checkDraw(char board[3][3]);                      // Function to check if the game is a draw
void switchPlayer(char &currentPlayer);                // Function to switch turns between players

int main()
{
    // Initialize the game board with numbers 1-9
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X'; // Set the starting player to 'X'
    bool gameWon = false;     // Boolean flag to indicate if the game has been won
    bool gameDraw = false;    // Boolean flag to indicate if the game is a draw
    char playAgain;           // Variable to store the player's response to play again

    do // Outer loop to handle the play-again functionality
    {
        while (!gameWon && !gameDraw) // Inner loop to handle a single game session
        {
            displayBoard(board);                      // Display the current state of the board
            playerMove(board, currentPlayer);         // Prompt the current player to make a move
            gameWon = checkWin(board, currentPlayer); // Check if the current player has won
            gameDraw = checkDraw(board);              // Check if the game is a draw

            if (!gameWon && !gameDraw) // If the game is neither won nor drawn, switch players
            {
                switchPlayer(currentPlayer);
            }
        }

        displayBoard(board); // Display the final state of the board

        if (gameWon) // If the game has been won, announce the winner
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
        }
        else if (gameDraw) // If the game is a draw, announce the draw
        {
            cout << "The game is a draw!" << endl;
        }

        // Ask if the players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y') // If players choose to play again, reset the game
        {
            // Reset the board to its initial state
            board[0][0] = '1';
            board[0][1] = '2';
            board[0][2] = '3';
            board[1][0] = '4';
            board[1][1] = '5';
            board[1][2] = '6';
            board[2][0] = '7';
            board[2][1] = '8';
            board[2][2] = '9';
            currentPlayer = 'X'; // Reset the starting player to 'X'
            gameWon = false;     // Reset the game won flag
            gameDraw = false;    // Reset the game draw flag
        }

    } while (playAgain == 'y' || playAgain == 'Y'); // Repeat the outer loop if players choose to play again

    return 0; // End the program
}

void displayBoard(char board[3][3])
{
    // Print the game board
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void playerMove(char board[3][3], char currentPlayer)
{
    int move;               // Variable to store the player's move
    bool validMove = false; // Flag to check if the move is valid

    do // Loop until a valid move is made
    {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move; // Get the player's move

        // Check the move and update the board accordingly
        switch (move)
        {
        case 1:
            if (board[0][0] == '1')
            {
                board[0][0] = currentPlayer; // Update the board with the current player's symbol
                validMove = true;            // Set the move as valid
            }
            break;
        case 2:
            if (board[0][1] == '2')
            {
                board[0][1] = currentPlayer;
                validMove = true;
            }
            break;
        case 3:
            if (board[0][2] == '3')
            {
                board[0][2] = currentPlayer;
                validMove = true;
            }
            break;
        case 4:
            if (board[1][0] == '4')
            {
                board[1][0] = currentPlayer;
                validMove = true;
            }
            break;
        case 5:
            if (board[1][1] == '5')
            {
                board[1][1] = currentPlayer;
                validMove = true;
            }
            break;
        case 6:
            if (board[1][2] == '6')
            {
                board[1][2] = currentPlayer;
                validMove = true;
            }
            break;
        case 7:
            if (board[2][0] == '7')
            {
                board[2][0] = currentPlayer;
                validMove = true;
            }
            break;
        case 8:
            if (board[2][1] == '8')
            {
                board[2][1] = currentPlayer;
                validMove = true;
            }
            break;
        case 9:
            if (board[2][2] == '9')
            {
                board[2][2] = currentPlayer;
                validMove = true;
            }
            break;
        default: // If the move is invalid, prompt the player to try again
            cout << "Invalid move. Try again." << endl;
            break;
        }

        if (!validMove) // If the move is on an already taken spot, prompt the player to try again
        {
            cout << "Spot already taken. Try again." << endl;
        }
    } while (!validMove); // Repeat until a valid move is made
}

bool checkWin(char board[3][3], char currentPlayer)
{
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
        {
            return true; // Return true if there is a win in any row or column
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
    {
        return true; // Return true if there is a win in any diagonal
    }

    return false; // Return false if there is no win
}

bool checkDraw(char board[3][3])
{
    // Check if all spots on the board are taken without a win
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') // If there is an empty spot, it's not a draw
            {
                return false;
            }
        }
    }
    return true; // If all spots are taken, return true indicating a draw
}

void switchPlayer(char &currentPlayer)
{
    // Switch the current player from 'X' to 'O' or 'O' to 'X'
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}