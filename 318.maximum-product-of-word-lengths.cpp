/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * (n + alpha_size)) if alpha_size can fit in int/long bits
    // S: O(n) if alpha_size can fit in int/long bits
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);

        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (const auto& c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            masks[i] = std::move(mask);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    ans = std::max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return ans;
    }
};
// @lc code=end

