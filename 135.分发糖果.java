import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=135 lang=java
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        if (n < 2)  return n;
        int[] candies = new int[n];
        Arrays.fill(candies, 1);
        
        // iterate from left to right
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        // then iterate from right to left and sum things up at the same time
        int sum = candies[n-1];
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1] && candies[i] < candies[i+1] + 1) {
                candies[i] = candies[i+1] + 1;
            }
            sum += candies[i];
        }
        return sum;
    }
}
// @lc code=end

