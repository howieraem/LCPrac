/*
 * @lc app=leetcode id=1718 lang=java
 *
 * [1718] Construct the Lexicographically Largest Valid Sequence
 */

// @lc code=start
class Solution {
    // Backtracking (nested)
    // T: O(n!)
    // S: O(n)
    public int[] constructDistancedSequence(int n) {
        int[] res = new int[(n << 1) - 1];
        boolean[] vis = new boolean[n + 1];
        backtrack(0, res, vis, n);
        return res;
    }

    // return a bool for early stopping (trim search branches)
    private boolean backtrack(int i, int[] res, boolean[] vis, final int n) {
        if (i == res.length) {
            return true;
        }

        if (res[i] != 0) {  // value already assigned, proceed to next one
            return backtrack(i + 1, res, vis, n);
        }

        // iterate from n to 1 for lexicographically largest sequence
        for (int x = n; x >= 1; --x) {
            if (vis[x]) {
                continue;
            }
            
            res[i] = x;
            vis[x] = true;
            if (x == 1 && backtrack(i + 1, res, vis, n)) {
                // value 1 should appear once
                return true;
            } else if (x + i < res.length && res[x + i] == 0) {
                // assign the second occurrence of the same x value
                res[x + i] = x;
                if (backtrack(i + 1, res, vis, n)) {
                    return true;
                }
                res[x + i] = 0;  // reset
            }
            // reset
            res[i] = 0;
            vis[x] = false;
        }

        // unable to find a valid sequence
        return false;
    }
}
// @lc code=end

