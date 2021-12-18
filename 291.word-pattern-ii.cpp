/*
 * @lc app=leetcode id=291 lang=cpp
 *
 * [291] Word Pattern II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * nCm), m := len(pattern), n := len(s), m <= n
    // S: O(m * n)
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> mp;  // key is pattern character, value is word (substring of s)
        unordered_set<string> vis;
        return backtrack(s, 0, pattern, 0, mp, vis);
    }

private:
    bool backtrack(string s, int i, string p, int j, unordered_map<char, string> &mp, unordered_set<string> &vis) {
        bool endi = (i == s.size()),
             endj = (j == p.size());
        if (endi || endj)  return endi && endj;
        const char c = p[j];

        // If the current pattern character exists
        if (mp.find(c) != mp.end()) {
            string str = mp[c];
            // Look ahead and try matching s[i, i + len(str)] to str
            if (s.substr(i, str.size()) != str) {
                return false;
            }
            return backtrack(s, i + str.size(), p, j + 1, mp, vis);
        }

        for (int k = i; k < s.size(); ++k) {
            string ss = s.substr(i, k - i + 1);
            if (vis.find(ss) != vis.end()) {
                continue;
            }

            mp[c] = ss;
            vis.insert(ss);

            if (backtrack(s, k + 1, p, j + 1, mp, vis)) {
                return true;
            }

            // undo
            mp.erase(c);
            vis.erase(ss);
        }
        return false;
    }
};
// @lc code=end

