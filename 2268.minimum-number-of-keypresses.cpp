/*
 * @lc app=leetcode id=2268 lang=cpp
 *
 * [2268] Minimum Number of Keypresses
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // Greedy: less typing for the more frequent characters
    // T: O(n + s * log(s))
    // S: O(s)
    int minimumKeypresses(const string& s) {
        vector<int> cnts(26);
        for (const char& c : s) {
            ++cnts[c - 'a'];
        }
        std::sort(cnts.begin(), cnts.end());
        int ch = 0, ans = 0;
        for (int i = 25; i >= 0; --i) {
            if (!cnts[i]) break;
            ans += (ch / 9 + 1) * cnts[i];
            ++ch;
        }
        return ans;
    }
};
// @lc code=end
