/*
 * @lc app=leetcode.cn id=149 lang=java
 *
 * [149] 直线上最多的点数
 */
import java.util.HashMap;

// @lc code=start
class Solution {
    // GCD + hash map
    // T: O(n ^ 2 * log(max(pt[0], pt[1]) for pt in points))
    // S: O(n)
    public int maxPoints(int[][] points) {
        if (points.length < 3) {
            return points.length;
        }
        int res = 0;
        // 遍历每个点
        for (int i = 0; i < points.length; i++) {
            // 保存经过当前点的直线中，最多的点
            int duplicate = 0, max = 0;
            HashMap<String, Integer> map = new HashMap<>();

            // Compare all possible pairs of points
            for (int j = i + 1; j < points.length; j++) {
                // 求出分子分母
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    // Avoid division by 0
                    // 避免计算最大公约数时出现问题
                    ++duplicate;
                    continue;
                }
                
                // Get GCD to avoid floating point precision issues
                // 进行约分，把斜率作为键，斜率相同则在同一直线上
                int gcd = gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;
                String key = dx + "/" + dy;   // avoid floating point precision problem
                map.put(key, map.getOrDefault(key, 0) + 1);
                max = Math.max(max, map.get(key));
            }
            // 1 代表当前考虑的点，duplicate 代表和当前的点重复的点
            res = Math.max(res, max + duplicate + 1);
        }
        return res;
    }
    
    // Calculate greatest common divisor
    /** 计算最大公约数 */
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}
// @lc code=end

