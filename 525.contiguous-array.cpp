/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */
#include <unordered_map>

// @lc code=start
class Solution {
public:
    // Treat all 0 as -1, then it becomes a special case of Q325 with k = 0
    // T: O(n)
    // S: O(n)
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> mp;  // k: sum, v: index
        int sum = 0, ans = 0;

        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] ? 1 : -1;
            if (mp.find(sum) != mp.end()) {
                // Same prefix sum found, which means the sum of 
                // the numbers in the interval in between is 0
                ans = std::max(ans, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};
// @lc code=end

