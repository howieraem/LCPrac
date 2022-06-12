/*
 * @lc app=leetcode id=1606 lang=cpp
 *
 * [1606] Find Servers That Handled Most Number of Requests
 */
#include <bits/stdc++.h>

using std::pair;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(k)), n := no. of requests
    // S: O(n + k)
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> srv_reqs(k, 0);

        std::set<int> avail;
        for (int i = 0; i < k; ++i) {
            avail.insert(i);
        }

        // PQ with elements (end_time, srv_id)
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        
        for (int i = 0; i < arrival.size(); ++i) {
            int t_cur = arrival[i], t_end = t_cur + load[i];

            // Find available servers with end time of previous request
            // less than or equal to the time of current request
            while (busy.size() && busy.top().first <= t_cur) {
                // busy.pop() at most (n - k) times
                int srv = busy.top().second; busy.pop();
                avail.insert(srv);
            }

            if (avail.empty()) continue;  // all busy, drop request

            // Assign req to the first available server whose index 
            // is greater than i % k in circular order. 
            auto it = avail.lower_bound(i % k);
            if (it == avail.end())  it = avail.begin();
            ++srv_reqs[*it];
            busy.emplace(t_end, *it);
            avail.erase(*it);
        }

        // Find servers that handled the most requests
        int max_reqs = *std::max_element(srv_reqs.begin(), srv_reqs.end());
        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; ++i) {
            if (srv_reqs[i] == max_reqs) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

