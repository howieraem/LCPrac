/*
 * @lc app=leetcode.cn id=1787 lang=java
 *
 * [1787] 使所有区间的异或结果为零
 */
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;


// @lc code=start
class Solution {
    // x 的范围为 [0, 2^10)
    private static final int MAXX = 1 << 10;
    // 极大值，为了防止整数溢出选择 INT_MAX / 2
    private static final int INFTY = Integer.MAX_VALUE / 2;

    public int minChanges(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[MAXX];
        Arrays.fill(dp, INFTY);
        // 边界条件 dp(-1,0)=0
        dp[0] = 0;
        
        for (int i = 0; i < k; ++i) {
            // 第 i 个组的哈希映射
            Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
            int size = 0;
            for (int j = i; j < n; j += k) {
                cnt.put(nums[j], cnt.getOrDefault(nums[j], 0) + 1);
                ++size;
            }

            // 求出 t2
            int t2min = Arrays.stream(dp).min().getAsInt();

            int[] g = new int[MAXX];
            Arrays.fill(g, t2min);
            for (int mask = 0; mask < MAXX; ++mask) {
                // t1 则需要枚举 x 才能求出
                for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
                    int x = entry.getKey(), countx = entry.getValue();
                    g[mask] = Math.min(g[mask], dp[mask ^ x] - countx);
                }
            }
            
            // 别忘了加上 size
            for (int j = 0; j < MAXX; ++j) {
                g[j] += size;
            }
            dp = g;
        }

        return dp[0];
    }
}
// @lc code=end

