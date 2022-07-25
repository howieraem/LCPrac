/*
 * @lc app=leetcode id=2214 lang=cpp
 *
 * [2214] Minimum Health to Beat Game
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 1;  // final HP > 0
        int max_x = 0;
        for (const int& x : damage) {
            ans += x;
            max_x = std::max(max_x, x);
        }
        ans -= std::min(armor, max_x);
        return ans;
    }
};
// @lc code=end
