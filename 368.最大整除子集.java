/*
 * @lc app=leetcode.cn id=368 lang=java
 *
 * [368] 最大整除子集
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

// @lc code=start
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        // 判断一个数 a 能整除一个能相互整除的集合 S，可先判断这个数 a 能否整除这个集合 S 里最大的那个数 b 。
        // 如果一个数A能整除集合里最大的数 b ，那一定能整除这个子集里所有的其他数。
        // 为了更方便地找到最大的数，先对数组进行排序。
        int n = nums.length;
        if (n == 0)  return new ArrayList<>();
        Arrays.sort(nums);

        List<Integer>[] dp = new ArrayList[n];
        dp[0] = new ArrayList<>();
        dp[0].add(nums[0]);
        List<Integer> res = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = new ArrayList<>();
            dp[i].add(nums[i]);

            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size() + 1) {
                    // 以数字 S[i] 作为这个集合的最大数，只要判断是否存在以 S[k] 为最大数的集合，使最大数 S[k] 能被 S[i] 整除即可。
                    // dp[i] 代表以 nums[i] 为结尾的最大整除子集（该子集是排序了的）。
                    // The reason for `dp[j].size() + 1` is that `nums[i]` has not been added to `dp[j]` yet. 
                    dp[i] = new ArrayList<>(dp[j]);
                    dp[i].add(nums[i]);
                }
            }

            if (res.size() < dp[i].size()) {
                res = dp[i];
            }
        }
        return res;
    }
}
// @lc code=end

