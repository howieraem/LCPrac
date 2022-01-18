#
# @lc app=leetcode.cn id=135 lang=python3
#
# [135] 分发糖果
#

# @lc code=start
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n < 2:
            return n
        candies = [1] * n

        # 先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为
        # 左边孩子的糖果数加1。
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1

        # 再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数
        # 不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加1。
        # 与此同时，第二次遍历可以顺带求和。
        ans = candies[-1]
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:  # and candies[i] < candies[i + 1] + 1:
                candies[i] = max(candies[i], candies[i + 1] + 1)
            ans += candies[i]
        return ans

# @lc code=end

