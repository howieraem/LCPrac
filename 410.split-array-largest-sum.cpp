/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O
    int splitArray(vector<int>& nums, int m) {
        // Lower: max(nums)
        // Upper: sum(nums)
        int l = nums[0], r = nums[0], mid;
        for (int i = 1; i < nums.size(); ++i) {
            l = max(l, nums[i]);
            r += nums[i];
        }
        if (m == 1)  return r;

        while (l < r) {
            mid = l + ((r - l) >> 1);
            int n_splits = split(nums, mid);
            if (n_splits > m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;   // lower bound of maximum subarray sum
    }

private:
    static int split(const vector<int> &nums, int max_subarr_sum) {
        int cnt = 1, sum = 0;
        for (const int num : nums) {
            if (sum + num > max_subarr_sum) {
                // split
                ++cnt;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt;
    }
};
// @lc code=end

