/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class TimeMap {
    // If timestamps of set() for the same key is not guaranteed strictly increasing,
    // need to use a sorted map.
    // Otherwise, we can just use a vector and do binary search.
    // k: key, v: map or list of (timestamp, value)
    std::unordered_map<string, std::map<int, string>> data;
    // std::unordered_map<string, std::vector<std::pair<int, string>>> data;

public:
    TimeMap() {}
    
    // T: O(log(n)) if timestamps not sorted for the same key, or O(1) if sorted timestamps guaranteed
    void set(string key, string value, int timestamp) {
        data[key].insert({timestamp, value});

        // Vector version:
        // data[key].push_back({timestamp, value});
    }
    
    // T: O(log(n))
    string get(string key, int timestamp) {
        auto ts_it = data.find(key);
        if (ts_it == data.end()) {
            return "";
        }
        const auto& ts_map = ts_it->second;

        // Because we need the largest prev_t <= timestamp,
        // use upper_bound to find the smallest t strictly > timestamp,
        // and then get its previous value
        auto it = ts_map.upper_bound(timestamp);
        return it == ts_map.begin() ? "" : std::prev(it)->second; 

        // Vector version:
        // auto ts_it = data.find(key);
        // if (ts_it == data.end()) {
        //     return "";
        // }
        // const auto& ts_vec = ts_it->second;
        // auto it = std::upper_bound(ts_vec.begin(), ts_vec.end(), std::pair<int, string>(timestamp, ""), [](
        //     const std::pair<int, string>& a, const std::pair<int, string>& b) { return a.first < b.first; });
        // return it == ts_vec.begin() ? "" : std::prev(it)->second; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

