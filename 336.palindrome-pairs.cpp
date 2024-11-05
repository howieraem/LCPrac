/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    bool is_palindrome(const std::string_view& s) {
        return std::equal(s.begin(), s.end(), s.rbegin());
    }

public:
    // Hash map + two pointers
    // T: O(n * l ^ 2), n := len(words), l := avg(len(w) for w in words)
    // S: O(n * l)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int n = words.size();

        std::unordered_map<std::string_view, int> word_to_idx;
        for (int i = 0; i < n; ++i) {
            word_to_idx[words[i]] = i;
        }

        vector<vector<int>> res;
        res.reserve(((n * (n - 1)) >> 1));

        for (int i = 0; i < n; ++i) {
            // Reverse the word
            string w = words[i];
            std::reverse(w.begin(), w.end());
            const int l = w.size();
            std::string_view wv(w);

            // Each string can be divided at a particular index into two substrings,
            // prefix and suffix. We first check whether prefix is a palindrome and 
            // if so it is possible to form a new palindrome by using this prefix.
            // To check whether the palindrome can be formed with the prefix, we 
            // need to check whether the reverse of suffix is present in the map.
            for (int k = 0; k <= l; ++k) {
                auto it = word_to_idx.find(wv.substr(0, k));
                // Since w has been reversed, wv.substr(k) is the original prefix.
                // If the prefix is a palindrome, then reversing won't affect it.
                // Note that an empty prefix is also considered a palindrome.
                // Example 1: k = 3, w = "cba", wv = "abc", wv[:k] = "abc", "abc" in map, wv[k:] = "" is palindromic 
                // Example 2: k = 1, w = "lls", wv = "sll", wv[:k] = "s", "s" in map, wv[k:] = "ll" is palindromic 
                if (it != word_to_idx.end() && it->second != i && is_palindrome(wv.substr(k))) {
                    res.push_back({it->second, i});
                }
            }

            // The rule above also applies to forming a palindrome with the suffix.
            for (int k = 0; k < l; ++k) {
                auto it = word_to_idx.find(wv.substr(l - k, k));
                if (it != word_to_idx.end() && it->second != i && is_palindrome(wv.substr(0, l - k))) {
                    res.push_back({i, it->second});
                }
            }
        }
        return res;
    }
};
// @lc code=end

