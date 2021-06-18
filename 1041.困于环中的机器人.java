/*
 * @lc app=leetcode.cn id=1041 lang=java
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution {
    public boolean isRobotBounded(String instructions) {
        int dir = 0; // 0 N, 1 E, 2 S, 3 W
        int x = 0, y = 0;
        char ch;
        for (int i = 0; i < instructions.length(); ++i) {
            ch = instructions.charAt(i);
            switch (ch) {
                case 'L':
                    if (dir == 0) dir = 3;
                    else --dir;
                    break;
                case 'R':
                    if (dir == 3) dir = 0;
                    else ++dir;
                    break;
                case 'G':
                    switch (dir) {
                        case 0: ++y;  break;
                        case 1: ++x;  break;
                        case 2: --y;  break;
                        case 3: --x;  break;
                    }
                    break;
            }
        }

        // If at the end of loop it reaches the origin again
        // or its direction becomes different from the beginnin',
        // then according to symmetry it will go back to
        // the origin eventually
        return ((x == 0 && y == 0) || dir != 0);
    }
}
// @lc code=end

