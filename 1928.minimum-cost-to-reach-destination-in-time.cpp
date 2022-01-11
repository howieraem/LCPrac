/*
 * @lc app=leetcode id=1928 lang=cpp
 *
 * [1928] Minimum Cost to Reach Destination in Time
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(V + E * log(V))
    // S: O(V + E)
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        const int E = edges.size(), V = fees.size();
        vector<vector<vector<int>>> A(1001);
        for (const auto &e : edges) {
            A[e[0]].push_back({e[1], e[2], fees[e[1]]});
            A[e[1]].push_back({e[0], e[2], fees[e[0]]});
        }

        vector<int> cost(1001, INT_MAX), time(1001, INT_MAX);
        cost[0] = fees[0];
        time[0] = 0;

        // Modified Dijkstra's Algo
        // min-heap is used, which compares cost first and then time
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[0], time[0], 0}); // (cost, time, vertex), start from vertex 0

        while (pq.size()) {
            vector<int> info = pq.top(); pq.pop();
            int c = info[0], t = info[1], v = info[2];
            if (v == V - 1)  return c;

            for (int i = 0; i < A[v].size(); ++i) {
                int c_next = A[v][i][0], t_next = A[v][i][1], v_next = A[v][i][2];
                if (t + t_next <= maxTime) {
                    if (cost[c_next] > c + v_next || time[c_next] > t + t_next) {    // if cost or time will decrease 
                        cost[c_next] = c + v_next;
                        time[c_next] = t + t_next;
                        pq.push({cost[c_next], time[c_next], c_next});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

