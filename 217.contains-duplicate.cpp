/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <unordered_set>

using std::unordered_set;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (const int& num : nums) {
            if (s.find(num) != s.end()) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};
// @lc code=end

