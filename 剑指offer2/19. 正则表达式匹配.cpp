#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int n = s.size(), m = p.size();
        bool dp[n + 1][m + 1];  // avoid using vector<bool>
        for (int i = 0; i <= n; ++i) {
            fill_n(dp[i], m + 1, false);
        }

        dp[0][0] = true;    // dp[i][j] means whether s[:i] matches p[:j]
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] != '*') {
                    // Current regex character is not '*', check exact match or '.'
                    if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    // Current regex character is '*', two cases
                    // case 1: omit ('*' matches none)
                    if (j >= 2) {
                        dp[i][j] = dp[i][j] || dp[i][j - 2];
                    }
                    // case 2: do not omit
                    if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};
