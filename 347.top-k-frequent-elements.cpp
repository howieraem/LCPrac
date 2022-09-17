/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++f[nums[i]];
        }

        vector<vector<int>> buckets(n + 1);
        for (const auto &e : f) {
            buckets[e.second].push_back(e.first);
        }

        vector<int> res;
        res.reserve(k);
        // upper bound of frequency is n
        for (int i = n; i >= 0 && res.size() < k; --i) {
            if (buckets[i].size()) {
                res.insert(res.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        // The problem specs state that "it is guaranteed that the answer is unique",
        // so no need to take the subarray from 0th element to kth element
        return res;
    }
};
// @lc code=end

