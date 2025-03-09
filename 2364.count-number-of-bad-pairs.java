import java.util.*;

class Solution {
    // Hash Map + Math
    // T: O(n)
    // S: O(n)
    public long countBadPairs(int[] nums) {
        final long n = (long) nums.length;
        long tot_good_pairs = 0L;

        // find the number of pairs such that nums[j] - j == nums[i] - i
        Map<Integer, Long> freq = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int k = nums[i] - i;
            long existing_good_pairs = freq.getOrDefault(k, 0L);
            tot_good_pairs += existing_good_pairs;
            freq.put(k, existing_good_pairs + 1L);
        }

        // the no. of bad pairs is the total number of pairs subtracted by 
        // the number of other pairs
        return ((n * (n - 1)) >> 1) - tot_good_pairs;
    }
}