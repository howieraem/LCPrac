/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(n)
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> x2ys;

        for (const auto &p : points) {
            x2ys[p[0]].insert(p[1]);
        }

        const int n = points.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 != x2 && y1 != y2) {
                    unordered_set<int> *sy1 = &x2ys[x1], *sy2 = &x2ys[x2];
                    // If y2 is in set of x1's y and y1 is in set of x2's y,
                    // the two points form one diagonal of a rectangle.
                    if (sy1->find(y2) != sy1->end() && sy2->find(y1) != sy2->end()) {
                        ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;    // returns 0 if no rectangle exists
    }
};
// @lc code=end

