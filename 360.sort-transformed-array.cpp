/*
 * @lc app=leetcode id=360 lang=cpp
 *
 * [360] Sort Transformed Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
#define F(x, a, b, c) (a * x * x + b * x + c)

class Solution {
public:
    // Math + two pointers
    // T: O(n)
    // S: O(1) excl. output
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        // auto f = [&](int x) { return a * x * x + b * x + c; };   
        int n = nums.size();

        vector<int> res(n);

        // Use two pointers because nums already sorted and every num needs transformation
        int i = 0;
        int j = n - 1;
        int k;

        // Parabola shape:
        // If a > 0, f(x) is greater if x goes to either inf or -inf
        // If a < 0, f(x) is smaller if x goes to either inf or -inf
        if (a >= 0) {
            k = n - 1;

            while (i <= j) {
                int fi = F(nums[i], a, b, c);
                int fj = F(nums[j], a, b, c);
                if (fi > fj) {
                    res[k--] = fi;
                    ++i;
                } else {
                    res[k--] = fj;
                    --j;
                }
            }

        } else {
            k = 0;

            while (i <= j) {
                int fi = F(nums[i], a, b, c);
                int fj = F(nums[j], a, b, c);
                if (fi > fj) {
                    res[k++] = fj;
                    --j;
                } else {
                    res[k++] = fi;
                    ++i;
                }
            }
        }

        return res;
    }
};
// @lc code=end

