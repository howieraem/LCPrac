import java.util.Map;
import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=1658 lang=java
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
    public int minOperations(int[] nums, int x) {
        Map<Integer, Integer> prefix2idx = new HashMap<>();

        int n = nums.length;
        int ans = Integer.MAX_VALUE;

        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];

            if (prefixSum == x) {
                // 前缀和等于x，可以只移除左侧的这部分元素 
                ans = Math.min(ans, i + 1); 
            }

            prefix2idx.put(prefixSum, i);
        }

        int suffixSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffixSum += nums[i];

            if (suffixSum == x) {
                // 后缀和等于x,可以只移除右侧的这部分元素
                ans = Math.min(ans, n - i);
            }

            // 考虑左侧和右侧都有移除的情况
            int diff = x - suffixSum;
            if (prefix2idx.containsKey(diff) && prefix2idx.get(diff) < i) {
                // 找到的前缀和所对应的索引必须小于当前从后往前遍历的索引
                ans = Math.min(ans, (n - i) + (prefix2idx.get(diff) + 1));
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
// @lc code=end

