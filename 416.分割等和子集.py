#
# @lc app=leetcode.cn id=416 lang=python3
#
# [416] 分割等和子集
#
from typing import List

# @lc code=start
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        _sum, n = sum(nums), len(nums)
        if _sum % 2:    
            # cannot partition with odd sum because `sum_ // 2 != sum_ / 2`
            return False
        
        # 转化为背包问题：是否存在nums的子集能刚好装满`_sum/2`容量的背包
        _sum //= 2      
        dp = [False]*(_sum+1)
        dp[0] = True
        for i in range(n):
            for j in range(_sum, -1, -1):
                if j - nums[i] >= 0:
                    dp[j] |= dp[j - nums[i]]    # dp[j] or dp[j-nums[i]]
        return dp[-1]

# @lc code=end
