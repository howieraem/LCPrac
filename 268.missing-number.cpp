/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Bit manipulation. For i from 0 to n - 1, if i exists in the array
     * somewhere, then the XOR of this number and this number
     * (i.e., the index) is 0. Do this XOR for all indices and
     * array elements, if there is a number not in the range(0, n),
     * the XOR result will reflect it.
     */
    // T: O(n)
    // S: O(1)
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }

    /*
    // Solution based on cyclic sort, without bit manipulations (but modifies input array)
    // T: O(n)
    // S: O(1)
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int i = 0;
        while (i < n) {
            // try to place nums[i] at i
            int correct_idx = nums[i];
            if (nums[i] < n && nums[i] != nums[correct_idx]) {
                std::swap(nums[i], nums[correct_idx]);
            } else {
                ++i;
            }
        }

        // find the discrepancy
        for (int j = 0; j < n; ++j) {
            if (j != nums[j]) {
                return j;
            }
        }
        return n;  // last number missing
    }
    */
};
// @lc code=end

