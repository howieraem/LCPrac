import java.util.ArrayList;
import java.util.List;
/*
 * @lc app=leetcode.cn id=658 lang=java
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> res = new ArrayList<>();
        int n = arr.length;

        // Find the left bound of a window instead of a value.
        int l = 0, r = n - k;
        while (l < r) {
            int m = ((r - l) >> 1) + l;
            if (arr[m + k] - x >= x - arr[m])  r = m;
            else  l = m + 1; 
        }

        for (int i = l; i < l + k; ++i) {
            res.add(arr[i]);
        }
        return res;
    }
}
// @lc code=end

