/*
 * @lc app=leetcode.cn id=373 lang=java
 *
 * [373] 查找和最小的K对数字
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

// @lc code=start
class Solution {
    private class Pair {
        public int i, j;

        public Pair(int a, int b) {
            i = a;  j = b;
        }
    }

    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> res = new ArrayList<>();
        int m = nums1.length, n = nums2.length;
        if (nums1 == null || nums2 == null || m == 0 || n == 0 || k <= 0) {
            return res; 
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> nums1[p1.i] + nums2[p1.j] - nums1[p2.i] - nums2[p2.j]);
        for (int i = 0; i < m; ++i)  pq.add(new Pair(i, 0));

        for (int i = 0; i < k && !pq.isEmpty(); ++i) {
            Pair p = pq.poll();
            res.add(Arrays.asList(nums1[p.i], nums2[p.j]));
            if (p.j + 1 < n)  pq.add(new Pair(p.i, p.j + 1));
        }
        return res;
    }
}
// @lc code=end

