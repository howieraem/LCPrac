/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
#include <bits/stdc++.h>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, const unordered_set<string>& dict) {
        auto cached_it = memo.find(s);
        if (cached_it != memo.end()) {
            return cached_it->second;
        }
        vector<string> res;
        if (dict.find(s) != dict.end()) {
            res.push_back(s);
        }
        for (int i = 1; i < s.size(); ++i) {
            string w = s.substr(i);
            if (dict.find(w) != dict.end()) {
                string rest = s.substr(0, i);
                vector<string> sub_res = dfs(rest, dict);
                for (auto& x : sub_res) {
                    x.append(" ");
                    x.append(w);
                    res.push_back(x);
                }
            }
        }
        memo[s] = res;
        return res;
    }

public:
    // DFS with memo
    // T: O(m ^ n), m := len(wordDict), n := len(s)
    // S: O(m ^ n) memo
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
};
// @lc code=end

