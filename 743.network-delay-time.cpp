/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
/** 
 * Actual Question: 
 * Find the shortest path (path with the least cost/weight) to cover all nodes. 
 * If any nodes are not covered, return -1.
 */
class Solution {
public:
    /*
    // Bellman Ford Algorithm: works with negative weights. Dijkstra's algorithm
    // only works with non-negative weights. However, time complexity is O(V*E).
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);   // add 1 because of 1-indexed nodes
        dist[k] = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
    */

    // Dijkstra's algorithm, O(V + E*log(V))
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (const auto &e : times) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        int u, v, w;
        while (!pq.empty()) {
            pair<int, int> p = pq.top(); pq.pop();
            u = p.second;
            for (const auto &t : g[u]) {
                v = t.first, w = t.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

