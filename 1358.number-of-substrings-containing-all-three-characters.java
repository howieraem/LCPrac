/*
 * @lc app=leetcode id=1358 lang=java
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
    /*
    // Solution 1: sliding window + two pointers + hash map
    // T: O(n)
    // S: O(alpha_sz), alpha_sz := 3
    public int numberOfSubstrings(String s) {
        final int n = s.length();
        int windowed_cnts[] = {0, 0, 0};
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            ++windowed_cnts[s.charAt(r) - 'a'];

            while (windowed_cnts[0] > 0 && windowed_cnts[1] > 0 && windowed_cnts[2] > 0) {
                ans += n - r;  // count eligible substrings (all chars to the right of `r` can contribute)
                --windowed_cnts[s.charAt(l++) - 'a'];
            }

            // Equivalently
            // ans += l;
        }
        return ans;
    }
    */

    // Solution 2: three pointers + greedy + hash map
    // T: O(n)
    // S: O(alpha_sz), alpha_sz := 3
    public int numberOfSubstrings(String s) {
        final int n = s.length();
        int last_occur[] = {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            last_occur[s.charAt(i) - 'a'] = i;

            // When the substring ending index is i,
            // in order to include all 3 chars, the 
            // corresponding left index has to be 
            // min(last_occur)
            ans += Math.min(last_occur[0], Math.min(last_occur[1], last_occur[2])) + 1;
        }
        return ans;
    }
}
// @lc code=end

