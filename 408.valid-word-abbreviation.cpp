/*
 * @lc app=leetcode id=408 lang=cpp
 *
 * [408] Valid Word Abbreviation
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(max(m, n)), m := len(word), n := len(abbr)
    // S: O(1)
    bool validWordAbbreviation(std::string word, std::string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) {
                ++i, ++j;
                continue;
            }
            if (abbr[j] <= '0' || abbr[j] > '9') {
                // word[i] != abbr[j] and abbr[j] is not a positive digit
                return false;
            }

            // abbr[j] is a non-zero digit. Keep accumulating until abbr[j] is not a digit
            int start = j, num = 0;
            while (j < abbr.size() && abbr[j] >= '0' && abbr[j] <= '9') {
                num = num * 10 + (abbr[j] - '0');
                ++j;
            }
            i += num;   // shift i to the corresponding index
        }
        return i == word.size() && j == abbr.size();
    }
};
// @lc code=end

