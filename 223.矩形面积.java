/*
 * @lc app=leetcode.cn id=223 lang=java
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int base = (D - B) * (C - A) + (H - F) * (G - E);
        if (D <= F || C <= E || B >= H || A >= G)  return base;     // no overlap
        // find boundaries of the intersection
        int left = Math.max(A, E);
        int right = Math.min(C, G);
        int top = Math.min(D, H);
        int bottom = Math.max(B, F);
        return base - (right - left) * (top - bottom);
    }
}
// @lc code=end

