/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */
#include <bits/stdc++.h>

using std::vector;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(k)
    bool containsNearbyAlmostDuplicate(const vector<int>& nums, const int& k, const int& t) {
        auto get_bucket_id = [&](int i) {
            int bucket_id = nums[i] / ((long)t + 1);
            // For negative numbers, we need to decrement bucket id
			// to ensure floor division.
			// For example, -1/2 = 0 but -1 should be put in buckets[-1].
            return bucket_id - (nums[i] < 0);
        };

        unordered_map<int, int> buckets;
        for (int i = 0; i < nums.size(); ++i) {
            int bid = get_bucket_id(i);

            // If two numbers in the same bucket, then their difference must be <= t
            if (buckets.find(bid) != buckets.end()) return true;
            
            buckets[bid] = nums[i];

            // Check neighbor buckets where difference <= t is possible
            if ((buckets.find(bid - 1) != buckets.end() && (long)nums[i] - buckets[bid - 1] <= t) || 
                (buckets.find(bid + 1) != buckets.end() && (long)buckets[bid + 1] - nums[i] <= t)) {
                return true;
            }
            
            if (buckets.size() > k) {
                // sliding window
                buckets.erase(get_bucket_id(i - k));
            }
        }
        return false;
    }
};
// @lc code=end

