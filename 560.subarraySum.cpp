/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix_sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];

            // Sum of a subarray sum(nums[i:j + 1]) = prefix_sum[j] - prefix_sum[i - 1]
            auto it = mp.find(prefix_sum - k);
            if (it != mp.end()) {
                ans += it->second;
            }
            ++mp[prefix_sum];
        }
        return ans;
    }
};
// @lc code=end

