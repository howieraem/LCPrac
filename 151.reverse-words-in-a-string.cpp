/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include <algorithm>
#include <string>

// @lc code=start
class Solution {
public:
    // Two pointers, inplace
    // T: O(n)
    // S: O(1)
    std::string reverseWords(std::string& s) {
        const int n = s.size();
        int i = 0, j = 0;
        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') {
                ++i;
            }

            // new space delimiter (single space)
            if (i < n && j > 0) {
                s[j++] = ' ';
            }

            // Found a word, record the start idx, shift it to the left, 
            // and then reverse (will reverse again later)
            int start = j;
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            std::reverse(s.begin() + start, s.begin() + j);
        }

        // Reverse again to recover each word's character order
        s.resize(j);
        std::reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

