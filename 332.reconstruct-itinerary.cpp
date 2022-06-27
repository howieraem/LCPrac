/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::priority_queue;
using std::unordered_map;

// @lc code=start
class Solution {
public:
    // T: O(E*log(E)), E := the number of edges
    // S: O(E)
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> res;
        res.reserve(tickets.size());
        string start = "JFK";
        dfs(start, graph, res);

        // In dfs(), node is added to result container at the end, 
        // so need to reverse the order
        std::reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string& airport, unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>>& graph, vector<string>& res) {
        auto next_airports = &graph[airport];
        while (next_airports->size()) {
            string next_airport = next_airports->top(); next_airports->pop();
            dfs(next_airport, graph, res);
        }
        res.push_back(airport);
    }
};
// @lc code=end

