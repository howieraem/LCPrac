#
# @lc app=leetcode.cn id=877 lang=python3
#
# [877] 石子游戏
#
from typing import List

# @lc code=start
class Solution:
    '''
    def stoneGame(self, piles: List[int]) -> bool:
        # 1. As sum(piles) % 2 != 0, there will not be draw.
        # 2. As len(piles) % 2 == 0, one will always win, no matter who starts first.
        return True
    '''

    def stoneGame(self, piles: List[int]) -> bool:
        """
        Solution that works for odd len(piles) and computes the final scores.
        
        T: O(n ^ 2)
        S: O(n ^ 2)
        """
        n = len(piles)
        dp = [[(0, 0)] * n for _ in range(n)]
        for left in range(n - 1, -1, -1):
            for right in range(left, n):
                if left == right:
                    dp[left][right] = (piles[left], 0)
                    continue
                pick_left = dp[left + 1][right]
                pick_right = dp[left][right - 1]
                if piles[left] + pick_left[1] > piles[right] + pick_right[1]:
                    # If the left choice has higher score than the right choice,
                    # then pick left
                    dp[left][right] = (piles[left] + pick_left[1], pick_left[0])
                else:
                    # Pick right
                    dp[left][right] = (piles[right] + pick_right[1], pick_right[0])

        alice, lee = dp[0][n - 1]
        return alice > lee


# @lc code=end

