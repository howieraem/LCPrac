/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */
#include <string>

// @lc code=start
class Solution {
public:
    // T: O(m + n)
    // S: O(s)
    string customSortString(string order, string s) {
        int cnt[26] {};
        for (const char& c : s) {
            ++cnt[c - 'a'];
        }

        std::string ans;
        for (const char& c : order) {
            while (cnt[c - 'a']-- > 0) {
                ans.push_back(c);
            }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            while (cnt[c - 'a']-- > 0) {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
// @lc code=end

