#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

class Solution {
public:
    // T: O(n)
    // S: O(n)
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long window_sum = 0;
        unordered_map<int, int> cnts;
        int n_uniq = 0;  // avoid erasing map 
        for (int r = 0; r < nums.size(); ++r) {
            n_uniq += (cnts[nums[r]]++ == 0);
            window_sum += nums[r];

            if (r == k - 1 && n_uniq == k) {
                // first eligible subarry
                ans = window_sum;
            }

            if (r >= k) {
                int l = r - k;
                n_uniq -= (--cnts[nums[l]] == 0);
                window_sum -= nums[l];
                if (n_uniq == k) {
                    ans = std::max(ans, window_sum);
                }
            }
        }
        return ans;
    }
};