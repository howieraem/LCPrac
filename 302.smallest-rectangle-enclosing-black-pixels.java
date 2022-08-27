/*
 * @lc app=leetcode id=302 lang=java
 *
 * [302] Smallest Rectangle Enclosing Black Pixels
 */

// @lc code=start
class Solution {
    // Binary search: for example, if x1 < x and the col of x1 has black, then no need to search cols between x1 and x
    // T: O(m * log(n) + n * log(m))
    // S: O(1)
    public int minArea(char[][] image, int x, int y) {
        int left = leftmost(image, 0, y, true),
            right = rightmost(image, y, image[0].length - 1, true),
            top = leftmost(image, 0, x, false),
            bottom = rightmost(image, x, image.length - 1, false);
        return (right - left + 1) * (bottom - top + 1);
    }

    // T: O(log(r - l))
    private static int leftmost(final char[][] image, int l, int r, boolean isHorizontal) {
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (hasBlack(image, m, isHorizontal)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    // T: O(log(r - l))
    private static int rightmost(final char[][] image, int l, int r, boolean isHorizontal) {
        while (l < r) {
            int m = l + ((r - l + 1) >> 1);
            if (hasBlack(image, m, isHorizontal)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return r;
    }

    // Checks whether a row/col contains a black pixel. 
    // T: O(m) or O(n)
    private static boolean hasBlack(final char[][] image, int m, boolean isHorizontal) {
        if (isHorizontal) {
            for (int i = 0; i < image.length; ++i) {
                if (image[i][m] == '1') return true;
            }
        } else {
            for (int i = 0; i < image[0].length; ++i) {
                if (image[m][i] == '1') return true;
            }
        }
        return false;
    }
}
// @lc code=end

