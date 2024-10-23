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
    // S: O(m), or O(1) if erase inplace
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < strs[i].size() && ans[j] == strs[i][j]) {
                ++j;
            }
            // ans = ans.substr(0, j);
            ans.erase(ans.begin() + j, ans.end());
            if (ans.empty()) {
                return ans;
            }
        }
        return ans;
    }
};
// @lc code=end

