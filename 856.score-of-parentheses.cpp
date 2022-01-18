/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1
    // T: O(n)
    // S: O(n)
    int scoreOfParentheses(string s) {
        int cur = 0;
        stack<int> stk;

        for (const char &c : s) {
            if (c == '(') {
                stk.push(cur);
                cur = 0;
            } else {
                // If cur == 0, there is no inner parentheses, so add 1.
                cur += stk.top() + max(cur, 1); stk.pop();
            }
        }
        return cur;
    }
    */

    // Solution 2
    // T: O(n)
    // S: O(1)
    int scoreOfParentheses(string s) {
        int ans = 0, lvl = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++lvl;
            } else {
                --lvl;
            }

            if (s[i] == ')' && s[i - 1] == '(') {
                // Assume s is always valid.
                // If "()" encountered, the number of levels outside is known.
                ans += (1 << lvl);  // lvl * 2
            }
        }
        return ans;
    }
};
// @lc code=end

