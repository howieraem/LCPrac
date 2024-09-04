/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val2idx;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto it = val2idx.find(diff);
            if (it != val2idx.end()) {
                return {it->second, i};
            }
            val2idx[nums[i]] = i;
        }
        return vector<int>();
    }
};
// @lc code=end

