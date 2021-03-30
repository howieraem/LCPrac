/*
 * @lc app=leetcode.cn id=352 lang=java
 *
 * [352] 将数据流变为多个不相交区间
 */
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.List;
import java.util.ArrayList;

// @lc code=start
class SummaryRanges {
    SortedSet<Integer> data;

    /** Initialize your data structure here. */
    public SummaryRanges() {
        data = new TreeSet<>();
    }
    
    public void addNum(int val) {
        data.add(val);
    }
    
    public int[][] getIntervals() {
        List<int[]> intervals = new ArrayList<>();
        int left = data.first(), right = data.first();
        for (int num : data) {
            if (num > right + 1) {
                // add the previous interval to the result and update begining of the new interval
                intervals.add(new int[]{left, right});
                left = num;
            }
            right = num;
        }
        intervals.add(new int[]{left, right});  // don't forget the last interval

        int[][] res = new int[intervals.size()][2];
        for (int i = 0; i < res.length; ++i) {
            res[i] = intervals.get(i);
        }
        return res;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * int[][] param_2 = obj.getIntervals();
 */
// @lc code=end

