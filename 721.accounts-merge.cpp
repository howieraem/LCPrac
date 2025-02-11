/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class UF {
    vector<int> parent, size;

public:
    UF(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // a node's parent is itself initially
        }
    }

    void connect(int p, int q) {
        int rootP = find(p), rootQ = find(q);
        if (rootP == rootQ)  return;  // already connected

        // Re-balance height by connecting the smaller graph to the larger graph,
        // to avoid building a linked list
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }
    
    int find(int x) {
        while (parent[x] != x) {
            // path compression
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    // union find + hash map
    // T: O(m * n * log(n)), m := len(accounts), n := avg(len(a) for a in accounts)
    // S: O(m * n)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int n = accounts.size();
        UF uf(n);
        unordered_map<string, int> email2id;
        for (int i = 0; i < n; ++i) {
            // `accounts[i][0]` is user name
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                // Choose the first email encountered as the root of this user in UF.
                // Other emails will connect to this root.
                auto id_it = email2id.find(email);
                if (id_it == email2id.end()) {
                    email2id[email] = i;
                } else {
                    uf.connect(i, id_it->second);
                }
            }
        }

        // Collect emails that belong to the same users 
        // (doesn't include the first email above)
        unordered_map<int, vector<string>> id2emails;
        for (const auto &e : email2id) {
            id2emails[uf.find(e.second)].push_back(e.first);
        }

        // Transform to the required output format
        vector<vector<string>> res;
        for (const auto &e : id2emails) {
            vector<string> emails = e.second;
            sort(emails.begin(), emails.end());   // sort emails of an account

            vector<string> account;
            account.reserve(1 + emails.size());
            account.push_back(accounts[e.first][0]);  // add first email
            for (auto& email : emails) {  // add other same-person emails
                account.push_back(std::move(email));
            }
            res.push_back(std::move(account));
        }
        return res;
    }
};
// @lc code=end

