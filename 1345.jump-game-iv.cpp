/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */
#include <bits/stdc++.h>

using std::queue;
using std::vector;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // T: O(n) as indices of the same value only visited once
    // S: O(n)
    int minJumps(vector<int>& arr) {
        const int n = arr.size();

        unordered_map<int, vector<int>> val_to_idxs;
        for (int i = 0; i < n; ++i) {
            val_to_idxs[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<uint8_t> vis_pos(n, 0);

        q.push(0);
        vis_pos[0] = 1;

        int steps = 0;
        while (q.size()) {
            auto qs = q.size();
            while (qs-- > 0) {
                int i = q.front(); q.pop();
                if (i == n - 1) {
                    // reached last index
                    return steps;
                }

                vector<int>& next_idxs = val_to_idxs[arr[i]];  // same-value indices option
                next_idxs.push_back(i + 1);  // add forward option
                next_idxs.push_back(i - 1);  // add backward option

                for (const int& j : next_idxs) {
                    if (0 <= j && j < n && !vis_pos[j]) {
                        q.push(j);
                        vis_pos[j] = 1;
                    }
                }

                // IMPORTANT: avoids visiting indices of the same value more than once
                next_idxs.clear();
            }

            ++steps;
        }

        return steps;
    }
};
// @lc code=end

