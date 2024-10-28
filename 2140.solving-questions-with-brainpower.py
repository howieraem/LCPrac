#
# @lc app=leetcode id=2140 lang=python3
#
# [2140] Solving Questions With Brainpower
#
from typing import *

# @lc code=start
class Solution:
    # Memoized DFS (top-bottom 1D DP)
    # T: O(n)
    # S: O(n)
    def mostPoints(self, questions: List[List[int]]) -> int:
        # If a question is solved with brain power x, 
        # then the next x questions can't be chosen.
        n = len(questions)
        memo = [None] * n  # memo[i] means the most points gained if starting with questions[i]

        def dfs(i: int) -> int:
            if i >= len(questions):
                return 0
            v = memo[i]
            if v is not None:
                return v
            
            ans = max(
                # skip current question
                dfs(i + 1),
                # pick current question and skip the next few
                questions[i][0] + dfs(i + 1 + questions[i][1])  
            )
            memo[i] = ans
            return ans
            
        return dfs(0)
    
    # Bottom-up 1D DP
    # Same state transition equation, but need to update 
    # the dp array reversely




# @lc code=end

