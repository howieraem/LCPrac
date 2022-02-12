/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n), m := average word length, n := the number of words
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j;
            for (j = 0; j < strs[i].size() && ans[j] == strs[i][j]; ++j);
            ans = ans.substr(0, j);
            if (ans.empty())  return ans;
        }
        return ans;
    }
};
// @lc code=end

