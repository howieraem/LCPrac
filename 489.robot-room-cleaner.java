/*
 * @lc app=leetcode id=489 lang=java
 *
 * [489] Robot Room Cleaner
 */
import java.util.*;

interface Robot {
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    public boolean move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    public void turnLeft();
    public void turnRight();

    // Clean the current cell.
    public void clean();
}

// @lc code=start
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * interface Robot {
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     public boolean move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     public void turnLeft();
 *     public void turnRight();
 *
 *     // Clean the current cell.
 *     public void clean();
 * }
 */

class Solution {
    public void cleanRoom(Robot robot) {
        dfs(robot, 0, 0, 0, new HashSet<>());
    }

    private static final int[] D = {0, 1, 0, -1, 0};  // initial direction (0, 1)

    private static void dfs(Robot robot, int x, int y, int dirn, Set<Long> vis) {
        robot.clean();
        vis.add(convert_pt_to_key(x, y));
        for (int i = 0; i < 4; ++i) {
            int newDirn = ((dirn + i) & 3);  // % 4
            int newX = x + D[newDirn], newY = y + D[newDirn + 1];
            if (!vis.contains(convert_pt_to_key(newX, newY)) && robot.move()) {
                dfs(robot, newX, newY, newDirn, vis);
                resetRobot(robot);  // backtrack, undo last move and reset direction
            }
            robot.turnRight();
        }
    }

    private static void resetRobot(Robot robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    /** Reference: https://stackoverflow.com/questions/12772939 */
    private static long convert_pt_to_key(int x, int y) {
        return (((long)x) << 32) | (y & 0xffffffffL);
    }
}
// @lc code=end

