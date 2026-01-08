Tic Tac Toe Game with AI (C++)

Project Description:
This project is a console-based Tic Tac Toe game developed in C++ where a human player competes against a computer-controlled opponent. The computer uses rule-based decision logic to attempt winning moves, block the player, and handle draw conditions. The project demonstrates structured programming and basic artificial intelligence concepts.

Features:
Player vs Computer gameplay
Intelligent CPU move selection
Automatic win and draw detection
Console-based graphical layout
Valid move checking and error handling

Technologies & Concepts Used:
Programming Language: C++
Core Concepts:
2D arrays
Functions and recursion
Conditional statements
Loops
Global state handling
Basic AI logic (rule-based decision making)

Game Rules:
The game is played on a 3×3 grid.
The player uses X, and the computer uses O.
Players take turns placing their symbol in an empty cell.
The first player to align three symbols in a row, column, or diagonal wins.
If all cells are filled with no winner, the game ends in a draw.

AI Logic Explanation:
The computer follows a priority-based strategy:
Attempt to complete a winning move.
Block the player if they are about to win.
Place a move in the first available empty position.
This deterministic approach ensures competitive gameplay without using advanced algorithms like Minimax.

Learning Outcomes:
Implemented game logic using structured programming
Designed a basic AI opponent using conditional decision-making
Gained experience with 2D arrays and game state tracking
Improved understanding of control flow and recursion in C++

Limitations:
Uses global variables for state management
AI follows rule-based logic and is not optimal
Platform-specific console commands are used (system("cls"))

Future Improvements:
Implement Minimax algorithm for optimal AI behavior
Refactor code using object-oriented programming
Add difficulty levels
Improve portability by removing platform-specific commands
Add a graphical user interface (GUI)

