/*
 * @lc app=leetcode id=716 lang=cpp
 *
 * [716] Max Stack
 */
#include <bits/stdc++.h>

// @lc code=start
// Solution 1: Red-black tree and doubly linked list
class MaxStack {
    std::list<int> l;
    std::map<int, std::vector<std::list<int>::iterator>> mp;

public:
    MaxStack() {}

    // T: O(log(n))
    void push(int x) {
        l.push_front(x);
        mp[x].push_back(l.begin());
    }
    
    // T: O(log(n))
    int pop() {
        int x = l.front();
        mp[x].pop_back();
        if (mp[x].empty()) {
            mp.erase(x);
        }
        l.pop_front();
        return x;
    }
    
    // T: O(1)
    int top() {
        return l.front();    
    }
    
    // T: O(1)
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    // T: O(log(n))
    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp.rbegin()->second.back();

        // One thing worth pointing attention to is C++ iterator validity 
        // after erase() operations. For data structures such as lists 
        // and set and unordered_sets, an iterator to any element besides 
        // the one that gets erased() remain valid. For other data structures 
        // such as vectors and deques, this is not the case. 
        l.erase(it);
        mp[x].pop_back();

        if (mp[x].empty()) {
            mp.erase(x);
        }
        return x;
    }
};
/*
// Solution 2: Dual stacks
class MaxStack {
    // s1 for normal numbers, s2 for local maxima
    std::stack<int> s1, s2;

public:
    MaxStack() {}

    // T: O(1)
    void push(int x) {
        s1.push(x);
        if (s2.empty() || s2.top() <= x) {
            s2.push(x);
        }
    }
    
    // T: O(1)
    int pop() {
        int x = s1.top(); s1.pop();
        if (x == peekMax()) {
            s2.pop();
        }
        return x;
    }
    
    // T: O(1)
    int top() {
        return s1.top();
    }
    
    // T: O(1)
    int peekMax() {
        return s2.top();
    }
    
    // T: O(n)
    int popMax() {
        int x = peekMax();
        std::stack<int> tmp;
        while (x != top()) {
            tmp.push(pop());
        }
        pop();
        while (tmp.size()) {
            push(tmp.top()); tmp.pop();
        }
        return x;
    }
};
*/

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
// @lc code=end

