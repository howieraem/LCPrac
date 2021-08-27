import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

/*
 * @lc app=leetcode.cn id=855 lang=java
 *
 * [855] 考场就座
 */

// @lc code=start
class ExamRoom {
    private int n;

    private Map<Integer, int[]> startMap, endMap;   // map points to segments

    // TreeSet is balanced binary tree which is sorted and has O(logN) operations.
    // It stores segments with start p and end q. When a new student comes, the
    // algorithm should find a proper segment and put the student in the middle
    // to maximize the distances.
    private TreeSet<int[]> pq;  

    public ExamRoom(int N) {
        n = N;
        startMap = new HashMap<>();
        endMap = new HashMap<>();
        pq = new TreeSet<>((a, b) -> {
            // sort segments by length
            int distA = dist(a), distB = dist(b);
            // Allocate student to the left most possible seat if distances the same
            return distA == distB ? b[0] - a[0] : distA - distB;
        });
        // Add a dummy segment, like in a custom linked list,
        // such that when there are less than 3 students,
        // they are allocated to the left most and right
        // most seats respectively.
        addSegment(new int[] {-1, N});  
    }
    
    public int seat() {
        int[] longest = pq.last();
        int p = longest[0], q = longest[1];
        int seat;
        if (p == -1)  seat = 0;
        else if (q == n)  seat = n - 1;
        else  seat = p + ((q - p) >> 1);   // avoid overflow, equivalent to (p + q) / 2

        removeSegment(longest);
        addSegment(new int[] {p, seat});    // new left segment
        addSegment(new int[] {seat, q});    // new right segment
        return seat;
    }
    
    public void leave(int p) {
        int[] rightSeg = startMap.get(p);
        int[] leftSeg = endMap.get(p);
        removeSegment(leftSeg);
        removeSegment(rightSeg);
        addSegment(new int[] {leftSeg[0], rightSeg[1]});
    }

    private void addSegment(int[] seg) {
        pq.add(seg);
        startMap.put(seg[0], seg);
        endMap.put(seg[1], seg);
    }

    private void removeSegment(int[] seg) {
        pq.remove(seg);
        startMap.remove(seg[0]);
        endMap.remove(seg[1]);
    }

    private int dist(int[] seg) {
        int p = seg[0], q = seg[1];
        if (p == -1)  return q;
        if (q == n)  return n - 1 - p;
        return (q - p) >> 1;
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
// @lc code=end

