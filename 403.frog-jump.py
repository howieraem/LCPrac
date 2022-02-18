#
# @lc app=leetcode id=403 lang=python3
#
# [403] Frog Jump
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(n)
    def canCross(self, stones: List[int]) -> bool:
        dp_dead_end = set()

        target = stones[-1]
        stones = set(stones)

        def memo_dfs(pos, step_size):
            state = (pos, step_size)
            if state in dp_dead_end:
                return False

            if pos == target:
                return True
            
            if pos > target or pos < 0 or step_size <= 0 or pos not in stones:
                return False

            for next_step_size in (step_size - 1, step_size, step_size + 1):
                next_pos = pos + next_step_size
                if next_pos in stones and memo_dfs(next_pos, next_step_size):
                    return True

            dp_dead_end.add(state)
            return False

        return memo_dfs(1, 1)

# @lc code=end

