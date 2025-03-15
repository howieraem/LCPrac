/*
 * @lc app=leetcode id=657 lang=java
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution {
    // Simulation + Math + Counter
    // T: O(n)
    // S: O(1)
    public boolean judgeCircle(String moves) {
        int dx = 0;
        int dy = 0;
        for (int i = 0; i < moves.length(); ++i) {
            switch (moves.charAt(i)) {
                case 'U':
                    ++dy;
                    break;
                case 'D': 
                    --dy;
                    break;
                case 'L':
                    --dx;
                    break;
                case 'R':
                    ++dx;
                    break;
            }
        }
        return dx == 0 && dy == 0;
    }
}
// @lc code=end

