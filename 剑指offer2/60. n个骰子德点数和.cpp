#include <bits/stdc++.h>

using std::vector;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // dp[i][j] means the number of times sum j occurs after i attempts.
        // The maximum sum would be 6 * n. Add 1 to to the dimension(s) as 
        // 1-indexing is a better representation in this question.
        // int dp[n + 1][6 * n + 1];
        int dp[6 * n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= 6; ++i) {
            // dp[1][i] = 1;
            dp[i] = 1;
        }

        /*
        // Original state transition, 2D
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= 6 * i; ++j) {
                for (int cur = 1; cur <= 6; ++cur) {
                    // In the ith attempt, sum j minus the current points must be no less than i - 1.
                    if (j - cur < i - 1)  break;
                    dp[i][j] += dp[i - 1][j - cur];
                }
            }
        }
        */

        // Since cases of the nth attempt only directly depends on the (n - 1)th attempt, 
        // compress the states to 1D.
        // Explanations: 
        //   https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/
        for (int i = 2; i <= n; ++i) {
            for (int j = 6 * i; j >= i; --j) {
                dp[j] = 0;
                for (int cur = 1; cur <= 6; ++cur) {
                    if (j - cur < i - 1)  break;
                    dp[j] += dp[j - cur];
                }
            }
        }

        double tot = (double) pow(6, n);
        // vector<double> res;
        vector<double> res(5 * n + 1);
        for (int i = n; i <= 6 * n; ++i) {
            // res.push_back(dp[n][i] / tot);
            res[i - n] = dp[i] / tot;
        }
        return res;
    }
};
