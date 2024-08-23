/*
 * @lc app=leetcode id=1151 lang=cpp
 *
 * [1151] Minimum Swaps to Group All 1's Together
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int minSwaps(vector<int>& data) {
        const int n = data.size();
        if (n < 3) {
            return 0;
        }

        int tot = 0;
        for (int x : data) {
            tot += (x == 1);
        }
        // The total number of 1's is the target window size

        int l = 0;
        int r = 0;
        int window_cnt = 0;
        int max_window_cnt = 0;
        while (r < n) {
            while (r < n && r - l < tot) {
                // right bound slides
                if (data[r++] == 1) {
                    ++window_cnt;
                }
            }

            max_window_cnt = std::max(max_window_cnt, window_cnt);

            if (data[l++] == 1) {
                // left bound slides
                --window_cnt;
            }
        }

        // The number of swaps equals the diff between target window size 
        // and max count of 1 in any window
        return tot - max_window_cnt;
    }
};
// @lc code=end

