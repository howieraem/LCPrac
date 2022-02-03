/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> rearrangeArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        int i = 0, j = 1, p = 0;
        while (p < n) {
            if (nums[p] > 0) {
                res[i++] = nums[p++]; 
                i++;
            } else {
                res[j++] = nums[p++];
                j++;
            }
        }
        return res;
    }
};
// @lc code=end
