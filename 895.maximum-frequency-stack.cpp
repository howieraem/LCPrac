/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */
#include <bits/stdc++.h>

using std::stack;
using std::unordered_map;

// @lc code=start
// S: Ω(n)
class FreqStack {
    int max_cnt;
    unordered_map<int, int> num_to_cnts;  // k: a number, v: freq
    unordered_map<int, stack<int>> cnt_to_nums;  // k: freq, v: stack of nums with sample freq

public:
    FreqStack() {}

    // T: O(1)
    void push(int val) {
        int cnt = num_to_cnts[val] + 1;
        // Note that the same val might present in multiple stacks 
        // as its count increments (space-expensive but time-cheap).
        // And this logic remains correct if this value is popped
        // multiple times.
        cnt_to_nums[cnt].push(val);
        num_to_cnts[val] = cnt;

        max_cnt = std::max(max_cnt, cnt);
    }
    
    // T: O(1)
    int pop() {
        auto st = &cnt_to_nums[max_cnt];
        // If there is a tie for the most frequent element, 
        // the element closest to the stack's top is removed 
        // and returned.
        int num = st->top(); st->pop();
        num_to_cnts[num] = max_cnt - 1;
        max_cnt -= st->empty();
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

