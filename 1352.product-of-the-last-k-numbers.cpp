/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class ProductOfNumbers {
    vector<int> prefix_product;

public:
    ProductOfNumbers() {
        prefix_product = {1};
    }
    
    // T: O(1)
    void add(int num) {
        if (num == 0) {
            // If a 0 is added, all prefix products before become invalid
            prefix_product = {1};
        } else {
            prefix_product.push_back(prefix_product.back() * num);
        }
    }
    
    // T: O(1)
    int getProduct(int k) {
        const int n = prefix_product.size();
        if (k >= n) {
            // Either k is too large, or there was a 0 added before.
            // k == n also returns 0 because there's a leading 1 in the array
            return 0;
        }
        // IMPORTANT
        return prefix_product[n - 1] / prefix_product[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

