import java.util.Set;
import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=391 lang=java
 *
 * [391] 完美矩形
 */

// @lc code=start
class Solution {
    /** 
     * 如果是完美矩形，那么一定满足两点： 
     * （1）最左下 最左上 最右下 最右上 的四个点只出现一次，其他点成对出现 
     * （2）四个点围出的矩形面积 = 小矩形的面积之和
     */
    public boolean isRectangleCover(int[][] rectangles) {
        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE; 
        int top = Integer.MIN_VALUE, bottom = Integer.MAX_VALUE;
        int sumArea = 0;
        Set<String> set = new HashSet<>();
        
        for (int i = 0; i < rectangles.length; ++i) {
            int l = rectangles[i][0], b = rectangles[i][1], r = rectangles[i][2], t = rectangles[i][3];

            left = Math.min(left, l);
            bottom = Math.min(bottom, b);
            right = Math.max(right, r);
            top = Math.max(top, t);

            sumArea += (r - l) * (t - b);

            String lt = l + " " + t;
            String lb = l + " " + b;
            String rt = r + " " + t;
            String rb = r + " " + b;

            if (!set.contains(lt))  set.add(lt);
            else  set.remove(lt);
            if (!set.contains(lb))  set.add(lb);
            else  set.remove(lb);
            if (!set.contains(rt))  set.add(rt);
            else  set.remove(rt);
            if (!set.contains(rb))  set.add(rb);
            else  set.remove(rb);
        }

        return (
            set.size() == 4 &&
            set.contains(left + " " + top) &&
            set.contains(left + " " + bottom) &&
            set.contains(right + " " + top) &&
            set.contains(right + " " + bottom) &&
            sumArea == (right - left) * (top - bottom)
        );
    }
}
// @lc code=end

