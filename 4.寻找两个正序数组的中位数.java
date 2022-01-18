/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            // Ensure n1 < n2
            int[] tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }
        final int n1 = nums1.length, n2 = nums2.length;

        /* See https://zxi.mytechroad.com/blog/wp-content/uploads/2017/11/4-ep102.png for explanation of maxLeft and minRight. */
        int l = 0, r = n1;
        int k = (n1 + n2 + 1) >> 1;

        // int maxLeft = 0, minRight = 0;
        // while (l <= r) {
        //     int mid1 = l + ((r - l) >> 1);
        //     int mid2 = k - mid1;

        //     int nums1MidLeft = (mid1 == 0 ? Integer.MIN_VALUE : nums1[mid1 - 1]);
        //     int nums1Mid = (mid1 == n1 ? Integer.MAX_VALUE : nums1[mid1]);
        //     int nums2MidLeft = (mid2 == 0 ? Integer.MIN_VALUE : nums2[mid2 - 1]);
        //     int nums2Mid = (mid2 == n2 ? Integer.MAX_VALUE : nums2[mid2]);

        //     if (nums1MidLeft <= nums2Mid) {
        //         maxLeft = Math.max(nums1MidLeft, nums2MidLeft);
        //         minRight = Math.min(nums1Mid, nums2Mid);
        //         l = mid1 + 1;
        //     } else {
        //         r = mid1 - 1;
        //     }
        // }
        // return (n1 + n2) % 2 == 0 ? (maxLeft + minRight) / 2. : (double) maxLeft;
        while (l < r) {
            int m1 = l + ((r - l) >> 1), m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }
        int m1 = l, m2 = k - l;
        int maxLeft = Math.max(
                m1 <= 0 ? Integer.MIN_VALUE : nums1[m1 - 1], 
                m2 <= 0 ? Integer.MIN_VALUE : nums2[m2 - 1]);
        if ((n1 + n2) % 2 == 1)  return maxLeft;
        int minRight = Math.min(
                m1 >= n1 ? Integer.MAX_VALUE : nums1[m1], 
                m2 >= n2 ? Integer.MAX_VALUE : nums2[m2]);
        return (maxLeft + minRight) * 0.5;
    }
}
// @lc code=end
