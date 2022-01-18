/*
 * @lc app=leetcode.cn id=852 lang=java
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
    // Find the index of rotation point of a rotated decending sorted array
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0, r = arr.length - 2, ans = -1;
        // Initialize r = n - 2 rather than n - 1 
        // because arr[m + 1] will be compared 
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (arr[m] <= arr[m + 1])  l = m + 1;
            else {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
}
// @lc code=end

