/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <vector>

using std::swap;
using std::vector;

// @lc code=start
class Solution {
public:
    Solution() : gen((std::random_device())()) {};

    // We are finding the k-th largest, not the k-th smallest. Thus, set k = n - k.
    // T: O(n) average, O(n ^ 2) worst
    // S: O(log(n)) average, O(n) worst
    int findKthLargest(vector<int>& nums, int k) {
        _k = nums.size() - k;  // IMPORTANT
        quickSelect(nums, 0, nums.size() - 1);
        return nums[_k];
    }

private:
    std::mt19937 gen;
    int _k;

    void quickSelect(vector<int> &nums, int begin, int end) {
        std::uniform_int_distribution<> distrib(begin, end);
        int pivot_idx = distrib(gen);
        swap(nums[pivot_idx], nums[begin]);
        int pivot = nums[begin];

        int l = begin + 1, r = end;
        while (l <= r) {
            if (nums[l] <= pivot) {
                ++l;
                continue;
            }
            if (nums[r] > pivot) {
                --r;
                continue;
            }

            swap(nums[l++], nums[r--]);
        }

        swap(nums[begin], nums[r]);
        if (r < _k)  quickSelect(nums, r + 1, end);
        else if (r > _k)  quickSelect(nums, begin, r - 1);
    }
};
// @lc code=end

