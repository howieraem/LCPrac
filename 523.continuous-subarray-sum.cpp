/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(k)
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int running_sum = 0;  // a variant of prefix sum
        for (int i = 0; i < nums.size(); ++i) {
            running_sum += nums[i];
            running_sum %= k;
            auto it = mp.find(running_sum);
            // Math: if a > b, a is divisible by k and b is divisible by k, 
            // then (a - b) which is a subarray sum is also divisible by k.
            if (it != mp.end()) {
                if (i - it->second > 1) {
                    // subarray len >= 2
                    return true;
                }
            } else {
                mp[running_sum] = i;
            }
        }
        return false;
    }
};
// @lc code=end

