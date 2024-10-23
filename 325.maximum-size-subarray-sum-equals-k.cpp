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
    // Prefix sum + two sum
    // CANNOT use a sliding window approach if nums contain non-positive values
    // T: O(n)
    // S: O(n)
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> map;
        long long sum = 0; 
        int ans = 0;

        map[0] = -1;  // IMPORTANT: handle edge case if the subarr starts from idx 0
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // IMPORTANT: without the initial map entry {0, -1}, below is necessary
            // if (sum == k) {
            //     ans = i + 1;
            // }

            // Below is similar to two sum problem
            auto it = map.find(sum - k);
            if (it != map.end()) {
                // sum - k in map
                ans = max(ans, i - it->second);
            }

            if (map.find(sum) == map.end()) {
                // Only insert index when sum is not in map, as 
                // it's looking for the maximum length
                map[sum] = i;
            }

            
        }
        return ans;
    }
};
// @lc code=end
