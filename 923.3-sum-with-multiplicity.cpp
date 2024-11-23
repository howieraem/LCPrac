/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // Solution 1: hash maps + math
    // Consider different combination cases and use combination formula
    // Combination not permutation because a < b < c
    // T: O(n ^ 2) worst if no duplicate in arr, n := len(arr)
    // S: O(n)
    int threeSumMulti(std::vector<int>& arr, int target) {
        std::unordered_map<int, long> cnts;
        long ans = 0;
        const long MOD = 1000000007;

        for (const int &x : arr) {
            ++cnts[x];
        }

        for (const auto &p1 : cnts) {
            for (const auto &p2 : cnts) {
                int a = p1.first, b = p2.first, c = target - a - b;
                auto p3_it = cnts.find(c);
                if (p3_it == cnts.end()) {
                    // can't form a triplet with sum == target
                    continue;
                }
                if (a == b && b == c) {
                    // Three numbers equal
                    // C(n, 3)
                    // ans += cnts[a] * (cnts[a] - 1) * (cnts[a] - 2) / 6;
                    ans += p1.second * (p1.second - 1) * (p1.second - 2) / 6;
                } else if (a == b && b != c) {
                    // Two numbers equal
                    // Case 1: a == b < c,
                    // Case 2: c < a == b (i.e., a < b == c)
                    // C(n_i, 2) * n_k
                    // ((n_i * (n _i - 1)) // 2) * n_k
                    // ans += ((cnts[a] * (cnts[a] - 1)) >> 1) * cnts[c];
                    ans += ((p1.second * (p1.second - 1)) >> 1) * p3_it->second;
                } else if (a < b && b < c) {
                    // Three numbers all different
                    ans += p1.second * p2.second * p3_it->second;
                }
            }
        }
        return static_cast<int>(ans % MOD);
    }

    /*
    // Solution 2: based on original 3-sum, may encounter TLE if lots of duplicates exist
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    int threeSumMulti(std::vector<int>& arr, int target) {
        std::unordered_map<int, int> mp;
        int ans = 0;
        const int MOD = 1000000007;

        for (int a = 0; a < arr.size(); ++a) {
            ans = (ans + mp[target - arr[a]]) % MOD;

            for (int b = 0; b < a; ++b) {
                ++mp[arr[a] + arr[b]];
            }
        }
        return ans;
    }
    */
};
// @lc code=end

