
/*
 * @lc app=leetcode.cn id=315 lang=java
 *
 * [315] 计算右侧小于当前元素的个数
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

// @lc code=start
class Solution {
    private int[] idxs, tmp, tmpIdxs, res;

    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        if (n == 0)  return new ArrayList<>();

        idxs = new int[n];  // as numbers as swapped during sorting, use an auxiliary array to record their indices
        tmp = new int[n];
        tmpIdxs = new int[n];
        res = new int[n];
        for (int i = 0; i < n; ++i)  idxs[i] = i;

        mergeSort(nums, 0, n - 1);

        return Arrays.stream(res).boxed().collect(Collectors.toList());
    }

    private void mergeSort(int[] nums, int l, int r) {
        if (l >= r)  return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    private void merge(int[] nums, int l, int m, int r) {
        int i = l, j = m + 1, k = l;
        // Merge until one of the pointers has reached the end of a sorted array
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k] = nums[i];
                tmpIdxs[k] = idxs[i];
                res[idxs[i]] += (j - m - 1);
                ++i;
                ++k;
            } else {
                tmp[k] = nums[j];
                tmpIdxs[k] = idxs[j];
                ++j;
                ++k;
            }
        }

        // Deal with the rest in another sorted array
        while (i <= m) {
            tmp[k] = nums[i];
            tmpIdxs[k] = idxs[i];
            res[idxs[i]] += (j - m - 1);
            ++i;
            ++k;
        }
        while (j <= r) {
            tmp[k] = nums[j];
            tmpIdxs[k] = idxs[j];
            ++j;
            ++k;
        }

        // Copy the merged arrays back to their original collections
        for (int p = l; p <= r; ++p) {
            nums[p] = tmp[p];
            idxs[p] = tmpIdxs[p];
        }
    }
}
// @lc code=end
