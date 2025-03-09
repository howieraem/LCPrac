class Solution {
    private static final long F = 1000000007;

    // dp[i][j] means the number of ways to assign i performers to j stages 
    // such that each stage has at least one performer.
    // n, x <= 1000
    private static long[][] dp = new long[1001][1001];
    static {
        dp[0][0] = 1L;
        for (int i = 1; i <= 1000; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % F;
            }
        }
    }

    // 2D DP + Math
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    public int numberOfWays(int n, int x, int y) {
        // calculate perm(x, a), picking x events from a events
        long perm = 1L;
        
        // calculate pow(y, a), a events, each of which can score from 1 to y (inclusive)
        long pow = 1L;
        
        // Total no. of event ways = perm(x, a) * dp[n][a] * pow(y, a)
        long ans = 0L;
        int upper = Math.min(n, x);
        for (int i = 1; i <= upper; ++i) {
            perm = perm * (x - i + 1) % F;
            pow = pow * y % F;
            ans = (ans + perm * dp[n][i] % F * pow) % F;
        }
        return (int) ans;
    }
}