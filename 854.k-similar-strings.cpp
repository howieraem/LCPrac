/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */
#include <bits/stdc++.h>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
    // Graph BFS - least steps from one node to another
    // T: O((alpha_size ^ n) * n ^ 2), n := len(s1)
    // S: O(alpha_size ^ n)
    int kSimilarity(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return -1;
        }
        if (s1 == s2) {
            return 0;
        }

        queue<string> q;
        unordered_set<string> vis;
        q.push(s1);
        vis.insert(s1);

        int lvl = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                for (auto& nxt : get_neighbors(q.front(), s2)) {
                    if (vis.find(nxt) == vis.end()) {
                        if (nxt == s2) {
                            return lvl + 1;
                        }
                        vis.insert(nxt);
                        q.push(std::move(nxt));
                    }
                }
                q.pop();
            }
            ++lvl;
        }

        return -1;
    }

private:
    // Instead of trying all swaps, swap iff the next state has one more match to s2.
    vector<string> get_neighbors(string& s1, const string& s2) {
        vector<string> res;
        int i = 0;
        while (i < s1.size() && s1[i] == s2[i]) {
            ++i;
        }

        for (int j = i + 1; j < s1.size(); ++j) {
            if (s1[j] == s2[i]) {  
                // find next swap that can increase matches
                std::swap(s1[i], s1[j]);
                res.push_back(string(s1));
                std::swap(s1[i], s1[j]);  // IMPORTANT undo
            }
        }
        return res;
    }
};
// @lc code=end

