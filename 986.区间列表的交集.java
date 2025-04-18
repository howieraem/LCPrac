/*
 * @lc app=leetcode.cn id=986 lang=java
 *
 * [986] 区间列表的交集
 */
import java.util.List;
import java.util.ArrayList;

// @lc code=start
class Solution {
    // Two pointers + greedy + interval
    // T: O(m + n)
    // S: O(1)
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        final int n1 = firstList.length; 
        final int n2 = secondList.length;
        if (n1 == 0 || n2 == 0) {
            return new int[0][0];
        }

        List<int[]> res = new ArrayList<>();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            int start1 = firstList[i][0], end1 = firstList[i][1], 
                start2 = secondList[j][0], end2 = secondList[j][1];
            // if (start1 > end2) {
            //     ++j;
            //     continue;
            // }
            // if (start2 > end1) {
            //     ++i;
            //     continue;
            // }
            // if (start1 == start2 && end1 == end2) {
            //     res.add(new int[]{start1, end1});
            //     ++i;
            //     ++j;
            // } else if (start1 <= end2 && start1 >= start2) {
            //     if (end1 > end2) {
            //         res.add(new int[]{start1, end2});
            //         ++j;
            //     } else {
            //         res.add(new int[]{start1, end1});
            //         ++i;
            //     }
            // } else if (start2 <= end1 && start2 >= start1) {
            //     if (end2 > end1) {
            //         res.add(new int[]{start2, end1});
            //         ++i;
            //     } else {
            //         res.add(new int[]{start2, end2});
            //         ++j;
            //     }
            // }
            int start = Math.max(start1, start2); 
            int end;  // end = min(end1, end2);
            if (end1 < end2) {
                end = end1;
                ++i;
            } else {
                end = end2;
                ++j;
            }
            if (start <= end) {
                res.add(new int[]{start, end});
            }
        }
        
        return res.toArray(new int[res.size()][]);
    }
}
// @lc code=end

