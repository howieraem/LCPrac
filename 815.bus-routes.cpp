/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n), n := total number of stops
    // S: O(n)
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)  return 0;    // necessary because of early returning in BFS
        unordered_map<int, vector<int>> stop2route;
        for (int i = 0; i < routes.size(); ++i) {
            for (const int &stop : routes[i]) {
                stop2route[stop].push_back(i);
            }
        }

        queue<int> q;   // stores stops
        q.push(source);
        unordered_set<int> vis;     // stores routes instead of stops visited
        int steps = 1;
        while (q.size()) {
            int qs = q.size();

            while (qs--) {
                int cur = q.front(); q.pop();
            
                for (const int &route_id : stop2route[cur]) {
                    if (vis.find(route_id) == vis.end()) {
                        vis.insert(route_id);
                        for (const int &next_stop : routes[route_id]) {
                            if (next_stop == target)  return steps; // early returning
                            else  q.push(next_stop);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};
// @lc code=end

