/*
 * @lc app=leetcode id=2217 lang=cpp
 *
 * [2217] Find Palindrome With Fixed Length
 */
#include <string>
#include <vector>

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n * len)
    // S: O(len)
    vector<long long> kthPalindrome(const vector<int>& queries, const int& len) {
        // Examples:
        // Say we need to find the 35th palindrome number. 
        // If len = 10 (even):
        //     min_val = 9999+1, max_val = 99999
        //     1st half number = 9999+35 = 10034
        //     2nd half number = reverse(10034) = 43001
        //     ans = 1003443001
        // 
        // If len = 11 (odd):
        //     min_val = 99999+1, max_val = 999999
        //     1st half number = 99999+35 = 100034
        //     2nd half number = reverse(10003) = 30001
        //     ans = 10003430001
        const int half_len = (len >> 1);
        const int is_odd = (len & 1);
        int min_digits = half_len - !is_odd,
            max_digits = half_len + is_odd;
        long long min_val = 0, max_val = 0;
        while (min_digits-- > 0) min_val = min_val * 10 + 9;
        while (max_digits-- > 0) max_val = max_val * 10 + 9;
        const int max_diff = max_val - min_val;
        
        const int n = queries.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int k_th = queries[i];
            if (k_th > max_diff) {
                res[i] = -1;
            } else {
                string s1 = std::to_string(min_val + k_th);
                string s2 = is_odd ? s1.substr(0, half_len) : s1;
                std::reverse(s2.begin(), s2.end());
                res[i] = std::stoll(s1 + s2);
            }
        }
        return res;
    }
};
// @lc code=end
