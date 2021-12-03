/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 */
#include <unordered_set>
#include <utility>

using std::pair;
using std::unordered_set;

// @lc code=start
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const pair<T1, T2> &pair) const {
        auto h1 = std::hash<T1>()(pair.first);
        auto h2 = std::hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

class Solution {
    static constexpr int DIRN[5] = {-1, 0, 1, 0, -1};

    void dfs(Robot& robot, int x, int y, int dirn, unordered_set<pair<int, int>, pair_hash> &visited) {
        robot.clean();
        visited.insert(pair<int, int>(x, y));
        for (int d = 0; d < 4; ++d) {
            int newDirn = (dirn + d) & 3;   // % 4
            int nx = x + DIRN[newDirn], ny = y + DIRN[newDirn + 1];
            if (visited.find(pair<int, int>(nx, ny)) == visited.end() && robot.move()) {
                dfs(robot, nx, ny, newDirn, visited);
                goBackAndKeepDirn(robot);   // backtrack (undo action)
            }
            robot.turnRight();
        }
    }

    void goBackAndKeepDirn(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

public:
    void cleanRoom(Robot& robot) {
        unordered_set<pair<int, int>, pair_hash> vis;
        dfs(robot, 0, 0, 0, vis);
    }
};
// @lc code=end

