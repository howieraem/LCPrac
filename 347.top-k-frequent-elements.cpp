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
        int cnt = 0;
        // upper bound of frequency is n
        for (int i = n; i >= 0 && cnt < k; --i) {
            if (buckets[i].size()) {
                res.insert(res.end(), buckets[i].begin(), buckets[i].end());
                cnt += buckets[i].size();
            }
        }
        return res;
    }
};
// @lc code=end

