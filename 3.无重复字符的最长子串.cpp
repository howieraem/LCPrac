/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.size()) {
            char c = s[r];
            ++r;
            ++window[c];
            while (window[c] > 1) {
                char d = s[l];
                ++l;
                --window[d];
            }
            res = max()
        }
    }
};
// @lc code=end

