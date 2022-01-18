/*
 * @lc app=leetcode.cn id=1353 lang=java
 *
 * [1353] 最多可以参加的会议数目
 */
import java.util.*;

// @lc code=start
class Solution {
    public int maxEvents(int[][] events) {
        int ans = 0;

        // Sort by start time then by end time
        Arrays.sort(events, (e1, e2) -> e1[0] == e2[0] ? e1[1] - e2[1] : e1[0] - e2[0]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int i = 0, n = events.length, curDay = 1;
        while (i < n || !pq.isEmpty()) {
            while (i < n && events[i][0] == curDay) {
                pq.offer(events[i++][1]);
            }
            while (!pq.isEmpty() && pq.peek() < curDay) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                pq.poll();
                ++ans;
            }
            ++curDay;
        }
        return ans;
    }
}
// @lc code=end

