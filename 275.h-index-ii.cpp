/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(log(n))
    // S: O(1)
    int hIndex(vector<int>& citations) {
        const auto n = citations.size();
        if (citations[0] >= n)  return n;
        int l = 0, r = n - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            int h = n - m;
            if (citations[m] == h)  return h;   // by definition
            else if (citations[m] > h)  r = m - 1;
            else  l = m + 1;
        }
        return n - l;   // by definition
    }
};
// @lc code=end

