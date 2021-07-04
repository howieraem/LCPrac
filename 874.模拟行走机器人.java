import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=874 lang=java
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution {
    private static final int[][] DIRN = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int robotSim(int[] commands, int[][] obstacles) {
        int x = 0, y = 0;
        int dIdx = 0;
        int ans = 0;

        // Trick: convert obstable info to a set for quicker comparison 
        // (avoid looping on obstables) while robot is moving forward 
        // every step
        Set<String> obs = new HashSet<>();
        for (int[] ob : obstacles) {
            obs.add(ob[0] + "_" + ob[1]);
        }

        for (int command : commands) {
            if (command == -2) {
                dIdx += 3;
            } else if (command == -1) {
                ++dIdx;
            } else {
                int[] curDirn = DIRN[dIdx & 3];     // dIdx % 4
                for (int k = 0; k < command; ++k) {
                    int nx = x + curDirn[0];
                    int ny = y + curDirn[1];
                    // Looping on obstables here is avoided
                    if (obs.contains(nx + "_" + ny))  break;
                    x = nx;
                    y = ny;
                    ans = Math.max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
}
// @lc code=end

