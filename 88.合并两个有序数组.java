/*
 * @lc app=leetcode.cn id=88 lang=java
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int tail1 = m - 1, tail2 = n - 1, tail = m + n - 1;
        while (tail != tail1) {
            if (tail1 >= 0 && nums1[tail1] > nums2[tail2]) {
                nums1[tail--] = nums1[tail1--];
            } else { 
                // incl. the case of `tail1 < 0`, need to copy the remaining elements in `nums2`
                nums1[tail--] = nums2[tail2--];
            }
        }
    }
}
// @lc code=end

