#
# @lc app=leetcode id=343 lang=python3
#
# [343] Integer Break
#

# @lc code=start
class Solution:
    # 1D DP, like knapsack problem
    # T: O(n ^ 2)
    # S: O(n)
    def integerBreak(self, n: int) -> int:
        dp = [1] * (n + 1)  # dp[i] means the max product of ints summing to i

        for i in range(2, n + 1):
            # only need to iterate to half of i, because j and i - j are symmetric
            for j in range(1, (i >> 1) + 1):
                # Pick max of {
                #   dp[i - j] * dp[j]
                #   dp[i - j] * j
                #   (i - j) * dp[j]
                #   (i - j) * j 
                # }
                dp[i] = max(dp[i], max(dp[i - j], i - j) * max(dp[j], j))
        
        return dp[n]
    
    '''
    # Math method: 
    # T: O(1)
    # S: O(1)
    # Property: for all integers n > 4, (n - 3) * 3 > n
    def integerBreak(self, n: int) -> int:
        if n == 2: 
            return 1
        if n == 3: 
            return 2
        
        mult, remainder = divmod(n, 3)

        if remainder == 0:
            return 3 ** mult
        elif remainder == 1:
            remainder += 3
            mult -= 1
        return 3 ** mult * remainder
    '''


# @lc code=end

