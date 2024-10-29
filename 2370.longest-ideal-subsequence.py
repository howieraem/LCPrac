class Solution:
    # 2D DP
    # T: O(len(s) * alpha_size)
    # S: O(alpha_size) with state compression
    def longestIdealString(self, s: str, k: int) -> int:
        OFFSET = ord('a')
        
        # Variant of LIS Q300
        # dp[i][j] means length of longest ideal subseq for s[...i] ending with chr(j)
        # dp[i][...] only depends on dp[i - 1][...], compress state
        dp = [0] * 26

        ans = 1

        for c in s:
            ci = ord(c) - OFFSET
            dp[ci] += 1

            for cj in range(max(0, ci - k), min(25, ci + k) + 1):
                if cj == ci:
                    # avoid updating same kind of char again
                    continue
                dp[ci] = max(dp[ci], dp[cj] + 1)

            ans = max(ans, dp[ci])

        return ans
