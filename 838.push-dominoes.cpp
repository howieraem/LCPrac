/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // Advanced two pointers
    // T: O(n)
    // S: O(1)
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        int last_known_r = -1;

        for (int i = 0; i < N; ++i) {
            if (dominoes[i] == 'L') {
                if (last_known_r == -1) {
                    // Case: .....L
                    for (int j = i - 1; j >= 0 && dominoes[j] == '.'; --j) {
                        dominoes[j] = 'L';
                    }
                } else {
                    // Case: R....L
                    int lo = last_known_r + 1;
                    int hi = i - 1;
                    while (lo < hi) {
                        dominoes[lo++] = 'R';
                        dominoes[hi--] = 'L';
                    }
                    last_known_r = -1;
                }
            } else if (dominoes[i] == 'R') {
                if (last_known_r != -1) {
                    // Case: R....
                    for (int j = last_known_r + 1; j < i; ++j) {
                        dominoes[j] = 'R';
                    }
                }
                last_known_r = i;
            }
        }

        // Don't forget the final movements
        if (last_known_r != -1) {
            for (int j = last_known_r + 1; j < N; ++j) {
                dominoes[j] = 'R';
            }
        }
        return dominoes;
    }
};
// @lc code=end

