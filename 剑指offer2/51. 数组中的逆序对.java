class Solution {
    private int res;

    public int reversePairs(int[] nums) {
        final int n = nums.length;
        if (n == 0)  return 0;
        res = 0;
        mergeSort(nums, 0, n - 1);
        return res;
    }

    private void mergeSort(int[] nums, int l, int r) {
        if (l >= r)  return;
        int m = l + ((r - l) >> 1);
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    private void merge(int[] nums, int l, int m, int r) {
        int[] tmp = new int[r - l + 1];
        int i = l, j = m + 1, k = 0;
        // Merge until one of the pointers has reached the end of a sorted array
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
                // 左右子数组已各自排好序。每当遇到 左子数组当前元素 > 右子数组当前元素 时，
                // 意味着 「左子数组当前元素 至 末尾元素」 与 「右子数组当前元素」 构成了若干 「逆序对」 。
                // 当前构成的逆序对的数量就是左子数组当前元素到左子数组末尾元素的数量。
                res += (m - i + 1);
            }
        }

        // Deal with the rest in another sorted array
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }

        // Copy the merged arrays back to their original collections
        for (int p = 0; p < tmp.length; ++p) {
            nums[p + l] = tmp[p];
        }
    }
}