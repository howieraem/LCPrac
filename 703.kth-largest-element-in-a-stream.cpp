/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include <bits/stdc++.h>

// @lc code=start
class KthLargest {
    // S: O(k)
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int _k;

public:
    // T: O(n * log(k))
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto& x : nums) {
            min_heap.push(std::move(x));
            // Keep the heap size no more than k by popping the smaller values,
            // so that the heap top is always the k-th largest.
            if (min_heap.size() > k) min_heap.pop();
        }
    }
    
    // T: O(log(k))
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > _k) min_heap.pop();
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

