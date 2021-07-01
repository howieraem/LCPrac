import java.util.Random;

/*
 * @lc app=leetcode.cn id=528 lang=java
 *
 * [528] 按权重随机选择
 */

// @lc code=start
/**
 * Model with prefix sum and binary search.
 * 
 * Example:
 *      Given:
 *          i = [0, 1]     
 *          w = [1, 3]
 *          prefix sum = [1, 4]
 *      The prefix sums form the following intervals:
 *          {[0, 1), [1, 4)}
 *      We can then generate a random number in [0, 4) and see which interval it falls into. 
 *      The answer to the question is equivalent to finding the index of: 
 *          - the closest prefix sum greater than this number
 *          - the next prefix sum if this number equals a prefix sum
 */
class Solution {
    private int[] prefixSum;
    int n, sum;
    Random rand = new Random();

    public Solution(int[] w) {
        n = w.length;
        prefixSum = new int[n];
        prefixSum[0] = w[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + w[i];
        }
        sum = prefixSum[n - 1];
    }
    
    public int pickIndex() {
        int target = rand.nextInt(sum);
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            // Note: when target equals a prefix sum, the left boundary
            // still needs to be shifted because the target falls into 
            // the next interval between this prefix sum and its next one
            if (prefixSum[m] <= target)  l = m + 1;
            else  r = m;
        }
        return l;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
// @lc code=end

