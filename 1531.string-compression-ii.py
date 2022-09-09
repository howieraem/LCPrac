#
# @lc app=leetcode id=1531 lang=python3
#
# [1531] String Compression II
#
import functools

# @lc code=start
def cid(c: str):
    return ord(c) - ord('a')

class Solution:
    # T: O(n ^ 2 * k * s), s := 27
    # S: O(n ^ 2 * k * s)
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        INF = float('inf')
        n = len(s)

        # memo[n + 1][26][n + 1][k + 1]
        # memo[i][c][j][k] means the result for s[:i + 1] with previous char c, previous char count j and remaining k
        # memo = [[[[INF] * (k + 1) for _ in range(n + 1)] for _ in range(27)] for _ in range(n + 1)]
        
        @functools.lru_cache(None)  # had to use built-in memo, otherwise TLE
        def dfs(i: int, pre_c: str, cnt: int, k: int) -> int:
            if k < 0:
                return INF
            if i == n:
                return 0
            # ci = cid(pre_c)
            # if memo[i][ci][cnt][k] != INF:
            #     return memo[i][ci][cnt][k]
            
            ans = 0
            if s[i] == pre_c:
                # Same char as previous, increment the cnt and possibly the length
                ans = dfs(i + 1, pre_c, cnt + 1, k) + (cnt == 1 or cnt == 9 or cnt == 99)  # These cnts + 1 will increment result string length
            else:
                # Whether or not to delete a char
                ans = min(dfs(i + 1, s[i], 1, k) + 1, dfs(i + 1, pre_c, cnt, k - 1))

            # memo[i][ci][cnt][k] = ans
            return ans

        # Previous char at the beginning doesn't exist. Use '{' as a placeholder for 
        # easy conversion to index (the char after 'z')
        return dfs(0, '{', 0, k)


# @lc code=end

