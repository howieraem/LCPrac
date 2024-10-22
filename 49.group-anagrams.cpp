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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string &s : strs) {
            /*
            // Below is faster for long strings and small alphabet size
            // T: O(m * (n + s)), m := len(strs), n := max. length of string in strs
            // S: O(m * (n + S))
            int cnt[26] {};
            for (const auto &c : s) {
                ++cnt[c - 'a'];
            }

            string key;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    key.push_back('a' + i);
                    key.append(to_string(cnt[i]));
                }
            }
            */

            // Below is faster for short strings and large alphabet size
            // T: O(m * n * log(n))
            // S: O(m * n)
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& p : groups) {
            res.push_back(std::move(p.second));
        }
        return res;
    }
};
// @lc code=end

