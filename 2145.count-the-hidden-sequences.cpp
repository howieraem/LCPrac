#include <bits/stdc++.h>

class Solution {
public:
    // T: O(n)
    // S: O(1)
    int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
        long long xi = 0, min_x = 0, max_x = 0;
        for (int d : differences) {
            xi += d;  // mock numbers in the sequences
            min_x = std::min(min_x, xi);   // min of the hidden seq
            max_x = std::max(max_x, xi);   // max of the hidden seq
        }
        // The number of possible seqs is bound by (upper - lower)
        // https://assets.leetcode.com/users/images/3d4d6da3-bfbf-4fb1-bc48-6e5b0deb77a7_1642871020.8740537.png
        return std::max(0LL, (upper - lower) - (max_x - min_x) + 1);
    }
};