/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
typedef pair<string, int> sc;

class Solution {
public:
    // T: O(n * log(k))
    // S: O(n)
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        for (const string &w : words) {
            ++f[w];
        }

        // sort by count and then by natural order
        auto cmp = [&](const sc &p1, const sc &p2) {
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        };
        priority_queue<sc, vector<sc>, decltype(cmp)> q(cmp);

        for (const auto &e : f) {
            q.push(e);
            if (q.size() > k)  q.pop();
        }

        vector<string> res;
        while (q.size()) {
            res.push_back(q.top().first); q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

