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
        # d[i][j] means cups of liquid at ith row and jth col
        dp_i = [poured]

        for i in range(query_row + 1):
            # dp[i + 1][...], there are i + 1 glasses on the ith row as i is zero-indexed
            dp_i_1 = [0] * (i + 2)

            for j in range(i + 1):
                if dp_i[j] >= 1:
                    flowed = (dp_i[j] - 1) / 2.
                    dp_i_1[j] += flowed 
                    dp_i_1[j + 1] += flowed
                    dp_i[j] = 1
                
            if i < query_row:
                # rolling
                dp_i = dp_i_1

        return dp_i[query_glass]
        
# @lc code=end

