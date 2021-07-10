/*
 * @lc app=leetcode.cn id=1792 lang=java
 *
 * [1792] 最大平均通过率
 */
import java.util.PriorityQueue;

// @lc code=start
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        // Add students to classes which can lead to greater increment first
        // (not classes with smaller pass ratios first).
        PriorityQueue<int[]> pq = new PriorityQueue<>((c1, c2) -> {
            // double preP1 = (c1[0] + 0.) / c1[1], preP2 = (c2[0] + 0.) / c2[1];
            // double curP1 = (c1[0] + 1.) / (c1[1] + 1.), curP2 = (c2[0] + 1.) / (c2[1] + 1.);
            // return Double.compare(curP1 - preP1, curP2 - preP2) > 0 ? -1 : 1;
            double inc1 = (c1[1] - c1[0]) / (c1[1] * (c1[1] + 1.)),
                    inc2 = (c2[1] - c2[0]) / (c2[1] * (c2[1] + 1.));
            return Double.compare(inc1, inc2) > 0 ? -1 : 1;
        });

        for (int[] c : classes) {
            pq.offer(c);
        }

        while (extraStudents > 0) {
            int[] c = pq.poll();
            ++c[0];
            ++c[1];
            pq.add(c);
            --extraStudents;
        }

        double sum = 0;
        while (!pq.isEmpty()) {
            int[] c = pq.poll();
            sum += ((c[0] + 0.) / c[1]);
        }
        return sum / classes.length;
    }
}
// @lc code=end

