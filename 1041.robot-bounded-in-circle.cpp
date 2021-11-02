/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirn = 0, x = 0, y = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            switch (instructions[i]) {
                case 'L':
                    if (!dirn)  dirn = 3;
                    else  --dirn;
                    break;
                case 'R':
                    if (dirn == 3)  dirn = 0;
                    else  ++dirn;
                    break;
                case 'G':
                    switch (dirn) {
                        case 0: ++y; break; // N
                        case 1: ++x; break; // E
                        case 2: --y; break; // S
                        case 3: --x; break; // W
                    }
                    break;
            }
        }

        // If it returns to the origin, or 
        // its direction is different from 
        // the original direction.
        return (!(x || y) || dirn);
    }
};
// @lc code=end

