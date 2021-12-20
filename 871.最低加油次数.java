/*
 * @lc app=leetcode.cn id=871 lang=java
 *
 * [871] 最低加油次数
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n * log(n))
    // S: O(n)
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int n = stations.length;
        if (n == 0)  return startFuel >= target ? 0 : -1;

        int ans = 0, cur = startFuel;
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1);
        for (int i = 0; i < n; ++i) {
            while (cur < stations[i][0]) {  // one liter of gas per one mile
                if (pq.isEmpty())  return -1;
                // Greedy: always go to and refuel with max available amount 
                // (no need to sort stations before as they are sorted by
                // position).
                cur += pq.poll();
                ++ans;
            }
            pq.offer(stations[i][1]);
        }

        // final step if possible
        while (cur < target) {
            if (pq.isEmpty())  return -1;
            cur += pq.poll();
            ++ans;
        }
        return ans;
    }
}
// @lc code=end

