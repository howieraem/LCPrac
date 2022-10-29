/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(1)
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < (n << 1) - 1; ++i) {
            // for each char, try to expand on both sides to form palindromes
            int l = i >> 1, r = (i >> 1) + (i & 1);
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

