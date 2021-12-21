/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    string reverseParentheses(string s) {
        const int n = s.size();
        stack<int> open;
        vector<int> pairs(n);

        // Find pairwise indices of parenthese
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                int j = open.top(); open.pop();
                pairs[i] = j;
                pairs[j] = i;
            }
        }

        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pairs[i];   // jump to the paired position
                d = -d;     // reverse the order of iteration
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end

