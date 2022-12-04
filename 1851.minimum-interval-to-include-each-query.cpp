/*
 * @lc app=leetcode id=1851 lang=cpp
 *
 * [1851] Minimum Interval to Include Each Query
 */
#include <bits/stdc++.h>

using std::greater;
using std::priority_queue;
using std::vector;
using std::unordered_map;

// @lc code=start
using interval_info = std::pair<int, int>;

class Solution {
public:
    // T: O(n * log(n) + q * log(q)), n := len(intervals), q := len(queries)
    // S: O(n + q)
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        vector<int> queries_copy = queries;
        std::sort(queries_copy.begin(), queries_copy.end());

        // priority queue of (interval size, interval end)
        priority_queue<interval_info, vector<interval_info>, greater<interval_info>> min_heap;

        int i = 0;
        unordered_map<int, int> raw_res;

        // Iterate queries from small value to large value (not in the original order)
        for (const int& q : queries_copy) {
            // Add intervals possibly containing q
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                min_heap.emplace(r - l + 1, r);
                ++i;
            }

            // Remove intervals not containing q
            while (!min_heap.empty() && min_heap.top().second < q) {
                min_heap.pop();
            }

            // Now if the heap is not empty, then the heap top 
            // is the minimum size of the interval containing q,
            // otherwise none of the intervals contain q
            raw_res[q] = min_heap.empty() ? -1 : min_heap.top().first;
        }

        // Restore the original query order
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = raw_res[queries[i]];
        }
        return res;
    }
};
// @lc code=end

