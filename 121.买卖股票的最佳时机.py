#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    '''
    def maxProfit(self, prices: List[int]) -> int:
        # A more general solution: mono-stack,
        # which can be used in any problem of
        # the following form:
        # 用O(n)的时间得知所有位置两边第一个比他大(或小)的数的位置
        ans, stack = 0, []
        prices = prices + [-1]  # 加"哨兵"，确保单调栈中的每个元素都被进行判定
        for price in prices:
            while stack and stack[-1] > price:
                ans = max(ans, stack[-1] - stack[0])
                stack.pop()
            stack.append(price)
        return ans
    '''
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        ans = 0
        for price in prices:
            ans = max(ans, price-min_price)
            min_price = min(min_price, price)
        return ans
    

# @lc code=end

