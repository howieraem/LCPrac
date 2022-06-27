/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n * l), l := avg length of string at a step
    // S: O(l)
    string countAndSay(int n) {
        string res = "1";
        while (n-- > 1) {
            res = helper(res);
        }
        return res;
    }

private:
    string helper(const string& s) {
        string res;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == c) {
                ++cnt;
            } else {
                res.append(std::to_string(cnt)).push_back(c);
                c = s[i];
                cnt = 1;
            }
        }
        // don't forget the last kind of digit and its count
        res.append(std::to_string(cnt)).push_back(c);
        return res;
    }
};
// @lc code=end

