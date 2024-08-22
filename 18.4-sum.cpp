/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 3)
    // S: O(log(n)) std::sort
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) {
            return res;
        }
        std::sort(nums.begin(), nums.end());
        long long t = (long long)target;

        for (int i = 0; i < n - 3; ++i) {
            int w = nums[i];
            if (i > 0 && nums[i - 1] == w) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                int x = nums[j];
                if (j > i + 1 && nums[j - 1] == x) {
                    continue;
                }

                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    int y = nums[l];
                    int z = nums[r];
                    long long s = (long long)w + x + y + z;

                    if (s > t) {
                        --r;
                    } else if (s < t) {
                        ++l;
                    } else {
                        res.push_back({w, x, y, z});
                        while (l < r && nums[l + 1] == nums[l]) { ++l; }
                        while (l < r && nums[r - 1] == nums[r]) { --r; }
                        ++l;
                        --r;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

