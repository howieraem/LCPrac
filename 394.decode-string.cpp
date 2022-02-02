/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include <cctype>
#include <stack>
#include <string>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    string decodeString(string s) {
        string cur;
        int mult;
        stack<pair<int, string>> stk;

        for (const auto &c : s) {
            if (c == '[') {
                stk.push({mult, cur});
                mult = 0;
                cur.clear();
            } else if (c == ']') {
                auto [outer_mult, outer] = stk.top(); stk.pop();
                while (outer_mult--) {
                    outer += cur;
                }
                cur = outer;
            } else if (isdigit(c)) {
                mult = mult * 10 + (c - '0');
            } else {
                cur.push_back(c);
            }
        }
        return cur;
    }
};
// @lc code=end

