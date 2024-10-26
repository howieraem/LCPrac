/*
 * @lc app=leetcode.cn id=852 lang=java
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
    // Binary search: find the index of rotation point of 
    // a rotated descending sorted array
    // T: O(log(n))
    // S: O(1)
    public int peakIndexInMountainArray(int[] arr) {
        int l = 0; 
        int r = arr.length - 2; 
        int ans = -1;
        // Initialize r = n - 2 rather than n - 1 
        // because arr[m + 1] will be compared 
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (arr[m] <= arr[m + 1])  {
                l = m + 1;
            } else {  // arr[m] > arr[m + 1]
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }

    // Follow-up: Q1095
}
// @lc code=end

