#
# @lc app=leetcode id=1088 lang=python3
#
# [1088] Confusing Number II
#

# @lc code=start
class Solution:
    mapping = {
        0: 0,
        1: 1,
        6: 9,
        8: 8,
        9: 6
    }

    # T: O(5 ^ log10(n))
    # S: O(log10(n)) recursion stack
    def confusingNumberII(self, n: int) -> int:
        def dfs(x, x_rotated, base):
            if x > n:
                return 0
            ans = x != x_rotated
            for d in self.mapping:
                if d == 0 and x == 0:
                    continue
                ans += dfs(x * 10 + d, self.mapping[d] * base + x_rotated, base * 10)
            return ans

        return dfs(0, 0, 1)

# @lc code=end

