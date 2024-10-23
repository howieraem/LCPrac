#
# @lc app=leetcode id=799 lang=python3
#
# [799] Champagne Tower
#

# @lc code=start
class Solution:
    # T: O(query_row ^ 2)
    # S: O(query_row)
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        if query_glass > query_row:
            return 0
        
        # dp[i][j] means cups of liquid at ith row and jth col
        dp = [poured]

        for i in range(query_row + 1):
            # dp[i + 1][...], there are i + 1 glasses on the ith row as i is zero-indexed
            dp_next = [0] * (i + 2)

            for j in range(i + 1):
                if dp[j] > 1:
                    flowed = (dp[j] - 1) / 2.
                    dp_next[j] += flowed 
                    dp_next[j + 1] += flowed
                    dp[j] = 1
                
            if i < query_row:
                # rolling
                dp = dp_next

        return dp[query_glass]

# @lc code=end

