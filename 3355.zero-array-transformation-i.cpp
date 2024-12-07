#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    // Sweeping line
    // T: O(n)
    // S: O(n)
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<int> net_decre(n + 1);
        for (const auto& q : queries) {
            ++net_decre[std::max(q[0], 0)];
            --net_decre[std::min(q[1] + 1, n)];
        }

        int tot_decre = 0;
        for (int i = 0; i < n; ++i) {
            tot_decre += net_decre[i];
            if (tot_decre < nums[i]) {
                // if n_decre > nums[i], assume nums[i] stays at 0
                return false;
            }
        }
        return true;
    }
};