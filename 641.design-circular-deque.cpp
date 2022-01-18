/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */
#include <vector>

using std::vector;

// @lc code=start
class MyCircularDeque {
    vector<int> buf;
    int size, cap, front, back;
    // `front` is the back of `buf`, and
    // `back` is the front of `buf`

public:
    MyCircularDeque(int k) : buf(k, 0), size(0), cap(k), front(k - 1), back(0) {}

    bool insertFront(int value) {
        if (isFull())  return false;
        buf[front] = value;
        front = (front - 1 + cap) % cap;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())  return false;
        buf[back] = value;
        back = (back + 1) % cap;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())  return false;
        front = (front + 1) % cap;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())  return false;
        back = (back - 1 + cap) % cap;
        --size;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : buf[(front + 1) % cap];
    }
    
    int getRear() {
        return isEmpty() ? -1 : buf[(back - 1 + cap) % cap];
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

