#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start
class Solution:
    def fib(self, N: int) -> int:
        if N < 2:
            return N
        ans = 0
        dp_i_2, dp_i_1 = 0, 1
        for _ in range(2, N+1):
            ans = dp_i_1 + dp_i_2
            dp_i_2 = dp_i_1
            dp_i_1 = ans
        return ans

        
# @lc code=end
