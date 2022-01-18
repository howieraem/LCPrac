/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
#include <string>
#include <unordered_map>
#include <vector>

using std::stoi;
using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * 2 ^ n), n := len(expression)
    // S: ? (memorization involved)
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return helper(expression, memo);
    }

private:
    vector<int> helper(string expr, unordered_map<string, vector<int>> &memo) {
        vector<int> res;
        const int n = expr.size();
        for (int i = 0; i < n; ++i) {
            const char c = expr[i];
            bool b1 = (c == '+'), b2 = (c == '-'), b3 = (c == '*'); 
            if (b1 || b2 || b3) {
                vector<int> lr, rr;
                string ls = expr.substr(0, i), rs = expr.substr(i + 1);
                if (memo.find(ls) != memo.end()) {
                    lr = memo[ls];
                } else {
                    lr = helper(ls, memo);
                }
                if (memo.find(rs) != memo.end()) {
                    rr = memo[rs];
                } else {
                    rr = helper(rs, memo);
                }

                for (const auto &l : lr) {
                    for (const auto &r : rr) {
                        if (b1) {
                            res.push_back(l + r);
                        } else if (b2) {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }

        if (res.empty()) {
            // expr is a pure number
            res.push_back(stoi(expr));
        }
        memo[expr] = res;
        return res;
    }
};
// @lc code=end

