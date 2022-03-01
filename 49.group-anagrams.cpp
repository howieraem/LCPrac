/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(m * n), m := len(strs), n := max. length of string in strs
    // S: O(m * n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        int cnt[26];
        for (const string &s : strs) {
            fill_n(cnt, 26, 0);
            for (const auto &c : s) {
                ++cnt[c - 'a'];
            }

            string key;
            for (int i = 0; i < 26; ++i) {
                key.push_back('a' + i);
                key += to_string(cnt[i]);
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto &p : groups) {
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end

