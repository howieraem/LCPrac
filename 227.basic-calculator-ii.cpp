/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int calculate(string s) {
        const int n = s.size();
        stack<int> stk;
        char pre_op = '+';
        int cur_num = 0, top;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            bool is_digit = isdigit(c);
            if (is_digit) {
                cur_num = cur_num * 10 + (c - '0');
            } 
            
            if ((!is_digit && c != ' ') || i == n - 1) {
                // c denotes an operator, or i has reached the end of s
                switch (pre_op) {
                    case '+':
                        stk.push(cur_num);
                        break;
                    case '-':
                        stk.push(-cur_num);
                        break;
                    case '*':
                        top = stk.top(); stk.pop(); 
                        stk.push(top * cur_num);
                        break;
                    case '/':
                        top = stk.top(); stk.pop();
                        stk.push(top / cur_num);
                        break;
                }
                cur_num = 0;
                pre_op = c;
            }
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top(); stk.pop();
        }
        return ans;
    }
};
// @lc code=end

