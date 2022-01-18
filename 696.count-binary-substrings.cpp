/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1: two loops
    int countBinarySubstrings(string s) {
        vector<int> contiguousLen;
        int cnt = 1;
        // Split s into substrings of zeros or ones, and
        // find the length of each substring
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1])  ++cnt;
            else  {
                contiguousLen.push_back(cnt);
                cnt = 1;
            }
        }
        contiguousLen.push_back(cnt);   // don't forget the last one

        int ans = 0;
        for (int i = 1; i < contiguousLen.size(); ++i) {
            // Example: given 00011, contiguousLen = [3, 2], then 
            // there are min([3, 2]) = 2 substrings: '0011' and '01'.
            ans += min(contiguousLen[i - 1], contiguousLen[i]);
        }
        return ans;
    }
    */

    // Solution 2: optimized version of solution 1, only one loop
    int countBinarySubstrings(string s) {
        int cur = 1, pre = 0, ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1])  ++cur;
            else {
                ans += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        ans += min(cur, pre);   // don't forget the last one
        return ans;
    }
};
// @lc code=end

