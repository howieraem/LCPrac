/*
 * @lc app=leetcode id=975 lang=cpp
 *
 * [975] Odd Even Jump
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int oddEvenJumps(std::vector<int>& arr) {
        const int n = arr.size();
        std::vector<uint8_t> higher(n, 0), lower(n, 0);
        higher[n - 1] = lower[n - 1] = 1;
        std::map<int, int> mp;
        mp[arr[n - 1]] = n - 1;
        int ans = 1;  // trivial case: start from the last index?
        for (int i = n - 2; i >= 0; --i) {
            auto hi = mp.lower_bound(arr[i]), lo = mp.upper_bound(arr[i]);
            if (hi != mp.end()) higher[i] = lower[hi->second];
            if (lo != mp.begin()) lower[i] = higher[std::prev(lo)->second];
            ans += higher[i];  // only updates for odd-numbered jumps because the start index will be the 1st jump
            mp[arr[i]] = i;
        }
        return ans;
    }
};
// @lc code=end

