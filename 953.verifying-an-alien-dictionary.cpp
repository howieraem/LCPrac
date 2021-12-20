/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */
#include <algorithm>
#include <string>
#include <vector>

using std::is_sorted;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(s + n * l), s := len(order) (alphabet size), n := len(words), l := avg word length
    // S: O(s)
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        // Map order to normal order
        for (int i = 0; i < 26; ++i) {
            mapping[order[i] - 'a'] = i;
        }

        for (string &w : words) {
            for (char &c : w) {
                c = mapping[c - 'a'];   // changes strings inplace
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};
// @lc code=end

