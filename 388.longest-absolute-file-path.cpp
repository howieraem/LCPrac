/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n * l), n := the number of lines, l := line length
    // S: O(n)
    int lengthLongestPath(std::string input) {
        std::stringstream ss(input);
        std::string line;
        std::stack<int> stk;
        stk.push(0);
        int ans = 0;

        while (std::getline(ss, line, '\n')) {
            int n_tabs = line.find_last_of('\t') + 1;
            while (n_tabs + 1 < stk.size()) {
                // Skip directories or files at the same level 
                // to get the length of parent directory
                stk.pop();
            }

            // Omit all '\t' and add a '/' when calculating the length
            int cur_len = stk.top() + (line.size() - n_tabs + 1);
            stk.push(cur_len);
            if (line.find_last_of('.') != std::string::npos) {
                // Only update the answer if it's a file
                ans = std::max(ans, cur_len - 1);
            }
        }
        return ans;
    }
};
// @lc code=end

