/*
 * @lc app=leetcode id=2232 lang=cpp
 *
 * [2232] Minimize Result by Adding Parentheses to Expression
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 3) due to substr copy
    // S: O(n) due to substr copy
    string minimizeResult(string expression) {
        int idx_of_plus_symbol = expression.find('+');
        string x1 = expression.substr(0, idx_of_plus_symbol),
               x2 = expression.substr(idx_of_plus_symbol + 1);

        int cur_min = INT_MAX;
        string ans;

        for (int l = 0; l < x1.size(); ++l) {  // idx of the left parenthesis
            for (int r = 0; r < x2.size(); ++r) { // idx of the right parenthesis
                // Place the parentheses, so that the expression becomes a(c + d)b
                string a = x1.substr(0, l), b = x2.substr(r + 1),
                       c = x1.substr(l), d = x2.substr(0, r + 1);

                int ax = a.empty() ? 1 : std::stoi(a);
                int bx = b.empty() ? 1 : std::stoi(b);
                int val = ax * (std::stoi(c) + std::stoi(d)) * bx;
                if (cur_min > val) {
                    cur_min = val;
                    ans = a + "(" + c + "+" + d + ")" + b;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
