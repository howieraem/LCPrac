/*
 * @lc app=leetcode.cn id=1442 lang=java
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
class Solution {
    public int countTriplets(int[] arr) {
        int n = arr.length, ans = 0;

        // a == b -> 
        // a ^ b = 0 ->
        // arr[i] ^ ... ^ arr[j] ^ ... arr[k] = 0, i < j <= k ->
        // j can be chosen from any number in interval (i, k]
        for (int i = 0; i < n - 1; ++i) {
            int sum = 0;
            for (int k = i; k < n; ++k) {
                sum ^= arr[k];
                if (sum == 0 && k > i) {
                    ans += (k - i);
                }
            }
        }

        return ans;
    }
}
// @lc code=end

