/*
 * @lc app=leetcode.cn id=781 lang=java
 *
 * [781] 森林中的兔子
 */
import java.util.Map;
import java.util.HashMap;

// @lc code=start
class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> cnts = new HashMap<>();
        for (int ans : answers) {
            cnts.put(ans, cnts.getOrDefault(ans, 0) + 1);
        }
        int least = 0;
        for (Map.Entry<Integer, Integer> entry : cnts.entrySet()) {
            int ans = entry.getKey(), cnt = entry.getValue();
            // 如果有 x 只兔子都回答 y，则至少有 ceil(x / (y+1)) 种不同的颜色，且每种颜色有 y+1 只兔子。
            // 加一是因为回答不包括这只兔子自己。
            least += ((int) Math.ceil(cnt / (ans + 1.0))) * (ans + 1); 
        }
        return least;
    }
}
// @lc code=end

