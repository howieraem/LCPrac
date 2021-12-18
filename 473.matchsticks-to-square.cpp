/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
    static const int N = 4;

    // T: O(N ^ n), N := the number of sides, n := len(matchsticks)
    // S: O(1)
    bool backtrack(vector<int> &sides, const vector<int> &matches, int idx, int target) {
        if (idx == matches.size()) {
            // All sides must have the same length.
            for (int i = 1; i < N; ++i) {
                if (sides[i] != sides[i - 1])  return false;
            }
            return true;
        }
        for (int i = 0; i < N; ++i) {
            if (sides[i] + matches[idx] > target)  continue;  // prune

            // Pruning: no need to re-check the same side length
            int j = i - 1;
            while (j >= 0 && sides[j--] != sides[i]);
            if (j != -1)  continue;

            sides[i] += matches[idx];
            if (backtrack(sides, matches, idx + 1, target))  return true;
            sides[i] -= matches[idx];
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        // Prunes trivial cases
        if (matchsticks.size() < N)  return false;
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); ++i) {
            sum += matchsticks[i];
        }
        if (sum % N)  return false;

        // Sort matchsticks DESC to help pruning
        sort(matchsticks.begin(), matchsticks.end(), [](const int &x, const int &y) { return x > y; });
        vector<int> sides(N, 0);
        return backtrack(sides, matchsticks, 0, sum / N);
    }
};
// @lc code=end

