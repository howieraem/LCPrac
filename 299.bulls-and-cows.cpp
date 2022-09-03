/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(s), s := the number of digits 10
    string getHint(string secret, string guess) {
        int digit_cnts[10] {};
        int n_a = 0, n_b = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++n_a;
            } else {
                // digit has appeared in guess before
                n_b += digit_cnts[secret[i] - '0'] < 0;

                // digit has appeared in secret before
                n_b += digit_cnts[guess[i] - '0'] > 0;

                ++digit_cnts[secret[i] - '0'];
                --digit_cnts[guess[i] - '0'];
            }
        }
        return std::to_string(n_a) + "A" + std::to_string(n_b) + "B";
    }
};
// @lc code=end

