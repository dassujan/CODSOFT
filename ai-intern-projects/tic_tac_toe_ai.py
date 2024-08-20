# Tic-Tac-Toe with Unbeatable AI using Minimax Algorithm

# Initialize the board as a list of 9 empty spaces
board = [' ' for _ in range(9)]

# Function to print the current state of the board
def print_board():
    for i in range(3):
        print(f"{board[3*i]} | {board[3*i+1]} | {board[3*i+2]}")  # Print each row
        if i < 2:
            print("--+---+--")  # Print row separators

# Function to check if a player has won
def is_winner(player):
    win_conditions = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
        [0, 4, 8], [2, 4, 6]              # Diagonals
    ]
    # Check if any winning condition is met
    return any(all(board[pos] == player for pos in line) for line in win_conditions)

# Function to check if the board is full (no empty spaces)
def is_board_full():
    return all(cell != ' ' for cell in board)

# Minimax algorithm to find the optimal move
def minimax(is_maximizing):
    if is_winner('O'):
        return 1  # AI wins
    if is_winner('X'):
        return -1  # Player wins
    if is_board_full():
        return 0  # Tie

    if is_maximizing:
        best_score = -float('inf')
        for i in range(9):
            if board[i] == ' ':
                board[i] = 'O'  # AI's move
                score = minimax(False)  # Recur with minimizing player
                board[i] = ' '  # Undo move
                best_score = max(best_score, score)  # Get the best score
        return best_score
    else:
        best_score = float('inf')
        for i in range(9):
            if board[i] == ' ':
                board[i] = 'X'  # Player's move
                score = minimax(True)  # Recur with maximizing player
                board[i] = ' '  # Undo move
                best_score = min(best_score, score)  # Get the best score
        return best_score

# Function to find the best move for the AI
def best_move():
    best_score = -float('inf')
    move = 0
    for i in range(9):
        if board[i] == ' ':
            board[i] = 'O'  # AI's move
            score = minimax(False)  # Get score for this move
            board[i] = ' '  # Undo move
            if score > best_score:
                best_score = score  # Update best score
                move = i  # Update best move
    return move

# Function to play the game
def play_game():
    print("Welcome to Tic-Tac-Toe!")
    print_board()

    while True:
        # Player's move
        while True:
            try:
                move = int(input("Enter your move (1-9): ")) - 1  # Get player's move
                if board[move] == ' ':
                    board[move] = 'X'  # Place player's move on board
                    break
                else:
                    print("This position is already taken. Try again.")
            except (IndexError, ValueError):
                print("Invalid input. Enter a number between 1 and 9.")

        print_board()  # Print the board after player's move
        if is_winner('X'):
            print("Congratulations! You win!")
            break
        if is_board_full():
            print("It's a tie!")
            break

        # AI's move
        print("AI is making a move...")
        ai_move = best_move()  # Get the best move for the AI
        board[ai_move] = 'O'  # Place AI's move on board
        print_board()  # Print the board after AI's move
        if is_winner('O'):
            print("AI wins! Better luck next time.")
            break
        if is_board_full():
            print("It's a tie!")
            break

# Entry point of the program
if __name__ == "__main__":
    play_game()