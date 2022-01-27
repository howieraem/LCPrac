/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
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
    string minRemoveToMakeValid(string s) {
        const int n = s.size();
        bool keep_flags[n];
        fill_n(keep_flags, n, true);

        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                // not match a ')' yet
                stk.push(i);
                keep_flags[i] = false;
            } else if (s[i] == ')') {
                if (stk.empty()) { 
                    // cannot match any '('
                    keep_flags[i] = false;
                } else {
                    int pre_idx = stk.top(); stk.pop();
                    keep_flags[pre_idx] = true;
                }
            }
        }

        string res;
        for (int i = 0; i < n; ++i) {
            if (keep_flags[i])  res.push_back(s[i]);
        }
        return res;
    }
    */

    // Solution 2: in-place modification
    // T: O(n)
    // S: O(n)
#define REMOVE_SIGN '*'
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (stk.empty()) {
                    // Could not match any '('
                    s[i] = REMOVE_SIGN;
                } else {
                    stk.pop();
                }
            }
        }

        while (stk.size()) {
            // Find any '(' without matching ')'
            s[stk.top()] = REMOVE_SIGN; stk.pop();
        }

        s.erase(remove(s.begin(), s.end(), REMOVE_SIGN), s.end());
        return s;
    }
};
// @lc code=end

