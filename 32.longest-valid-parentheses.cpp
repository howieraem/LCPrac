/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include <algorithm>
#include <stack>
#include <string>

using std::max;
using std::stack;
using std::string;

// @lc code=start
class Solution {
public:
    /*
    // iterate string once
    // T: O(N)
    // S: O(N)
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk; // stack of indices
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')  stk.push(i);
            else {
                stk.pop();
                if (stk.size()) {
                    ans = max(ans, i - stk.top());
                } else {
                    stk.push(i);    // stack is empty, didn't match a '('
                }
            }
        }
        return ans;
    }
    */

    // iterate string twice
    // T: O(N)
    // S: O(1)
    int longestValidParentheses(string s) {
        const int n = s.size();
        int ans = 0, l = 0, r = 0;

        // iterate from left to right
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')  ++l;
            else  ++r;

            if (l == r)  ans = max(ans, r << 1);    // r * 2
            else if (l < r)  l = r = 0;  // reset if there are more ')' than '(' 
        }

        l = r = 0;
        // iterate from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(')  ++l;
            else  ++r;

            if (l == r)  ans = max(ans, l << 1);    // l * 2
            else if (l > r)  l = r = 0;  // reset if there are more '(' than ')'
        }
        return ans;
    }
};
// @lc code=end

