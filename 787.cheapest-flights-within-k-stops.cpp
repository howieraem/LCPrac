/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <bits/stdc++.h>

using std::greater;
using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

// @lc code=start
using state = std::array<int, 3>;  // (cost, next_vertex, no_of_stops)

class Solution {
public:
    /*
    // Solution 1: Variant of Dijkstra's Algorithm
    // T: O(E * k * log(E * k)), E := len(flights)
    // S: O(E * k)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build graph
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        priority_queue<state, vector<state>, greater<state>> min_heap;
        vector<int> stops(n, INT_MAX);

        min_heap.push({0, src, 0});

        // The heap will store at max E*k values which will happen when `dst` cannot be reached in k stops
        while (min_heap.size()) {
            auto [cost, u, cur_stops] = min_heap.top(); min_heap.pop();
            // IMPORTANT: 1. pruning; 2. at most k edges => at most k+1 nodes
            if (cur_stops > stops[u] || cur_stops > k + 1) {
                continue;
            }
            if (u == dst) return cost;
            stops[u] = cur_stops++;
            
            for (const auto& [v, w] : adj[u]) {
                min_heap.push({cost + w, v, cur_stops});
            }

        }
        return -1;
    }
    */

    /*
    // Solution 2: Variant of Bellman-Ford Algorithm (also works for negative edge weights)
    // T: O((E + n) * k)
    // S: O(n)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        // IMPORTANT: looping k+1 instead of n times
        for (int i = 0; i <= k; ++i) {
            vector<int> tmp(cost);

            for (const auto& e : flights) {
                if (cost[e[0]] != INT_MAX && tmp[e[1]] > cost[e[0]] + e[2]) {
                    tmp[e[1]] = cost[e[0]] + e[2];
                }
            }
            
            cost.swap(tmp);
        }

        return cost[dst] != INT_MAX ? cost[dst] : -1;
    }
    */

    // Solution 3: BFS, variant of level-order traversal, with cost array and constraint k
    // T: O(E * k)
    // S: O(E * k + n)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build graph
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // IMPORTANT: the queue needs to store both vertex and cur_cost, because 
        // the cost of a vertex can be updated multiple times
        queue<pair<int, int>> q;
        vector<int> cost(n, INT_MAX);  // acts as the visited array and helps pruning

        q.emplace(src, 0);
        cost[src] = 0;

        ++k;  // at most k edges => at most k+1 nodes
        
        while (k-- != 0 && q.size()) {
            int qs = q.size();

            while (qs-- > 0) {
                auto [u, cur_cost] = q.front(); q.pop();

                for (const auto& [v, w] : adj[u]) {
                    if (cost[v] > cur_cost + w) {
                        cost[v] = cur_cost + w;
                        q.emplace(v, cost[v]);
                    }
                }
            }
        }
        return cost[dst] != INT_MAX ? cost[dst] : -1;
    }
};
// @lc code=end

