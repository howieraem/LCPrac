/*
 * @lc app=leetcode id=1188 lang=cpp
 *
 * [1188] Design Bounded Blocking Queue
 */
#include <condition_variable>
#include <mutex>
#include <queue>

using std::condition_variable;
using std::lock_guard;
using std::mutex;
using std::queue;
using std::unique_lock;

// @lc code=start
class BoundedBlockingQueue {
    queue<int> q;
    int cap;
    mutex mux;
    condition_variable full, empty;

public:
    BoundedBlockingQueue(int capacity) : cap(capacity) {}
    
    void enqueue(int element) {
        unique_lock<mutex> lock(mux);
        full.wait(lock, [this] { return q.size() != cap; });
        q.push(element);
        empty.notify_one();
    }

    int dequeue() {
        unique_lock<mutex> lock(mux);
        empty.wait(lock, [this] { return !q.empty(); });
        int front = q.front(); q.pop();
        full.notify_one();
        return front;
    }
    
    int size() {
        lock_guard<mutex> lock(mux);
        return q.size();
    }
};
// @lc code=end

