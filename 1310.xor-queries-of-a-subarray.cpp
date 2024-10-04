/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n), or O(1) if arr can be modified
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix_xors(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) {
            prefix_xors[i + 1] = prefix_xors[i] ^ arr[i];
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            // [l, r], r inclusive
            // Fact: x ^ x = 0
            // so prefix_xors[...l] will be eliminated
            res[i] = prefix_xors[queries[i][0]] ^ prefix_xors[queries[i][1] + 1];
        }
        return res;
    }
};
// @lc code=end

