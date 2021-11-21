/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++f[s[i] - 'a'];
            --f[t[i] - 'a'];
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (f[i] > 0)  ans += f[i];
        }
        return ans;
    }
};
// @lc code=end

