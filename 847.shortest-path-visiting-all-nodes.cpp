/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
struct State {
    int mask, nodeId, cost;

    State(int _mask, int _nodeId, int _cost) {
        mask = _mask;
        nodeId = _nodeId;
        cost = _cost;
    }

    bool equals(const State &other) const {
        return mask == other.mask && nodeId == other.nodeId && cost == other.cost;
    }

    int hashCode() const {
        return 1331 * mask + 7193 * nodeId + 727 * cost;
    }
};

struct StateHash {
    size_t operator () (const State &s) const {
        return s.hashCode();
    }
};

static bool operator == (const State &l, const State &r) {
    return l.equals(r);
};

class Solution {
public:
    // T: O(N^2 * 2^N)
    // S: O(N)
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();

        queue<State> q;
        unordered_set<State, StateHash> vis;

        // 1 <= n <= 12, can use int as a bit mask to mark the nodes visited so far.
        // Note that this is not the same as State stored in the vis set. A state
        // in this problem is not just the corresponding node but also what other
        // nodes have been traversed so far, because a node can be visited multiple
        // times to get the shortest path.
        for (int i = 0; i < n; ++i) {
            int mask = (1 << i);
            q.emplace(State(mask, i, 1));
            vis.emplace(State(mask, i, 0));
        }

        while (q.size()) {
            int qs = q.size();
            while (qs--) {
                State s = q.front(); q.pop();
                if (s.mask == (1 << n) - 1)  return s.cost - 1;
                for (const int &j : graph[s.nodeId]) {
                    int mask = s.mask;
                    mask |= (1 << j);
                    State ns(mask, j, 0);
                    if (vis.find(ns) == vis.end()) {
                        q.emplace(State(mask, j, s.cost + 1));
                        vis.emplace(ns);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

