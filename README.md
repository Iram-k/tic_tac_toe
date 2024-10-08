# Tic-Tac-Toe: Human vs. Computer

## Project Overview

This is a simple Tic-Tac-Toe game implemented in C++. It allows a human player to compete against a computer that uses the Minimax algorithm with backtracking to make optimal decisions. The player can select their moves by entering a number between 1 and 9, corresponding to the grid position.

The game will alternate turns between the player and the computer until a winner is declared or the board is full (resulting in a tie). The game board updates after each move, and the winner is displayed when the game ends.

## Features

- **Human vs. Computer:** The player plays against an AI opponent.
- **Minimax Algorithm:** The computer uses the Minimax algorithm to determine the best move.
- **Dynamic Board Display:** The board is updated and displayed after each turn.
- **Input System:** The player selects moves by entering a number between 1-9 corresponding to board positions.


### Input System

- The player enters a number (1-9) to place their mark ('X') on the board.
- The computer automatically places its mark ('O') in the most strategic position based on the Minimax algorithm.

## Rules of the Game

1. The game is played on a 3x3 grid.
2. The player and the computer take turns marking spaces with 'X' (for player) and 'O' (for computer).
3. The first player to get 3 marks in a row (horizontally, vertically, or diagonally) wins.
4. If all spaces are filled and no one has 3 marks in a row, the game is a tie.

## Minimax Algorithm Overview

The Minimax algorithm is used by the computer to ensure it makes the best possible moves. It evaluates the current state of the board and simulates all possible moves to determine which one will lead to the best outcome.

### How Minimax Works

- The algorithm recursively simulates all possible moves by both the player and the computer.
- The computer (maximizer) tries to maximize the score, while the player (minimizer) tries to minimize it.
- The algorithm assumes the opponent is also playing optimally, and it chooses moves based on this assumption.
- It returns the best score for the maximizer (computer) and the worst score for the minimizer (human).
