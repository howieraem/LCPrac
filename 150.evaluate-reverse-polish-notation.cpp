/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int evalRPN(const vector<string>& tokens) {
        std::stack<int> stk;
        int a, b;
        for (const auto& s : tokens) {
            if (s == "+") {
                a = stk.top(); stk.pop();
                b = stk.top(); stk.pop();
                stk.push(b + a);
            } else if (s == "-") {
                a = stk.top(); stk.pop();
                b = stk.top(); stk.pop();
                stk.push(b - a);
            } else if (s == "*") {
                a = stk.top(); stk.pop();
                b = stk.top(); stk.pop();
                stk.push(b * a);
            } else if (s == "/") {
                a = stk.top(); stk.pop();
                b = stk.top(); stk.pop();
                stk.push(b / a);
            } else {
                stk.push(std::stoi(s));
            }
        }
        return stk.top();
    }
};
// @lc code=end

