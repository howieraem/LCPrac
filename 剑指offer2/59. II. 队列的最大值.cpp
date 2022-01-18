#include <bits/stdc++.h>

using std::queue;
using std::deque;

class MaxQueue {
public:
    MaxQueue() {}
    
    int max_value() {
        return dq.empty() ? -1 : dq.front();
    }
    
    void push_back(int value) {
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        dq.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())  return -1;
        int ans = q.front();
        if (ans == dq.front()) {
            dq.pop_front();
        }
        q.pop();
        return ans;
    }

private:
    queue<int> q;
    deque<int> dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */