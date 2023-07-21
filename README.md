# Evolved Connect 4 Game Documentation - AUTh

This documentation pertains to the project "Evolved Connect 4" developed during my course work in the 1st Semester at the School of Electrical & Computer Engineering, Aristotle University in 2019.

## Table of Contents

- [Project Understanding and Approach](#project-understanding-and-approach)
- [Program Structure](#program-structure)
- [Code Explanation](#code-explanation)
- [Author](#author)

## Project Understanding and Approach

I began by thoroughly understanding the basic gameplay of Connect 4. I formulated strategies for determining my moves by calculating possible winning scenarios and taking the necessary actions to prevent the opponent from winning. This involved complex checks and calculations. I noticed an increased chance of winning if the first move is towards the center. I implemented additional checks to accommodate various scenarios, such as my chips being slanted or if there's a gap in my sequence of chips.

## Program Structure

The structure of the program is as follows:

- Static int
- Structure board
- CheckAdvancedMove
- Extern int player10148

The functions encapsulated within this program include determining the player number, determining the initial play, advanced checks for opponents, and advanced checks for my gameplay. There's a function to add a chip to an existing series and one to add a chip if no other conditions are met.

## Code Explanation

The code starts with setting PlayerNum to static int to retain its value across multiple invocations. The CheckAdvancedMove function is used to initialize various elements necessary for the game.

Several checks are in place to detect scenarios where adding more chips would be advantageous for the player or detrimental for the opponent. Additional checks are made for managing the diagonals and the creation of doubles. Rejected checks are discarded and the maximum of the acceptable checks are selected for further processing.

In the main function, player10148, the turn of the player is checked to determine the player number for subsequent checks. The first move is decided based on the board's center or to the right of it. The CheckAdvancedMove function is called for the opponent and the player to determine the next move.

In case of no valid moves as per the previous checks, the program decides to put a chip wherever feasible without going off the board.

## Author

- Chrysostomos Koumidis
- AEM 10148
