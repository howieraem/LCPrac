/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

bool isBadVersion(int version);

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Find lower bound of bad version
    // T: O(log(n)) if isBadVersion() is O(1)
    // S: O(1) if isBadVersion() is O(1)
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (isBadVersion(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
// @lc code=end

