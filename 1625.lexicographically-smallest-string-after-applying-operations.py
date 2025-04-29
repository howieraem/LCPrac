#
# @lc app=leetcode id=1625 lang=python3
#
# [1625] Lexicographically Smallest String After Applying Operations
#

# @lc code=start
class Solution:
    # DFS
    # T: O(n ^ 3), no. of unique strings bound by 10 * n ^ 2, next string op O(n)
    # S: O(n ^ 2)
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        OFFSET = ord('0')
        n = len(s)

        def op_a(s: str) -> str:
            s = list(s)
            for i in range(1, n, 2):
                s[i] = chr((ord(s[i]) - OFFSET + a) % 10 + OFFSET)
            return ''.join(s)

        def op_b(s: str) -> str:
            return s[n - b:] + s[:n - b]

        vis = set()
        ans = s

        def dfs(s: str):
            if s in vis:
                return

            nonlocal ans
            ans = min(ans, s)

            vis.add(s)
            dfs(op_a(s))
            dfs(op_b(s))

        dfs(s)

        return ans


# @lc code=end

