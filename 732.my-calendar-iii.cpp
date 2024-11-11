/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */
#include <bits/stdc++.h>

using std::map;

// @lc code=start
// sweeping line
// S: O(n)
class MyCalendarThree {
    std::map<int, int> mp;  // k: time, v: count

public:
    // T: O(1)
    MyCalendarThree() {}
    
    // T: O(n)
    int book(int startTime, int endTime) {
        ++mp[startTime];
        --mp[endTime];

        int k = 0;
        int running_sum = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            running_sum += it->second;
            k = std::max(k, running_sum);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end

