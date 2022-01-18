import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1818 lang=java
 *
 * [1818] 绝对差值和
 */

// @lc code=start
class Solution {
    private static final int F = 1000000007;

    // 带剪枝的暴力法，O(N^2)
    // public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
    //     int n = nums1.length;
    //     int sum = 0;
    //     int max = 0;
    //     for (int i = 0; i < n; ++i) {
    //         int abs = Math.abs(nums1[i] - nums2[i]);
    //         sum = (sum + abs) % F;

    //         // 剪枝：由于只替换一个数，若已模拟替换后的差值大于当前绝对值则不会发生替换
    //         if (max >= abs)  continue;

    //         for (int num : nums1) {
    //             max = Math.max(max, abs - Math.abs(num - nums2[i]));
    //         }
    //     }
    //     return (sum - max + F) % F;
    // }

    // 排序 + 二分查找nums1中最接近每个nums2中的数，O(NlogN)
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] nums1c = nums1.clone();
        Arrays.sort(nums1c);
        int sum = 0, max = 0;
        for (int i = 0; i < n; ++i) {
            int abs = Math.abs(nums1[i] - nums2[i]);
            if (abs == 0)  continue;
            sum = (sum + abs) % F;

            // 找到 nums1 中大于等于 nums2[i] 的最小下标，即左边界
            int target = nums2[i];
            int l = 0, r = n;
            while (l < r) {
                int m = ((r - l) >> 1) + l;
                if (nums1c[m] < target)  l = m + 1;
                else  r = m;
            }
            
            if (l < n) {
                // nums1c[l] >= nums2[i]
                max = Math.max(max, abs - (nums1c[l] - target));
            }
            if (l > 0) {
                // nums1c[l] < nums2[i]
                max = Math.max(max, abs - (target - nums1c[l - 1]));
            }
        }
        return (sum - max + F) % F;
    }
}
// @lc code=end

