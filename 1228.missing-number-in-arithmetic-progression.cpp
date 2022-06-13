/*
 * @lc app=leetcode id=1228 lang=cpp
 *
 * [1228] Missing Number In Arithmetic Progression
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Any arithmetic progression is sorted, so we can use binary search
    // T: O(log(n))
    // S: O(1)
    int missingNumber(vector<int>& arr) {
        const int n = arr.size();
        int d = (arr[n - 1] - arr[0]) / n;
        int l = 0, r = n;
        
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (arr[m] == arr[0] + d * m) {
                // Since there's only one missing,
                // the condition is "==".
                l = m + 1;
            } else {
                // This should only be triggered once
                r = m;
            }
        }
        return arr[0] + d * l;
    }
};
// @lc code=end

