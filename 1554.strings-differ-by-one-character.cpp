/*
 * @lc app=leetcode id=1554 lang=cpp
 *
 * [1554] Strings Differ by One Character
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // Rabin-Karp Algorithm based on hashing
    // T: O(n * l) without hash collision check, n := len(dict), l := word length; O(n * l ^ 2) worst case with hash collision check
    // S: O(n)
    bool differByOne(vector<string>& dict) {
        const int n = dict.size(), l = dict[0].size(), MOD = 1000000007;
        vector<int> hash(n);
        // hash[i] = w[0] * 26 ^ (l - 1) + w[1] * 26 ^ (l - 2) + ... + w[l - 2] * 26 + w[l - 1], w = dict[i]
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < l; ++j) {
                hash[i] = (26l * hash[i] + (dict[i][j] - 'a')) % MOD;
            }
        }

        int mult = 1;
        for (int j = l - 1; j >= 0; --j) {
            unordered_map<int, vector<int>> mp;
            for (int i = 0; i < n; ++i) {
                // Compute a hash without one of the chars and check if there's another string with the same hash.
                // Add MOD to prevent h being negative.
                int h = (MOD + hash[i] - (long)mult * (dict[i][j] - 'a') % MOD) % MOD;
                auto it = mp.find(h);
                if (it != mp.end()) {
                    // Do collision check, i.e. dict[i][:j] == dict[k][:j] and dict[i][j + 1:] == dict[k][j + 1:]
                    for (int k : it->second) {
                        if (std::equal(dict[i].cbegin(), dict[i].cbegin() + j, dict[k].cbegin()) && 
                            std::equal(dict[i].cbegin() + j + 1, dict[i].cend(), dict[k].cbegin() + j + 1)) {
                            return true;
                        }
                    }
                }
                mp[h].push_back(i);
            }
            mult = 26l * mult % MOD;
        }
        return false;
    }
};
// @lc code=end

