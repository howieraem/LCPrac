/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(V+E) = O(m*n + m*n) = O(m*n), m := len(words), n := max(len(w) for w in words)
    // S: O(m*n)
    string alienOrder(vector<string>& words) {
        // Build graph
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDeg;
        for (const auto& w : words) {
            for (const auto& c : w) {
                // IMPORTANT: initialize for all chars 0 in-deg to distinguish from non-existent chars
                inDeg[c] = 0; 
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            string pre = words[i - 1], cur = words[i];
            int n = min(pre.size(), cur.size());
            
            // By comparing the adjacent words, the first character that is different between 
            // two adjacent words reflect the lexicographical order
            for (int j = 0; j < n; ++j) {
                if (pre[j] != cur[j]) {
                    graph[pre[j]].insert(cur[j]);

                    // IMPORTANT: we may update inDeg here rather than below, but need to check 
                    // if graph[pre[j]] already contains cur[j]
                    
                    break;
                }

                // The word order is probably incorrect, because when pre[:n] == cur[:n] but len(pre) > len(cur),
                // namely cur is a prefix of pre, then lexicographically pre > cur. Impossible to give a solution.
                if (j == n - 1 && pre.size() > cur.size())  return "";
            }
        }
        for (const auto& [_, neighbors] : graph) {
            for (const auto& u : neighbors) {
                ++inDeg[u];
            }   
        }

        // Topological sort
        queue<char> q;
        for (const auto& [u, deg] : inDeg) {
            if (deg == 0)  q.push(u);
        }
        string res;
        res.reserve(inDeg.size());
        while (q.size()) {
            char u = q.front(); q.pop();
            res.push_back(u);

            auto it = graph.find(u);
            if (it != graph.end()) {
                for (const auto &v : it->second) {
                    if (--inDeg[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
        // If any cycles exist, then it's impossible to form a solution
        return res.size() == inDeg.size() ? res : "";
    }
};
// @lc code=end

