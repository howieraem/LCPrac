/*
 * @lc app=leetcode id=729 lang=java
 *
 * [729] My Calendar I
 */
import java.util.*;

// @lc code=start
class MyCalendar {
    private TreeSet<int[]> bookings;

    public MyCalendar() {
        bookings = new TreeSet<int[]>((int[] a, int[] b) -> a[0] - b[0]);
    }

    // O(log(n))
    public boolean book(int start, int end) {
        int[] booking = new int[] {start, end};
        int[] ceil = bookings.ceiling(booking);
        if (ceil != null && ceil[0] < end) return false;
        int[] floor = bookings.floor(booking);
        if (floor != null && start < floor[1]) return false; 
        bookings.add(booking);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
// @lc code=end

