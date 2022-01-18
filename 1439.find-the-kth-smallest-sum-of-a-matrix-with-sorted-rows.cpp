/*
 * @lc app=leetcode id=1439 lang=cpp
 *
 * [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
typedef pair<int, int> int_pair;

class Solution {
public:
    // T: O(k * log(k) * m), m := len(mat)
    // S: O(k)
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        for (int i = 1; i < mat.size(); ++i) {
            row = kSmallestPairs(row, mat[i], k);
        }
        return row[k - 1];
    }

private:
    // Code adapted from Question 373, returning the pair sum instead of 
    // pair of indices. Time complexity O(k * log(k)).
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int m = nums1.size(), n = nums2.size();

        auto compare = [&nums1, &nums2](const int_pair &a, const int_pair &b) { 
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<int_pair, vector<int_pair>, decltype(compare)> pq(compare);
        pq.emplace(0, 0);

        vector<int> res;
        while (k-- > 0 && pq.size()) {
            auto p = pq.top(); pq.pop();
            res.push_back(nums1[p.first] + nums2[p.second]);
            if (p.first + 1 < m) {
                pq.emplace(p.first + 1, p.second);
            }
            if (!p.first && p.second + 1 < n) {
                pq.emplace(p.first, p.second + 1);
            }
        }
        return res;
    }
};
// @lc code=end

