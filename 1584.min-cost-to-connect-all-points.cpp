/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */
#include <bits/stdc++.h>

using std::array;
using std::greater;
using std::priority_queue;
using std::vector;

// @lc code=start
// Find the minimum spanning tree (MST)
class Solution {
public:
    /*
    // Solution 1: Kruskal's Algorithm, edges sorted by cost/weight and then union find
    struct UF {
        vector<int> parent;
        vector<int> rank;
        int count;

        UF(int n) : parent(n), rank(n, 0), count(n) {
            for (int i = 0; i < n; ++i) parent[i] = i;
        }

        bool connect(int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) return false;
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
                ++rank[pu];
            } else {
                parent[pu] = pv;
            }
            --count;
            return true;
        }

        int find(int u) {
            while (u != parent[u]) {
                parent[u] = parent[parent[u]];
                u = parent[u];
            }
            return u;
        }
    };

    // T: O(n ^ 2 * log(n)) as there are n*(n-1)/2 possible undirected edges for n points and log(n^2) = 2log(n)
    // S: O(n ^ 2)
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<array<int, 3>> edges;  // an edge is represented as (cost, u, v)
        edges.reserve((n * (n - 1)) >> 1);  // there are n*(n-1)/2 pairs of points
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back({
                        std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]),
                        i,
                        j});
            }
        }

        // sort edges by cost ASC
        std::sort(edges.begin(), edges.end(), [] (const auto& e1, const auto& e2) { return e1[0] < e2[0]; });

        // Connect until the graph is connected, i.e. 1 connected component
        UF uf(n);
        int ans = 0;
        for (const auto& [cost, i, j] : edges) {
            if (uf.connect(i, j)) {
                ans += cost;
            }
            if (uf.count == 1) break;
        }
        return ans;
    }
    */
    
    using neighbor = std::pair<int, int>;  // (neighbor vertex, edge cost)

    // Solution 2: Prim's Algorithm, min heap
    // T: O(n ^ 2 * log(n)) might be slightly faster than Kruskal's Algorithm as edges are pushed to heap only before all points are connected
    // S: O(n ^ 2)
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        // Build an adjacency list
        vector<vector<neighbor>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                adj[i].emplace_back(j, cost);
                adj[j].emplace_back(i, cost);
            }
        }

        auto comparator = [] (const neighbor& v1, const neighbor& v2) { return v1.second > v2.second; };
        priority_queue<neighbor, vector<neighbor>, decltype(comparator)> min_heap(comparator);
        vector<uint8_t> vis(n, 0);
        
        // Start from the first point
        for (auto& p0_neighbor : adj[0]) {
            min_heap.push(std::move(p0_neighbor));
        }
        vis[0] = 1;
        int n_connected = 1;

        int ans = 0;
        while (min_heap.size() && n_connected < n) {
            auto [v, cost] = min_heap.top(); min_heap.pop();
            if (!vis[v]) {
                vis[v] = 1;
                ++n_connected;
                ans += cost;

                for (auto& v_neighbor : adj[v]) {
                    if (!vis[v_neighbor.first]) {
                        min_heap.push(std::move(v_neighbor));
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

