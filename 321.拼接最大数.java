/*
 * @lc app=leetcode.cn id=321 lang=java
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        // Find the max. subsequence from nums1 and nums2 respectively,
        // then merge them.
        int m = nums1.length, n = nums2.length;
        int[] res = new int[k], curMaxSubseq;
        int start = Math.max(0, k - n), end = Math.min(k, m);
        for (int i = start; i <= end; ++i) {
            curMaxSubseq = merge(maxSubseq(nums1, i), maxSubseq(nums2, k - i));
            if (compare(curMaxSubseq, 0, res, 0) > 0) {
                System.arraycopy(curMaxSubseq, 0, res, 0, k);
            }
        }
        return res;
    }

    private int[] maxSubseq(int[] nums, int k) {
        // Obtain the monotonic stack with length k from nums
        int n = nums.length;
        int[] stack = new int[k];
        int top = -1, remain = n - k;
        for (int num : nums) {
            while (top >= 0 && stack[top] < num && remain > 0) {
                --top;
                --remain;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                --remain;
            }
        }
        return stack;
    }

    private int[] merge(int[] subseq1, int[] subseq2) {
        int m = subseq1.length, n = subseq2.length;
        if (m == 0)  return subseq2;
        if (n == 0)  return subseq1;
        int l = m + n;
        int[] merged = new int[l];
        int idx1 = 0, idx2 = 0;
        for (int i = 0; i < l; ++i) {
            if (compare(subseq1, idx1, subseq2, idx2) > 0) {
                merged[i] = subseq1[idx1++];
            } else {
                merged[i] = subseq2[idx2++];
            }
        }
        return merged;
    }

    private int compare(int[] subseq1, int idx1, int[] subseq2, int idx2) {
        int m = subseq1.length, n = subseq2.length;
        while (idx1 < m && idx2 < n) {
            int diff = subseq1[idx1] - subseq2[idx2];
            if (diff != 0)  return diff;
            ++idx1; 
            ++idx2;
        }
        return (m - idx1) - (n - idx2);     // subseq1 longer, or subseq2?
    }
}
// @lc code=end

