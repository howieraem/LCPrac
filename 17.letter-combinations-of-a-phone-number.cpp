/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <bits/stdc++.h>

using std::string;
using std::string_view;
using std::vector;

// @lc code=start
class Solution {
    const string_view mapping[10] {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };  // k: digit (used as index), v: chars

public:
    /*
    // Iterative solution
    // T: O(4 ^ len(digits)) as one digit corresponds to at most 4 letters
    // S: O(len(digits)) for copying intermediate results
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        res.push_back("");

        for (const auto& digit : digits) {
            vector<string> intermediate_res;
            for (const auto& letter : mapping[digit - '0']) {
                for (const auto& prev_s : res) {
                    intermediate_res.push_back(prev_s + letter);
                }
            }
            res.swap(intermediate_res);
        }
        return res;
    }
    */

    // Recursive solution (backtracking)
    // T: O(4 ^ len(digits)) as one digit corresponds to at most 4 letters
    // S: O(len(digits)) for copying intermediate results
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string path(digits.size(), '*');
        dfs(digits, 0, path, res);
        return res;
    }

    void dfs(const string& digits, int i, string& path, vector<string>& res) {
        if (i == digits.size()) {
            res.push_back(path);
            return;
        }
        // proceed with children
        for (const auto& letter : mapping[digits[i] - '0']) {
            path[i] = letter;
            dfs(digits, i + 1, path, res);
        }
    }
};
// @lc code=end

