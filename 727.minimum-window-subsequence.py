#
# @lc app=leetcode id=727 lang=python3
#
# [727] Minimum Window Subsequence
#

# @lc code=start
class Solution:
    # Solution 1: two pointers
    # T: O(m ^ 2) worst, O(m * n) on average
    # S: O(1)
    def minWindow(self, s1: str, s2: str) -> str:
        m = len(s1)
        n = len(s2)
        i = 0
        j = 0
        min_len = m + 1
        min_subseq_start = -1

        while i < m:
            if s1[i] == s2[j]:
                j += 1
                
                if j == n:
                    # Found a valid subseq in s1
                    subseq_end = i + 1

                    # Try to shorten the subseq by checking 
                    # characters reversely
                    j = n - 1
                    subseq_start = subseq_end - 1
                    while j >= 0:
                        if s1[subseq_start] == s2[j]:
                            j -= 1
                        if j >= 0:
                            subseq_start -= 1

                    # Update answer
                    new_len = subseq_end - subseq_start
                    if new_len < min_len:
                        min_len = new_len
                        min_subseq_start = subseq_start

                    # Update pointer of s1 to search for next subseq (will add 1 below). 
                    # j should be 0 at this point.
                    i = subseq_start

            i += 1

        return s1[min_subseq_start:min_subseq_start + min_len] if min_subseq_start != -1 else ""
    
    # Solution 2: 2D DP
    # T: O(m * n)
    # S: O(m * n), or O(n) with state compression
    def minWindow(self, s1: str, s2: str) -> str:
        m = len(s1)
        n = len(s2)
        
        # dp[i][j] means the starting index (1-indexed) of the substring for s1[:i] and s2[:j]
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            # add 1 to distinguish from dp[i][j] == 0
            dp[i][0] = i + 1
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:  # char matches
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i - 1][j]
        
        min_len = m + 1
        start = 0
        for i in range(1, m + 1):   # i indicates substr end index here
            if dp[i][n] > 0:
                cur_len = i - (dp[i][n] - 1)
                if cur_len < min_len:
                    min_len = cur_len
                    start = dp[i][n] - 1

        return '' if min_len == m + 1 else s1[start:start + min_len]


# @lc code=end

