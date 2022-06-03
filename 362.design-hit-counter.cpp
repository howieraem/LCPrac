/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 */
#include <vector>

// @lc code=start
const int MAX_SECS = 300;

// Idea: for getHits(), we don't care about hits before 300s ago. Also, 
// there are constraints on function calls. Thus, we can use buckets.
// S: O(s), s := MAX_SECS
class HitCounter {
    std::vector<int> times, hits;

public:
    HitCounter() : times(MAX_SECS), hits(MAX_SECS) {}
    
    // T: O(1)
    void hit(int timestamp) {
        int idx = timestamp % MAX_SECS;
        if (times[idx] != timestamp) {
            // Reset if entering the next 5-minute interval
            times[idx] = timestamp;
            hits[idx] = 1;
        } else {
            ++hits[idx];
        }
    }
    
    // T: O(s)
    int getHits(int timestamp) {
        int ans = 0;
        for (int i = 0; i < MAX_SECS; ++i) {
            if (timestamp - times[i] < MAX_SECS) {
                ans += hits[i];
            }
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
// @lc code=end

