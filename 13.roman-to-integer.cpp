/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int romanToInt(std::string s) {
        int ans = 0;
        int preNum = getInt(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            int num = getInt(s[i]);
            if (num > preNum) {
                // example: IV, IX
                ans -= preNum;
            } else {
                // In other cases, larger digits will be on the left
                ans += preNum;
            }
            preNum = num;
        }
        ans += preNum;  // don't forget the last one
        return ans;
    }

    static int getInt(const char &c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
// @lc code=end

