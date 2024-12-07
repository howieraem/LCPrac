#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    // Greedy + Variant of sweeping line
    // T: O(m + n), m := len(queries)
    // S: O(n)
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int k = 0;
        vector<int> net_decre(n + 1);
        int tot_decre = 0;
        for (int i = 0; i < n; ++i) {
            while (tot_decre + net_decre[i] < nums[i]) {
                if (k == queries.size()) {
                    // reached end of queries, impossible to decrement all to zero
                    return -1;
                }
                
                if (queries[k][1] < i) {
                    // current query will not contribute to the decrement of nums[i]
                    // due to its range, skip 
                    ++k;
                    continue;
                }

                // 1. Always do the max decrement amount, assume nums[i] won't go below 0
                // 2. If queries[k][0] < i, update net_decre at i instead
                net_decre[std::max(queries[k][0], i)] += queries[k][2];
                net_decre[std::min(queries[k][1] + 1, n)] -= queries[k][2];
                ++k;
            }
            tot_decre += net_decre[i];
        }

        return k;
    }
};