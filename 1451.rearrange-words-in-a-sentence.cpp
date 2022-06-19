/*
 * @lc app=leetcode id=1451 lang=cpp
 *
 * [1451] Rearrange Words in a Sentence
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(l * log(l)), l := the number of word lengths
    // S: O(l)
    string arrangeWords(string text) {
        text[0] = std::tolower(text[0]);
        std::stringstream input(text);

        string w;
        std::map<int, string> mp;
        while (input >> w) {
            mp[w.size()].append(w).push_back(' ');
        }

        string res;
        res.reserve(text.size() + 1);
        for (const auto& p : mp) {
            res.append(p.second);
        }
        res.pop_back(); // remove the trailing space
        res[0] = std::toupper(res[0]);
        return res;
    }
};
// @lc code=end

