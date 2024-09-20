#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0LL);
        long long cur_max = (long long)nums[0];
        long long cur_convr = cur_max + nums[0];
        res[0] = cur_convr;
        for (int i = 1; i < n; ++i) {
            cur_max = std::max(cur_max, (long long) nums[i]);
            long long cur_convr = cur_max + nums[i];
            res[i] = res[i - 1] + cur_convr;
        }
        return res;
    }
};