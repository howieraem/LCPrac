/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include <algorithm>
#include <unordered_set>
#include <vector>

using std::max;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
    // Hash set + Greedy?
    // T: O(n)
    // S: O(n)
    int longestConsecutive(vector<int>& nums) {
        // Add all numbers to set
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for (const auto& x : s) {
            // IMPORTANT: with this check, time complexity is not O(n ^ 2)
            if (s.find(x - 1) == s.end()) {
                // Begin a new consecutive elements sequence
                int y = x + 1;
                while (s.find(y) != s.end()) {
                    ++y;
                }
                ans = max(ans, y - x);
            }
        }
        return ans;
    }
};
// @lc code=end

