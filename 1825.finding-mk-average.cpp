/*
 * @lc app=leetcode id=1825 lang=cpp
 *
 * [1825] Finding MK Average
 */
#include <bits/stdc++.h>

using std::multiset;
using std::vector;

// @lc code=start
class MKAverage {
    size_t m, k, sz, p;
    long sum;
    vector<int> circular;  // can also use a queue

    // std::multiset is implemented with balanced tree (red-black tree, AVL tree, etc.).
    // Rebalance the following sets when adding or removing numbers,
    // such that the sizes of left and right are both k.
    multiset<int> left, mid, right;

    // Rebalance helper functions
    void add(int x) {
        left.insert(x);
        if (left.size() > k) {
            auto it = std::prev(left.end());
            mid.insert(*it);
            sum += *it;
            left.erase(it);
        }
        if (mid.size() > sz) {
            auto it = std::prev(mid.end());
            right.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }

    void remove(int x) {
        if (x <= *left.rbegin()) {
            left.erase(left.find(x));
        } else if (x <= *mid.rbegin()) {
            auto it = mid.find(x);
            sum -= *it;
            mid.erase(it);
        } else {
            right.erase(right.find(x));
        }

        if (left.size() < k) {
            auto mid_min_it = mid.begin();
            left.insert(*mid_min_it);
            sum -= *mid_min_it;
            mid.erase(mid_min_it);
        }
        if (mid.size() < sz) {
            auto right_min_it = right.begin();
            mid.insert(*right_min_it);
            sum += *right_min_it;
            right.erase(right_min_it);
        }
    }

public:
    MKAverage(int m, int k) : m(m), k(k), sz(m - (k << 1)), p(0), sum(0), circular(m) {}
    
    // T: O(log(m))
    void addElement(int num) {
        if (p >= m) {
            remove(circular[p % m]);
        }
        add(num);
        circular[p++ % m] = num;
    }
    
    // T: O(1)
    int calculateMKAverage() {
        return p >= m ? sum / sz : -1;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
// @lc code=end

