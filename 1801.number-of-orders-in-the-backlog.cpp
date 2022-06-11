/*
 * @lc app=leetcode id=1801 lang=cpp
 *
 * [1801] Number of Orders in the Backlog
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;

        for (const auto& o : orders) {
            if (o[2]) {
                sell.push(o);
            } else {
                buy.push(o);
            }

            while (buy.size() && sell.size() && sell.top()[0] <= buy.top()[0]) {
                int k = min(buy.top()[1], sell.top()[1]);
                vector<int> tmp = buy.top(); buy.pop();
                tmp[1] -= k;
                if (tmp[1]) {
                    buy.push(tmp);
                }
                tmp = sell.top(); sell.pop();
                tmp[1] -= k;
                if (tmp[1]) {
                    sell.push(tmp);
                }
            }
        }

        const int MOD = 1000000007;
        int ans = 0;
        while (buy.size()) {
            ans = (ans + buy.top()[1]) % MOD;
            buy.pop();
        }
        while (sell.size()) {
            ans = (ans + sell.top()[1]) % MOD;
            sell.pop();
        }
        return ans;
    }
};
// @lc code=end

