import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=350 lang=java
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int n1 = nums1.length, n2 = nums2.length;
        int[] res = new int[Math.min(n1, n2)];

        int ptr1 = 0, ptr2 = 0, i = 0;
        while (ptr1 < n1 && ptr2 < n2) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ++ptr1;
            } else if (nums1[ptr1] > nums2[ptr2]) {
                ++ptr2;
            } else {
                res[i++] = nums1[ptr1++];
                ++ptr2;
            }
        }
        return Arrays.copyOfRange(res, 0, i);
    }
}
// @lc code=end

