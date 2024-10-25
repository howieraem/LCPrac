/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include <stack>
#include <utility>

using std::pair;
using std::stack;

// @lc code=start
typedef pair<int, int> data_pt; // (value, min_value_when_value_was_inserted)

// S: O(n)
class MinStack {
    stack<data_pt> stk;

public:
    MinStack() {}
    
    // T: O(1)
    void push(int val) {
        stk.emplace(val, stk.empty() ? val : std::min(val, getMin()));
    }
    
    // T: O(1)
    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }
    
    // T: O(1)
    int top() {
        return stk.top().first;
    }
    
    // T: O(1)
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

