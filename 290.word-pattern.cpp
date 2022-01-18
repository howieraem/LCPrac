/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include <sstream>
#include <string>
#include <unordered_map>

using std::istringstream;
using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    bool wordPattern(string pattern, string s) {
        int p2i[26] {};
        unordered_map<string, int> w2i;

        const int n = pattern.size();
        istringstream in(s);
        int i = n;
        for (string word; in >> word; --i) {
            if (!i || p2i[pattern[n - i] - 'a'] != w2i[word]) {
                return false;
            }
            p2i[pattern[n - i] - 'a'] = w2i[word] = i;
        }
        return !i;
    }
};
// @lc code=end

