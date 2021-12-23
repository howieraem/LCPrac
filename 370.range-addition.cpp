/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n + m), n := length, m := len(updates)
    // S: O(n)
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for (const auto &update : updates) {
            res[update[0]] += update[2];
            if (update[1] < length - 1) {
                // If there is no element after the end index update[1],
                // no need to subtract.
                res[update[1] + 1] -= update[2];
            }
        }

        // Convert to prefix sum form so that the changes of values at the
        // start indices and the end indices above take effects.
        // For example, if we set the update value at the start index,
        // then all subsequent prefix sums will take it into account,
        // unless at the index after end index an negative update value
        // is set.
        for (int i = 1; i < length; ++i) {
            res[i] += res[i - 1];
        }
        return res;
    }
};
// @lc code=end

