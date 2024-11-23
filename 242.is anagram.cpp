/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // Hash map
    // T: O(n + alpha_sz)
    // S: O(alpha_sz)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int count[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }

        // check if all char net counts are zero
        for (const auto &num : count) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

