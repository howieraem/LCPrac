/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(k)
    bool containsNearbyDuplicate(const vector<int>& nums, const int& k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
            if (s.size() > k) {
                // sliding window
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end

