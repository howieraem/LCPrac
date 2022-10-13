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
    // Bellman-Ford Algorithm: works with negative edge costs/weights
    // T: O(V * E)
    // S: O(V)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);   // add 1 because of 1-indexed nodes
        dist[k] = 0;
        
        for (int i = 0; i < n; ++i) {
            for (const auto &[u, v, w] : times) {
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());  // add 1 to begin() because of 1-indexed nodes
        return ans == INT_MAX ? -1 : ans;
    }
    */

    using pos = pair<int, int>;

    // Dijkstra's Algorithm. Only works with non-negative edge costs/weights.
    // T: O((V + E) * log(V))
    // S: O(V + E)
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list and convert nodes from 1-indexed to 0-indexed
        --k;
        vector<vector<pos>> adj(n);
        for (const auto &e : times) {
            adj[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        }

        // Priority queue of (edge cost, edge destination node)
        priority_queue<pos, vector<pos>, greater<pos>> min_heap;
        vector<int> dist(n, INT_MAX);

        // Start from node k
        min_heap.emplace(0, k);
        dist[k] = 0;
        
        while (min_heap.size()) {
            auto [_, u] = min_heap.top(); min_heap.pop();
            for (const auto& [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    min_heap.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

