#
# @lc app=leetcode.cn id=877 lang=python3
#
# [877] 石子游戏
#

# @lc code=start
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        # 1. As sum(piles) % 2 != 0, there will not be draw.
        # 2. As len(piles) % 2 == 0, one will always win, no matter who starts first.
        return True

# @lc code=end

