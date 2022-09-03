/*
 * @lc app=leetcode id=1592 lang=cpp
 *
 * [1592] Rearrange Spaces Between Words
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    string reorderSpaces(string text) {
        vector<string> words;
        std::stringstream ss(text);
        string w;
        int n = text.size(), n_letters = 0;
        while (ss >> w) {
            n_letters += w.size();
            words.push_back(std::move(w));
        }
        
        int n_spaces = n - n_letters;
        if (n_spaces == 0) return text;
        int nw = words.size();
        int n_spaces_between = nw > 1 ? n_spaces / (nw - 1) : 1;

        string res;
        res.reserve(n);
        // Process words except the last one
        for (int i = 0; i < nw - 1; ++i) {
            res.append(words[i]).append(string(n_spaces_between, ' '));
            n_spaces -= n_spaces_between;
        }
        // Process the last word
        res.append(words.back()).append(string(n_spaces, ' '));
        return res;
    }
};
// @lc code=end

