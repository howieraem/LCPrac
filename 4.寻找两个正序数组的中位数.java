/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            // always make nums2 the longer array
            int[] tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }
        int l1 = nums1.length, l2 = nums2.length;
        // assert l2 > 0;

        int min1 = 0, max1 = l1;
        int maxLeft = 0, minRight = 0;
        while (min1 <= max1) {
            int mid1 = min1 + (max1 - min1) / 2;
            int mid2 = (l1 + l2 + 1) / 2 - mid1;

            int nums1MidLeft = (mid1 == 0 ? Integer.MIN_VALUE : nums1[mid1-1]);
            int nums1Mid = (mid1 == l1 ? Integer.MAX_VALUE : nums1[mid1]);
            int nums2MidLeft = (mid2 == 0 ? Integer.MIN_VALUE : nums2[mid2-1]);
            int nums2Mid = (mid2 == l2 ? Integer.MAX_VALUE : nums2[mid2]);

            if (nums1MidLeft <= nums2Mid) {
                maxLeft = Math.max(nums1MidLeft, nums2MidLeft);
                minRight = Math.min(nums1Mid, nums2Mid);
                min1 = mid1 + 1;
            } else {
                max1 = mid1 - 1;
            }
        }
        return (l1 + l2) % 2 == 0 ? (maxLeft + minRight) / 2. : (double) maxLeft;
    }
}
// @lc code=end
