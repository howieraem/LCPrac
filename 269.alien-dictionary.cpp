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
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDeg;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                inDeg[words[i][j]] = 0; 
            }
        }

        // Build graph
        for (int i = 1; i < words.size(); ++i) {
            string pre = words[i - 1], cur = words[i];
            int n = min(pre.size(), cur.size());
            for (int j = 0; j < n; ++j) {
                if (pre[j] != cur[j]) {
                    unordered_set<char> *st = &graph[pre[j]];
                    if (st->find(cur[j]) == st->end()) {
                        st->insert(cur[j]);
                        ++inDeg[cur[j]];
                    }
                    break;
                }
                if (j == n - 1 && pre.size() > cur.size())  return "";
            }
        }

        // Topological sort
        string res;
        queue<char> q;
        for (const auto &entry : inDeg) {
            if (!entry.second)  q.push(entry.first);
        }
        while (q.size()) {
            char cur = q.front(); q.pop();
            res.push_back(cur);

            if (graph[cur].size()) {
                for (const auto &c : graph[cur]) {
                    --inDeg[c];
                    if (!inDeg[c]) {
                        q.push(c);
                    }
                }
            }
        }
        // Check if there is any cycles
        return res.size() == inDeg.size() ? res : "";
    }
};
// @lc code=end

