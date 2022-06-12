/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int compress(vector<char>& chars) {
        const int n = chars.size();
        int i = 0, j = 0;
        while (i < n) {
            char cur = chars[i];
            int cnt = 0;
            while (i < n && chars[i] == cur) {
                ++i; 
                ++cnt;
            }
            chars[j++] = cur;
            if (cnt != 1) {
                // len(str(cnt)) is always no more than the number of repeated characters
                /*
                // Below takes O(log10(n)) space
                for (const auto &c : to_string(cnt)) {
                    chars[j++] = c;
                }
                */

                // Below keeps space complexity O(1) and seems to be faster,
                // even though needs to reverse the digits
                int k = j;
                while (cnt) {
                    chars[j++] = (char) ((cnt % 10) + '0'); 
                    cnt /= 10;
                }
                reverse(chars.begin() + k, chars.begin() + j);
            }
        }
        return j;
    }
};
// @lc code=end

