/*
 * @lc app=leetcode.cn id=554 lang=java
 *
 * [554] 砖墙
 */
import java.util.List;
import java.util.Map;
import java.util.HashMap;

// @lc code=start
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> d = new HashMap<>();
        for (List<Integer> widths : wall) {
            int sum = 0;
            for (int i = 0; i < widths.size() - 1; ++i) {
                // Do NOT count the last brick of each row as
                // all rows sum up to the same number (max
                // width) and the line cannot be drawn on
                // the right boundary
                int width = widths.get(i);
                sum += width;
                d.put(sum, d.getOrDefault(sum, 0) + 1);
            }
        }

        int maxGaps = 0;
        for (Map.Entry<Integer, Integer> e : d.entrySet()) {
            maxGaps = Math.max(maxGaps, e.getValue());
        }
        return wall.size() - maxGaps;
    }
}
// @lc code=end

