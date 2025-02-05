/*
 * @lc app=leetcode id=465 lang=cpp
 *
 * [465] Optimal Account Balancing
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
// "settle the debt" means no one owes others

class Solution {
public:
    // backtracking
    // T: O((n - 1)!), n := len(transactions)
    // S: O(n)
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balances;
        for (const auto& tran : transactions) {
            balances[tran[0]] -= tran[2];
            balances[tran[1]] += tran[2];
        }
        vector<int> debts;
        for (const auto& p : balances) {
            if (p.second != 0) {
                // debts[i] > 0 means someone owes others;
                // debts[i] < 0 means someone needs money returned by others
                debts.push_back(p.second);
            }
        }

        return dfs(0, debts);
    }

private:
    int dfs(int start_idx, vector<int>& debts) {
        const int n = debts.size();

        // skip the zero debts
        while (start_idx < n && debts[start_idx] == 0) {
            ++start_idx;
        }

        if (start_idx == n) {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = start_idx + 1; i < n; ++i) {
            if (debts[i] * debts[start_idx] < 0) {   // different signs, one owes other
                debts[i] += debts[start_idx];
                ans = std::min(ans, 1 + dfs(start_idx + 1, debts));
                debts[i] -= debts[start_idx];  // backtrack
            }
        }
        return ans;
    }
};
// @lc code=end

