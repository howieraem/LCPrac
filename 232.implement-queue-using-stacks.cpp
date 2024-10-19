/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <stack>

using std::stack;

// @lc code=start
// S: O(n)
class MyQueue {
    stack<int> s_push, s_pop;

    void transfer() {
        if (s_pop.empty()) {
            while (!s_push.empty()) {
                s_pop.push(s_push.top()); s_push.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    // O(1)
    void push(int x) {
        s_push.push(x);
    }

    // Amortised: O(1)
    int pop() {
        int ans = peek();
        s_pop.pop();
        return ans;
    }

    // Amortised: O(1)
    int peek() {
        transfer();
        return s_pop.top();
    }

    // O(1)
    bool empty() {
        return s_push.empty() && s_pop.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

