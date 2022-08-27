/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <bits/stdc++.h>

// @lc code=start
typedef std::pair<int, int> booking;

class MyCalendar {
    std::set<booking> bookings;

public:
    MyCalendar() {}

    // O(log(n))
    bool book(int start, int end) {
        booking b(start, end);
        auto next = bookings.upper_bound(b);
        if (next != bookings.end() && next->first < end) return false; // equivalent to Java's TreeMap.ceiling()
        if (next != bookings.begin() && start < std::prev(next)->second) return false; // equivalent to Java's TreeMap.floor()
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

