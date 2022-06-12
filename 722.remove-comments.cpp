/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n * l), n := the number of lines, l := max. line length
    // S: O(l)
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        res.reserve(source.size());

        string buf;
        bool is_block = false;

        for (const auto& line : source) {
            int i = 0, l = line.size();
            while (i < l) {
                if (i < l - 1 && line.substr(i, 2) == "//" && !is_block) { 
                    break;
                } else if (i < l - 1 && line.substr(i, 2) == "/*" && !is_block) {
                    is_block = true;
                    ++i;
                } else if (i < l - 1 && line.substr(i, 2) == "*/" && is_block) {
                    is_block = false;
                    ++i;
                } else if (!is_block) {
                    buf.push_back(line[i]);
                }
                ++i;
            }

            if (buf.size() && !is_block) {
                // std::move() will clear buf at the same time
                res.push_back(std::move(buf));
            }
        }
        return res;
    }
};
// @lc code=end

