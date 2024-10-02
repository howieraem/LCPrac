/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else if (cur % 10 != 9 && cur + 1 <= n) {
                ++cur;
            } else {
                while (cur % 10 == 9 || cur == n) {
                    cur /= 10;
                }
                ++cur;
            }
        }

        return res;
    }
};
// @lc code=end

