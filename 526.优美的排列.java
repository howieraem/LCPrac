import java.util.*;
/*
 * @lc app=leetcode.cn id=526 lang=java
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
    private int n;
    // private int ans;
    // private Map<Integer, Integer> memo;
    private int[] memo;

    public int countArrangement(int n) {
        this.n = n;
        // ans = 0;
        // memo = new HashMap<>();
        memo = new int[1 << (n + 1)];  // 1-indexed, add 1
        Arrays.fill(memo, -1);

        // 1 <= n <= 15, can use an integer to store seen status
        // instead of boolean[n + 1].
        int seen = 0;
        // backtrack(1, seen);
        // return ans;
        return backtrack(1, seen);
    }

    private int backtrack(int step, int seen) {
        if (step == n + 1) {
            // ++ans;
            return 1;
        }
        // if (memo.containsKey(seen))  return memo.get(seen);
        if (memo[seen] != -1)  return memo[seen];

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            // if (seen[i] == false) {
            if (((seen >> i) & 1) == 0) {
                // seen[i] = true;
                if (i % step == 0 || step % i == 0) {
                    cnt += backtrack(step + 1, seen | (1 << i));
                }
                // seen[i] = false;
            }
        }
        // memo.put(seen, cnt);
        // return cnt;
        return memo[seen] = cnt;
    }
}
// @lc code=end

