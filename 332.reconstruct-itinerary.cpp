/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
#include <bits/stdc++.h>

using std::greater;
using std::string;
using std::vector;
using std::priority_queue;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // Find the Eulerian path: visit each edge once and only once; if multiple paths possible, return the one with smallest lexical order
    // T: O(E*log(E)), E := the number of edges
    // S: O(E)
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;  // key is a vertex, value is a min heap of neighbor vertices as we need smallest lexical order
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> res;
        res.reserve(tickets.size());
        string start = "JFK";
        dfs(start, graph, res);

        // IMPORTANT: In DFS, nodes are visited in stack order (the later ones are added to result container first), 
        // so need to reverse the order
        std::reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string& airport, unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>>& graph, vector<string>& res) {
        auto p_next_airports = &graph[airport];
        while (p_next_airports->size()) {
            string next_airport = p_next_airports->top(); p_next_airports->pop();
            dfs(next_airport, graph, res);
        }
        res.push_back(std::move(airport));
    }
};
// @lc code=end

