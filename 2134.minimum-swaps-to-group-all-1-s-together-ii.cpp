/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int minSwaps(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) {
            return 0;
        }

        int tot = 0;
        for (int x : nums) {
            tot += (x == 1);
        }
        // The total number of 1's is the target window size

        int l = 0;
        int r = 0;
        int window_cnt = 0;
        int max_window_cnt = 0;

        // circular array simple trick: double upper bound, and use i % n for indexing
        int upper = (n << 1);
        while (r < upper) {
            while (r < upper && (r - l) % n < tot) {
                // right bound slides
                if (nums[r++ % n] == 1) {
                    ++window_cnt;
                }
            }

            max_window_cnt = std::max(max_window_cnt, window_cnt);

            if (nums[l++ % n] == 1) {
                // left bound slides
                --window_cnt;
            }
        }
        // Alternative approach: instead of shifting l and r pointers based on conditions,
        // use a fixed window size equal to tot, i.e. l = [0...n), r = (l + tot) % n

        // The number of swaps equals the diff between target window size 
        // and max count of 1 in any window
        return std::max(tot - max_window_cnt, 0);
    }
};
// @lc code=end

