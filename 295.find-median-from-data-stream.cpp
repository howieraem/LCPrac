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
// Dual heaps
class MedianFinder {
    // S: O(n)
    priority_queue<int> small;  // max heap storing the smaller half of the elements
    priority_queue<int, vector<int>, greater<int>> large;   // min heap storing the larger half of the elements
    
public:
    // T: O(log(n))
    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
        } else {
            large.push(num);
        }
        
        // Balance heap sizes.
        // If the total number of elements is odd, make the max heap store one more element,
        // so that its top is the median.
        if (small.size() < large.size()) {
            small.push(large.top()); large.pop();
        } else if (small.size() > large.size() + 1) {
            large.push(small.top()); small.pop();
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

