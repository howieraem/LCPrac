/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target)  return 0;  // trivial
        
        const int n = stations.size();
        std::priority_queue<int> max_heap;
        int i = 0, reachable = startFuel, ans = 0;
        while (reachable < target) {
            while (i < n && stations[i][0] <= reachable) {
                // push all reachable fuels to the queue
                max_heap.push(stations[i++][1]);
            }
            if (max_heap.empty())  return -1;
            // Refuel with the maximum available one
            reachable += max_heap.top(); max_heap.pop();
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

