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

    # 2D DP
    # Solution that works for odd len(piles) and computes the final scores.
    # T: O(n ^ 2)
    # S: O(n ^ 2)
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)

        # dp[l][r] means best scores alice and lee will get for piles[l...r]
        dp = [[(0, 0)] * n for _ in range(n)]

        for left in range(n - 1, -1, -1):
            for right in range(left, n):
                if left == right:
                    # odd number of piles, the first player picks
                    dp[left][right] = (piles[left], 0)
                    continue
                
                # Prevent the other player picking the pile that makes the score larger
                pick_left = dp[left + 1][right]
                pick_right = dp[left][right - 1]
                left_oppo_score = piles[left] + pick_left[1]
                right_oppo_score = piles[right] + pick_right[1]
                
                if left_oppo_score > right_oppo_score:
                    # If the left choice has higher score than the right choice,
                    # then pick left
                    dp[left][right] = (left_oppo_score, pick_left[0])
                else:
                    # Pick right
                    dp[left][right] = (right_oppo_score, pick_right[0])

        alice, lee = dp[0][n - 1]
        return alice > lee


# @lc code=end

