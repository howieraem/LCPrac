/*
 * @lc app=leetcode.cn id=493 lang=java
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
    public int reversePairs(int[] nums) {
        int n = nums.length;
        int[] sorted = new int[n];
        return mergeSort(nums, sorted, 0, n - 1);
    }

    private int mergeSort(int[] nums, int[] sorted, int l, int r) {
        if (l == r)  return 0;
        int m = l + ((r - l) >> 1);
        int ans = mergeSort(nums, sorted, l, m) +
                mergeSort(nums, sorted, m + 1, r) + 
                findReversedPairs(nums, l, m, r);

        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j])  sorted[k++] = nums[i++];
            else  sorted[k++] = nums[j++];
        }
        while (i <= m)  sorted[k++] = nums[i++];
        while (j <= r)  sorted[k++] = nums[j++];

        for (int idx = l; idx <= r; ++idx) {
            nums[idx] = sorted[idx];
        }
        return ans;
    }

    private int findReversedPairs(int[] nums, int l, int m, int r) {
        int ans = 0;
        int i = l, j = m + 1;
        while (i <= m) {
            while (j <= r && (long) nums[i] > 2 * (long) nums[j]) {
                ans += m - i + 1;
                ++j;
            }
            ++i;
        }
        return ans;
    }
}
// @lc code=end

