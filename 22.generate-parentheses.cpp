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
    // T: O(2 ^ (2n))
    // S: O(n)
    static void backtrack(string path, int nLeft, int nRight, vector<string> &res) {
        if (nLeft > nRight) {
            // As below we are adding the left parethesis first, need to ensure 
            // the number of right paretheses do not exceed the number of left
            // paretheses.
            return;
        }
        if (!(nLeft || nRight)) {
            res.push_back(path);
            return;
        }
        if (nLeft) {
            backtrack(path + '(', nLeft - 1, nRight, res);
        }
        if (nRight) {
            backtrack(path + ')', nLeft, nRight - 1, res);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", n, n, res);
        return res;
    }
};
// @lc code=end

