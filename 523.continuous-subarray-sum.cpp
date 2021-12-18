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
        int runningSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            runningSum %= k;
            if (mp.find(runningSum) != mp.end()) {
                if (i - mp[runningSum] > 1)  return true;
            } else {
                mp[runningSum] = i;
            }
        }
        return false;
    }
};
// @lc code=end

