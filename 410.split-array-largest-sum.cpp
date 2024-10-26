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
    // Binary search
    // T: O(n * log(x)), n := len(nums), x := sum(nums) - max(nums)
    // S: O(1)
    int splitArray(vector<int>& nums, int m) {
        // Range for binary search
        // minimum: max(nums)
        // maximum: sum(nums)
        int l = nums[0]; 
        int r = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            l = max(l, nums[i]);
            r += nums[i];  // be aware of overflow
        }
        if (m == 1) {
            return r;
        }

        while (l < r) {
            int mid = l + ((r - l) >> 1);
            int n_splits = get_num_splits(nums, mid);
            if (n_splits > m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;   // leftmost eligible maximum subarray sums
    }

private:
    static int get_num_splits(const vector<int>& nums, const int& max_subarr_sum) {
        int cnt = 1, sum = 0;
        for (const int& num : nums) {
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

