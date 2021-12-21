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
    static void backtrack(string &path, int nLeft, int nRight, vector<string> &res) {
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
        // As path + '(' or path + ')' will create a new string,
        // space complexity is better with push_back() and 
        // pop_back(). 
        if (nLeft) {
            // backtrack(path + '(', nLeft - 1, nRight, res);
            path.push_back('(');
            backtrack(path, nLeft - 1, nRight, res);
            path.pop_back();
        }
        if (nRight) {
            // backtrack(path + ')', nLeft - 1, nRight, res);
            path.push_back(')');
            backtrack(path, nLeft, nRight - 1, res);
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

