/*
 * @lc app=leetcode id=1761 lang=cpp
 *
 * [1761] Minimum Degree of a Connected Trio in a Graph
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> A(n + 1, vector<bool>(n + 1, false));
        vector<int> deg(n + 1, 0);

        for (auto &e : edges) {
            int v1 = e[0], v2 = e[1];
            A[v1][v2] = A[v2][v1] = true;   // undirected
            ++deg[v1];  ++deg[v2];
        }

        int ans = INT_MAX;
        // Notice the prune conditions added
        for (int i = 1; i <= n - 2; ++i) {
            if (deg[i] < 2) continue;
            for (int j = i + 1; j <= n - 1; ++j) {
                if (!A[i][j] || deg[j] < 2)  continue;
                for (int k = j + 1; k <= n; ++k) {
                    if (A[j][k] && A[i][k]) {
                        ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

