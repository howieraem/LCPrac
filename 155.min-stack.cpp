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

class MinStack {
private:
    stack<data_pt> stk;

public:
    MinStack() {}
    
    void push(int val) {
        stk.emplace(val, std::min(val, stk.size() ? getMin() : val));
    }
    
    void pop() {
        if (stk.size()) {
            stk.pop();
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
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

