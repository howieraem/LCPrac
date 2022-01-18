import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=452 lang=java
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0)  return 0;
        Arrays.sort(points, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                // can't return a[1] - b[1] due to potential overflow
                if (a[1] > b[1]) {
                    return 1;
                } else if (a[1] < b[1]) {
                    return -1;
                } else {
                    return 0;
                }
            }
        });     // sort by the right boundary of each interval

        int cnt = 1;
        int pre_end = points[0][1];
        for (int[] interval : points) {
            if (interval[0] > pre_end) {
                // note > instead of >= in Q435
                ++cnt;
                pre_end = interval[1];
            }
        }
        return cnt;
    }
}
// @lc code=end

