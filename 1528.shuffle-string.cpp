/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // Cyclic sort to optimize space
    // It works because indices values are between 0 and n - 1
    // T: O(n)
    // S: O(1)
    string restoreString(string& s, vector<int>& indices) {
        for (int i = 0; i < indices.size(); ++i) {
            while (indices[i] != i) {
                // place indices[i] at the correct index
                std::swap(s[i], s[indices[i]]);
                std::swap(indices[i], indices[indices[i]]);
            }
        }
        // at this point, indices should become [0, 1, ..., n - 1] which match the natural index order
        return s;
    }
};
// @lc code=end

