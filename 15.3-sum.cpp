/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        const int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (x > 0) {
                // After sorting, since y and z below will be greater than x, 
                // we have x + y + z > 0. There is thus no need to iterate
                // the rest of the x.
                return res;
            }
            if (i && nums[i - 1] == x)  continue;   // skip duplicates of x

            int l = i + 1, r = n - 1;
            while (l < r) {
                int y = nums[l], z = nums[r], s = x + y + z;
                if (s == 0) {
                    res.push_back({x, y, z});

                    // skip duplicates of y and z
                    while (l < r && nums[l + 1] == nums[l])  ++l;
                    while (l < r && nums[r - 1] == nums[r])  --r;
                    ++l;
                    --r;
                } 
                else if (s > 0)  --r;
                else  ++l; 
            }
        }
        return res;
    }
};
// @lc code=end

