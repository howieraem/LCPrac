import java.util.List;

class Solution {
    // Boyer-Moore Majority Vote Algo + Math
    // T: O(n)
    // S: O(1)
    public int minimumIndex(List<Integer> nums) {
        final int n = nums.size();
        if (n == 0) {
            return -1;
        }

        // Find the dominant element of the entire array
        int majority = nums.get(0);
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            Integer x = nums.get(i);
            if (x == majority) {
                ++cnt;
            } else {
                --cnt;

                if (cnt == 0) {
                    majority = x;
                    cnt = 1;
                }
            }
        }

        // Check where to split for the dominant element found 
        cnt = 0;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (nums.get(i) == majority) {
                ++cnt;
                
                // To make the split valid, the number of dominant element occurrences
                // must be greater than (iterated array length + 1) / 2
                if (cnt > ((i + 1) >> 1) && ans == -1) {
                    ans = i;
                }
            }
        }

        return cnt > ((n + 1) >> 1) ? ans : -1;
    }
}