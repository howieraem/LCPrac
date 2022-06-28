/*
 * @lc app=leetcode id=1298 lang=cpp
 *
 * [1298] Maximum Candies You Can Get from Boxes
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2) because of possible duplicate keys in different boxes
    // S: O(n)
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        std::queue<int> q;
        vector<uint8_t> reachable_closed(status.size(), 0);
        for (const int& b : initialBoxes) {
            if (status[b]) q.push(b);
            else reachable_closed[b] = 1;
        }

        int ans = 0;
        while (q.size()) {
            int b = q.front(); q.pop();
            ans += candies[b];
            for (const int& k : keys[b]) {
                if (reachable_closed[k]) {
                    reachable_closed[k] = 0;
                    q.push(k);
                }
                status[k] = 1;
            }

            for (const int& next_b : containedBoxes[b]) {
                if (status[next_b]) {
                    q.push(next_b);
                } else {
                    reachable_closed[next_b] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

