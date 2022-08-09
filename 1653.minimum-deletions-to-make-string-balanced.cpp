/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int minimumDeletions(string s) {
        const int n = s.size();
        int cnt_a = 0;
        for (const auto& c : s) {
            cnt_a += c == 'a';
        }
        int cnt_b = 0, ans = n;
        for (const auto& c : s) {
            cnt_a -= c == 'a';
            ans = std::min(ans, cnt_a + cnt_b);
            cnt_b += c == 'b';
        }
        return ans;
    }
};
// @lc code=end

