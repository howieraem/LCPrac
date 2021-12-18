/*
 * @lc app=leetcode id=422 lang=cpp
 *
 * [422] Valid Word Square
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * l), n := len(words), l := avg(len(w) for w in words)
    // S: O(1)
    bool validWordSquare(vector<string>& words) {
        const int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= n || words[j].size() <= i || words[j][i] != words[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

