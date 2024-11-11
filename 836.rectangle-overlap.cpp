/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Math + geometry
    // T: O(1)
    // S: O(1)
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // not (rec1_x1 >= rec2_x2 or rec1_x2 <= rec2_x0 or rec1_y1 >= rec2_y2 or rec1_y2 <= rec2_y1)
        return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);

        // alternative solution
        // int x11 = rec1[0], y11 = rec1[1], x12 = rec1[2], y12 = rec1[3];
	    // int x21 = rec2[0], y21 = rec2[1], x22 = rec2[2], y22 = rec2[3];
	    // return (x11 < x22 && x21 < x12 && y11 < y22 && y21 < y12);
    }
};
// @lc code=end

