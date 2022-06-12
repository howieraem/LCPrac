/*
 * @lc app=leetcode id=1562 lang=cpp
 *
 * [1562] Find Latest Group of Size M
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int findLatestStep(vector<int>& arr, int m) {
        const int N = arr.size();
        if (m == N)  return N;  // trivial
        int ans = -1;
        
        vector<int> lengths(N + 2);

        for (int i = 0; i < N; ++i) {
            int a = arr[i];

            // Check the length of group on the left and
            // also the length of group on the right
            int left = lengths[a - 1], right = lengths[a + 1];
            if (left == m || right == m) {
                ans = i;
            }

            // When the bit at arr[i] is 1, the left and right groups are connected.
            // The length value is updated on the leftmost and the rightmost bit of the group.
            // The length values inside the group may be outdated (but it is fine because
            // the group sizes are expanding?)
            lengths[a - left] = lengths[a + right] = left + right + 1;
        }
        return ans;
    }
};
// @lc code=end

