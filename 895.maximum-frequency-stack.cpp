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
    unordered_map<int, int> num_to_cnts;
    unordered_map<int, stack<int>> cnt_to_nums;

public:
    FreqStack() {}

    // T: O(1)
    void push(int val) {
        int cnt = num_to_cnts[val] + 1;
        cnt_to_nums[cnt].push(val);
        num_to_cnts[val] = cnt;

        // Note that the same val might present in multiple stacks 
        // as its count increments (space-expensive but time-cheap)
        max_cnt = std::max(max_cnt, cnt);
    }
    
    // T: O(1)
    int pop() {
        auto st = &cnt_to_nums[max_cnt];
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

