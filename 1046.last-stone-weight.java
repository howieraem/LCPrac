/*
 * @lc app=leetcode id=1046 lang=java
 *
 * [1046] Last Stone Weight
 */
import java.util.*;

// @lc code=start
class Solution {
    // Simulation
    // T: O(n * log(n))
    // S: O(n)
    public int lastStoneWeight(int[] stones) {
        // Use Integer.compare() rather than y - x to avoid overflow
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((x, y) -> Integer.compare(y, x));
        for (int stone : stones) {
            maxHeap.add(stone);
        }

        while (maxHeap.size() > 1) {
            Integer y = maxHeap.poll(), x = maxHeap.poll();
            Integer diff = y - x;
            if (diff != 0) {
                maxHeap.add(diff);
            }
        }

        return maxHeap.isEmpty() ? 0 : maxHeap.poll();
    }
}
// @lc code=end

