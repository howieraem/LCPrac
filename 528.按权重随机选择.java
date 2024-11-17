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
// Prefix sum + binary search
// S: O(n)
class Solution {
    private int[] prefixSum;
    private int n, sum;
    private Random rand = new Random();

    // T: O(n)
    public Solution(int[] w) {
        n = w.length;
        prefixSum = new int[n];
        prefixSum[0] = w[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + w[i];
        }
        sum = prefixSum[n - 1];
    }
    
    // T: O(log(n))
    public int pickIndex() {
        // In Java, random.nextInt(X) will return value from 0 to X - 1 (inclusive).
        // As there is no 0 weight, we need to add 1 to avoid getting 0 from the random function.
        // Add 1 will make the range as 1 to X, which is exactly the real range we need.
        int target = rand.nextInt(sum) + 1;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (prefixSum[m] == target) {
                return m;
            } else if (prefixSum[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
}

// Follow-up: randomly sample a number from disjoint intervals
public class RandomFromIntervals {
    Random rand = new Random();
  
    private int getRandomInRange(int[][] intervals) {
        int[] preSum = getCumulativeSum(intervals);
        int target = rand.nextInt(preSum[intervals.length - 1]);
        int idx = binarySearch(target, preSum, 0, preSum.length - 1);

        // find the index of the interval hit, then add offset
        return intervals[idx][0] + target - (idx > 0 ? preSum[idx - 1] : 0);
    }
  
    private int binarySearch(int target, int[] preSum, int l, int r) {
        while (l <= r) {
            int m = l + ((r - l) >>> 1);
            
            if (preSum[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l;
    }
  
    private int[] getCumulativeSum(int[][] intervals) {
        int[] preSum = new int[intervals.length];

        // the element for computing prefix sum becomes the interval length instead
        preSum[0] = intervals[0][1] - intervals[0][0] + 1;
        for (int i = 1; i < intervals.length; ++i) {
            preSum[i] = intervals[i][1] - intervals[i][0] + 1 + preSum[i - 1];
        }
        return preSum;
    }
  }

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
// @lc code=end

