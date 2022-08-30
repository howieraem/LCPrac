/*
 * @lc app=leetcode id=975 lang=java
 *
 * [975] Odd Even Jump
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n * log(n))
    // S: O(n)
    public int oddEvenJumps(int[] arr) {
        final int n = arr.length;
        boolean[] higher = new boolean[n], lower = new boolean[n];
        higher[n - 1] = lower[n - 1] = true;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        mp.put(arr[n - 1], n - 1);
        int ans = 1;  // trivial case: start from the last index?

        for (int i = n - 2; i >= 0; --i) {
            Map.Entry<Integer, Integer> hi = mp.ceilingEntry(arr[i]),
                                        lo = mp.floorEntry(arr[i]);
            if (hi != null) higher[i] = lower[(int)hi.getValue()];
            if (lo != null) lower[i] = higher[(int)lo.getValue()];
            if (higher[i]) ++ans;  // only updates for odd-numbered jumps because the start index will be the 1st jump
            mp.put(arr[i], i);
        }
        return ans;
    }
}
// @lc code=end

