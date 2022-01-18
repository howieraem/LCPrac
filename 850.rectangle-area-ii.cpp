/*
 * @lc app=leetcode id=850 lang=cpp
 *
 * [850] Rectangle Area II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
    static const int MOD = 1000000007;

public:
    // Sweeping line algo
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> all_x;
        for (const auto &r : rectangles) {
            all_x.push_back(r[0]);
            all_x.push_back(r[2]);
        }
        sort(all_x.begin(), all_x.end());
        vector<int> x {all_x[0]};
        for (int i = 1; i < all_x.size(); ++i) {
            if (all_x[i] == all_x[i - 1])  continue;
            x.push_back(all_x[i]);
        }

        unordered_map<int, int> x_i;
        for (int i = 0; i < x.size(); ++i) {
            x_i[x[i]] = i;
        }

        vector<int> x_covers(x.size(), 0);
        vector<vector<int>> L;
        for (const auto &r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            // l[3] = 1 means entering a rectangle, otherwise leaving
            L.push_back({y1, x1, x2, 1});
            L.push_back({y2, x1, x2, -1});
        }
        sort(L.begin(), L.end());   // sort lines by y coordinate?
        long long cur_y = 0, cur_x_sum = 0, ans = 0;
        for (const auto &l : L) {
            long long y = l[0], x1 = l[1], x2 = l[2], state = l[3];
            ans = (ans + (y - cur_y) * cur_x_sum) % MOD;
            cur_y = y;
            for (int i = x_i[x1]; i < x_i[x2]; ++i) {
                x_covers[i] += state;
            }
            cur_x_sum = 0;
            for (int i = 0; i < x.size(); ++i) {
                if (x_covers[i]) {
                    // Check x_covers[i] != 0 to calculate the union
                    // of all rectangles.  
                    // Change this to x_covers[i] > 1 if finding 
                    // the overlapping area (intersection) only.
                    // All intersections are considered once only.
                    cur_x_sum += x[i + 1] - x[i];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

