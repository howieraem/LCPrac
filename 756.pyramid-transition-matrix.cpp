/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

// @lc code=start
class Solution {
    bool dfs(string bottom, const unordered_map<string, vector<char>>& mp, unordered_set<string>& invalid, int start, string next) {
        if (bottom.size() == 1) return true;  // reached the top
        if (invalid.find(bottom) != invalid.end()) return false;

        if (start == bottom.size() - 1) {
            // move to the next layer
            return dfs(next, mp, invalid, 0, "");
        }
        
        const string prefix = bottom.substr(start, 2);
        if (mp.find(prefix) != mp.end()) {
            for (const auto& c : mp.at(prefix)) {
                if (dfs(bottom, mp, invalid, start + 1, next + c)) {
                    return true;
                }
            }
        }
        invalid.insert(bottom);
        return false;
    }

public:
    // T: O(m^2 * n), m := len(bottom), n := len(allowed)
    // S: O(m + n) recursion stack and hash map
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (const auto& s : allowed) {
            mp[s.substr(0, 2)].push_back(s.back());
        }
        unordered_set<string> invalid;  // this also acts like the memo in memorized dfs
        return dfs(bottom, mp, invalid, 0, "");
    }
};
// @lc code=end

