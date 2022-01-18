/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */
#include <algorithm>

using std::min;
using std::max;

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        if (ax1 >= bx2 || ax2 <= bx1 || ay1 >= by2 || ay2 <= by1)  return s;
        int left = max(bx1, ax1);
        int right = min(ax2, bx2);
        int top = min(by2, ay2);
        int bottom = max(ay1, by1);
        return s - (right - left) * (top - bottom);
    }
};
// @lc code=end

