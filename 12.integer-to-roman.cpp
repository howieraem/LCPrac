/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
    const std::vector<std::pair<std::string, int>> mp = {
        {"M", 1000},
        {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
        {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10},
        {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };

public:
    // T: O(log(num))
    // S: O(1)
    std::string intToRoman(int num) {
        std::string ans;
        for (const auto &p : mp) {
            auto& [s, v] = p;
            if (num >= v) {
                int cnt = num / v;
                num %= v;
                while (cnt--) {
                    ans += s;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

