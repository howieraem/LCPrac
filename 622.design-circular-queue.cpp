/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */
#include <memory>

// @lc code=start
// Array and pointers
// T: O(1)
// S: O(k)
class MyCircularQueue {
    int cap;  // max capacity 
    int len;  // current size
    int front;  // front pointer
    int rear;   // rear pointer
    std::unique_ptr<int[]> arr;

public:
    MyCircularQueue(int k) : cap{k}, arr{new int[k]}, front{0}, rear{-1}, len{0} {}
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % cap;    // if (++rear == cap) rear = 0;
        arr[rear] = value;
        ++len;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % cap;  // if (++front == cap) front = 0;
        --len;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == cap;     
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

