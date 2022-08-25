/*
 * @lc app=leetcode id=2034 lang=cpp
 *
 * [2034] Stock Price Fluctuation 
 */
#include <bits/stdc++.h>

using std::map;
using std::unordered_map;

// @lc code=start
class StockPrice {
    std::unordered_map<int, int> records;

    // Below might be replaced with std::multiset. Reference: 
    // https://leetcode.com/problems/stock-price-fluctuation/discuss/1513413
    map<int, int> price_counts;

    int latest_time = -1;

public:
    StockPrice() {}
    
    // T: O(log(n))
    void update(int timestamp, int price) {
        latest_time = std::max(latest_time, timestamp);
        if (records.find(timestamp) != records.end()) {
            int pre_price = records[timestamp];
            auto it = price_counts.find(pre_price);
            if (it->second == 1) {
                price_counts.erase(pre_price);
            } else {
                it->second--;
            }
        }
        records[timestamp] = price;
        price_counts[price]++;
    }
    
    // T: O(1)
    int current() {
        return records[latest_time];
    }
    
    // T: O(1)
    int maximum() {
        return price_counts.rbegin()->first;
    }
    
    // T: O(1)
    int minimum() {
        return price_counts.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

