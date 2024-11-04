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
    // Memoized DFS + divide and conquer
    // T: O(n * 2 ^ n), n := len(expression)
    // S: O(2 ^ n)
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;  // k: expression (substring), v: list of possible results
        return helper(expression, memo);
    }

private:
    vector<int> helper(string expr, unordered_map<string, vector<int>> &memo) {
        auto cache_it = memo.find(expr);
        if (cache_it != memo.end()) {
            return cache_it->second;
        }

        vector<int> res;
        
        // split expression by operators
        for (int i = 0; i < expr.size(); ++i) {
            const char& c = expr[i];
            bool is_add = (c == '+'); 
            bool is_minus = (c == '-'); 
            bool is_mult = (c == '*'); 
            if (is_add || is_minus || is_mult) {
                // Divide
                // exclude current operator char, and merge left and right substring results 
                vector<int> left_res = helper(expr.substr(0, i), memo);
                vector<int> right_res = helper(expr.substr(i + 1), memo);

                // Conquer
                // operate on every pair of left_res and right_res elements
                for (const auto &l : left_res) {
                    for (const auto &r : right_res) {
                        if (is_add) {
                            res.push_back(l + r);
                        } else if (is_minus) {
                            res.push_back(l - r);
                        } else if (is_mult) {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }

        // No operator found
        if (res.empty()) {
            // expr is a pure number (base case)
            res.push_back(stoi(expr));
        }
        memo[expr] = res;
        return res;
    }
};
// @lc code=end

