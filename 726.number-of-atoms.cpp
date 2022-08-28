/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */
#include <bits/stdc++.h>

using std::map;
using std::stack;
using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n)), n := len(formula)
    // S: O(n)
    string countOfAtoms(string formula) {
        // Code will be cleaner if reversing formula first.
        // Though iterating backwards also works, but that 
        // might involve unnecessary string copying when 
        // concatenating characters.
        std::reverse(formula.begin(), formula.end());

        // keep lexicographical order of elements
        map<string, int> cnts;

        string elem;
        int cur_cnt = 1;
        stack<int> stk;
        stk.push(cur_cnt);
        
        int i = 0;
        while (i < formula.size()) {
            char& c = formula[i];
            if (std::isdigit(c)) {
                int cnt = 0, base = 1;
                while (std::isdigit(c)) {
                    // Remember, digits are also reversed
                    cnt += (c - '0') * base;
                    base *= 10;
                    c = formula[++i];
                }
                cur_cnt = cnt;
                continue;  // no need to ++i again
            } else if ('a' <= c && c <= 'z') {
                // lowercase
                elem.push_back(c);
            } else if ('A' <= c && c <= 'Z') {
                // uppercase, first char of an element
                elem.push_back(c);
                
                // Reverse element characters back
                std::reverse(elem.begin(), elem.end());
                cnts[elem] += cur_cnt * stk.top();
                cur_cnt = 1;
                elem.clear();
            } else if (c == ')') {
                stk.push(cur_cnt * stk.top());
                cur_cnt = 1;
            } else {  // c == '('
                stk.pop();
            }
            ++i;
        }

        string res;
        res.reserve(cnts.size());
        for (const auto& p : cnts) {
            res.append(p.first);
            if (p.second > 1) {
                res.append(std::to_string(p.second));
            }
        }
        return res;
    }
};
// @lc code=end

