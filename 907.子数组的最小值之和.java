import java.util.*;
/*
 * @lc app=leetcode.cn id=907 lang=java
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
    private static final int F = 1000000007;

    // T: O(n)
    // S: O(n)
    public int sumSubarrayMins(int[] arr) {
        final int n = arr.length;
    
        // For arr[i], assuming there are L numbers that are greater than arr[i] in arr[0:i], and 
        // R numbers that are greater than or equal to arr[i] in arr[i:n – 1]. 
        // Then, arr[i] will be the minimum of all (L + 1) * (R + 1) subarrays.
        Stack<Integer> nums = new Stack<>(), lens = new Stack<>();
        int[] left = new int[n], right = new int[n];
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (!nums.empty() && nums.peek() > arr[i]) {
                nums.pop();
                len += lens.pop();
            }
            nums.push(arr[i]);
            lens.push(len);
            left[i] = len;
        }

        nums.clear();
        lens.clear();
        for (int i = n - 1; i >= 0; --i) {
            int len = 1;
            while (!nums.empty() && nums.peek() >= arr[i]) {
                nums.pop();
                len += lens.pop();
            }
            nums.push(arr[i]);
            lens.push(len);
            right[i] = len;
        }

        // The answer is thus the sum of arr[i] * left[i] * right[i].
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            // (a + b) % f = (a % f + b % f) % f
            // (a * b) % f = (a % f * b % f) % f
            // It seems in Java even (arr[i] % F * left[i] % F * right[i] % F) % F is too large to store in int
            ans = (ans % F + (((long) arr[i] % F * left[i] % F * right[i] % F) % F) % F) % F;
        }
        return (int) ans;
    }
}
// @lc code=end
