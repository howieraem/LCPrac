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
    // hash maps
    // T: O(n)
    // S: O(n + alpha_size) = O(n)
    bool wordPattern(string pattern, string s) {
        int p2i[26] {};
        unordered_map<string, int> w2i;

        const int n = pattern.size();
        istringstream in(s);  // need to iterate backwards
        int i = n;
        for (string word; in >> word; --i) {
            if (i == 0 || p2i[pattern[n - i] - 'a'] != w2i[word]) {
                // compare last appearance indices, or check if
                // i == 0 (meaning pattern and s sizes mismatch)
                return false;
            }
            p2i[pattern[n - i] - 'a'] = w2i[word] = i;
        }
        return i == 0;  // i != 0 means pattern and s sizes mismatch
    }
};
// @lc code=end

