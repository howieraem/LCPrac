/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Two pointers
    // T: O(n)
    // S: O(1)
    vector<int> rearrangeArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        int i = 0; 
        int j = 1; 
        int p = 0;
        while (p < n) {
            if (nums[p] > 0) {
                res[i++] = nums[p++]; 
                i++;  // skip the next opposite signed number
            } else {
                res[j++] = nums[p++];
                j++;  // skip the next opposite signed number
            }
        }
        return res;
    }
};
// @lc code=end
