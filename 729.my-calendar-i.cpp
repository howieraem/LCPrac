/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <bits/stdc++.h>

// @lc code=start
typedef std::pair<int, int> booking;

// S: O(n)
class MyCalendar {
    std::set<booking> bookings;

public:
    MyCalendar() {}

    // T: O(log(n))
    bool book(int start, int end) {
        booking b(start, end);
        auto next = bookings.upper_bound(b);
        if (next != bookings.end() && next->first < end) {
            // equivalent to Java's TreeMap.ceiling()
            // there is an existing interval with start < the booking's end
            return false; 
        }
        if (next != bookings.begin() && start < std::prev(next)->second) {
            // equivalent to Java's TreeMap.floor()
            // there is an existing interval with end > the booking's start
            return false; 
        }
        bookings.insert(std::move(b));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

