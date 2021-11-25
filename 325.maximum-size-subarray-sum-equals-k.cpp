/*
 * @lc app=leetcode id=325 lang=cpp
 *
 * [325] Maximum Size Subarray Sum Equals k
 */
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // CANNOT use a sliding window approach if nums contain non-positive values
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // IMPORTANT
            if (sum == k) {
                ans = i + 1;
            }

            // Below is similar to 2-sum problem
            if (map.find(sum) == map.end()) {
                // Only insert index when sum is not in map, as 
                // it's looking for the maximum length
                map[sum] = i;
            }

            if (map.find(sum - k) != map.end()) {
                // sum - k in map
                ans = max(ans, i - map[sum - k]);
            }
        }
        return ans;
    }
};
// @lc code=end
