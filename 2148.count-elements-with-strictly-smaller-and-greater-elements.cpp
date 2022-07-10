/*
 * @lc app=leetcode id=2148 lang=cpp
 *
 * [2148] Count Elements With Strictly Smaller and Greater Elements
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int countElements(vector<int>& nums) {
        int min_n = INT_MAX, max_n = INT_MIN;
        for (const int &num : nums) {
            min_n = min(min_n, num);
            max_n = max(max_n, num);
        }
        
        int ans = 0;
        for (const int &num : nums) {
            ans += (num > min_n && num < max_n);
        }
        return ans;
    }
};
// @lc code=end
