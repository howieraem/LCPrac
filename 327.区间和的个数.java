/*
 * @lc app=leetcode.cn id=327 lang=java
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        // 问数组有多少个连续的子数组，子数组的元素的和在 [lower,upper] 的范围内。
        long sum = 0;
        long[] prefixSums = new long[nums.length + 1];
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            prefixSums[i + 1] = sum;
        }
        return countRangeSumRecursive(prefixSums, lower, upper, 0, prefixSums.length - 1);
    }

    private int countRangeSumRecursive(long[] prefixSums, int lower, int upper, int left, int right) {
        if (left == right)  return 0;
        int mid = left + (right - left) / 2;
        int n1 = countRangeSumRecursive(prefixSums, lower, upper, left, mid);
        int n2 = countRangeSumRecursive(prefixSums, lower, upper, mid + 1, right);
        int ans = n1 + n2;

        // 统计符合条件的下标对数量，即 prefixSums[j] - prefixSums[i] 在区间 [lower, upper] 内的数量
        int i = left, l = mid + 1, r = mid + 1;
        while (i <= mid) {
            while (l <= right && prefixSums[l] - prefixSums[i] < lower) {
                ++l;
            }
            while (r <= right && prefixSums[r] - prefixSums[i] <= upper) {
                ++r;
            }
            ans += r - l;
            ++i;
        }

        // 对前缀和做归并排序
        long[] sorted = new long[right - left + 1];
        int p1 = left, p2 = mid + 1, p = 0;
        while (p1 <= mid && p2 <= right) {
            if (prefixSums[p1] < prefixSums[p2]) {
                sorted[p++] = prefixSums[p1++];
            } else {
                sorted[p++] = prefixSums[p2++];
            }
        }
        while (p1 <= mid) {
            sorted[p++] = prefixSums[p1++];
        }
        while (p2 <= right) {
            sorted[p++] = prefixSums[p2++];
        }
        for (int j = 0; j < sorted.length; ++j) {
            prefixSums[left + j] = sorted[j];
        }

        return ans;
    }
}
// @lc code=end

