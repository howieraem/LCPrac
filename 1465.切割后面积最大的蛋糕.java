import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1465 lang=java
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
    private static final long F = (long) (1e9 + 7);

    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        int nh = horizontalCuts.length, nw = verticalCuts.length;

        long hMax = horizontalCuts[0], wMax = verticalCuts[0];
        for (int i = 1; i < nh; ++i) {
            hMax = Math.max(hMax, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        hMax = Math.max(hMax, h - horizontalCuts[nh - 1]);
        for (int i = 1; i < nw; ++i) {
            wMax = Math.max(wMax, verticalCuts[i] - verticalCuts[i - 1]);
        }
        wMax = Math.max(wMax, w - verticalCuts[nw - 1]);

        return (int) (hMax * wMax % F);
    }
}
// @lc code=end

