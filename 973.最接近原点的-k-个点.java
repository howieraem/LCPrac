/*
 * @lc app=leetcode.cn id=973 lang=java
 *
 * [973] 最接近原点的 K 个点
 */
// import java.util.Arrays;
import java.util.PriorityQueue;

// @lc code=start
class Solution {
    // Method 1: direct sorting with comparator (not recommended for interview)
    // public int[][] kClosest(int[][] points, int k) {
    //     Arrays.sort(points, (pt1, pt2) -> pt1[0] * pt1[0] + pt1[1] * pt1[1] - pt2[0] * pt2[0] - pt2[1] * pt2[1]);
    //     return Arrays.copyOfRange(points, 0, k);
    // }

    // Method 2: heap with comparator, point indices stored
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            // Java's PQ is a max heap, so comparator should be d2 - d1.
            (pt1, pt2) -> calcD(pt2) - calcD(pt1));

        // insert the first k points into the heap
        for (int i = 0; i < k; ++i) {
            pq.offer(points[i]);
        }

        // For the rest points, insert if dist is less 
        // (usually quicker than adding all points)
        for (int i = k; i < points.length; ++i) {
            int d = calcD(points[i]);
            if (d < calcD(pq.peek())) {
                pq.poll();
                pq.offer(points[i]);
            }
        }

        // Convert heap to result format
        int[][] res = new int[k][2];
        for (int i = 0; i < k; ++i) {
            res[i] = pq.poll();
        }
        return res;
    }

    private static int calcD(int[] pt) {
        return pt[0] * pt[0] + pt[1] * pt[1];
    }
}
// @lc code=end

