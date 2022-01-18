import java.util.*;
/*
 * @lc app=leetcode.cn id=943 lang=java
 *
 * [943] 最短超级串
 */

// @lc code=start
class Solution {
    public String shortestSuperstring(String[] words) {
        int n = words.length;

        // Build the cost graph.
        // g[i][j]: the cost of appending words[j] after words[i], i.e. the length of trailing substring of words[j] 
        // that do not overlap with the trailing substring of words[i], which equals the length of words[j] 
        // minus the number of overlapping chars between trailing chars of words[i] and leading 
        // chars of words[j].
        // The objective is to find the shortest path (min. cost) to visit each node exactly once.
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int li = words[i].length(), lj = words[j].length();
                g[i][j] = lj;
                int l = Math.min(li, lj);
                for (int k = 1; k <= l; ++k) {
                    if (words[i].substring(li - k).equals(words[j].substring(0, k))) {
                        g[i][j] = lj - k;
                    }
                }
            }
        }

        int m = (1 << n);   // n <= 12 < 32, can use Integer mask to store node indices seen, i.e. the state
        int[][] dp = new int[m][n];     // dp[s][i]: min. cost to visit nodes encoded by state s ending at i.
        int[][] parents = new int[m][n];
        for (int i = 0; i < m; ++i) {
            Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
            Arrays.fill(parents[i], -1);
        }
        for (int i = 0; i < n; ++i) {
            // base case: for just the node itself without visiting other nodes, the cost is the word's length
            dp[1 << i][i] = words[i].length();
        }
        for (int s = 1; s < m; ++s) {
            for (int j = 0; j < n; ++j) {
                if ((s & (1 << j)) == 0)  continue;     // seen
                int ps = s & ~(1 << j);     // mark seen
                for (int i = 0; i < n; ++i) {
                    int newCost = dp[ps][i] + g[i][j];
                    if (newCost < dp[s][j]) {
                        dp[s][j] = newCost;
                        parents[s][j] = i;
                    }
                }
            }
        }
        

        // Find the beginning word
        int s = m - 1;
        int min = Integer.MAX_VALUE, j = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[s][i] < min) {
                min = dp[s][i];
                j = i;
            }
        }

        // Reconstruct string with the shortest path found
        String ans = "";
        while (s > 0) {  
            // start from the state where all nodes are seen, then recover the path and mark unseen
            int i = parents[s][j];
            if (i < 0) {
                ans = words[j] + ans;
            } else {
                ans = words[j].substring(words[j].length() - g[i][j]) + ans;
            }
            s &= ~(1 << j);
            j = i;
        }
        return ans;
    }
}
// @lc code=end

