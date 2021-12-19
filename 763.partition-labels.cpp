/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */
#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(s), s := alphabet size
    vector<int> partitionLabels(string s) {
        const int n = s.size();
        int lastIdxs[26] {};
        for (int i = 0; i < n; ++i) {
            lastIdxs[s[i] - 'a'] = i;
        }

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, lastIdxs[s[i] - 'a']);
            
            // Partition as many as possble, so just partition
            // at the last occurrence of a type of character.
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
// @lc code=end

