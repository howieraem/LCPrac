/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include <vector>

using std::vector;

// @lc code=start
class NumArray {
    vector<int> psum;   // S: O(n)

public:
    // T: O(n)
    NumArray(vector<int>& nums) {
        psum.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            psum.push_back(psum.back() + nums[i]);
        }
    }
    
    // T: O(1)
    int sumRange(int left, int right) {
        return psum[right + 1] - psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

