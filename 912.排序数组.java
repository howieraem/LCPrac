/*
 * @lc app=leetcode.cn id=912 lang=java
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        mergeSort(nums, new int[n], 0, n - 1);
        return nums;
    }
    
    private void mergeSort(int[] nums, int[] sorted, int l, int r) {
        if (l == r)  return;
        int m = l + ((r - l) >> 1);
        mergeSort(nums, sorted, l, m);
        mergeSort(nums, sorted, m + 1, r);

        // Merge
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
    }
}
// @lc code=end

