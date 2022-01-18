import java.util.*;
/*
 * @lc app=leetcode id=1481 lang=java
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : arr) {
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }

        /* Below is O(NlogN) time
        // Build a priority queue of integers based on their frequencies.
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparing(freq::get));
        pq.addAll(freq.keySet());
        while (k > 0) {
            k -= freq.get(pq.poll());
        }
        // If k < 0, an extra integer has been "removed", need to put it back
        return k < 0 ? pq.size() + 1 : pq.size();
        */

        /* Below is O(N) time */
        int[] freqCnt = new int[arr.length + 1];
        for (int v : freq.values()) {
            ++freqCnt[v];
        }
        int ans = freq.size(), curFreq = 1;
        while (k > 0) {
            int k_next = k - curFreq * freqCnt[curFreq];
            if (k_next >= 0) {
                k = k_next;
                ans -= freqCnt[curFreq++];
            } else {
                // k not large enough, so deduct less than 
                // freqCnt[curFreq] from unique count
                return ans - k / curFreq;
            }
        }
        return ans;
    }
}
// @lc code=end

