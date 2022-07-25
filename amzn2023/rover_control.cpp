/**
 * https://leetcode.com/discuss/interview-question/985703
 * 
 * A Mars rover is directed to move within a square matrix. It accepts a sequence of commands to move 
 * in any of the four directions from each cell: [UP, DOWN, LEFT or RIGHT]. The rover starts from cell 
 * 0. and may not move diagonally or outside of the boundary. 
 * 
 * Each cell in the matrix has a position equal to: (row * size) + column
 * where row and column are zero-indexed, size = row length of the matrix.
 * 
 * Return the final position of the rover after all moves.
 * 
 * Example:
 * n = 4
 * commands = [RIGHT, UP, DOWN, LEFT, DOWN, DOWN]
 * 
 * The rover path is shown below.
 * 0 1 2 3
 * 4 5 6 7
 * 8 9 10 11
 * 12 13 14 15
 * 
 * RIGHT: Rover moves to position 1
 * UP: Position unchanged, as the move would take the rover out of the boundary.
 * DOWN: Rover moves to Position 5.
 * LEFT: Rover moves to position 4.
 * DOWN: Rover moves to position 8.
 * DOWN: The rover ends up in position 12.
 * 
 * The function returns 12.
 * 
 * Function Description:
 * Inputs:
 * - int n: the size of the square matrix
 * - string cmds[m]: the commands
 */
#include <bits/stdc++.h>

using std::vector;

int rover_control(const std::vector<std::string>& cmds, int n) {
    int row = 0, col = 0;
    for (const auto& cmd : cmds) {
        if (cmd == "RIGHT") {
            if (col < n - 1) ++col;
        } else if (cmd == "LEFT") {
            if (col > 0) --col;
        } else if (cmd == "UP") {
            if (row > 0) --row;
        } else {
            if (row < n - 1) ++row;
        }
    }
    return row * n + col;
}
