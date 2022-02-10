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
    // We are finding the k-th largest, not the k-th smallest. Thus, set k = n - k.
    // T: O(n) average, O(n ^ 2) worst
    // S: O(log(n)) average, O(n) worst
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        quickSelect(nums, 0, nums.size() - 1, k);
        return nums[k];
    }

private:
    static void quickSelect(vector<int> &nums, int begin, int end, const int &k) {
        int pivot = nums[begin], l = begin, r = end;
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
        if (r < k)  quickSelect(nums, r + 1, end, k);
        else if (r > k)  quickSelect(nums, begin, r - 1, k);
    }
};
// @lc code=end

