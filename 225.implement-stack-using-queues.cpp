/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include <bits/stdc++.h>

// @lc code=start
// S: O(n)
class MyStack {
    std::queue<int> q;

public:
    MyStack() {}
    
    // T: O(n)
    void push(int x) {
        size_t pre_qs = q.size();
        q.push(x);
        while (pre_qs-- > 0) {
            q.push(q.front()); q.pop();
        }
    }
    
    // T: O(1)
    int pop() {
        int top = q.front(); q.pop();
        return top;
    }
    
    // T: O(1)
    int top() {
        return q.front();
    }
    
    // T: O(1)
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

