import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=295 lang=java
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
    // S: O(n)
    private PriorityQueue<Integer> minHeap;  // stores the larger half of the elems
    private PriorityQueue<Integer> maxHeap;  // stores the smaller half of the elems

    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b, a));
    }
    
    // T: O(log(n))
    public void addNum(int num) {
        if (minHeap.isEmpty() || num >= minHeap.peek()) {
            minHeap.add(num);
        } else {
            maxHeap.add(num);
        }
        
        // If the total number of elements is odd, make the larger half 
        // contain exactly one more element than the smaller half.
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.add(minHeap.poll());
        } else if (minHeap.size() < maxHeap.size()) {
            minHeap.add(maxHeap.poll());
        }
    }
    
    // T: O(1)
    public double findMedian() {
        // If the number of elements is odd, the median is the top of the min heap (minimum of the larger half of the elements)
        // Otherwise, the median is the average of the 2 heap tops.
        return minHeap.size() == maxHeap.size() ? (minHeap.peek() + maxHeap.peek()) / 2. : minHeap.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
// @lc code=end

