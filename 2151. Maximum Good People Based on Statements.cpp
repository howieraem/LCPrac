/*
 * @lc app=leetcode id=2151 lang=cpp
 *
 * [2151] Maximum Good People Based on Statements
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // Explores all possibilities of good/bad person combinations and check their validities.
    // T: O(n ^ 2 * 2 ^ n)
    // S: O(n)
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        const int n = statements.size();
        string cur = "";
        backtrack(statements, cur, 0, 0, ans, n);
        return ans;
    }

private:
    static void backtrack(const vector<vector<int>> &ss, string &cur, int i, int cnt, int &ans, const int &n) {
        if (i == n) {
            if (valid(ss, cur, n)) {
                ans = max(ans, cnt);
            }
            return;
        }
        cur.push_back('0');  // try guessing bad
        backtrack(ss, cur, i + 1, cnt, ans, n);
        cur.back() = '1';   // try guessing good
        backtrack(ss, cur, i + 1, cnt + 1, ans, n);
        cur.pop_back();
    }
    
    // T: O(n ^ 2)
    static bool valid(const vector<vector<int>> &ss, string &cur, const int &n) {
        for (int i = 0; i < n; ++i) {
            if (cur[i] == '1') {
                for (int j = 0; j < n; ++j) {
                    if (ss[i][j] != 2 && ss[i][j] != cur[j] - '0') {
                        // The statement is found inconsistent, so the current number of
                        // good people is wrong.
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
