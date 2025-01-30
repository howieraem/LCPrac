/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // Hash Map
    // T: O(n)
    // S: O(alpha_size)
    int firstUniqChar(string s) {
        int cnt[26] {0};
        for (const auto &c : s) {
            ++cnt[c - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

