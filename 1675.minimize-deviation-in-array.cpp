/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */
#include <bits/stdc++.h>

using std::set;
using std::vector;

// @lc code=start
class Solution {
public:
    // Even numbers can be divided multiple times until they become odd.
    // Odd numbers can be doubled only once as they become even.
    // Thus, even numbers should not be increased. Follow the steps:
    // 1. Traverse the array and double all odd numbers;
    // 2. Decrease the largest number while it's even;
    // 3. To make numbers sorted, use a tree set;
    // 4. Greedily reduce the maximum number in the set;
    // 5. If the maximum number becomes odd, return the deviation.
    // T: O(n * log(n)).
    // S: O(n).
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) {  // odd
                s.insert(nums[i] << 1);
            } else {    // even
                s.insert(nums[i]);
            }
        }

        // s.rbegin() points to the maximum
        // s.begin() points to the minimum
        int ans = *s.rbegin() - *s.begin();
        while ((*s.rbegin() & 1) == 0) {
            int x = *s.rbegin();
            s.erase(x);
            s.insert(x >> 1);
            ans = std::min(ans, *s.rbegin() - *s.begin());
        }
        return ans;
    }
};
// @lc code=end

