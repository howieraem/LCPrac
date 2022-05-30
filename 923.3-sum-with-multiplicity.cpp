/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // Solution 1: consider different combination cases and use combination formula
    // T: O(n), n := len(arr)
    // S: O(n)
    int threeSumMulti(std::vector<int>& arr, int target) {
        std::unordered_map<int, long> cnt;
        long ans = 0;
        const long MOD = 1000000007;

        for (const int &x : arr)  ++cnt[x];

        for (const auto &p1 : cnt) {
            for (const auto &p2 : cnt) {
                int i = p1.first, j = p2.first, k = target - i - j;
                if (cnt.find(k) == cnt.end())  continue;
                if (i == j && j == k) {
                    // C(n, 3)
                    ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
                } else if (i == j && j != k) {
                    // i == j < k or k < i == j (i.e., i < j == k)
                    // C(n_i, 2) * n_k
                    ans += ((cnt[i] * (cnt[i] - 1)) >> 1) * cnt[k];
                } else if (i < j && j < k) {
                    ans += cnt[i] * cnt[j] * cnt[k];
                }
            }
        }
        return static_cast<int>(ans % MOD);
    }

    /*
    // Solution 2: based on original 3-sum
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    int threeSumMulti(std::vector<int>& arr, int target) {
        std::unordered_map<int, int> mp;
        int ans = 0;
        const int MOD = 1000000007;

        for (int i = 0; i < arr.size(); ++i) {
            ans = (ans + mp[target - arr[i]]) % MOD;

            for (int j = 0; j < i; ++j) {
                ++mp[arr[i] + arr[j]];
            }
        }
        return ans;
    }
    */
};
// @lc code=end

