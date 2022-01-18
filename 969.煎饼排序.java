import java.util.LinkedList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=969 lang=java
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
    public List<Integer> pancakeSort(int[] arr) {
        LinkedList<Integer> res = new LinkedList<>();
        sort(arr, arr.length, res);
        return res;
    }

    private void sort(int[] cakes, int n, List<Integer> res) {
        // Strategy: 
        // 1. find the largest number;
        // 2. reverse numbers above and include that largest number;
        // 3. reverse all n numbers, such that the largest will be at the bottom.
        // 4. reduce n by 1 and repeat steps 1-3 until n = 1
        // 
        // Note that it may not produce the shortest path.
        if (n == 1)  return;
        int max = 0;
        int argMax = 0;
        for (int i = 0; i < n; ++i) {
            if (cakes[i] > max) {
                max = cakes[i];
                argMax = i;
            }
        }
        reverse(cakes, 0, argMax);
        res.add(argMax + 1);
        reverse(cakes, 0, n - 1);
        res.add(n);
        sort(cakes, n - 1, res);
    }

    private void reverse(int[] arr, int i, int j) {
        while (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            ++i;
            --j;
        }
    }
}
// @lc code=end

