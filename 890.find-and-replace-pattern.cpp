/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
    static string norm(string w) {
        unordered_map<char, int> f;
        for (const char &c : w) {
            if (f.find(c) == f.end()) {
                f[c] = f.size();
            }
        }
        for (int i = 0; i < w.size(); ++i) {
            w[i] = 'a' + f[w[i]];
        }
        return w;
    }

public:
    // T: O(n * l), n := len(words), l := avg(len(w) for w in words)
    // S: O(n * l)
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        const string normed = norm(pattern);
        for (const auto &w : words) {
            if (norm(w) == normed)  res.push_back(w);
        }
        return res;
    }
};
// @lc code=end

