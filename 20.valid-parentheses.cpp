/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <stack>

using std::stack;

// @lc code=start
class Solution {
public:
    // T: O(N)
    // S: O(N)
    bool isValid(string s) {
        stack<char> stk;
        for (const auto &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty())  return false;
                auto sc = stk.top();
                if ((c == ')' && sc != '(') || 
                    (c == ']' && sc != '[') || 
                    (c == '}' && sc != '{'))
                    return false;
                stk.pop();
            }       
        }
        return stk.empty();
    }
};
// @lc code=end
