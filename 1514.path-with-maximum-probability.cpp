/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */
#include <queue>
#include <vector>
#include <utility>

using std::pair;
using std::priority_queue;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(V + E * log(V))
    // S: O(V + E)
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& probs, int start, int end) {
        vector<vector<pair<int, double>>> G(n);
        for (int i = 0; i < edges.size(); ++i) {
            G[edges[i][0]].push_back({edges[i][1], probs[i]});
            G[edges[i][1]].push_back({edges[i][0], probs[i]});
        }
        bool vis[n];    // avoid using vector<bool>
        fill_n(vis, n, false);
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        priority_queue<pair<double, int>> q;
        q.push({1.0, start});

        while (q.size()) {
            auto top = q.top(); q.pop();
            int v = top.second;
            if (!vis[v]) {
                vis[v] = true;
                double prob = top.first;
                for (const auto &to : G[v]) {
                    int nextV = to.first;
                    double nextP = to.second;
                    if (maxProb[nextV] < nextP * prob) {
                        maxProb[nextV] = nextP * prob;
                        q.push({maxProb[nextV], nextV});
                    }
                }
            }
        }
        return maxProb[end];
    }
};
// @lc code=end

