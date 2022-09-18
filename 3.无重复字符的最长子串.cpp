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
    // S: O(s), s := alphabet size
    int lengthOfLongestSubstring(string s) {
        const int LIMIT = 1;  // changing this number will make the solution generalize to a specified number of repeating chars

        // unordered_map<char, int> window;
        int window[128] {0};
        
        int ans = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            char& c = s[r];
            ++window[c];

            // If including the current rightmost character there is a duplicate,
            // shift the left boundary and update the frequency.
            while (window[c] > LIMIT) {
                char& d = s[l++];
                --window[d];
            }

            // Update maximum length found
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end

