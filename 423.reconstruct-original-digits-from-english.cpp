/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(s), s := alphabet size 
    string originalDigits(string s) {
        int cnt[26] {0};
        for (const char &c : s) {
            ++cnt[c - 'a'];
        }
        
        int digit_cnt[10] {0};

        // 'z' appears only in 'zero'
        digit_cnt[0] = cnt['z' - 'a'];

        // 'w' appears only in 'two'
        digit_cnt[2] = cnt['w' - 'a'];

        // 'u' appears only in 'four'
        digit_cnt[4] = cnt['u' - 'a'];

        // 'x' appears only in 'six'
        digit_cnt[6] = cnt['x' - 'a'];

        // 'g' appears only in 'eight'
        digit_cnt[8] = cnt['g' - 'a'];

        // 'h' appears in 'three' and 'eight'
        digit_cnt[3] = cnt['h' - 'a'] - digit_cnt[8];

        // 'f' appears in 'four' and 'five'
        digit_cnt[5] = cnt['f' - 'a'] - digit_cnt[4];

        // 's' appears in 'six' and 'seven'
        digit_cnt[7] = cnt['s' - 'a'] - digit_cnt[6];

        // 'i' appears in 'five', 'six', 'eight' and 'nine'
        digit_cnt[9] = cnt['i' - 'a'] - digit_cnt[5] - digit_cnt[6] - digit_cnt[8];

        // 'n' appears in 'one', 'seven' and 'nine' (twice).
        digit_cnt[1] = cnt['n' - 'a'] - digit_cnt[7] - (digit_cnt[9] << 1);

        string res;
        for (int i = 0; i < 10; ++i) {
            res += string(digit_cnt[i], i + '0');
        }
        return res;
    }
};
// @lc code=end

