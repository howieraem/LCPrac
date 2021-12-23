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
    // Sliding window
    // T: O(n)
    // S: O(1)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.size()) {
            // Shift the right boundary
            char c = s[r];
            ++r;
            ++window[c];

            // If after including the rightmost character there is a duplicate,
            // shift the left boundary and update the frequency.
            while (window[c] > 1) {
                char d = s[l];
                ++l;
                --window[d];
            }

            // Update maximum length found
            ans = max(ans, r - l);
        }
        return ans;
    }
};
// @lc code=end

