/*
 * @lc app=leetcode id=2281 lang=cpp
 *
 * [2281] Sum of Total Strength of Wizards
 */
#include <bits/stdc++.h>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
    // 1. Use a mono-stack to find a subarray [L, R] where the current pivot is 
    //    the smallest element. Then, we need to compute sum of all subarrays 
    //    within [L, R] that include pivot.
    // 2. Use prefix sum and prefix multiple to find sum of all subarrays from pivot to 
    //    L (left_sum), and from pivot to R (right_sum). Then the sum of all subarrays 
    //    is right_sum * (pivot - left + 1) + left_sum * (right - pivot). Finally, we 
    //    multiply this sum by the value of the pivot (smallest) element and add it to 
    //    the result.
    // Detailed explanation: https://leetcode.com/problems/sum-of-total-strength-of-wizards/discuss/2061787
    // T: O(n) amortized
    // S: O(n)
    int totalStrength(vector<int>& strength) {
        const long long n = strength.size(), MOD = 1000000007;
        vector<int> pre_sum_l(n + 1), pre_sum_r(n + 1), pre_mul_l(n + 1), pre_mul_r(n + 1);
        stack<int> st;  // stores indices of strengths ordered ASC (stack top corresponds to weakest)

        for (long long l = 0; l < n; ++l) {
            pre_sum_l[l + 1] = (pre_sum_l[l] + strength[l]) % MOD;
            pre_mul_l[l + 1] = (pre_mul_l[l] + (l + 1) * strength[l]) % MOD;
            
            long long r = n - l - 1;
            pre_sum_r[r] = (pre_sum_r[r + 1] + strength[r]) % MOD;
            pre_mul_r[r] = (pre_mul_r[r + 1] + (n - r) * strength[r]) % MOD;
        }

        long long ans = 0;
        for (long long r = 0; r <= n; ++r) {
            while (!st.empty() && (r == n || strength[st.top()] >= strength[r])) {
                int pivot = st.top(); st.pop();
                long long l = st.empty() ? 0 : st.top() + 1;
                long long l_sum = (MOD + pre_mul_l[pivot + 1] - pre_mul_l[l] - l * (pre_sum_l[pivot + 1] - pre_sum_l[l]) % MOD) % MOD,
                          r_sum = (MOD + pre_mul_r[pivot + 1] - pre_mul_r[r] - ((n - r) * (pre_sum_r[pivot + 1] - pre_sum_r[r]) % MOD)) % MOD;
                long long sum = (r_sum * (pivot - l + 1) + l_sum * (r - pivot)) % MOD;
                ans = (ans + sum * strength[pivot]) % MOD;
            }
            st.push(r);
        }
        return ans;
    }
};
// @lc code=end
