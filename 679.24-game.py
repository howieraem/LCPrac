#
# @lc app=leetcode id=679 lang=python3
#
# [679] 24 Game
#
from typing import List

# @lc code=start
class Solution:
    # Backtracking
    # T: O(2 ^ (k * n ^ 2)), n := len(cards), k := the no. of op combinations between two numbers which can be 4, 5 or 6
    # S: O(n * k)? recursive stack
    def judgePoint24(self, cards: List[int]) -> bool:
        EPS = 0.001
        TARGET = 24

        def get_op_ret_combos(a: int, b: int):
            nums = [a + b, a - b, b - a, a * b]
            if b > EPS:
                nums.append(a / b)
            if a > EPS:
                nums.append(b / a)
            return nums

        def backtrack(nums: list) -> bool:
            n = len(nums)
            if n == 1:
                return abs(nums[0] - TARGET) < EPS

            for i in range(n):
                for j in range(i + 1, n):
                    # neighbors: {the operation results between two selected numbers nums[i] and nums[j]} 
                    #            union {other numbers in nums}
                    next_nums = [nums[k] for k in range(n) if k != i and k != j]
                    for x in get_op_ret_combos(nums[i], nums[j]):
                        next_nums.append(x)
                        if backtrack(next_nums):
                            return True
                        next_nums.pop()
            
            return False

        return backtrack(cards)

# @lc code=end

