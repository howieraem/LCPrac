class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        curMin = INT_MAX;
    }
    
    void push(int x) {
        // If x is the new minimum, push the old minimum to the stack first
        // and then x, so that curMin can be updated easily in pop()
        if (x <= curMin) {
            data.push_back(curMin);
            curMin = x;
        }
        data.push_back(x);
    }
    
    void pop() {
        auto top = data.back();
        data.pop_back();
        // Since the former min value is always in front of the curMin value,'
        // curMin can be set to that former value if it gets popped
        if (top == curMin) {
            curMin = data.back();
            data.pop_back();
        }
    }
    
    int top() {
        return data.back();
    }
    
    int min() {
        return curMin;
    }

private:
    vector<int> data;
    int curMin;     
};
