/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Prefix sum + two sum
    // Treat all 0 as -1, then it becomes a special case of Q325 with k = 0
    // T: O(n)
    // S: O(n)
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> mp;  // k: sum, v: index
        int sum = 0, ans = 0;

        mp[0] = -1;  // IMPORTANT: handle edge case if the subarr starts from idx 0
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 1 ? 1 : -1;
            auto it = mp.find(sum);
            if (it != mp.end()) {
                // Same prefix sum found, which means the sum of 
                // the numbers in the interval in between is 0
                ans = std::max(ans, i - it->second);
            } else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};
// @lc code=end

