/*
 * @lc app=leetcode id=259 lang=cpp
 *
 * [259] 3Sum Smaller
 */
#include <algorithm>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(log(n))
    int threeSumSmaller(vector<int>& nums, int target) {
        const auto n = nums.size();
        if (n < 3)  return 0;

        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < target) {
                    ans += r - l;
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

