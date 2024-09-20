#include <bits/stdc++.h>

class Solution {
public:
    // T: O(n)
    // S: O(1)
    int longestContinuousSubstring(std::string s) {
        const int n = s.size();
        if (n == 0) {
            return 0;
        }
        int ans = 1, cur_len = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] - s[i - 1] == 1) {
                ++cur_len;
                ans = std::max(ans, cur_len);
            } else {
                cur_len = 1;
            }
        }
        return ans;
    }
};