/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include <functional>
#include <queue>
#include <vector>

using std::greater;
using std::priority_queue;
using std::vector;

// @lc code=start
class MedianFinder {
    // S: O(n)
    priority_queue<int> small;  // max heap
    priority_queue<int, vector<int>, greater<int>> large;   // min heap

public:
    // T: O(log(n))
    void addNum(int num) {
        small.push(num);
        large.push(small.top()); small.pop();
        if (small.size() < large.size()) {
            small.push(large.top()); large.pop();
        }
    }

    // T: O(1)
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

