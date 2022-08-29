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
        int cnt = 0, sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // Sum of a subarray sum(nums[i:j + 1]) = prefix_sum[j] - prefix_sum[i - 1]
            auto it = mp.find(sum - k);
            if (it != mp.end()) {
                cnt += it->second;
            }
            ++mp[sum];
        }
        return cnt;
    }
};
// @lc code=end

