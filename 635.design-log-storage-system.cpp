/*
 * @lc app=leetcode id=635 lang=cpp
 *
 * [635] Design Log Storage System
 */
#include <bits/stdc++.h>

using std::map;
using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class LogSystem {
    const string T_MIN = "1970:00:00:00:00:00";
    const string T_MAX = "2017:12:31:23:59:59";
    const unordered_map<string, int> GRAN_IDX {
            {"Year", 4}, {"Month", 7}, {"Day", 10},
            {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
    map<string, int> log;  // keys ordered (assume no duplicate timestamps)
    // If a timestamp corresponds to multiple ids, use map<string, vector<int>>

public:
    LogSystem() {}
    
    // T: O(log(n))
    void put(int id, string timestamp) {
        log.emplace(timestamp, id);
    }
    
    // T: O(log(n) + (t_end - t_start))
    // S: O(len(timestamp))
    vector<int> retrieve(string start, string end, string granularity) {
        auto gran_it = GRAN_IDX.find(granularity);
        if (gran_it == GRAN_IDX.end()) {
            return {};
        }

        int slice_idx = gran_it->second;
        start = start.substr(0, slice_idx) + T_MIN.substr(slice_idx);
        end = end.substr(0, slice_idx) + T_MAX.substr(slice_idx);

        auto it_start = log.lower_bound(start);
        auto it_end = log.upper_bound(end);
        vector<int> res;
        res.reserve(std::distance(it_start, it_end));
        for (auto it = it_start; it != it_end; ++it) {
            res.push_back(it->second);
            // If a timestamp corresponds to multiple ids, add all ids from that vector<int> to res
        }
        return res;
    }
};

/**
 * Follow up: What if the number of logs is extremely large?
 * 
 * Can use a Trie: year->month->day->hour->minute->second
 * Each trie node has children stored in an ordered map
 * More specifically:
 * - Root: map<int, TrieNode*> children;
 * - Year: vector<TrieNode*> children(12);
 * - Month: vector<TrieNode*> children(31);
 * - etc.
 */

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
// @lc code=end

