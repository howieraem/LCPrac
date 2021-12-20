/*
 * @lc app=leetcode id=1494 lang=cpp
 *
 * [1494] Parallel Courses II
 */
#include <algorithm>
#include <vector>

using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
    // Main difference from Q1136: limited number of courses in each semester
    // T: O(n * 2 ^ n)
    // S: O(2 ^ n)
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        // pre[i]: the bit representation of all dependencies of course i
        vector<int> pre(n);

        for (auto &e : relations) {
            --e[0]; --e[1]; // convert 1-indexed to 0-indexed
            pre[e[1]] |= (1 << e[0]);
        }

        // i is the bit representation of a combination of courses. 
        // dp[i] is the minimum days to complete all the courses.
        const int max = 1 << n;
        vector<int> dp(max, n);
        dp[0] = 0; // base case: need 0 time to finish 0 course

        for (int i = 0; i < max; ++i) {
            // Find out ex, the bit representation of the all courses that we can study now.
            // Since we have i and pre[j], we know course j can be studied if i contains all its prerequisites ((i & pre[j]) == pre[j])
            int ex = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & pre[j]) == pre[j])  ex |= (1 << j);
            }
            // We don't want to study anything from what we have already studied (i represents set of courses that we have studied)
            ex &= ~i;

            // Enumerate all the bit 1 combinations of ex.
            // This is a typical method to enumerate all subsets of a bit representation:
            for (int s = ex; s != 0; s = (s - 1) & ex) {
                if (__builtin_popcount(s) <= k) {
                    // Any combination of courses (if less or equal than k) could be studied at this step.
                    // i | s means what we combine already studied courses before with courses we can study at the current step.
                    dp[i | s] = min(dp[i | s], dp[i] + 1);
                }
            }
        }
        // dp.back is the state when we studied all the courses. e.g. 11111...
        return dp.back(); 
    }
};
// @lc code=end

