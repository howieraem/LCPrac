/*
 * @lc app=leetcode id=591 lang=cpp
 *
 * [591] Tag Validator
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    bool isValid(string code) {
        std::stack<string> stk;
        for (int i = 0; i < code.size(); ++i) {
            if (i && stk.empty()) return false;

            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                i = code.find("]]>", j);
                if (i < 0) return false;
                i += 2;
            } else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find('>', j);
                if (stk.empty() || code.substr(j, i - j) != stk.top()) return false;
                stk.pop();
            } else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find('>', j);
                if (i < 0 || i == j || i - j > 9) return false;
                for (int k = j; k < i; ++k) {
                    if (!std::isupper(code[k])) return false;
                }
                stk.push(code.substr(j, i - j));
            }
        }
        return stk.empty();
    }
};
// @lc code=end

