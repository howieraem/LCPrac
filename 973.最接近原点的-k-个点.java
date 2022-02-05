/*
 * @lc app=leetcode.cn id=973 lang=java
 *
 * [973] 最接近原点的 K 个点
 */
import java.util.Arrays;
// import java.util.PriorityQueue;

// @lc code=start
class Solution {
    private static int calcD(int[] pt) {
        return pt[0] * pt[0] + pt[1] * pt[1];
    }

    // Method 1: direct sorting with comparator (not recommended for interview)
    // public int[][] kClosest(int[][] points, int k) {
    //     Arrays.sort(points, (pt1, pt2) -> calcD(pt1) - calcD(pt2));
    //     return Arrays.copyOfRange(points, 0, k);
    // }

    // Method 2: heap with comparator, point indices stored
    // public int[][] kClosest(int[][] points, int k) {
    //     PriorityQueue<int[]> pq = new PriorityQueue<>(
    //         // Java's PQ is a max heap, so comparator should be d2 - d1.
    //         (pt1, pt2) -> calcD(pt2) - calcD(pt1));

    //     // insert the first k points into the heap
    //     for (int i = 0; i < k; ++i) {
    //         pq.offer(points[i]);
    //     }

    //     // For the rest points, insert if dist is less 
    //     // (usually quicker than adding all points)
    //     for (int i = k; i < points.length; ++i) {
    //         int d = calcD(points[i]);
    //         if (d < calcD(pq.peek())) {
    //             pq.poll();
    //             pq.offer(points[i]);
    //         }
    //     }

    //     // Convert heap to result format
    //     int[][] res = new int[k][2];
    //     for (int i = 0; i < k; ++i) {
    //         res[i] = pq.poll();
    //     }
    //     return res;
    // }

    // Method 3: Quick select (worst O(N^2), expected O(N))
    public int[][] kClosest(int[][] points, int k) {
        final int n = points.length;
        if (n == k)  return points;     // avoid index out of bound
        quickSelect(points, 0, n - 1, k);
        return Arrays.copyOfRange(points, 0, k);
    }

    private void quickSelect(int[][] points, int start, int end, int k) {
        // Always choose element at the start index as pivot (equivalent to random index
        // as swaps will be done multiple times)
        int pivot = calcD(points[start]);

        // Swap elements, such that in terms of distance to origin, 
        // elements on the left of pivot are less than pivot, and
        // elements on the right of pivot are greater than pivot
        int l = start, r = end;
        while (l <= r) {
            if (calcD(points[l]) <= pivot) {
                // Element on the left of pivot already less than pivot,
                // so skip it
                ++l;
                continue;
            }
            if (calcD(points[r]) > pivot) {
                // Element on the right of pivot already greater than pivot,
                // so skip it
                --r;
                continue;
            }
            
            // If neither conditions above are met, swap elements
            swap(points, l, r);
            ++l;
            --r;
        }

        // Swap pivot with the element at the right index.
        // If the right index equals k, all elements on the
        // left of k-th element (pivot) are less, then stop
        // quick select and return these elements as answer.
        swap(points, start, r);
        if (r == k)  return;
        // If less than k elements obtained, do quick select
        // on the right of the right boundary to include 
        // larger elements.
        else if (r < k)  quickSelect(points, r + 1, end, k);
        // If more than k elements obtained, shift the right boundary
        // and do quick select again.
        else  quickSelect(points, start, r - 1, k);
    }

    private void swap(int[][] points, int l, int r) {
        int[] tmp = points[l];
        points[l] = points[r];
        points[r] = tmp;
    }
}
// @lc code=end

