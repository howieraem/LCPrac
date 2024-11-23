/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    // backtracking
    // T: O(2 ^ (2n)) as there are 2 recursive calls in backtrack() and it requires 2n steps to get one result
    // S: O(n)
    static void backtrack(string& path, int l_remain, int r_remain, vector<string>& res) {
        if (l_remain > r_remain) {
            // As below we are adding the left parenthesis first, need to ensure 
            // the number of right parentheses do not exceed the number of left
            // parentheses (i.e., N - r_remain <= N - l_remain).
            // Example: we want a left parenthesis to appear in front of
            // its corresponding right parenthesis. Without this, 
            // results will contain things like ")))((("
            return;
        }
        if (!(l_remain > 0 || r_remain > 0)) {
            // l_remain == r_remain == 0
            // path.size() == N * 2
            res.push_back(path);
            return;
        }
        // As `path + '('` or `path + ')'` will create a new string,
        // space complexity is better with passing `path` by reference 
        // and using push_back() and pop_back(). 
        if (l_remain > 0) {
            // backtrack(path + '(', l_remain - 1, r_remain, res);
            path.push_back('(');
            backtrack(path, l_remain - 1, r_remain, res);
            path.pop_back();
        }
        if (r_remain > 0) {
            // backtrack(path + ')', l_remain - 1, r_remain, res);
            path.push_back(')');
            backtrack(path, l_remain, r_remain - 1, res);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrack(path, n, n, res);
        return res;
    }
};
// @lc code=end

