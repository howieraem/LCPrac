/*
 * @lc app=leetcode.cn id=321 lang=java
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
    // Mono-stack + DP + sorted lists merge
    // T: O((m + n) ^ 3)
    // S: O(m + n)
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        // Find the max. subsequence from nums1 and nums2 respectively,
        // then merge them.
        int m = nums1.length, n = nums2.length;
        int[] res = new int[k];

        // pick k numbers from nums2, then the remaining n - k must be from nums1
        int start = Math.max(0, k - n);
        int end = Math.min(k, m);

        for (int i = start; i <= end; ++i) {
            int[] curMaxSubseq = merge(maxSubseq(nums1, i), maxSubseq(nums2, k - i));

            // if curMaxSubseq can form a larger number, update res
            if (compare(curMaxSubseq, 0, res, 0) > 0) {
                System.arraycopy(curMaxSubseq, 0, res, 0, k);
            }
        }
        return res;
    }

    // Return the max subseq from nums with length k
    private int[] maxSubseq(int[] nums, int k) {
        // Obtain the monotonic stack with length k from nums
        int n = nums.length;
        int[] stack = new int[k];
        int top = -1;   // pointer to stack top 
        
        for (int i = 0; i < n; ++i) {
            // Stack numbers are ordered DESC to maximize the number resulted
            while (top >= 0 && stack[top] < nums[i] && k - top - 1 < n - i) {
                // Simulate pop; 
                // do NOT pop if the remaining numbers can't fill the k-length subseq
                --top;
            }

            if (top < k - 1) {
                stack[++top] = nums[i];
            } // else stack is full
        }
        return stack;
    }

    // Merge two subseqs to maximize the number from the subseq resulted
    // T: O(n ^ 2) worst
    private int[] merge(int[] subseq1, int[] subseq2) {
        int m = subseq1.length, n = subseq2.length;
        if (m == 0) {
            return subseq2;
        }
        if (n == 0) {
            return subseq1;
        }
        int len = m + n;
        int[] merged = new int[len];
        int idx1 = 0;
        int idx2 = 0;
        for (int i = 0; i < len; ++i) {
            if (compare(subseq1, idx1, subseq2, idx2) > 0) {
                merged[i] = subseq1[idx1++];
            } else {
                merged[i] = subseq2[idx2++];
            }
        }
        return merged;
    }

    // simulate number subtraction
    // if compare() > 0, then the number formed by subseq1[idx1:] is greater than that of subseq2[idx2:] 
    private int compare(int[] subseq1, int idx1, int[] subseq2, int idx2) {
        int m = subseq1.length, n = subseq2.length;
        while (idx1 < m && idx2 < n) {
            int diff = subseq1[idx1] - subseq2[idx2];
            if (diff != 0) {
                return diff;
            }
            ++idx1; 
            ++idx2;
        }
        // If "prefix" exactly the same, is subseq1 longer or subseq2?
        return (m - idx1) - (n - idx2);
    }
}
// @lc code=end

